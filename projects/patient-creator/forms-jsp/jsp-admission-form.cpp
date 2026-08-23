
#include "jsp-admission-form.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

#include <QFile>


JSP_Admission_Form::JSP_Admission_Form(QString name, QString index_code, QString summary)
{

}

void JSP_Admission_Form::write_summary(QString file_path)
{
    QFile out_file(file_path);
    if (out_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
     QTextStream out(&out_file);
     out << summary_;
     out_file.close();
    }
}


void JSP_Admission_Form::parse_question(const QJsonObject& question_qjo)
{
    QString id = question_qjo.value("id").toString();
    QString label = question_qjo.value("label").toString();
    QString question_type = question_qjo.value("type").toString();
    bool is_required = question_qjo.value("required").toBool();

    QJsonObject question_options_qjo = question_qjo.value("questionOptions").toObject();

    QString rendering = question_options_qjo.value("rendering").toString();
    QString question_concept = question_options_qjo.value("concept").toString();
    QString question_default = question_options_qjo.value("default").toString();

    QString r = QString("\n :required ") + (is_required? "t" : "f");
    summary_ += "\n\nnew-question ;.";
    summary_ += r;
    summary_ += "\n :id $ " + id + " ;.";
    summary_ += "\n :label $ " + label + " ;.";
    summary_ += "\n :question-type $ " + question_type + " ;.";
    summary_ += "\n :question-concept $ " + question_concept + " ;.";
    summary_ += "\n :rendering $ " + rendering + " ;.";
    summary_ += "\n :default $ " + question_default + " ;.";
    summary_ += "\nfinalize-question ;.\n";

    QJsonArray answers = question_options_qjo.value("answers").toArray();

    for(const QJsonValue& answer_qjv : std::as_const(answers))
    {
        summary_ += "\n\nnew-answer ;.";
        QJsonObject answer_qjo = answer_qjv.toObject();

        QString answer_label = answer_qjo.value("label").toString();

        if(answer_label == "Yes")
            summary_ += "\n .affirmative-answer-option ;.";
        else if(answer_label == "Yes")
            summary_ += "\n .negative-answer-option ;.";
        else
            summary_ += "\n .answer-label $ " + answer_label + " ;.";


        summary_ += "\n .answer-concept $ " + answer_qjo.value("concept").toString() + " ;.";
        summary_ += "\nfinalize-answer ;.\n";
    }
}



void JSP_Admission_Form::read_JSON_Object(const QJsonObject& qjo)
{
    processor_ = qjo.value("processor").toString();
    uuid_ = qjo.value("uuid").toString();
    version_ = qjo.value("version").toString();

    summary_ += "\n\nnew-form ;.";
    summary_ += "\n .form-processor " + processor_ + " ;.";
    summary_ += "\n .form-uuid " + uuid_ + " ;.";
    summary_ += "\n .form-version " + version_ + " ;.";
    summary_ += "\nfinalize-form ;.";

    QJsonArray pages = qjo.value("pages").toArray();

    int page_count = 0;

    for(const QJsonValue& page_qjv : std::as_const(pages))
    {
        QJsonObject page_qjo = page_qjv.toObject();
        ++page_count;
        page_labels_.push_back(page_qjo.value("label").toString());
        section_labels_.push_back({});
        QStringList& current_section_labels = section_labels_.last();

        summary_ += "\n\nnew-page ;.";
        summary_ += "\n :label " + page_qjo.value("label").toString() + " ;.";
        summary_ += "\nfinalize-page ;.\n";

        QJsonArray sections = page_qjo.value("sections").toArray();
        for(const QJsonValue& section_qjv : std::as_const(sections))
        {
            QJsonObject section_qjo = section_qjv.toObject();
            current_section_labels.push_back(section_qjo.value("label").toString());

            summary_ += "\n\nnew-section ;.";
            summary_ += "\n :label " + section_qjo.value("label").toString() + " ;.";
            summary_ += "\nfinalize-section ;.\n";

            QJsonArray questions = section_qjo.value("questions").toArray();
            for(const QJsonValue& question_qjv : std::as_const(questions))
            {
                QJsonObject question_qjo = question_qjv.toObject();
                parse_question(question_qjo);

            }
        }
    }


#ifdef HIDE
    for (auto it = qjo.constBegin(); it != qjo.constEnd(); ++it)
    {
        //        Node_Type inner_nt = Node_Type::N_A;
        QString key = it.key();
        QJsonValue qjv = it.value();

        QJsonValue::Type ty = qjv.type();
        switch(ty)
        {
        case QJsonValue::String:
        {
            QString val = qjv.toString();
            if(val.startsWith(""))
                qDebug() << "Key:" << key << "Value:" << qjv;
        }
        break;
        default: break;

        }

    }
#endif
}


void JSP_Admission_Form::reset_field_prefix(QString prefix)
{
    current_field_prefix_ = prefix;
}

void JSP_Admission_Form::check_field_expand(QString& dispatch)
{
    if(dispatch.startsWith(':'))
    {
        if(current_field_prefix_.isEmpty())
        {
            dispatch.replace(0, 1, "any-");
            return;
        }

        dispatch[0] = QChar('-');

        QString check = current_field_prefix_ + dispatch;

        if(known_prefixes_.contains(check))
            dispatch = check;
        else
            dispatch.prepend("any");
    }

}

#define STATIC_BASIC_SPACE static QChar basic_space = QChar::fromLatin1(' ');

quint16 _advance_past(QString& basis, QString* skipped, int ix0 = 0)
{
    STATIC_BASIC_SPACE

    int ix1 = basis.indexOf(basic_space, ix0);

    if(ix1 == 0)
        return 0;
    if(ix1 == -1)
        return 0;

    int ix2 = ix1 + 1;

    while(basis[ix2] == basic_space)
        ++ix2;

    if(skipped)
        *skipped = basis.mid(ix0, ix1 - ix0);

    basis = basis.mid(ix2);

    return ix2;
}


quint16 JSP_Admission_Form::advance_past_dispatch(QString& basis, QString* skipped)
{
    STATIC_BASIC_SPACE

    int ix0 = 0;
    while(basis[ix0] == basic_space)
        ++ix0;

    return _advance_past(basis, skipped, ix0);
}

quint16 JSP_Admission_Form::advance_past_mid_control(QString& basis, QString* skipped)
{
    STATIC_BASIC_SPACE

    if(basis.startsWith(";."))
        return 0;

    return _advance_past(basis, skipped);



}

quint16 JSP_Admission_Form::advance_past_mid_control(QString& basis, Mid_Control_Kinds& mck, Mid_Control_Coords& mcc)
{
    static QMap<QString, Mid_Control_Kinds> known_mid_controls {
        {"_$", Mid_Control_Kinds::String},
        {"_#", Mid_Control_Kinds::U_Infer},
        {"$$", Mid_Control_Kinds::String_List},
        {"1#", Mid_Control_Kinds::U1},
        {"2#", Mid_Control_Kinds::U2},
        {"4#", Mid_Control_Kinds::U4},
        {"8#", Mid_Control_Kinds::U8},
        {"1+", Mid_Control_Kinds::S1},
        {"2+", Mid_Control_Kinds::S2},
        {"4+", Mid_Control_Kinds::S4},
        {"8+", Mid_Control_Kinds::S8},
        {"_+", Mid_Control_Kinds::S_Infer},
        {"4%", Mid_Control_Kinds::R4},
        {"8%", Mid_Control_Kinds::R8},
        {"%", Mid_Control_Kinds::Fractional},

    };

    QString control;
    quint16 result = advance_past_mid_control(basis, &control);

    QString control_key = control.size() == 1? QString("_") + control : control.left(2);

    bool rep = control_key[0] == control_key[1];

    if(!rep && control_key.size() > 2)
        rep = control_key[1] == control_key[2];

    mck = known_mid_controls.value(control_key, Mid_Control_Kinds::N_A);

    mcc = Mid_Control_Coords::N_A;

    return result;

}


quint16 JSP_Admission_Form::advance_past_end_control(QString& basis, QString* skipped)
{

}

quint16 JSP_Admission_Form::advance_past_end_control(QString& basis, QStringList* skipped)
{

}

quint16 JSP_Admission_Form::advance_past_end_control(QString& basis, quint64* skipped)
{

}

quint16 JSP_Admission_Form::advance_past_end_control(QString& basis, qint64* skipped)
{

}

quint16 JSP_Admission_Form::advance_past_end_control(QString& basis, qreal* skipped)
{

}

quint16 JSP_Admission_Form::advance_past_end_control(QString& basis, float* skipped)
{

}


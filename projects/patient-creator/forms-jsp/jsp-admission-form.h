

#ifndef JSP_ADMISSION_FORM__H
#define JSP_ADMISSION_FORM__H

#include <QJsonObject>
#include <QString>
#include <QStringList>

class JSP_Admission_Form
{
    QString summary_;
    QString current_field_prefix_;

    QString processor_;
    QString uuid_;
    QString version_;

    QStringList page_labels_;
    QVector<QStringList> section_labels_;

    QSet<QString> known_prefixes_;

    enum class Node_Type {
        N_A, Form_Root
    };

    void reset_field_prefix(QString prefix);
    void check_field_expand(QString& dispatch);

public:

    JSP_Admission_Form(QString name, QString index_code, QString summary);

    void read_JSON_Object(const QJsonObject& qjo);
    void parse_question(const QJsonObject& question_qjo);

    void write_summary(QString file_path);

    enum class Mid_Control_Kinds {
        N_A, String, U_Infer, U1, U2, U4, U8, S_Infer,
        S1, S2, S4, S8, R4, R8, Fractional, String_List
    };

    enum class Mid_Control_Coords {
        N_A, x2, x3, List, Matrix
    };

    quint16 advance_past_dispatch(QString& basis, QString* skipped = nullptr);
    quint16 advance_past_mid_control(QString& basis, QString* skipped = nullptr);
    quint16 advance_past_mid_control(QString& basis, Mid_Control_Kinds& mck, Mid_Control_Coords& mcc);
    quint16 advance_past_end_control(QString& basis, QString* skipped = nullptr);

    quint16 advance_past_end_control(QString& basis, QStringList* skipped);
    quint16 advance_past_end_control(QString& basis, quint64* skipped);
    quint16 advance_past_end_control(QString& basis, qint64* skipped);
    quint16 advance_past_end_control(QString& basis, qreal* skipped);
    quint16 advance_past_end_control(QString& basis, float* skipped);

};


#endif // JSP_ADMISSION_FORM__H

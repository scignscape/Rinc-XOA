
#include "patientcreatorwizard.h"

using namespace Patients;

#include <QApplication>

#include <QFile>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>

#include <QRegularExpression>

#include "forms-jsp/jsp-admission-form.h"

enum class Node_Type {
    N_A, Form_Root
};


void process_form_node(const QJsonObject& qjo, QString key = {}, Node_Type nt = Node_Type::N_A)
{
    QString name = qjo.value("name").toString();

    QRegularExpression rx("^(F(\\d+)-ITFC)\\s*(\\w*)");
    QRegularExpressionMatch m = rx.match(name);

    if(m.hasMatch())
    {
        QString c1 = m.captured(1);
        QString c2 = m.captured(2);
        QString c3 = m.captured(3);
       JSP_Admission_Form form_jsp(c1, c2, c3);

        qDebug() << "c1 = " << c1;
        qDebug() << "c2 = " << c2;
        qDebug() << "c3 = " << c3;

        form_jsp.read_JSON_Object(qjo);

        form_jsp.write_summary("_summary.txt");

        QString test = " test-dis  $  test-arg ;.";
        QString rs;


        int r = form_jsp.advance_past_dispatch(test, &rs);

        qDebug() << "rs = " << rs;
        qDebug() << "r = " << r;
        qDebug() << "t = " << test;
    }
}


int main(int argc, char *argv[])
{
    QFile qf("../../ampathforms/F08-ITFC_Admission_form.json");
    if(!qf.exists())
        qDebug() << "problem";

    qf.open(QFile::ReadOnly);

    QByteArray qba = qf.readAll();

    QJsonParseError err;
    QJsonDocument qjd = QJsonDocument::fromJson(qba, &err);

    if (err.error != QJsonParseError::NoError) {
        qWarning() << "JSON parse error:" << err.errorString()
        << "at offset" << err.offset;
        return 0;
    }

    if (qjd.isArray())
    {
        qDebug() << "Unexpected Aray";
        return 0;
    }
    if (qjd.isNull())
    {
        qDebug() << "Unexpected empty document";
        return 0;
    }

    QJsonObject root_obj = qjd.object();
    process_form_node(root_obj);
//    qDebug() << "Successfully loaded JSON object.";
    // Read keys using rootObj["key"].to...

    return 0;
}


int main1(int argc, char *argv[])
{
 QApplication qapp(argc, argv);

 PatientCreatorWizard pcw(nullptr);

 pcw.show();


 return qapp.exec();
}

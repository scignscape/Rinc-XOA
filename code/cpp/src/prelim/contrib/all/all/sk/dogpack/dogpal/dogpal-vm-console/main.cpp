
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include <QApplication>

#include <QFile>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>

#include <QRegularExpression>

#include <QDir>

#include "vm/qynviper-json-vm.h"

#ifdef HIDE
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
#endif

int main(int argc, char *argv[])
{
    // QString cwd = QDir::currentPath();
    // qDebug() << "Current working directory:" << cwd;

    //    QFile qf("../patient-creator/ampathforms/F08-ITFC_Admission_form.json");
    //    if(!qf.exists())
    //        qDebug() << "problem";

    //    qf.open(QFile::ReadOnly);

    //    QByteArray qba = qf.readAll();


    Qynviper_JSON_VM qjv;

    QString test = " test-dis  $  test-arg ;.";
    QString rs;


    int r = qjv.advance_past_dispatch(test, &rs);

    qDebug() << "rs = " << rs;
    qDebug() << "r = " << r;
    qDebug() << "t = " << test;

    Qynviper_JSON_VM::Mid_Control_Kinds mck;
    Qynviper_JSON_VM::Mid_Control_Coords mcc;

    qjv.advance_past_mid_control(test, mck, mcc);

    QString arg;

    qjv.advance_past_end_control(test, &arg);

    qDebug() << "arg = " << arg;

    return 0;
}


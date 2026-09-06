
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <QFile>


#include <QRegularExpression>

#include <QDir>

#include "dogpal-vm/vm-interpreter.h"

#include "otns.h"

USING_OTNS(DogPal)


int main(int argc, char *argv[])
{
 QString vm_file_path = DEFAULT_VM_FOLDER "/test/t1.4lr";
 VM_Interpreter vin;
 vin.load_file(vm_file_path);
 vin.parse();

 vin.run();

//    // QString cwd = QDir::currentPath();
//    // qDebug() << "Current working directory:" << cwd;

//    //    QFile qf("../patient-creator/ampathforms/F08-ITFC_Admission_form.json");
//    //    if(!qf.exists())
//    //        qDebug() << "problem";

//    //    qf.open(QFile::ReadOnly);

//    //    QByteArray qba = qf.readAll();


//    Qynviper_JSON_VM qjv;

//    QString test = " test-dis  $  test-arg ;.";
//    QString rs;


//    int r = qjv.advance_past_dispatch(test, &rs);

//    qDebug() << "rs = " << rs;
//    qDebug() << "r = " << r;
//    qDebug() << "t = " << test;

//    Qynviper_JSON_VM::Mid_Control_Kinds mck;
//    Qynviper_JSON_VM::Mid_Control_Coords mcc;

//    qjv.advance_past_mid_control(test, mck, mcc);

//    QString arg;

//    qjv.advance_past_end_control(test, &arg);

//    qDebug() << "arg = " << arg;

    return 0;
}


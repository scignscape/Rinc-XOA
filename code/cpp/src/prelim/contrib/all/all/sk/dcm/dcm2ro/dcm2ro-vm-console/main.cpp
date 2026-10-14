
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <QFile>


#include <QRegularExpression>

#include <QDir>
#include <QDebug>

#include "dcm2ro-vm/vm-interpreter.h"

#include "otns.h"

USING_OTNS(DCM2RO)


int main(int argc, char *argv[])
{
 qDebug() << argv[0];

// QString vm_file_path = DEFAULT_VM_FOLDER "/main-process.4lr";
// VM_Interpreter vin;
// vin.load_file(vm_file_path);
// vin.parse();
// vin.run();

 QString vm_file_path1 = DEFAULT_VM_FOLDER "/post-process.4lr";
 VM_Interpreter vin1;
 vin1.load_file(vm_file_path1);
 vin1.parse();
 vin1.run();



 return 0;
}


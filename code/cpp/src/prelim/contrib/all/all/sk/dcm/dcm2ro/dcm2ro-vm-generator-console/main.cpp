
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include <QApplication>

#include <QFile>


#include <QRegularExpression>

#include <QDir>

#include "dcm2ro-vm-generator/dcm2ro-vm-writer.h"

USING_OTNS(DCM2RO)

int main(int argc, char *argv[])
{
 VM_Writer vmw;

 QString mvm_path = DEFAULT_VM_FOLDER "/main_process.4lr";
 QString pvm_path = DEFAULT_VM_FOLDER "/post_process.4lr";

// QString xml_path = DEFAULT_XML_FOLDER "/f6575e67-db88-411a-bb3e-dc639cbaa350.xml";
 QString xml_path = DEFAULT_XML_FOLDER "/159.xml";

 vmw.scan_xml(xml_path);


 return 0;
}


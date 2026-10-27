
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

 QString mvm_path = DEFAULT_VM_FOLDER "/main-process_%1.4lr";
 QString pvm_path = DEFAULT_VM_FOLDER "/post-process_%1.4lr";

// QString xml_path = DEFAULT_XML_FOLDER "/f6575e67-db88-411a-bb3e-dc639cbaa350.xml";
 QString xml_path = DEFAULT_XML_FOLDER "/159.xml";

 vmw.use_tikz_template(DEFAULT_TEMPLATES_FOLDER "/tikz.tex");
 vmw.use_tikz_svg_html_template(DEFAULT_TEMPLATES_FOLDER "/tikz-svg.html");

 vmw.scan_xml(xml_path);

 vmw.finalize_mvm(mvm_path, DEFAULT_IMAGE_XML_FOLDER, DEFAULT_IMAGES_FOLDER);
 vmw.finalize_pvm(pvm_path, DEFAULT_TIKZ_FOLDER, DEFAULT_TIKZ_HTML_FOLDER);

// vmw.save_mvm(mvm_path);
// vmw.save_pvm(pvm_path);

 return 0;
}



//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef ASA_MODULE__H
#define ASA_MODULE__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "vm-reader.h"
#include "vm-opstatement.h"

#include "../module-base.h"

#include "otns.h"

OTNS_(DCM2RO)



class ASA_Module : public _Module_Base
{

public:

 ASA_Module();

 void load_html_template(QString file_path);
 void load_svg_template(QString file_path);
 void save_html_file(QString file_path);
 void save_svg_file(QString file_path);

};

_OTNS(DCM2RO)

#endif // ASA_MODULE__H

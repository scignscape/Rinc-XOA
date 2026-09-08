
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef RCS_MODULE__H
#define RCS_MODULE__H

#include "global-types.h"

#include "vm-reader.h"
#include "vm-opstatement.h"

#include "module-base.h"

#include "otns.h"

OTNS_(DogPal)

class RCS_Module : public _Module_Base
{


public:

 RCS_Module();

 void file_name_shortcut(QString sc);
 void add_module_uris(QStringList paths);
 void first_name(QString name);
 void last_name(QString name);
 void single_author();


};

_OTNS(DogPal)

#endif // RCS_MODULE__H

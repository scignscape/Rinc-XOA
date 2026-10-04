
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

class ASA_Form_Section;
class ASA_Form_Page;
class ASA_Form_Question;
class ASA_Form_Answer;


class ASA_Module : public _Module_Base
{

public:

 ASA_Module();


};

_OTNS(AMPATH_NRE)

#endif // ASA_MODULE__H


//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef NRE_FORM_BASE__H
#define NRE_FORM_BASE__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "otns.h"

OTNS_(AMPATH_NRE)

class NRE_Form_Base
{
protected:
 QString cpp_header_;
 QString cpp_implementation_;

 QTextStream header_acc_;
 QTextStream implementation_acc_;

public:

 NRE_Form_Base();

// ACCESSORS(QString ,current_class_name)

};

_OTNS(AMPATH_NRE)

#endif // NRE_FORM_BASE__H

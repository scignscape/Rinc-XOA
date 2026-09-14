
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef NRE_FORM_SECTION__H
#define NRE_FORM_SECTION__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "otns.h"

OTNS_(AMPATH_NRE)

class NRE_Section : public _Module_Base
{
 QString label_;

public:

 NRE_Module();

 ACCESSORS(QString ,label)

};

_OTNS(AMPATH_NRE)

#endif // NRE_FORM_SECTION__H

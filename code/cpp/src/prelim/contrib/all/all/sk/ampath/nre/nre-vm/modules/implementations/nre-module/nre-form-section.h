
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef NRE_FORM_SECTION__H
#define NRE_FORM_SECTION__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "nre-form-base.h"


#include "otns.h"

class NRE_Form_Page;


OTNS_(AMPATH_NRE)

class NRE_Form_Section : public NRE_Form_Base
{
 QString label_;

 QVector<NRE_Form_Page*> pages_;

public:

 NRE_Form_Section();

 ACCESSORS(QString ,label)

 void add_page(NRE_Form_Page* p);

 NRE_Form_Page* current_page();

 void cleanup()
 {
  for(NRE_Form_Page p : pages_)
    p->cleanup();
 }

};

_OTNS(AMPATH_NRE)

#endif // NRE_FORM_SECTION__H

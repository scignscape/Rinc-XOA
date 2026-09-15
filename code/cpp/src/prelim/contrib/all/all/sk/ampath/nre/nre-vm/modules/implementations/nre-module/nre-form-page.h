
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef NRE_FORM_PAGE__H
#define NRE_FORM_PAGE__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "nre-form-base.h"

#include "otns.h"

OTNS_(AMPATH_NRE)

class NRE_Form_Section;


class NRE_Form_Page : public NRE_Form_Base
{
 QString label_;

 QVList<NRE_Form_Section*> sections_;



public:

 NRE_Form_Page();

 ACCESSORS(QString ,label)

 void add_section(NRE_Form_Section* p);

 NRE_Form_Section* current_section();

 void cleanup();

 void write_sections();

 u2 section_count()
 {
  return sections_.size();
 }

 NRE_Form_Section* get_section(u2 which)
 {
  return sections_.value(which);
 }
};

_OTNS(AMPATH_NRE)

#endif // NRE_FORM_PAGE__H


//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef NRE_MODULE__H
#define NRE_MODULE__H

#include "global-types.h"

#include "vm-reader.h"
#include "vm-opstatement.h"

#include "../module-base.h"

#include "otns.h"

OTNS_(AMPATH_NRE)

class NRE_Module : public _Module_Base
{


public:

 NRE_Module();

 void form_processor(QString text);
 void form_uuid(QString text);
 void page_label(QString text);
 void section_label(QString text);
 void question_label(QString text);
 void question_type(QString text);
 void question_concept(QString text);
 void question_rendering(QString text);
 void question_default(QString text);
 void answer_label(QString text);
 void answer_concept(QString text);

 void form_version(u2 val);

 void new_form();
 void finalize_form();
 void new_page();
 void finalize_page();
 void new_section();
 void finalize_section();
 void new_question();
 void finalize_question();
 void question_unset_required();
 void new_answer();
 void finalize_answer();
 void answer_yes();
 void answer_no();


};

_OTNS(AMPATH_NRE)

#endif // NRE_MODULE__H

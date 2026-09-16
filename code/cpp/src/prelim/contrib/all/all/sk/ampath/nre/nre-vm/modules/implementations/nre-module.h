
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef NRE_MODULE__H
#define NRE_MODULE__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "vm-reader.h"
#include "vm-opstatement.h"

#include "../module-base.h"

#include "nre-module/nre-form-base.h"

#include "otns.h"

OTNS_(AMPATH_NRE)

class NRE_Form_Section;
class NRE_Form_Page;
class NRE_Form_Question;
class NRE_Form_Answer;


class NRE_Module : public _Module_Base, public NRE_Form_Base
{
 QString current_class_name_;

 QVList<NRE_Form_Page*> pages_;

 u2 page_count_;

 NRE_Form_Page* current_page();

 NRE_Form_Section* current_section();
 NRE_Form_Question* current_question();
 NRE_Form_Answer* current_answer();

 void write_form();

 NRE_Form_Page* current_finalized_page_;
 void finalize_current_page();

 NRE_Form_Section* current_finalized_section_;
 void finalize_current_section();

 NRE_Form_Question* current_finalized_question_;
 void finalize_current_question();

 NRE_Form_Answer* current_finalized_answer_;
 void finalize_current_answer();

public:

 NRE_Module();

 ACCESSORS(QString ,current_class_name)

 void write_class_header_lead();
 void write_class_implementation_lead();

 void save_header_file(QString file_path);
 void save_implementation_file(QString file_path);

 void finalize_header_file();
 void finalize_implementation_file();

 void form_processor(QString text);
 void form_uuid(QString text);
 void page_label(QString text);
 void section_label(QString text);
 void question_label(QString text);
 void question_id(QString text);
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

 void finalize_current_form();


};

_OTNS(AMPATH_NRE)

#endif // NRE_MODULE__H

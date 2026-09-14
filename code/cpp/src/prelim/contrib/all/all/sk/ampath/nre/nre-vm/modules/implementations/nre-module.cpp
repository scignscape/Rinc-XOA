
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "nre-module.h"

#include "nre-module/nre-form-answer.h"
#include "nre-module/nre-form-page.h"
#include "nre-module/nre-form-question.h"
#include "nre-module/nre-form-section.h"


#include <bit>

#include <QDebug>

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(AMPATH_NRE)

NRE_Module::NRE_Module()
 :  _Module_Base{"NRE"}, current_finalized_page_(nullptr),
    current_finalized_answer_(nullptr),
    current_finalized_question_(nullptr),
    current_finalized_section_(nullptr)
{

}

NRE_Form_Section* NRE_Module::current_section()
{
 return current_page()->current_section();
}

NRE_Form_Page* NRE_Module::current_page()
{
 return pages_.last();
}

NRE_Form_Question* NRE_Module::current_question()
{
 return current_section()->current_question();
}

NRE_Form_Answer* NRE_Module::current_answer()
{
 return current_question()->current_answer();
}



void NRE_Module::finalize_header_file()
{
 header_acc_top() << "\n\n}; // end class \n";
 header_acc_top() << "\n\n_KANS(AMPATH_Forms)\n\n";
 header_acc_top() << "#endif // __H guard";

}

void NRE_Module::finalize_implementation_file()
{

}

void NRE_Module::save_header_file(QString file_path)
{
 save_file(file_path, cpp_header_top());
}

void NRE_Module::save_implementation_file(QString file_path)
{
 save_file(file_path, cpp_implementation_top());
}

void NRE_Module::write_class_header_lead()
{
 QString guard = current_class_name_.toUpper() + "__H";

 header_acc_top() << R"(
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

                )"
  << "\n#ifndef " << guard << "\n#define " << guard << "\n\n"

  << "\n\n#include \"kans.h\n\nKANS_(AMPATH_Forms)\n\n"

  << "class " << guard << "\n{\n";


}

void NRE_Module::write_class_implementation_lead()
{
 QString inc = current_class_name_.toLower().replace("_", "-");

 implementation_acc_top() << R"(
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

                )"

  << "\n#include \"" << inc << "\"\n\n"
  << "USING_KANS(AMPATH_Forms)\n\n";
}

void NRE_Module::form_processor(QString text)
{

}

void NRE_Module::form_uuid(QString text)
{

}

void NRE_Module::page_label(QString text)
{
 current_page()->set_label(text);
}

void NRE_Module::section_label(QString text)
{
 current_section()->set_label(text);
}

void NRE_Module::question_label(QString text)
{
 current_question()->write_label(text);
}

void NRE_Module::question_type(QString text)
{
 current_question()->write_question_type(text);
}

void NRE_Module::question_concept(QString text)
{
 current_question()->write_concept(text);
}

void NRE_Module::question_rendering(QString text)
{
 current_question()->write_rendering(text);
}

void NRE_Module::question_default(QString text)
{

}

void NRE_Module::question_id(QString text)
{
 current_question()->set_id(text);
}

void NRE_Module::answer_label(QString text)
{

}

void NRE_Module::answer_concept(QString text)
{

}

void NRE_Module::form_version(u2 val)
{

}

void NRE_Module::new_form()
{
 for(NRE_Form_Page* p : pages_)
   p->cleanup();
}

void NRE_Module::write_form()
{
 for(NRE_Form_Page* p : pages_)
 {
  NRE_Form_Section* s = p->get_section(0);
  u2 sc = s->question_count();
  NRE_Form_Question* q = s->get_question(0);



  header_acc_top() << "\n\n // //  Page: " << p->label();
  header_acc_top() << "\n\n // //  ctor ";
  header_acc_top() << p->cpp_header_part("ctor");
  header_acc_top() << "\n\n // //  init ";
  header_acc_top() << p->cpp_header_part("init");
  header_acc_top() << "\n\n // //  methods ";
  header_acc_top() << p->cpp_header_part("methods");

  implementation_acc_top() << "\n\n // //  Page: " << p->label();
  implementation_acc_top() << "\n\n // //  ctor ";
  implementation_acc_top() << p->cpp_implementation_part("ctor");
  implementation_acc_top() << "\n\n // //  init ";
  implementation_acc_top() << p->cpp_implementation_part("init");
  implementation_acc_top() << "\n\n // //  methods ";
  implementation_acc_top() << p->cpp_implementation_part("methods");
 }

}

void NRE_Module::finalize_current_form()
{
 finalize_current_answer();
 finalize_current_question();
 finalize_current_section();
 finalize_current_page();
 write_form();
}

void NRE_Module::finalize_form()
{
 //write_form();
}

void NRE_Module::new_page()
{
 finalize_current_page();
 NRE_Form_Page* p = new NRE_Form_Page;
 pages_.push_back(p);
}

void NRE_Module::finalize_current_page()
{
 if(current_finalized_page_)
   current_finalized_page_->write_sections();
}

void NRE_Module::finalize_page()
{
 current_finalized_page_ = current_page();
}

void NRE_Module::new_section()
{
 finalize_current_section();
 NRE_Form_Section* s = new NRE_Form_Section;
 current_page()->add_section(s);
}

void NRE_Module::finalize_section()
{
 current_finalized_section_ = current_section();
}

void NRE_Module::finalize_current_section()
{
 if(current_finalized_section_)
   current_finalized_section_->write_questions();
}

void NRE_Module::new_question()
{
 finalize_current_question();
 NRE_Form_Question* q = new NRE_Form_Question;
 current_section()->add_question(q);
}

void NRE_Module::finalize_question()
{
 current_finalized_question_ = current_question();
}

void NRE_Module::finalize_current_question()
{
 if(current_finalized_question_)
   current_finalized_question_->write_answers();
}

void NRE_Module::question_unset_required()
{

}

void NRE_Module::new_answer()
{
 finalize_current_answer();
 NRE_Form_Answer* a = new NRE_Form_Answer;
 current_question()->add_answer(a);
}

void NRE_Module::finalize_answer()
{
 current_finalized_answer_ = current_answer();
}

void NRE_Module::finalize_current_answer()
{
 //?
}

void NRE_Module::answer_yes()
{
 current_answer()->answer(true);
}

void NRE_Module::answer_no()
{
 current_answer()->answer(false);
}




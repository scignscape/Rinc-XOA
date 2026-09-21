
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "nre-form-section.h"

#include <bit>

#include <QDebug>

#include "nre-form-question.h"

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(AMPATH_NRE)

NRE_Form_Section::NRE_Form_Section()
{
 init_accs({"ctor", "init", "methods", "labels", "concepts", "sf"});
}

void NRE_Form_Section::write_questions(u2 page_count)
{
 static QString accordion = "\n NRE_Accordion_List* %1_F%2_;";
 static QString new_accordion = "\n %1_F%2_ = new NRE_Accordion_List(F_%2_);"
   "\n %1_F%2_->set_text(\"%3\");"
   "\n %1_F%2_->set_enclosing_scroll_area(S_%2_);"
   ;

 static QString add_accordion = "\n F_%2_vbl_->addWidget(%1_F%2_);"
   "\n F_%2_vbl_->addSpacing(19);"
   ;

 static QString accordion_name = "%1_F%2_";
 static QString collapse_accordion = "\n %1_F%2_->collapse();\n"
   ;

 header_acc("ctor") << accordion.arg(label_.replace(" ", "_")).arg(page_count);
 implementation_acc("ctor") << new_accordion
   .arg(label_.replace(" ", "_")).arg(page_count).arg(label_);

 QString current_accordion = accordion_name.arg(label_.replace(" ", "_")).arg(page_count);

 for(NRE_Form_Question* q : questions_)
 {
  header_acc("ctor") << q->cpp_header_part("ctor");
  header_acc("init") << q->cpp_header_part("init");
  header_acc("methods") << q->cpp_header_part("methods");
  header_acc("labels") << q->cpp_header_part("labels");
  header_acc("concepts") << q->cpp_header_part("concepts");

  implementation_acc("ctor") << q->cpp_implementation_part("ctor").replace("###", current_accordion);
  implementation_acc("init") << q->cpp_implementation_part("init").replace("###", current_accordion);;
  implementation_acc("methods") << q->cpp_implementation_part("methods");
  implementation_acc("labels") << q->cpp_implementation_part("labels");
  implementation_acc("concepts") << q->cpp_implementation_part("concepts");
 }

 implementation_acc("init") << add_accordion.arg(label_.replace(" ", "_")).arg(page_count);
 implementation_acc("sf") << collapse_accordion.arg(label_.replace(" ", "_")).arg(page_count);
}

void NRE_Form_Section::cleanup()
{
 for(NRE_Form_Question* q : questions_)
 {
  q->cleanup();
  delete q;
 }
}


void NRE_Form_Section::add_question(NRE_Form_Question* q)
{
 questions_.push_back(q);
}

NRE_Form_Question* NRE_Form_Section::current_question()
{
 return questions_.last();
}


//void NRE_Form_Section::cleanup()
//{
// for(NRE_Form_Page* p : pages_)
// {
//  p->cleanup();
//  delete p;
// }
//}


//void NRE_Form_Section::add_page(NRE_Form_Page* p)
//{
// pages_.push_back(p);
//}

//NRE_Form_Page* NRE_Form_Section::current_page()
//{
// return pages_.last();
//}



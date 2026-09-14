
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "nre-form-page.h"

#include <bit>

#include <QDebug>

#include "nre-form-question.h"

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(AMPATH_NRE)

NRE_Form_Page::NRE_Form_Page()
{
 init_accs({"ctor", "init", "methods"});
}

void NRE_Form_Page::write_questions()
{
 for(NRE_Form_Question* q : questions_)
 {
  header_acc("ctor") << q->cpp_header_part("ctor");
  header_acc("init") << q->cpp_header_part("init");
  header_acc("methods") << q->cpp_header_part("methods");

  implementation_acc("ctor") << q->cpp_implementation_part("ctor");
  implementation_acc("init") << q->cpp_implementation_part("init");
  implementation_acc("methods") << q->cpp_implementation_part("methods");
 }

}


void NRE_Form_Page::cleanup()
{
 for(NRE_Form_Question* q : questions_)
 {
  q->cleanup();
  delete q;
 }
}


void NRE_Form_Page::add_question(NRE_Form_Question* q)
{
 questions_.push_back(q);
}

NRE_Form_Question* NRE_Form_Page::current_question()
{
 return questions_.last();
}

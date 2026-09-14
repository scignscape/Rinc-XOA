
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

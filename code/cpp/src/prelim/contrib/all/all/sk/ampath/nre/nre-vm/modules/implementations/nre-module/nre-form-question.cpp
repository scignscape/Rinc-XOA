
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "nre-form-question.h"

#include <bit>

#include <QDebug>

#include "nre-form-answer.h"

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(AMPATH_NRE)

NRE_Form_Question::NRE_Form_Question()
  :  required_cardinality_(0)
{
 init_accs({"ctor", "methods"});
}

void NRE_Form_Question::cleanup()
{
 for(NRE_Form_Answer* a : answers_)
 {
  a->cleanup();
  delete a;
 }
}

void NRE_Form_Question::add_answer(NRE_Form_Answer* a)
{
 answers_.push_back(a);
}

NRE_Form_Answer* NRE_Form_Question::current_answer()
{
 return answers_.last();
}






//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "nre-form-answer.h"

#include <bit>

#include <QDebug>

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(AMPATH_NRE)

NRE_Form_Answer::NRE_Form_Answer()
  :  answer_type_(Answer_Types::N_A)
{

}

QString NRE_Form_Answer::get_label()
{
 switch (answer_type_)
 {
 case Answer_Types::BOOL_no:
   return "No";
 case Answer_Types::BOOL_yes:
   return "Yes";
 default:
   return label_;
 }
}

void NRE_Form_Answer::cleanup()
{

}


//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef NRE_FORM_ANSWER__H
#define NRE_FORM_ANSWER__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "nre-form-base.h"

#include "otns.h"

OTNS_(AMPATH_NRE)

class NRE_Form_Answer : public NRE_Form_Base
{
 enum class Answer_Types {
  N_A, BOOL_yes, BOOL_no, Enum

  };

 Answer_Types answer_type_;

public:

 NRE_Form_Answer();

 void cleanup();

 void answer(bool yes_or_no)
 {
  answer_type_ = yes_or_no? Answer_Types::BOOL_yes : Answer_Types::BOOL_no;
 }

// ACCESSORS(QString ,current_class_name)

};

_OTNS(AMPATH_NRE)

#endif // NRE_FORM_ANSWER__H

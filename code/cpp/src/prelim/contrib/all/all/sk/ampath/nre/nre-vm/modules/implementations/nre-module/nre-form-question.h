
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef NRE_FORM_QUESTION__H
#define NRE_FORM_QUESTION__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "nre-form-base.h"

//#include "nre-form-answer.h"

#include "otns.h"

OTNS_(AMPATH_NRE)

class NRE_Form_Answer;


class NRE_Form_Question : public NRE_Form_Base
{
 QVList<NRE_Form_Answer*> answers_;

 QString id_;

 u2 required_cardinality_;

 enum class Question_Types {
   N_A, Observation, Markdown
 };

 QString enumerated_question_type(QString ty)
 {
  static QMap<QString, QString> static_map {
   {"obs", "Question_Types::Observation"},
   {"obs", "Question_Types::Markdown"},
  };

  return static_map.value(ty, "Question_Types::N_A");
 }

 enum class Rendering_Types {
   N_A, Text, TextArea, Number, DateTime, Date, Radio, Markdown,
   Select, MultiCheckbox, WorkspaceLauncher
 };

 Rendering_Types parse_rendering_type(QString ty)
 {
  static QMap<QString, Rendering_Types> static_map {
   {"text", Rendering_Types::Text},
   {"textarea", Rendering_Types::TextArea},
   {"number", Rendering_Types::Number},
   {"datetime", Rendering_Types::DateTime},
   {"date", Rendering_Types::Date},
   {"radio", Rendering_Types::Radio},
   {"multiCheckbox", Rendering_Types::MultiCheckbox},
   {"markdown", Rendering_Types::Markdown},
   {"select", Rendering_Types::Select},
   {"workspace-launcher", Rendering_Types::Select},
  };

  return static_map.value(ty, Rendering_Types::N_A);
 }

 Rendering_Types rendering_type_;

public:

 NRE_Form_Question();

 ACCESSORS(u2 ,required_cardinality)
 ACCESSORS(QString ,id)

 void add_answer(NRE_Form_Answer* a);

 NRE_Form_Answer* current_answer();

 void cleanup();

 void write_concept(QString text);
 void write_label(QString text);
 void write_question_type(QString text);

 void write_rendering(QString text);

 void write_answers();

};

_OTNS(AMPATH_NRE)

#endif // NRE_FORM_QUESTION__H

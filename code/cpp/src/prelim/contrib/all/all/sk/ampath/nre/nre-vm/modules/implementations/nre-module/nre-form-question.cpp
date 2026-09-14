
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
 init_accs({"ctor", "init", "methods"});
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

void NRE_Form_Question::write_concept(QString text)
{
 implementation_acc("init") << "\nset_concept(\""
   << id_ << "\", \"" << text << "\");";
}

void NRE_Form_Question::write_label(QString text)
{
 implementation_acc("init") << "\nset_label(\""
   << id_ << "\", \"" << text << "\");";
}

void NRE_Form_Question::write_question_type(QString text)
{
 implementation_acc("init") << "\nset_label(\""
   << id_ << "\", \"" << enumerated_question_type(text) << "\");";
}

void NRE_Form_Question::write_rendering(QString text)
{
 Rendering_Types rt = parse_rendering_type(text);

 switch (rt)
 {
 case Rendering_Types::Text:
  header_acc("methods") << "\nQLineEdit* " << id_ << "_";
  implementation_acc("ctor") << "\n" << id_ << "_" << " = new QLineEdit(this);";
  break;
 case Rendering_Types::TextArea:
  header_acc("methods") << "\nQTextArea* " << id_ << "_";
  implementation_acc("ctor") << "\n" << id_ << "_" << " = new QTextArea(this);";
  break;
 case Rendering_Types::Number:
  header_acc("methods") << "QLineEdit* " << id_ << "_";
  implementation_acc("ctor") << "\n" << id_ << "_" << " = new QLineEdit(this);";
  implementation_acc("ctor") << "\n" << id_ << "_" << "->setDefaultValue(0);";
  break;
 case Rendering_Types::DateTime:
  header_acc("methods") << "QDateTimeEdit* " << id_ << "_";
  implementation_acc("ctor") << "\n" << id_ << "_" << " = new QDateTimeEdit(this);";
//?  implementation_acc("ctor") << "\n" << id_ << "_" << "->setDefaultValue(0);";
  break;
 case Rendering_Types::Radio:
  header_acc("methods") << "QButtonGroup* " << id_ << "_";
  implementation_acc("ctor") << "\n" << id_ << "_" << " = new QButtonGroup(this);";
//?  implementation_acc("ctor") << "\n" << id_ << "_" << "->setDefaultValue(0);";
  break;
 default:
  break;
 }

}

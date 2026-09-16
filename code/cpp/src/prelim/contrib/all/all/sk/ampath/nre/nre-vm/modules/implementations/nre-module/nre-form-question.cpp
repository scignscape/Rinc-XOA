
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
 init_accs({"ctor", "init", "methods", "labels", "concepts"});
}

void NRE_Form_Question::cleanup()
{
 for(NRE_Form_Answer* a : answers_)
 {
  a->cleanup();
  delete a;
 }
}

void NRE_Form_Question::write_answers()
{

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
 implementation_acc("concepts") << "\n L_" << id_ << "_" <<
   "->setProperty(\"ocl-concept\", QVariant(\"" << text << "\"));";

 //concepts
// implementation_acc("init") << "\nset_concept(\""
//   << id_ << "\", \"" << text << "\");";
}

void NRE_Form_Question::write_label(QString text)
{
 implementation_acc("labels") << "\n L_" << id_ << "_" << "->setText(\"" << text << "\");";

// implementation_acc("init") << "\nset_label(\""
//   << id_ << "\", \"" << text << "\");";
}

void NRE_Form_Question::write_question_type(QString text)
{
 implementation_acc("init") << "\nset_question_type(\""
   << id_ << "\", \"" << enumerated_question_type(text) << "\");";
}

void NRE_Form_Question::write_rendering(QString text)
{
 header_acc("methods") << "\n QLabel* L_" << id_ << "_;";
 implementation_acc("ctor") << "\n L_" << id_ << "_" << " = new QLabel(###);";

 Rendering_Types rt = parse_rendering_type(text);

 switch (rt)
 {
 case Rendering_Types::Text:
  header_acc("methods") << "\n QLineEdit* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new QLineEdit(###);";
  break;
 case Rendering_Types::TextArea:
  header_acc("methods") << "\n QTextArea* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new QTextArea(###);";
  break;
 case Rendering_Types::Number:
  header_acc("methods") << "\n QLineEdit* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new QLineEdit(###);";
  implementation_acc("ctor") << "\n " << id_ << "_" << "->setDefaultValue(0);";
  break;
 case Rendering_Types::DateTime:
  header_acc("methods") << "\n QDateTimeEdit* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new QDateTimeEdit(###);";
//?  implementation_acc("ctor") << "\n" << id_ << "_" << "->setDefaultValue(0);";
  break;
 case Rendering_Types::Date:
  header_acc("methods") << "\n QDateEdit* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new QDateEdit(###);";
  break;
 case Rendering_Types::Radio:
  header_acc("methods") << "\n QButtonGroup* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new QButtonGroup(###);";
//?  implementation_acc("ctor") << "\n" << id_ << "_" << "->setDefaultValue(0);";
  break;
 case Rendering_Types::Markdown:
  header_acc("methods") << "\n QTextArea* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new QTextArea(###);";
  break;
 case Rendering_Types::Select:
  header_acc("methods") << "\n NRE_Combo_With_Label_Bar* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new Combo_With_Label_Bar(###);";
  implementation_acc("ctor") << "\n " << id_ << "_" << "->set_max_selectable(1);";
  break;
 case Rendering_Types::MultiCheckbox:
  header_acc("methods") << "\n NRE_Combo_With_Label_Bar* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new Combo_With_Label_Bar(###);";
  break;
 case Rendering_Types::WorkspaceLauncher:
  header_acc("methods") << "\n NRE_Workspace_Launcher_Button* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new NRE_Workspace_Launcher_Button(###);";
  break;


 default:
  qDebug() << "Unrecognized rendering type: " << text;
  break;
 }

 implementation_acc("ctor") << "\n ###->add_item(" <<
   "L_" << id_ << "_,\n   " << id_ << ");";
}

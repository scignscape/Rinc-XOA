
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
  :  required_cardinality_(0), rendering_type_(Rendering_Types::N_A)
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
 switch (rendering_type_)
 {
 case Rendering_Types::Select:
 case Rendering_Types::MultiCheckbox:
 case Rendering_Types::Radio:
  {
   for(NRE_Form_Answer* a : answers_)
   {
    implementation_acc("init") << "\n " << id_ << "_" << "->add_item(\""
      << a->get_label() << "\");";
   }
  }
  break;
 default: break;
 }

 implementation_acc("init") << add_v_or_h_;
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
 implementation_acc("concepts") << "\n " << id_ << "_" <<
   "->setProperty(\"ocl-concept\", QVariant(\"" << text << "\"));";

 //concepts
// implementation_acc("init") << "\nset_concept(\""
//   << id_ << "\", \"" << text << "\");";
}

void NRE_Form_Question::write_label(QString text)
{
//? implementation_acc("labels") << "\n L_" << id_ << "_" << "->setText(\"" << text << "\");";
 implementation_acc("labels") << "\n L_" << id_ << "_" << " = \"" << text << "\";";

// implementation_acc("ctor") << "\n L_" << id_ << "_" << " = \"" << label_ << "\"";


// implementation_acc("init") << "\nset_label(\""
//   << id_ << "\", \"" << text << "\");";
}

void NRE_Form_Question::write_question_type(QString text)
{
// implementation_acc("init") << "\nset_question_type(\""
//   << id_ << "\", \"" << enumerated_question_type(text) << "\");";
}

void NRE_Form_Question::write_rendering(QString text)
{
 header_acc("methods") << "\n QString L_" << id_ << "_;";
// implementation_acc("ctor") << "\n L_" << id_ << "_" << " = new QLabel(###);";
// implementation_acc("ctor") << "\n L_" << id_ << "_" << " = \"" << label_ << "\"";

 QString v_or_h;

 rendering_type_ = parse_rendering_type(text);

 switch (rendering_type_)
 {
 case Rendering_Types::Text:
  v_or_h = "horizontal";
  header_acc("methods") << "\n QLineEdit* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new QLineEdit(###);";
  break;
 case Rendering_Types::TextArea:
  v_or_h = "vertical";
  header_acc("methods") << "\n QPlainTextEdit* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new QPlainTextEdit(###);";
  break;
 case Rendering_Types::Number:
  v_or_h = "horizontal";
  header_acc("methods") << "\n QLineEdit* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new QLineEdit(###);";
  implementation_acc("ctor") << "\n " << id_ << "_" << "->setPlaceholderText(0);";
  break;
 case Rendering_Types::DateTime:
  v_or_h = "horizontal";
  header_acc("methods") << "\n QDateTimeEdit* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new QDateTimeEdit(###);";
//?  implementation_acc("ctor") << "\n" << id_ << "_" << "->setDefaultValue(0);";
  break;
 case Rendering_Types::Date:
  v_or_h = "horizontal";
  header_acc("methods") << "\n QDateEdit* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new QDateEdit(###);";
  break;
 case Rendering_Types::Radio:
  v_or_h = "vertical";
  header_acc("methods") << "\n NRE_Radio_Button_Group_Box* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new NRE_Radio_Button_Group_Box(###);";
//?  implementation_acc("ctor") << "\n" << id_ << "_" << "->setDefaultValue(0);";
  break;
 case Rendering_Types::Markdown:
  v_or_h = "vertical";
  header_acc("methods") << "\n QPlainTextEdit* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new QPlainTextEdit(###);";
  break;
 case Rendering_Types::Select:
  v_or_h = "vertical";
  header_acc("methods") << "\n NRE_Combo_With_Label_Bar* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new NRE_Combo_With_Label_Bar(###);";
  implementation_acc("ctor") << "\n " << id_ << "_" << "->set_max_selectable(1);";
  break;
 case Rendering_Types::MultiCheckbox:
  v_or_h = "vertical";
  header_acc("methods") << "\n NRE_Combo_With_Label_Bar* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" << " = new NRE_Combo_With_Label_Bar(###);";
  break;
 case Rendering_Types::WorkspaceLauncher:
  v_or_h = "vertical";
  header_acc("methods") << "\n NRE_Workspace_Launcher_Button* " << id_ << "_;";
  implementation_acc("ctor") << "\n " << id_ << "_" <<
    " = new NRE_Workspace_Launcher_Button(\"Running workspace: $name ...\", "
    "\"Choose configuration ...\",\n L_" << id_ << "_ + \" (default)\", ###);";
  break ;


 default:
  qDebug() << "Unrecognized rendering type: " << text;
  break;
 }

 add_v_or_h_ = "\n ###->add_%1_item(L_%2_,\n  %2_);"_qt.arg(v_or_h).arg(id_);

}

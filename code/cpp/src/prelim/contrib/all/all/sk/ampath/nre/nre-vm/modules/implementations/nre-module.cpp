
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "nre-module.h"

#include "nre-module/nre-form-answer.h"
#include "nre-module/nre-form-page.h"
#include "nre-module/nre-form-question.h"
#include "nre-module/nre-form-section.h"


#include <bit>

#include <QDebug>

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(AMPATH_NRE)

NRE_Module::NRE_Module()
 :  _Module_Base{"NRE"}, current_finalized_page_(nullptr),
    current_finalized_answer_(nullptr),
    current_finalized_question_(nullptr),
    current_finalized_section_(nullptr)
{

}

NRE_Form_Section* NRE_Module::current_section()
{
 return current_page()->current_section();
}

NRE_Form_Page* NRE_Module::current_page()
{
 return pages_.last();
}

NRE_Form_Question* NRE_Module::current_question()
{
 return current_section()->current_question();
}

NRE_Form_Answer* NRE_Module::current_answer()
{
 return current_question()->current_answer();
}



void NRE_Module::finalize_header_file()
{
 header_acc_top() << "\n\n}; // end class \n";
 header_acc_top() << "\n\n_KANS(AMPATH_Forms)\n\n";
 header_acc_top() << "#endif // __H guard";

}

void NRE_Module::finalize_implementation_file()
{

}

void NRE_Module::save_header_file(QString file_path)
{
 save_file(file_path, cpp_header_top());
}

void NRE_Module::save_implementation_file(QString file_path)
{
 save_file(file_path, cpp_implementation_top());
}

void NRE_Module::write_class_header_lead()
{
 QString guard = current_class_name_.toUpper() + "__H";

 header_acc_top() << R"(
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

                )"
  << "\n#ifndef " << guard << "\n#define " << guard << "\n\n"

  << "\n\n#include \"kans.h\n\nKANS_(AMPATH_Forms)\n\n"

  << "class " << current_class_name_ << "\n{\n";


}

void NRE_Module::write_class_implementation_lead()
{
 QString inc = current_class_name_.toLower().replace("_", "-");

 implementation_acc_top() << R"(
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

                )"

  << "\n#include \"" << inc << "\"\n\n"
  << "USING_KANS(AMPATH_Forms)\n\n";
}

void NRE_Module::form_processor(QString text)
{

}

void NRE_Module::form_uuid(QString text)
{

}

void NRE_Module::page_label(QString text)
{
 current_page()->set_label(text);
}

void NRE_Module::section_label(QString text)
{
 current_section()->set_label(text);
}

void NRE_Module::question_label(QString text)
{

  NRE_Form_Section* s = current_section();
  NRE_Form_Page* p = current_page();

  NRE_Form_Question* q = s->question_count()? current_question() : nullptr;

//  if(q)
//    qDebug() << " qid: " << q->id();
//  if(s)
//    qDebug() << " slabel: " << s->label();
//  if(p)
//    qDebug() << " plabel: " << p->label();


 current_question()->write_label(text);
}

void NRE_Module::question_type(QString text)
{
 current_question()->write_question_type(text);
}

void NRE_Module::question_concept(QString text)
{
 current_question()->write_concept(text);
}

void NRE_Module::question_rendering(QString text)
{
 current_question()->write_rendering(text);
}

void NRE_Module::question_default(QString text)
{

}

void NRE_Module::question_id(QString text)
{
 {
  NRE_Form_Section* s = current_section();
  NRE_Form_Page* p = current_page();

  NRE_Form_Question* q = s->question_count()? current_question() : nullptr;

//  if(q)
//    qDebug() << "qid: " << q->id();
//  if(s)
//    qDebug() << "slabel: " << s->label();
//  if(p)
//    qDebug() << "plabel: " << p->label();
 }

 current_question()->set_id(text);

 if(text == "howLongHasTheChildBeenSick")
 {
  NRE_Form_Question& q = *current_question();
  NRE_Form_Section& s = *current_section();
  NRE_Form_Page& p = *current_page();

//  qDebug() << q.id();
//  qDebug() << s.label();
//  qDebug() << p.label();

 }
}

void NRE_Module::answer_label(QString text)
{

}

void NRE_Module::answer_concept(QString text)
{

}

void NRE_Module::form_version(u2 val)
{

}

void NRE_Module::new_form()
{
 for(NRE_Form_Page* p : pages_)
   p->cleanup();
}

void NRE_Module::write_form()
{
 QStringList parts {"ctor", "init", "methods", "labels", "concepts"};

 QMap<QString, QString> header_pre_;
 QMap<QString, QString> implementation_pre_;

 QMap<QString, QString> header_post_;
 QMap<QString, QString> implementation_post_;

 static QString implementation_pre = R"(
%1%2::%3%4()
{
)";

 static QString header_pre = "\n%1 %2%3();";

 static QString implementation_post = "\n}// ::%1%2\n\n";
 static QString init = "init";
 static QString sp_void = " void";
 static QString void_sp = "void ";

 implementation_pre_["init"] = implementation_pre.arg(void_sp).arg(current_class_name_).arg(init).arg("");
 implementation_post_["init"] = implementation_post.arg(init).arg("");
 header_pre_["init"] = header_pre.arg(sp_void).arg(init).arg("");


 implementation_pre_["ctor"] = implementation_pre.arg("").arg(current_class_name_).arg(current_class_name_).arg("");
 implementation_post_["ctor"] = implementation_post.arg(current_class_name_).arg("");
 header_pre_["ctor"] = header_pre.arg("").arg(current_class_name_).arg("");

 implementation_pre_["labels"] = implementation_pre.arg(void_sp).arg(current_class_name_).arg(init).arg("_labels");
 implementation_post_["labels"] = implementation_post.arg(init).arg("_labels");
 header_pre_["labels"] = header_pre.arg(sp_void).arg(init).arg("_labels");

 implementation_pre_["concepts"] = implementation_pre.arg(void_sp).arg(current_class_name_).arg(init).arg("_concepts");
 implementation_post_["concepts"] = implementation_post.arg(init).arg("_concepts");
 header_pre_["concepts"] = header_pre.arg(sp_void).arg(init).arg("_concepts");

 header_pre_["ctor"] += R"(

private:
 QTabWiget* pages_tab_widget_;
)";

 header_pre_["ctor"].prepend("\npublic: ");

 implementation_pre_["ctor"] += R"(
 pages_tab_widget_ = new QTabWiget(this);
 init_labels();
 setCentralWidget(pages_tab_widget_);
 pages_tab_widget_->show();
)";

 for(QString part : parts)
 {
  header_acc_top() << "// //--> " << part;
  implementation_acc_top() << "// //--> " << part;

  header_acc_top() << header_pre_.value(part);
  implementation_acc_top() << implementation_pre_.value(part);

  for(NRE_Form_Page* p : pages_)
  {
   header_acc_top() << "\n\n // //  Page: " << p->label();
   header_acc_top() << p->cpp_header_part(part);

   implementation_acc_top() << "\n\n // //  Page: " << p->label();
   implementation_acc_top() << p->cpp_implementation_part(part);
  }

  header_acc_top() << header_post_.value(part);
  implementation_acc_top() << implementation_post_.value(part);

  header_acc_top() << "\n// //<-- " << part << "\n";
  implementation_acc_top() << "\n// //<-- " << part << "\n";
 }
}


//header_acc_top() << "\n\n // //  Page: " << p->label();
//header_acc_top() << " -- init ";
//header_acc_top() << p->cpp_header_part("init");

//header_acc_top() << "\n\n // //  Page: " << p->label();
//header_acc_top() << " -- methods ";
//header_acc_top() << p->cpp_header_part("methods");

//header_acc_top() << "\n\n // //  Page: " << p->label();
//header_acc_top() << " -- labels ";
//header_acc_top() << p->cpp_header_part("labels");

//header_acc_top() << "\n\n // //  Page: " << p->label();
//header_acc_top() << " -- concepts ";
//header_acc_top() << p->cpp_header_part("concepts");

//implementation_acc_top() << "\n\n // //  Page: " << p->label();
//implementation_acc_top() << " -- ctor ";
//implementation_acc_top() << p->cpp_implementation_part("ctor");

//implementation_acc_top() << "\n\n // //  Page: " << p->label();
//implementation_acc_top() << " -- init ";
//implementation_acc_top() << p->cpp_implementation_part("init");

//implementation_acc_top() << "\n\n // //  Page: " << p->label();
//implementation_acc_top() << " -- methods ";
//implementation_acc_top() << p->cpp_implementation_part("methods");

//implementation_acc_top() << "\n\n // //  Page: " << p->label();
//implementation_acc_top() << " -- labels ";
//implementation_acc_top() << p->cpp_implementation_part("labels");

//implementation_acc_top() << "\n\n // //  Page: " << p->label();
//implementation_acc_top() << " -- concepts ";
//implementation_acc_top() << p->cpp_implementation_part("concepts");


void NRE_Module::finalize_current_form()
{
// finalize_current_answer();
// finalize_current_question();
// finalize_current_section();
 finalize_current_page();
 write_form();
}

void NRE_Module::finalize_form()
{
 //write_form();
}

void NRE_Module::new_page()
{
 finalize_current_page();
 ++page_count_;
 NRE_Form_Page* p = new NRE_Form_Page;
 pages_.push_back(p);
}

void NRE_Module::finalize_current_page()
{
 finalize_current_section();
 if(current_finalized_page_)
   current_finalized_page_->write_sections();
}

void NRE_Module::finalize_page()
{
 current_page()->write_frame(page_count_);
 current_finalized_page_ = current_page();
}

void NRE_Module::new_section()
{
 finalize_current_section();
 NRE_Form_Section* s = new NRE_Form_Section;
 current_page()->add_section(s);
}

void NRE_Module::finalize_section()
{
 current_finalized_section_ = current_section();
}

void NRE_Module::finalize_current_section()
{
 finalize_current_question();
 if(current_finalized_section_)
   current_finalized_section_->write_questions(page_count_);
}

void NRE_Module::new_question()
{
 {
  NRE_Form_Section* s = current_section();
  NRE_Form_Page* p = current_page();

  NRE_Form_Question* q = s->question_count()? current_question() : nullptr;

//  if(q)
//    qDebug() << "qid: " << q->id();
//  if(s)
//    qDebug() << "slabel: " << s->label();
//  if(p)
//    qDebug() << "plabel: " << p->label();
 }

 finalize_current_question();
 NRE_Form_Question* q = new NRE_Form_Question;
 current_section()->add_question(q);
}

void NRE_Module::finalize_question()
{
 current_finalized_question_ = current_question();
}

void NRE_Module::finalize_current_question()
{
 finalize_current_answer();
 if(current_finalized_question_)
   current_finalized_question_->write_answers();
}

void NRE_Module::question_unset_required()
{

}

void NRE_Module::new_answer()
{
 finalize_current_answer();
 NRE_Form_Answer* a = new NRE_Form_Answer;
 current_question()->add_answer(a);
}

void NRE_Module::finalize_answer()
{
 current_finalized_answer_ = current_answer();
}

void NRE_Module::finalize_current_answer()
{
 //?
}

void NRE_Module::answer_yes()
{
 current_answer()->answer(true);
}

void NRE_Module::answer_no()
{
 current_answer()->answer(false);
}




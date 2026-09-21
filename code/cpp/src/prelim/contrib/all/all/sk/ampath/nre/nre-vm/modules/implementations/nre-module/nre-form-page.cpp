
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "nre-form-page.h"

#include <bit>

#include <QDebug>

#include "nre-form-section.h"

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(AMPATH_NRE)

NRE_Form_Page::NRE_Form_Page()
{
 init_accs({"ctor", "init", "methods", "labels", "concepts", "sf"});
}

void NRE_Form_Page::write_frame(u2 count)
{
 header_acc("ctor") << "\n QScrollArea* S_" << count
   << "_; // " << label_; // << "\n // // (" << section_count() << " sections)";

 header_acc("ctor") << "\n QFrame* F_" << count
   << "_; // " << label_; // << "\n // // (" << section_count() << " sections)";

 header_acc("ctor") << "\n QVBoxLayout* F_" << count
   << "_vbl_ ;";

 implementation_acc("ctor") << "\n F_" << count
   << "_ = new QFrame;";
 implementation_acc("ctor") << "\n F_" << count
   << "_vbl_ = new QVBoxLayout;";
 implementation_acc("ctor") << "\n F_" << count
   << "_->setLayout(F_" << count << "_vbl_);";
 implementation_acc("ctor") << "\n S_" << count
   << "_ = new QScrollArea;";

 implementation_acc("sf") << "\n S_" << count
   << "_->setWidget(F_" << count << "_);";

 implementation_acc("ctor") << "\n pages_tab_widget_->addTab(S_" << count
   << "_, \"" << label_ << "\");";

}

void NRE_Form_Page::write_sections()
{
 for(NRE_Form_Section* s : sections_)
 {
  header_acc("ctor") << "\n\n  // // Section: " << s->label();
  header_acc("ctor") << " -- ctor ";
  header_acc("ctor") << s->cpp_header_part("ctor");

  header_acc("init") << "\n\n  // // Section: " << s->label();
  header_acc("init") << " -- init ";
  header_acc("init") << s->cpp_header_part("init");

  header_acc("methods") << "\n\n  // // Section: " << s->label();
  header_acc("methods") << " -- methods ";
  header_acc("methods") << s->cpp_header_part("methods");

  header_acc("labels") << "\n\n  // // Section: " << s->label();
  header_acc("labels") << " -> labels ";
  header_acc("labels") << s->cpp_header_part("labels");

  header_acc("concepts") << "\n\n  // // Section: " << s->label();
  header_acc("concepts") << " -> concepts ";
  header_acc("concepts") << s->cpp_header_part("concepts");

  implementation_acc("ctor") << "\n\n  // // Section: " << s->label();
  implementation_acc("ctor") << " -- ctor ";
  implementation_acc("ctor") << s->cpp_implementation_part("ctor");

  implementation_acc("init") << "\n\n  // // Section: " << s->label();
  implementation_acc("init") << " -- init ";
  implementation_acc("init") << s->cpp_implementation_part("init");

  implementation_acc("methods") << "\n\n  // // Section: " << s->label();
  implementation_acc("methods") << " -- methods ";
  implementation_acc("methods") << s->cpp_implementation_part("methods");

  implementation_acc("labels") << "\n\n  // // Section: " << s->label();
  implementation_acc("labels") << " -- labels ";
  implementation_acc("labels") << s->cpp_implementation_part("labels");

  implementation_acc("concepts") << "\n\n  // // Section: " << s->label();
  implementation_acc("concepts") << " -- concepts ";
  implementation_acc("concepts") << s->cpp_implementation_part("concepts");

  implementation_acc("sf") << "\n\n  // // Section: " << s->label();
  implementation_acc("sf") << " -- sf ";
  implementation_acc("sf") << s->cpp_implementation_part("sf");

 }
}

void NRE_Form_Page::cleanup()
{
 for(NRE_Form_Section* s : sections_)
 {
  s->cleanup();
  delete s;
 }
}


void NRE_Form_Page::add_section(NRE_Form_Section* s)
{
 sections_.push_back(s);
}

NRE_Form_Section* NRE_Form_Page::current_section()
{
 return sections_.last();
}

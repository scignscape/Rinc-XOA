
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
 init_accs({"ctor", "init", "methods"});
}


void NRE_Form_Page::write_sections()
{
 for(NRE_Form_Section* s : sections_)
 {
  header_acc("ctor") << s->cpp_header_part("ctor");
  header_acc("init") << s->cpp_header_part("init");
  header_acc("methods") << s->cpp_header_part("methods");

  implementation_acc("ctor") << s->cpp_implementation_part("ctor");
  implementation_acc("init") << s->cpp_implementation_part("init");
  implementation_acc("methods") << s->cpp_implementation_part("methods");
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

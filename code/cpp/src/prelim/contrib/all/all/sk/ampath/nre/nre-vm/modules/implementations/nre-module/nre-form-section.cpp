
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "nre-form-section.h"

#include <bit>

#include <QDebug>

#include "nre-form-page.h"

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(AMPATH_NRE)

NRE_Form_Section::NRE_Form_Section()
{

}

void NRE_Form_Section::cleanup()
{
 for(NRE_Form_Page* p : pages_)
 {
  p->cleanup();
  delete p;
 }
}


void NRE_Form_Section::add_page(NRE_Form_Page* p)
{
 pages_.push_back(p);
}

NRE_Form_Page* NRE_Form_Section::current_page()
{
 return pages_.last();
}



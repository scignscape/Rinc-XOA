
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "asa-module.h"


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




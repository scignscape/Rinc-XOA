
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "tia-tex-file.h"

#include <bit>

#include <QDebug>

#include "textio.h"


USING_KANS(TextIO)

USING_OTNS(DCM2RO)

TIA_Tex_File::TIA_Tex_File()
  :  width_(0), height_(0)
{

}


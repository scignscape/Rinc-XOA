
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef SDI_MODULE__H
#define SDI_MODULE__H

#include "global-types.h"

#include "vm-reader.h"
#include "vm-opstatement.h"

#include "module-base.h"


#include "otns.h"

OTNS_(DogPal)

class SDI_Module : public _Module_Base
{

public:

 SDI_Module();

 void new_sentence(u4 id);
 void sentence_switch_pos(u4 id, u4 pos, u4 row, u4 col);
 void sentence__end_pos(u4 id, u4 pos, u4 row, u4 col);
 void sentence_end_pos(u4 id, u4 pos, u4 row, u4 col);
 void sentence_end_punctuation(QString mark);
 void sentence_text(QString text);


};

_OTNS(DogPal)

#endif // SDI_MODULE__H


//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "vm-opstatement.h"


USING_OTNS(DogPal)

VM_Opstatement::VM_Opstatement(u4 id, QString instruction)
  :  id_(id), instruction_(instruction),
     mid_control_kind_(Mid_Control_Kinds::N_A), control_coords_(Control_Coords::N_A)
{

}

VM_Opstatement::VM_Opstatement(u4 id, QString instruction, Control_Coords cc)
  : id_(id), instruction_(instruction), mid_control_kind_(Mid_Control_Kinds::N_A), control_coords_(cc)
{

}

VM_Opstatement::VM_Opstatement(u4 id, QString instruction, Mid_Control_Kinds mck, Control_Coords cc)
  : id_(id), instruction_(instruction), mid_control_kind_(mck), control_coords_(cc)
{

}


//void VM_Opstatement::parse_mid(QString mid)
//{

//}

//void VM_Opstatement::parse_param()
//{

//}

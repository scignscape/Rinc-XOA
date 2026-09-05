
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef VM_OPSTATEMENT__H
#define VM_OPSTATEMENT__H

#include "global-types.h"
#include "accessors.h"

#include "otns.h"

OTNS_(DogPal)

class VM_Opstatement
{
 QString instruction_;
 QString param_;
 u4 id_;

public:

 enum class Mid_Control_Kinds {
     N_A, String, S1, S2, S4, S8, U1, U2, U4, U8, R4, R8, String_List, Cached_String
 };

 enum class Control_Coords {
     N_A, _EOF, _CMD, _Cached_String, x0, x1, x2, x3, x4, List, Matrix, Tensor
 };

private:

 Mid_Control_Kinds mid_control_kind_;
 Control_Coords control_coords_;

public:

 VM_Opstatement(u4 id, QString instruction);

 VM_Opstatement(u4 id, QString instruction, Control_Coords cc);

 VM_Opstatement(u4 id, QString instruction, Mid_Control_Kinds mck, Control_Coords cc);

 ACCESSORS(Mid_Control_Kinds ,mid_control_kind)
 ACCESSORS(Control_Coords ,control_coords)
 ACCESSORS(QString ,instruction)
 ACCESSORS(QString ,param)
 ACCESSORS(u4 ,id)

 VM_Opstatement copy_as_string() const
 {
  return VM_Opstatement(id_, instruction_, Mid_Control_Kinds::String, Control_Coords::x1);
 }

// void parse_mid();
// void parse_param();

};

_OTNS(DogPal)

#endif // VM_INTERPRETER__H

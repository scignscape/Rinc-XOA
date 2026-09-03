
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef VM_INTERPRETER__H
#define VM_INTERPRETER__H

#include "global-types.h"

#include "otns.h"

OTNS_(DogPal)

class VM_Interpreter
{
public:
 enum class Mid_Control_Kinds {
     N_A, String, S1, S2, S4, S8, U1, U2, U4, U8, R4, R8, String_List
 };

 enum class Mid_Control_Coords {
     N_A, x2, x3, List, Matrix
 };

private:

public:

 u2 advance_past_dispatch(QString& basis, QString* skipped = nullptr);
 u2 advance_past_mid_control(QString& basis, QString* skipped = nullptr);
 u2 advance_past_mid_control(QString& basis, Mid_Control_Kinds& mck, Mid_Control_Coords& mcc);

 u2 advance_past_end_control(QString& basis, QString* skipped = nullptr);
 u2 advance_past_end_control(QString& basis, QStringList* skipped);
 u2 advance_past_end_control(QString& basis, quint64* skipped);
 u2 advance_past_end_control(QString& basis, qint64* skipped);
 u2 advance_past_end_control(QString& basis, qreal* skipped);
 u2 advance_past_end_control(QString& basis, float* skipped);


};

_OTNS(DogPack)

#endif // VM_INTERPRETER__H

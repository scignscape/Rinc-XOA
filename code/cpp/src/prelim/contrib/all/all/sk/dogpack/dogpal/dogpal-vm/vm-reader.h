
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef VM_READER__H
#define VM_READER__H

#include "global-types.h"

#include "vm-opstatement.h"


#include "otns.h"

OTNS_(DogPal)


class VM_Reader
{
//public:

//private:

 QString file_path_;
 QString file_contents_;

 u4 current_pos_;
 u4 opstatement_index_;
//? u4 cache_index_;

 VM_Opstatement _EOF();

public:

 VM_Reader();

 u4 advance_past_cached_string(QString& basis, u4 start_pos, QString* result);

 u4 advance_past_instruction(QString* skipped = nullptr);
 u4 advance_past_mid_control(QString* skipped = nullptr);
 u4 advance_past_mid_control(VM_Opstatement::Mid_Control_Kinds& mck, VM_Opstatement::Control_Coords& cc);

 u4 advance_past_end_control(QString* skipped = nullptr);
 u4 advance_past_end_control(QStringList* skipped);
 u4 advance_past_end_control(quint64* skipped);
 u4 advance_past_end_control(qint64* skipped);
 u4 advance_past_end_control(qreal* skipped);
 u4 advance_past_end_control(float* skipped);

 void skip_space();

 void load_file(QString path);

 VM_Opstatement next_opstatement();

};

_OTNS(DogPal)

#endif // VM_INTERPRETER__H

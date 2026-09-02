
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef SDI_SENTENCE__H
#define SDI_SENTENCE__H

#include "relae-graph/relae-node-ptr.h"

#include "accessors.h"

#include "global-types.h"

#include "flags.h"

#include "kans.h"

#include <QStringList>
#include <QTextStream>

#include "kernel/document/vm/sdi-vm-writer.h"

KANS_(GTagML)


class GTagML_Parser;
class GTagML_Output_Blocks;


class SDI_Sentence
{
 u4 id_;
 QString sentence_text_;

 SDI_VM_Writer* vm_writer_;

 void vm_opstatement(QString contents);
 void vm_opstatement(QString instruction, QString mid_control, QString parameter);
 void vm_opstatement(QString instruction, QString parameter);


public:

 SDI_Sentence(u4 id, SDI_VM_Writer* vm_writer_);

 ACCESSORS(QString ,sentence_text)
 ACCESSORS(u4 ,id)

 void read_sentence_text(QStringList read_dispatch);
 void read_sentence_gaps(QStringList read_dispatch);

 void read_sentence_range_Start(QStringList read_dispatch, QVector<s4> numbers);
 void read_sentence_range_End(QStringList read_dispatch, QVector<s4> numbers);
 void read_sentence_range__End(QStringList read_dispatch, QVector<s4> numbers);

 void read_sentence_gaps(QString lines);
};

_KANS(GTagML)


#endif

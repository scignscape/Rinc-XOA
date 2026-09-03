
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "sdi-sentence.h".h"


// #include "gtagml-document-light-xml.h"

#include <QFile>
#include <QTextStream>
#include <QRegularExpression>


#include "kans.h"

USING_KANS(GTagML)


SDI_Sentence::SDI_Sentence(u4 id, SDI_VM_Writer* vm_writer)
  :  id_(id), vm_writer_(vm_writer)
{
}

void SDI_Sentence::read_sentence_end_punctuation(QStringList read_dispatch)
{
 QString p = read_dispatch.last();
 if(p.isEmpty())
   vm_writer_->opstatement("sdi-sentence-end-punctuation-empty");
 else
   vm_writer_->opstatement("sdi-sentence-end-punctuation", p);
}

void SDI_Sentence::read_sentence_range_Start(QStringList read_dispatch, QVector<s4> numbers)
{
// if(id_ > 14)
//  qDebug() << id_;
 numbers.prepend(id_);
 vm_writer_->opstatement_u4s("sdi-sentence-start-pos", numbers);
}

void SDI_Sentence::read_sentence_range_End(QStringList read_dispatch, QVector<s4> numbers)
{
// if(id_ > 14)
//  qDebug() << id_;
 numbers.prepend(id_);
 vm_writer_->opstatement_u4s("sdi-sentence-end-pos", numbers);
}

void SDI_Sentence::read_sentence_range__End(QStringList read_dispatch, QVector<s4> numbers)
{
// if(id_ > 14)
//  qDebug() << id_;
 numbers.prepend(id_);
 vm_writer_->opstatement_u4s("sdi-sentence--end-pos", numbers);
}

void SDI_Sentence::read_sentence_range_Switch(QStringList read_dispatch, QVector<s4> numbers)
{
// if(id_ > 14)
//  qDebug() << id_;
 numbers.prepend(id_);
 vm_writer_->opstatement_u4s("sdi-sentence-switch-pos", numbers);
}


void SDI_Sentence::read_sentence_text(QStringList read_dispatch)
{
 if(read_dispatch.takeFirst() == "_end")
 {
  set_sentence_text(read_dispatch.last().trimmed());

  sentence_text_.replace("...\\", "...");
  sentence_text_.replace("{\\sssm}", "");
  sentence_text_.replace("\\-", "-");
  sentence_text_.replace("-=-", "---");

  sentence_text_.replace(QRegularExpression("<!\\((\\d+)\\)!>"), "(\\1)");
  sentence_text_.replace(QRegularExpression("<!!([\"'\\w()-]+)!!>"), "\\1");

  vm_writer_->write_text_block(sentence_text_);
  vm_writer_->opstatement_text_block("sdi-sentence-text");


 }
 else
 {
  qDebug() << read_dispatch.last();
 }
}

void SDI_Sentence::read_sentence_gaps(QStringList read_dispatch)
{
 if(read_dispatch.takeFirst() == "_end")
   read_sentence_gaps(read_dispatch.last());
}

void SDI_Sentence::read_sentence_gaps(QString lines)
{

}



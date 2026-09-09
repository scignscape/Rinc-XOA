
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "sdi-sentence.h"


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
   vm_writer_->opstatement("sentence-end-punctuation-empty", 3);
 else
   vm_writer_->opstatement("sentence-end-punctuation", p, 3);
}

void SDI_Sentence::read_sentence_range_Start(QStringList read_dispatch, QVector<s4> numbers)
{
// if(id_ > 14)
//  qDebug() << id_;
 numbers.prepend(id_);
 vm_writer_->opstatement_u4s("sentence-start-pos", numbers, 3);
}

void SDI_Sentence::read_sentence_range_End(QStringList read_dispatch, QVector<s4> numbers)
{
// if(id_ > 14)
//  qDebug() << id_;
 numbers.prepend(id_);
 vm_writer_->opstatement_u4s("sentence-end-pos", numbers, 3);
}

void SDI_Sentence::read_sentence_range__End(QStringList read_dispatch, QVector<s4> numbers)
{
// if(id_ > 14)
//  qDebug() << id_;
 numbers.prepend(id_);
 vm_writer_->opstatement_u4s("sentence--end-pos", numbers, 3);
}

void SDI_Sentence::read_sentence_range_Switch(QStringList read_dispatch, QVector<s4> numbers)
{
// if(id_ > 14)
//  qDebug() << id_;
 numbers.prepend(id_);
 vm_writer_->opstatement_u4s("sentence-switch-pos", numbers, 3);
}


void SDI_Sentence::read_sentence_text(QStringList read_dispatch)
{
 if(read_dispatch.takeFirst() == "_end")
 {
  set_sentence_text(read_dispatch.last().trimmed());

  sentence_text_.replace("...\\", "...");
  sentence_text_.replace("{\\sssm}", "");
  sentence_text_.replace("\\-", "-");

  QString atext = sentence_text_;
  QString stext = sentence_text_;

  stext.replace("<!!\"!!>", "");

  QRegularExpression srx("<!\\((\\d+)\\)!>|<!!([\"'>=+*. \\w()-]+)!!>");

  QRegularExpressionMatchIterator it = srx.globalMatch(stext);

  while(it.hasNext())
  {
   QRegularExpressionMatch match = it.next();
   QString c1 = match.captured(1);
   QString c2 = match.captured(2);

   if(c2 == "\"")
     continue;

   if(c2.isEmpty())
   {
    vm_writer_->opstatement("sentence-insert-iref", c1, 1);
    vm_writer_->opstatement("sentence-insert-inner-pos", "2#/2",
      "%1 %2"_qt.arg(match.capturedStart(1)).arg(match.capturedEnd(1)), 1);
   }
   else
   {
    vm_writer_->opstatement("sentence-insert-text", c2, 1);
    vm_writer_->opstatement("sentence-insert-inner-pos", "2#/2",
      "%1 %2"_qt.arg(match.capturedStart(2)).arg(match.capturedEnd(2)), 1);
   }
   vm_writer_->opstatement("sentence-insert-outer-pos", "2#/2",
     "%1 %2"_qt.arg(match.capturedStart()).arg(match.capturedEnd()), 1);
  }


  atext.replace("-=-", "---");

  atext.replace(QRegularExpression("<!\\((\\d+)\\)!>"), "(\\1)");
  atext.replace(QRegularExpression("<!!([\"'>=+*. \\w()-]+)!!>"), "\\1");

  vm_writer_->write_text_block(stext, 1);
  vm_writer_->write_text_block(atext, 2);
  vm_writer_->opstatement_text_block("sentence-text", 3);


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



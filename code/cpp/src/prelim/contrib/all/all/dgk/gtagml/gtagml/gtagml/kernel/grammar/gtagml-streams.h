
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef GTAGML_STREAMS__H
#define GTAGML_STREAMS__H


#include <QString>
#include <QTextStream>
#include <QXmlStreamWriter>
#include <QBuffer>

#include "global-types.h"

#include "accessors.h"

#include "textio.h"
USING_KANS(TextIO)


#include "kans.h"


KANS_(GTagML)


class GTagML_Parser;
class GTagML_Parse_State;


class GTagML_Streams
{
 GTagML_Parse_State* parse_state_;

 QXmlStreamWriter xml_writer_;
 QString jats_;
 QTextStream jats_stream_;
 QBuffer jats_buffer_;
 QByteArray jats_array_;

 QString latex_;
 QTextStream latex_stream_;

 QString tao_;
 QTextStream tao_stream_;

 QString sentences_sdi_;
 QTextStream sentences_sdi_stream_;

 QString primary_acc_;
 QTextStream primary_acc_stream_;


 GTagML_Parser* parser_;

 public:

 GTagML_Streams(GTagML_Parse_State* parse_state);

 ACCESSORS(QString ,jats)

 ACCESSORS__RGET(QTextStream ,primary_acc_stream)
 ACCESSORS__RGET(QTextStream ,latex_stream)
 ACCESSORS__RGET(QTextStream ,tao_stream)
 ACCESSORS__RGET(QTextStream ,jats_stream)
 ACCESSORS__RGET(QTextStream ,sentences_sdi_stream)
 ACCESSORS__RGET(QXmlStreamWriter ,xml_writer)
 ACCESSORS__RGET(QString ,primary_acc)

 QString latex_text()
 {
  return latex_;
 }

 u4 primary_text_size()
 {
  return primary_text().size();
 }

 QString primary_text()
 {
  return primary_acc_;
 }

 QString sentences_sdi_text()
 {
  return sentences_sdi_;
 }

 void tao(QString text);
 void latex(QString text);
 void primary(QString text);

 GTagML_Streams& tao_instr(QString text);
 GTagML_Streams& tao_mid(QString text);
 GTagML_Streams& tao_end(QString text);
 GTagML_Streams& tao_end();

 GTagML_Streams& tao_string_instr(QString text)
 {
  return tao_instr(text).tao_mid("$");
 }

 GTagML_Streams& tao_empty_instr(QString text)
 {
  return tao_instr(text).tao_end();
 }

 GTagML_Streams& tao_restrict_to_layer(QString text)
 {
  return tao_string_instr("restrict-to-layer").tao_end(text);
 }

 GTagML_Streams& tao_unrestrict_from_layer(QString text)
 {
  return tao_string_instr("unrestrict-from-layer").tao_end(text);
 }

 GTagML_Streams& tao_enter_element(QString element);
 GTagML_Streams& tao_leave_element(QString element);

 void tao_primary_acc(QString text);

 void insert_latex_template(QString path, QString* result = nullptr);
 void insert_xml_template(QString path, QString* result = nullptr);


 void new_text_node(u2 ply_id, QString text);
 void init();

 void prepare_jats(QString& text, QString bib_path);

 void save_jats(QString path, QString bib_path)
 {
  KA::TextIO::save_file(path + ".test", jats_array_);// jats_array_.replace("@=", "&"));

  QString text = QString::fromLatin1(jats_array_);
  prepare_jats(text,  bib_path);
  //jats_ = QString::fromLatin1(jat)
  KA::TextIO::save_file(path, text);// jats_array_.replace("@=", "&"));
 }

 void save_latex(QString path)
 {
  //jats_ = QString::fromLatin1(jat)
  KA::TextIO::save_file(path, latex_);
 }

 void save_tao(QString path)
 {
  //jats_ = QString::fromLatin1(jat)
  KA::TextIO::save_file(path, tao_);
 }

 void save_sentences(QString path)
 {
  KA::TextIO::save_file(path, sentences_sdi_);
 }

 void enter_abstract();
 void leave_abstract();

};


_KANS(GTagML)


#endif GTAGML_STREAMS__H

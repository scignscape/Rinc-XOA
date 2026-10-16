
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef ASA_MODULE__H
#define ASA_MODULE__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "vm-reader.h"
#include "vm-opstatement.h"

#include "../module-base.h"

#include "global-types.h"

#include "otns.h"


#include <QDomDocument>
#include <QDomElement>

OTNS_(DCM2RO)



class ASA_Module : public _Module_Base
{
 QMap<u2, QString> path_ids_;
 QMap<QVList<u2>, QVList<QString>> path_group_ids_and_glyphs_;

 QVList<u2> current_paths_;

 QDomDocument the_svg_;

 QString html_template_;
 QString html_text_;

 u2 em_path_counts_;
 u2 em_group_counts_;

 QList<QPair<QString, QString>> toggle_ids_;

public:

 ASA_Module();

 void load_svg_file(QString file_path);
 void save_svg_file(QString file_path);

 void path_group_id_string_auto(QString id);
 void path_id_string_auto(QString id);

 void path_group_id(QVList<u2> paths);
 void path_id(u2 path);

 void path_group_glyphs(QVList<QString> glyphs);

 void prepare_svg_file();

 void load_html_template(QString file_path);
 void prepare_html_file();
 void save_html_file(QString file_path);


};

_OTNS(DCM2RO)

#endif // ASA_MODULE__H

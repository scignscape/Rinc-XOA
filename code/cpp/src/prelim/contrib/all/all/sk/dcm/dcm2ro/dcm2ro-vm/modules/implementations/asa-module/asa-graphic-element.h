
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef ASA_GRAPHIC_ELEMENT__H
#define ASA_GRAPHIC_ELEMENT__H

#include <QTextStream>

#include <QMap>
#include <QVariant>

#include "global-types.h"

#include "accessors.h"

#include "otns.h"

OTNS_(DCM2RO)

class ASA_Graphic_Element
{
 u2 index_in_document_;

 QMap<QString, QVariant> characteristics_;

 QStringList interpretation_;

 QString svg_id_;

 QMap<u2, QString> path_ids_;
 QMap<QVList<u2>, QVList<QString>> path_group_ids_and_glyphs_;

 QList<QPair<QString, QString>> toggle_ids_;

public:

 ASA_Graphic_Element();

 ACCESSORS(QStringList ,interpretation)
 ACCESSORS(u2 ,index_in_document)

 ACCESSORS(QString ,svg_id)

 ACCESSORS__GETR(QMap<u2, QString> ,path_ids)
 ACCESSORS__GETR(QMap<QVList<u2>, QVList<QString>> ,path_group_ids_and_glyphs)
 ACCESSORS__GETR(QList<QPair<QString, QString>> ,toggle_ids)

 QVariant& add_characteristic(QString key);
 void characteristic_values(QStringList keys, QVariant value);

 QVariant get_characteristic(QString key, QVariant missing)
 {
  return characteristics_.value(key, missing);
 }

};

_OTNS(DCM2RO)

#endif // ASA_GRAPHIC_ELEMENT__H


//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DCM2RO_VM_SCRIPT_DATA__H
#define DCM2RO_VM_SCRIPT_DATA__H

#include "accessors.h"

#include "global-types.h"

#include "flags.h"

#include "kans.h"

#include <QStringList>
#include <QTextStream>

#include "otns.h"

OTNS_(DCM2RO)


class VM_Script_Data
{

 QMap<QString, u1> characteristics_map_;
 QString sop_instance_uid_;
 QVector<QPair<u2, u2>> coord_pairs_;

public:

 VM_Script_Data();

 ACCESSORS(QMap<QString, u1> ,characteristics_map)
 ACCESSORS(QString ,sop_instance_uid)
 ACCESSORS(QVector<QPair<u2, u2>> ,coord_pairs)


};

_OTNS(DCM2RO)


#endif

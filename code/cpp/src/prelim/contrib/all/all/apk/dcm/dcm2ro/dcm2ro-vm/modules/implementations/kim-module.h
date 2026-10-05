
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef KIM_MODULE__H
#define KIM_MODULE__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "vm-reader.h"
#include "vm-opstatement.h"

#include "../module-base.h"

#include "otns.h"

OTNS_(DCM2RO)



class KIM_Module : public _Module_Base
{

public:

 KIM_Module();

 void series_date_time(QString date_time);
 void series_modality(QString modality);
 void series_description(QString description);
 void series_protocol_name(QString name);
 void series_uid(QString uid);

//{"kim-series:date-time", (methods_String) &KIM_Module::series_date_time},
//{"kim-series:modality", (methods_String) &KIM_Module::series_modality},
//{"kim-series:description", (methods_String) &KIM_Module::series_description},
//{"kim-series:protocol-name", (methods_String) &KIM_Module::series_protocol_name},
//{"kim-series:uid", (methods_String) &KIM_Module::series_uid},



};

_OTNS(AMPATH_NRE)

#endif // KIM_MODULE__H

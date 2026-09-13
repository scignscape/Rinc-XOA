
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef NRE_MODULE__H
#define NRE_MODULE__H

#include "global-types.h"

#include "vm-reader.h"
#include "vm-opstatement.h"

#include "../module-base.h"

#include "otns.h"

OTNS_(AMPATH_NRE)

class NRE_Module : public _Module_Base
{


public:

 NRE_Module();

 void global_baseline_skip(r8 val);
 void global_baseline_stretch(r8 val);

 void dim_pt();
 void aux_X(r8 val);
 void aux_Y(r8 val);
 void aux_B(QString str);
 void aux_P(u4 val);
 void aux_H(u4 val);
 void aux_sh(u4 val);
 void aux_sp(u4 val);
 void aux_id(u4 val);


};

_OTNS(AMPATH_NRE)

#endif // NRE_MODULE__H

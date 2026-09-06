
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef TAO_MODULE__H
#define TAO_MODULE__H

#include "global-types.h"

#include "vm-reader.h"
#include "vm-opstatement.h"

#include "module-base.h"

#include "otns.h"

OTNS_(DogPal)

class TAO_Module : public _Module_Base
{


public:

 TAO_Module();

 enum class Signatures {
   N_A, x0, String, U4x1, U4x4
 };

 void restrict_to_layer(QString layer);
 void unrestrict_from_layer(QString layer);

};

_OTNS(DogPal)

#endif // TAO_MODULE__H

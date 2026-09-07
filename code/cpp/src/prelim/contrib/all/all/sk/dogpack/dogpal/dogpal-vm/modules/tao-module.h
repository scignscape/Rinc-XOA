
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

 void leave_subparagraph_with_continue();

 void restrict_to_layer(QString layer);
 void unrestrict_from_layer(QString layer);
 void primary_acc_spaces(n8 encoded);

 void primary_acc(QString text);
 void leave_element(QString element);
 void enter_element(QString element);

 void end_sentence(QString text);

};

_OTNS(DogPal)

#endif // TAO_MODULE__H

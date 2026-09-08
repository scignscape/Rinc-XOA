
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "tao-module.h"

#include <bit>

#include <QDebug>


USING_OTNS(DogPal)


void TAO_Module::primary_acc_spaces(n8 encoded)
{
 u1 highest_bit_index = std::bit_width(encoded);
 encoded &= (std::bit_floor(encoded) - 1);

 QString spaces;
 spaces.resize(highest_bit_index - 1);

 n8 mask = 1 << highest_bit_index - 1;

 for(u1 str_index = 0, index = highest_bit_index - 1; index > 0; --index, ++str_index)
 {
  mask >>= 1;
  if(encoded & mask)
    spaces[str_index] = QChar('\n');
  else
    spaces[str_index] = QChar(' ');
 }

 qDebug() << spaces;
}

void TAO_Module::leave_element(QString element)
{

}

void TAO_Module::enter_element(QString element)
{

}

void TAO_Module::end_sentence(QString text)
{

}

void TAO_Module::primary_acc(QString text)
{

}

void TAO_Module::leave_subparagraph_with_continue()
{

}

void TAO_Module::restrict_to_layer(QString layer)
{

}

void TAO_Module::unrestrict_from_layer(QString layer)
{

}

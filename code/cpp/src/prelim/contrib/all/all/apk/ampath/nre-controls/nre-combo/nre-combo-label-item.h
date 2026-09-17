
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#ifndef NRE_COMBO_LABEL_ITEM__H
#define NRE_COMBO_LABEL_ITEM__H


#include <QWidget>
#include <QPushButton>

class QHBoxLayout;



#include "kans.h"

KANS_(AMPATH_Forms)


class NRE_Combo_Label_Item : public QPushButton
{
 Q_OBJECT

public:

 NRE_Combo_Label_Item(QWidget *parent = nullptr);

};

//} // namespace Qtilities

_KANS(AMPATH_Forms)


#endif // NRE_COMBO_LABEL_ITEM__H

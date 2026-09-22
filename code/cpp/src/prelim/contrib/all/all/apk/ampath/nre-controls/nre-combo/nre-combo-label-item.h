
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#ifndef NRE_COMBO_LABEL_ITEM__H
#define NRE_COMBO_LABEL_ITEM__H


#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QToolButton>

class QHBoxLayout;



#include "kans.h"

KANS_(AMPATH_Forms)


class NRE_Combo_Label_Item : public QWidget
{
 Q_OBJECT

public:

 NRE_Combo_Label_Item(QString text, QWidget *parent = nullptr);

 QHBoxLayout* main_layout_;
 QToolButton* close_button_;
 QLabel* label_;

Q_SIGNALS:
 void close_requested(NRE_Combo_Label_Item*);

//private Q_SLOTS:
// void handle_closed();
};

//} // namespace Qtilities

_KANS(AMPATH_Forms)


#endif // NRE_COMBO_LABEL_ITEM__H



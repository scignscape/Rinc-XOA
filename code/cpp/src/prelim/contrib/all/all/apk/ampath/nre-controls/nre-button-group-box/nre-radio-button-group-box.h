
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#ifndef NRE_RADIO_BUTTON_GROUP_BOX__H
#define NRE_RADIO_BUTTON_GROUP_BOX__H


#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QGroupBox>



#include "kans.h"

KANS_(AMPATH_Forms)


class NRE_Radio_Button_Group_Box : public QGroupBox
{
 Q_OBJECT

//? QGroupBox* group_box_;
 QGridLayout* main_layout_;
//? QButtonGroup* button_group_;

public:

 NRE_Radio_Button_Group_Box(QWidget *parent = nullptr);


};


_KANS(AMPATH_Forms)


#endif // NRE_RADIO_BUTTON_GROUP_BOX__H

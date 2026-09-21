
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
#include <QLabel>
#include <QScrollArea>

#include "accessors.h"
#include "global-types.h"

#include "kans.h"

KANS_(AMPATH_Forms)


class NRE_Radio_Button_Group_Box : public QGroupBox
{
 Q_OBJECT

//? QGroupBox* group_box_;
 QGridLayout* main_layout_;
//? QButtonGroup* button_group_;

 u1 max_columns_;
 u1 current_row_;
 u1 current_column_;
 u1 current_count_;

 QLabel* placeholder_;

 QScrollArea* enclosing_scroll_area_;

 QWidget* parent_widget_;

public:

 NRE_Radio_Button_Group_Box(QWidget *parent = nullptr);

 ACCESSORS(u1 ,max_columns)

 ACCESSORS(QScrollArea* ,enclosing_scroll_area)

 void add_item(QString label);
 void add_placeholder(QString label);


};


_KANS(AMPATH_Forms)


#endif // NRE_RADIO_BUTTON_GROUP_BOX__H

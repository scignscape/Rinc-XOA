
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "nre-radio-button-group-box.h"

#include <QPainter>
#include <QStyleOption>
#include <QHBoxLayout>

#include <QToolButton>


#include "kans.h"
USING_KANS(AMPATH_Forms)


NRE_Radio_Button_Group_Box::NRE_Radio_Button_Group_Box(QWidget* parent)
 : QGroupBox(parent)
{
 main_layout_ = new QGridLayout;
 setLayout(main_layout_);
}


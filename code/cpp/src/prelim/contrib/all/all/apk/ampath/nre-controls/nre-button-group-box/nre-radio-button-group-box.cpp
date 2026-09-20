
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "nre-radio-button-group-box.h"

#include <QPainter>
#include <QStyleOption>
#include <QHBoxLayout>

#include <QToolButton>

#include <QRadioButton>

#include "kans.h"
USING_KANS(AMPATH_Forms)


NRE_Radio_Button_Group_Box::NRE_Radio_Button_Group_Box(QWidget* parent)
 : QGroupBox(parent)
{
 main_layout_ = new QGridLayout;
 setLayout(main_layout_);

 setTitle("Radio Buttons");

 setMinimumHeight(300);

 QRadioButton *radio1 = new QRadioButton(tr("&Radio button 1"));
 QRadioButton *radio2 = new QRadioButton(tr("R&adio button 2"));
 QRadioButton *radio3 = new QRadioButton(tr("Ra&dio button 3"));

 main_layout_->addWidget(radio1, 0, 0);
 main_layout_->addWidget(radio2, 1, 0);
 main_layout_->addWidget(radio3, 2, 0);
}


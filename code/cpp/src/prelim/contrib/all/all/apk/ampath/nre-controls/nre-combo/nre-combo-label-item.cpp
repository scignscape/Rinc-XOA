
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "nre-combo-label-item.h"

#include <QPainter>
#include <QStyleOption>
#include <QHBoxLayout>

#include <QWidget>
#include <QLabel>


#include "kans.h"
USING_KANS(AMPATH_Forms)


NRE_Combo_Label_Item::NRE_Combo_Label_Item(QString text, QWidget* parent)
 : QWidget(parent)
{
 main_layout_ = new QHBoxLayout;
 main_layout_->setContentsMargins(4, 2, 4, 2);
 main_layout_->setSpacing(4);
 setLayout(main_layout_);

 close_button_ = new QToolButton(this);
 close_button_->setText("×");
 close_button_->setStyleSheet("QToolButton { border: none; background: transparent; font-weight: bold; }");

 label_ = new QLabel(text, this);

 main_layout_->addWidget(close_button_);
 main_layout_->addWidget(label_);

 // Style the main container to look like a flat tag
 setStyleSheet("NRE_Combo_Label_Item { border: 1px solid gray; border-radius: 3px; background: #f0f0f0; }");

 connect(close_button_,
   &QToolButton::clicked, this, [this](){close_requested(this);});

}

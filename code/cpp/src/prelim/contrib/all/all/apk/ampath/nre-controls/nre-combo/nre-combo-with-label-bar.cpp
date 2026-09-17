
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "nre-combo-with-label-bar.h"

#include <QPainter>
#include <QStyleOption>
#include <QHBoxLayout>

#include <QToolButton>


#include "kans.h"
USING_KANS(AMPATH_Forms)


NRE_Combo_With_Label_Bar::NRE_Combo_With_Label_Bar(QWidget* parent)
 : QWidget(parent), max_selectable_(0), selected_count_(0)
{
 layout_ = new QHBoxLayout(this);

 combo_box_ = new QComboBox(this);


 layout_->setContentsMargins(0, 0, 0, 0);
 layout_->setSpacing(0);
 layout_->addWidget(combo_box_);
 setLayout(layout_);
}



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
 : QGroupBox(parent), max_columns_(5),
   current_row_(0), current_column_(0), current_count_(0), enclosing_scroll_area_(nullptr)
{
 parent_widget_ = parent;
 main_layout_ = new QGridLayout;
 setLayout(main_layout_);

 add_placeholder("You need to add radio buttons!");

 setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

//? setTitle("Radio Buttons");

// setMinimumHeight(300);

// add_item("Radio button 1");
// add_item("Radio button 2");
// add_item("Radio button 3");

}

void NRE_Radio_Button_Group_Box::add_placeholder(QString label)
{
 placeholder_ = new QLabel(label);
 main_layout_->addWidget(placeholder_, 0, 0);
}


void NRE_Radio_Button_Group_Box::add_item(QString label)
{
 if(placeholder_)
 {
  main_layout_->removeWidget(placeholder_);
  placeholder_->setVisible(false);
  placeholder_->deleteLater();
  placeholder_ = nullptr;
 }

 if(current_column_ == max_columns_ - 1)
 {
  current_column_ = 0;
  ++current_row_;
 }
 else if(current_count_)
  ++current_column_;

 ++current_count_;

 QRadioButton* r = new QRadioButton(label, this);

 QString position_info = "%1 %2 %3"_qt.arg(current_count_).arg(current_row_).arg(current_column_);
 r->setProperty("position-info", QVariant(position_info));

 main_layout_->addWidget(r, current_row_, current_column_);

 if(current_row_ == 0)
 {
  main_layout_->setColumnStretch(current_column_, 0);
  main_layout_->setColumnStretch(current_column_ + 1, 1);

  setMinimumWidth(current_column_ * 250);

  if(enclosing_scroll_area_)
  {
   enclosing_scroll_area_->widget()->setMinimumWidth(current_column_ * 150);
   enclosing_scroll_area_->setMinimumWidth(current_column_ * 150);
  }

  if(parent_widget_)
  {
   parent_widget_->setMinimumWidth(current_column_ * 150);
  }
 }

 main_layout_->invalidate();

 adjustSize();

 if(enclosing_scroll_area_)
 {
  enclosing_scroll_area_->adjustSize();
  enclosing_scroll_area_->widget()->adjustSize();
 }


}



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

NRE_Combo_With_Label_Bar::NRE_Combo_With_Label_Bar(QWidget *parent)
  :  NRE_Combo_With_Label_Bar("Choose one ...", parent)
{

}

NRE_Combo_With_Label_Bar::NRE_Combo_With_Label_Bar(QString top_option, QWidget* parent)
 : QWidget(parent), max_selectable_(0), selected_count_(0)
{
 main_layout_ = new QHBoxLayout(this);

 combo_box_ = new QComboBox(this);

 if(!top_option.isEmpty())
   combo_box_->addItem(top_option);

 QObject::connect(combo_box_, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated),
   this, &NRE_Combo_With_Label_Bar::handle_index_changed);

 main_layout_->setContentsMargins(0, 0, 0, 0);
 main_layout_->setSpacing(0);
 main_layout_->addWidget(combo_box_);

 left_layout_ = new QHBoxLayout(this);
 left_layout_->setContentsMargins(0, 0, 0, 0);
 left_layout_->setSpacing(0);

 main_layout_->addLayout(left_layout_);

 main_layout_->addStretch();

 setLayout(main_layout_);
}

void NRE_Combo_With_Label_Bar::add_option(QString identifier, QString label)
{
 //QString* option = new QString(identifier);
 options_.push_back(label);
 combo_box_->addItem(identifier);
}

QLabel* NRE_Combo_With_Label_Bar::get_label_by_index(u2 index)
{
 auto it = label_map_.find(index);
 if(it == label_map_.end())
 {
  QLabel* result = new QLabel(options_[index - 1], this);
  label_map_[index] = result;
  return result;
 }
 return it.value();
}

void NRE_Combo_With_Label_Bar::handle_index_changed(int ix)
{
 if(ix == 0)
   return;

 QLabel* lbl = get_label_by_index(ix);

 if(left_layout_->indexOf(lbl) == -1)
 {
  left_layout_->addWidget(lbl);
 }

}


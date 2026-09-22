
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "nre-combo-with-label-bar.h"

#include "nre-combo-label-item.h"

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

NRE_Combo_Label_Item* NRE_Combo_With_Label_Bar::get_label_by_index(u2 index)
{
 auto it = label_map_.find(index);
 if(it == label_map_.end())
 {
  NRE_Combo_Label_Item* result = new NRE_Combo_Label_Item(options_[index - 1], this);
  label_map_[index] = result;
  connect(result, &NRE_Combo_Label_Item::close_requested, this,
    &NRE_Combo_With_Label_Bar::handle_close_requested);
  return result;
 }
 return it.value();
}

void NRE_Combo_With_Label_Bar::handle_close_requested(NRE_Combo_Label_Item* which_item)
{
 left_layout_->removeWidget(which_item);
 which_item->hide();
 left_layout_->update();
 combo_box_->setCurrentIndex(0);
}

void NRE_Combo_With_Label_Bar::handle_index_changed(int ix)
{
 if(ix == 0)
   return;

 NRE_Combo_Label_Item* cli = get_label_by_index(ix);

 if(left_layout_->indexOf(cli) == -1)
 {
  left_layout_->addWidget(cli);
  cli->show();
 }

}


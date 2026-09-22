
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#ifndef NRE_COMBO_WITH_LABEL_BAR__H
#define NRE_COMBO_WITH_LABEL_BAR__H



#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QScrollArea>

class QHBoxLayout;


#include "global-types.h"
#include "accessors.h"

#include "kans.h"

KANS_(AMPATH_Forms)

class NRE_Combo_Label_Item;

class NRE_Combo_With_Label_Bar : public QWidget
{
 Q_OBJECT

 QHBoxLayout* main_layout_;

 QComboBox* combo_box_;
 QScrollArea* scroll_area_;
 QFrame* scrolled_frame_;
 QHBoxLayout* left_layout_;
 QHBoxLayout* frame_layout_;


 u2 max_selectable_;
 u2 selected_count_;

 QStringList options_;

 QMap<u2, NRE_Combo_Label_Item*> label_map_;

 NRE_Combo_Label_Item* get_label_by_index(u2 index);

 void update_max_selectable();

 QString auto_top_option_;

public:

 NRE_Combo_With_Label_Bar(QWidget *parent = nullptr);

 NRE_Combo_With_Label_Bar(QString top_option, QWidget *parent = nullptr);

 ACCESSORS__SDECLARE(u2, max_selectable)

 void add_option(QString identifier, QString label);
 void add_item(QString identifier)
 {
  add_option(identifier, identifier);
 }

public Q_SLOTS:
 void handle_index_changed(int ix);
 void handle_close_requested(NRE_Combo_Label_Item* which_item);


};

//} // namespace Qtilities

_KANS(AMPATH_Forms)


#endif // NRE_COMBO_WITH_LABEL_BAR__H

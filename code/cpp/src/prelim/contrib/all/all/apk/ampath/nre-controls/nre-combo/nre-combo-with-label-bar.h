
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#ifndef NRE_COMBO_WITH_LABEL_BAR__H
#define NRE_COMBO_WITH_LABEL_BAR__H



#include <QWidget>
#include <QComboBox>

class QHBoxLayout;

#include <QLabel>

#include "global-types.h"
#include "accessors.h"

#include "kans.h"

KANS_(AMPATH_Forms)


class NRE_Combo_With_Label_Bar : public QWidget
{
 Q_OBJECT

 QHBoxLayout* main_layout_;
 QHBoxLayout* left_layout_;

 QComboBox* combo_box_;

 u2 max_selectable_;
 u2 selected_count_;

 QStringList options_;

 QMap<u2, QLabel*> label_map_;

 QLabel* get_label_by_index(u2 index);

public:

 NRE_Combo_With_Label_Bar(QWidget *parent = nullptr);

 NRE_Combo_With_Label_Bar(QString top_option, QWidget *parent = nullptr);

 ACCESSORS(u2, max_selectable)

 void add_option(QString identifier, QString label);

 void handle_index_changed(int ix);


};

//} // namespace Qtilities

_KANS(AMPATH_Forms)


#endif // NRE_COMBO_WITH_LABEL_BAR__H


//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "nre-workspace-launcher-button.h"

#include <QPainter>
#include <QStyleOption>
#include <QHBoxLayout>

#include <QWidget>
#include <QLabel>


#include "kans.h"
USING_KANS(AMPATH_Forms)


NRE_Workspace_Launcher_Button::NRE_Workspace_Launcher_Button(QWidget* parent)
 : NRE_Combo_With_Label_Bar(parent)
{
 set_max_selectable(1);
 scroll_area_->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}


NRE_Workspace_Launcher_Button::NRE_Workspace_Launcher_Button(QString workspace_text, QString text,
  QString first_item, QWidget* parent)
 : NRE_Combo_With_Label_Bar(text, parent)
{
 set_workspace_text(workspace_text);
 set_max_selectable(1);
 scroll_area_->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

 add_item(first_item);
}


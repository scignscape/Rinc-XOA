
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#ifndef NRE_WORKSPACE_LAUNCHER_BUTTON__H
#define NRE_WORKSPACE_LAUNCHER_BUTTON__H


#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QToolButton>

#include "nre-combo-with-label-bar.h"

class QHBoxLayout;



#include "kans.h"

KANS_(AMPATH_Forms)


class NRE_Workspace_Launcher_Button : public NRE_Combo_With_Label_Bar
{
 Q_OBJECT

public:

 NRE_Workspace_Launcher_Button(QWidget *parent = nullptr);
 NRE_Workspace_Launcher_Button(QString workspace_text, QString text,
   QString first_item, QWidget *parent = nullptr);

};

//} // namespace Qtilities

_KANS(AMPATH_Forms)


#endif // NRE_COMBO_LABEL_ITEM__H



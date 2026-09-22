
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <QFile>


#include <QRegularExpression>

#include <QDir>
#include <QDebug>

#include <QApplication>

#include <QLineEdit>

#include "nre-combo/nre-combo-with-label-bar.h"

#include "kans.h"

#include <QVBoxLayout>
#include <QFrame>
#include <QScrollArea>


USING_KANS(AMPATH_Forms)


int main(int argc, char *argv[])
{
 QApplication qapp(argc, argv);

 NRE_Combo_With_Label_Bar* combo = new NRE_Combo_With_Label_Bar;

 combo->add_option("Opt 1", "test opt 1");
 combo->add_option("Opt 2", "test opt 2");
 combo->add_option("Opt 3", "test opt 3");
 combo->add_option("Opt 4", "test opt 4");
 combo->add_option("Opt 5", "test opt 5");
 combo->add_option("Opt 6", "test opt 6");

 combo->set_max_selectable(1);
 combo->show();

 return qapp.exec();
}


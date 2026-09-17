
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <QFile>


#include <QRegularExpression>

#include <QDir>
#include <QDebug>

#include <QApplication>

#include "nre-admission-form/nre-admission-form.h"

#include "kans.h"

USING_KANS(AMPATH_Forms)


int main(int argc, char *argv[])
{
 QApplication qapp(argc, argv);

 NRE_Admission_Form form;
 form.show();

 return qapp.exec();
}


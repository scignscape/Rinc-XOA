
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#ifndef NRE_ADMISSION_FORM__H
#define NRE_ADMISSION_FORM__H


#include <QMainWindow>

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>



#include "kans.h"

KANS_(AMPATH_Forms)

class NRE_Accordion_List;

class NRE_Admission_Form : public QMainWindow
{
 Q_OBJECT

public:

 NRE_Admission_Form(QWidget *parent = nullptr);

};


_KANS(AMPATH_Forms)


#endif // NRE_ADMISSION_FORM__H

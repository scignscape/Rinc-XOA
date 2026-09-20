
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

#include <QTabWidget>
#include <QFrame>
#include <QScrollArea>
#include <QLineEdit>


#include "kans.h"

KANS_(AMPATH_Forms)

class NRE_Accordion_List;

class NRE_Admission_Form : public QMainWindow
{
 Q_OBJECT

 QTabWidget* pages_tab_widget_;

 // //  Page: Admission
 QScrollArea* S_100_; // Admission
 QFrame* F_100_; // Admission
 QVBoxLayout* F_100_vbl_ ;

  // // Section: Admission_data -- ctor
 NRE_Accordion_List* Admission_data_F100_;

 QString L_caretakersName_;
 QLineEdit* caretakersName_;

 // //  Page: Anamnesis at admission
 QScrollArea* S_101_; // Anamnesis at admission
 QFrame* F_101_; // Anamnesis at admission
 QVBoxLayout* F_101_vbl_ ;

  // // Section: History_of_the_illness -- ctor
 NRE_Accordion_List* History_of_the_illness_F101_;

  // // Section: Feeding_history -- ctor
 NRE_Accordion_List* Feeding_history_F101_;

  // // Section: Family_history -- ctor
 NRE_Accordion_List* Family_history_F101_;

// QScrollArea* S_100_;
// QScrollArea* S_101_;

// QFrame* F_100_;
// QFrame* F_101_;

// NRE_Accordion_List* al1_;
// NRE_Accordion_List* al2_;

 void init_labels();

public:

 NRE_Admission_Form();//QWidget *parent = nullptr);

};


_KANS(AMPATH_Forms)


#endif // NRE_ADMISSION_FORM__H

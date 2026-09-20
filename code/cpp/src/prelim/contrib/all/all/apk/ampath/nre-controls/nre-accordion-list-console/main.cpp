
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

#include "nre-accordion-list/nre-accordion-list.h"

#include "kans.h"

#include <QVBoxLayout>
#include <QFrame>
#include <QScrollArea>


USING_KANS(AMPATH_Forms)


int main(int argc, char *argv[])
{
 QApplication qapp(argc, argv);

 QFrame* F_100_ = new QFrame;
 QVBoxLayout* F_100_vbl_ = new QVBoxLayout;
 F_100_->setLayout(F_100_vbl_);

 QScrollArea* S_100_ = new QScrollArea;


// NRE_Accordion_List nal;

// nal.set_text("Demo Accordion");

 NRE_Accordion_List* Admission_data_F100_ = new NRE_Accordion_List; //(S_100_);
 //F_100_vbl_->addWidget(Admission_data_F100_);

// Admission_data_F100_->set_text("Demo Accordion");

 QLineEdit* caretakersName_ = new QLineEdit(Admission_data_F100_);
 Admission_data_F100_->add_item("L_caretakersName_",
   caretakersName_);

 Admission_data_F100_->set_text("Admission_data_F100_");

// Admission_data_F100_->show();
// QLineEdit* qle = new QLineEdit;
// nal.add_item("QLE", qle);

// nal.show();

// Admission_data_F100_->show();

 F_100_vbl_->addWidget(Admission_data_F100_);

 F_100_->show();

//?
 S_100_->setWidget(F_100_);

 Admission_data_F100_->set_enclosing_scroll_area(S_100_);

 Admission_data_F100_->collapse();

// S_100_->setBackgroundRole(QPalette::Dark);
// Admission_data_F100_->setBackgroundRole(QPalette::Light);

 S_100_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
 S_100_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);


 S_100_->updateGeometry();


 S_100_->show();
// nal.onExpandWidget(true);

 return qapp.exec();
}


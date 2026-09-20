
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "nre-admission-form_manual.h"

#include <QPainter>
#include <QStyleOption>
#include <QHBoxLayout>

#include <QToolButton>

#include "nre-controls/nre-accordion-list/nre-accordion-list.h"


#include "kans.h"
USING_KANS(AMPATH_Forms)


NRE_Admission_Form::NRE_Admission_Form()//QWidget* parent)
 //: QMainWindow(parent)
{
 pages_tab_widget_ = new QTabWidget(this);
 init_labels();
 setCentralWidget(pages_tab_widget_);
 pages_tab_widget_->show();

 // //  Page: Admission
 F_100_ = new QFrame;
 F_100_vbl_ = new QVBoxLayout;
 F_100_->setLayout(F_100_vbl_);
 S_100_ = new QScrollArea(this);
 S_100_->setWidget(F_100_);

  // // Section: Admission_data -- ctor
 Admission_data_F100_ = new NRE_Accordion_List(S_100_);
 F_100_vbl_->addWidget(Admission_data_F100_);

 caretakersName_ = new QLineEdit(Admission_data_F100_);
 Admission_data_F100_->add_item(L_caretakersName_,
   caretakersName_);

 Admission_data_F100_->set_text("Admission_data_F100_");

 Admission_data_F100_->show();

 F_100_vbl_->update();


// S_100_ = new QScrollArea(this);
 S_101_ = new QScrollArea(this);

// F_100_ = new QFrame(this);
 F_101_ = new QFrame(this);

// Admission_data_F100_ = new NRE_Accordion_List(this);

//? QVBoxLayout* F_100_vbl_ = new QVBoxLayout;

// F_100_->setLayout(F_100_vbl_);
 F_101_->setLayout(new QVBoxLayout);

// F_100_vbl_->addWidget(Admission_data_F100_);

// caretakersName_ = new QLineEdit(Admission_data_F100_);
// Admission_data_F100_->add_item(L_caretakersName_,
//   caretakersName_);

// QPushButton* b0 = new QPushButton("b0");

// F_100_vbl_->addWidget(b0);
// F_100_vbl_->addWidget(al1_);


// pages_tab_widget_->addTab(S_100_, "100");
// pages_tab_widget_->addTab(S_101_, "101");

// QFrame* bf = new QFrame(this);
// QVBoxLayout* bfl = new QVBoxLayout;

// QPushButton* b = new QPushButton("b1");

// bfl->addWidget(b);
// bf->setLayout(bfl);

// pages_tab_widget_->addTab(bf, "b1");
//  pages_tab_widget_->addTab(S_100_, "100");
//  pages_tab_widget_->addTab(S_101_, "101");

 pages_tab_widget_->addTab(S_100_, "Admission");

// S_100_->setWidget(F_100_);
 S_101_->setWidget(F_101_);

//   pages_tab_widget_->addTab(S_100_, "100");
   pages_tab_widget_->addTab(S_101_, "101");


   pages_tab_widget_->show();
// bf->show();

}

void NRE_Admission_Form::init_labels()
{
 L_caretakersName_ = "Caretaker's Name";
}


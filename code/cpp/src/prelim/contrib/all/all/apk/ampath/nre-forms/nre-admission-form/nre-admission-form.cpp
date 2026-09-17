
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "nre-admission-form.h"

#include <QPainter>
#include <QStyleOption>
#include <QHBoxLayout>

#include <QToolButton>

#include "nre-controls/nre-accordion-list/nre-accordion-list.h"


#include "kans.h"
USING_KANS(AMPATH_Forms)


NRE_Admission_Form::NRE_Admission_Form(QWidget* parent)
 : QMainWindow(parent)
{
 pages_tab_widget_ = new QTabWidget(this);

 setCentralWidget(pages_tab_widget_);

 S_100_ = new QScrollArea(this);
 S_101_ = new QScrollArea(this);

 F_100_ = new QFrame(this);
 F_101_ = new QFrame(this);

 al1_ = new NRE_Accordion_List(this);
 al2_ = new NRE_Accordion_List(this);

 QPushButton* cl1 = new QPushButton(al1_);
// cl1->setText("close");
 al1_->add_item("close", cl1);

 QVBoxLayout* F_100_vbl_ = new QVBoxLayout;

 F_100_->setLayout(F_100_vbl_);
 F_101_->setLayout(new QVBoxLayout);

 QPushButton* b0 = new QPushButton("b0");

 F_100_vbl_->addWidget(b0);
 F_100_vbl_->addWidget(al1_);


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

 S_100_->setWidget(F_100_);
 S_101_->setWidget(F_101_);

   pages_tab_widget_->addTab(S_100_, "100");
   pages_tab_widget_->addTab(S_101_, "101");


   pages_tab_widget_->show();
// bf->show();

}


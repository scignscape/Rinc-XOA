
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



// modified from:

/*
    MIT License

    Copyright (c) 2021-2023 Andrea Zanellato <redtid3@gmail.com>

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to
    deal in the Software without restriction, including without limitation the
    rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
    sell copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/


#include "nre-accordion-item.h"

#include <QPainter>
#include <QStyleOption>
#include <QGridLayout>

#include <QToolButton>
#include <QLabel>


#include "kans.h"
USING_KANS(AMPATH_Forms)



NRE_Accordion_Item::NRE_Accordion_Item(QWidget* parent)
 : QWidget(parent), label_(nullptr),
   widget_column_(1),
   widget_row_(0),
   label_column_span_(1),
   label_row_span_(1)
{
 main_layout_ = new QGridLayout;
 setLayout(main_layout_);
}

void NRE_Accordion_Item::use_vertical_orientation()
{
 widget_column_ = 0;
 widget_row_ = 1;
}

void NRE_Accordion_Item::use_horizontal_orientation()
{
 widget_column_ = 1;
 widget_row_ = 0;
}


void NRE_Accordion_Item::set_text(QString label)
{
 if(!label_)
 {
  label_ = new QLabel(this);
  main_layout_->addWidget(label_, 0, 0, label_row_span_, label_column_span_);
 }
 label_->setText(label);
}

void NRE_Accordion_Item::set_widget(QWidget* w)
{
 main_layout_->addWidget(w, widget_row_, widget_column_);
 main_layout_->update();
 updateGeometry();
}

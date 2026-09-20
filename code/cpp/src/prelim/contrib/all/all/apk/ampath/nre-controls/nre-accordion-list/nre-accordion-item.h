
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

#ifndef NRE_ACCORDION_ITEM__H
#define NRE_ACCORDION_ITEM__H


#include <QWidget>
#include <QLabel>

class QGridLayout;

#include "global-types.h"

#include "kans.h"

KANS_(AMPATH_Forms)


class NRE_Accordion_Item : public QWidget
{
 Q_OBJECT

 QGridLayout* main_layout_;
 QLabel* label_;

 u1 widget_column_;
 u1 widget_row_;
 u1 label_column_span_;
 u1 label_row_span_;

public:

 NRE_Accordion_Item(QWidget *parent = nullptr);

 void set_text(QString label);
 void set_widget(QWidget* w);

 void use_vertical_orientation();
 void use_horizontal_orientation();
};

//} // namespace Qtilities

_KANS(AMPATH_Forms)


#endif // NRE_ACCORDION_ITEM__H

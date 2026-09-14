
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef NRE_FORM_SECTION__H
#define NRE_FORM_SECTION__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "nre-form-base.h"


#include "otns.h"

OTNS_(AMPATH_NRE)

class NRE_Form_Question;

class NRE_Form_Section : public NRE_Form_Base
{
 QString label_;

 QVector<NRE_Form_Question*> questions_;

public:

 NRE_Form_Section();

 ACCESSORS(QString ,label)

 void add_question(NRE_Form_Question* q);

 NRE_Form_Question* current_question();

 void cleanup();

 void write_questions();


};

_OTNS(AMPATH_NRE)

#endif // NRE_FORM_SECTION__H

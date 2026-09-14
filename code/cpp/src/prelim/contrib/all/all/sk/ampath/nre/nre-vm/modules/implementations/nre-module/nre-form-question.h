
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef NRE_FORM_QUESTION__H
#define NRE_FORM_QUESTION__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "nre-form-base.h"

//#include "nre-form-answer.h"

#include "otns.h"

OTNS_(AMPATH_NRE)

class NRE_Form_Answer;


class NRE_Form_Question : public NRE_Form_Base
{
 QVector<NRE_Form_Answer*> answers_;

 QString id_;

 u2 required_cardinality_;

public:

 NRE_Form_Question();

 ACCESSORS(u2 ,required_cardinality)
 ACCESSORS(QString ,id)

 void add_answer(NRE_Form_Answer* a);

 NRE_Form_Answer* current_answer();

 void cleanup();

 void write_concept(QString text);
 void write_label(QString text);

};

_OTNS(AMPATH_NRE)

#endif // NRE_FORM_QUESTION__H

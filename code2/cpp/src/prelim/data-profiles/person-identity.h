
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef PERSON_IDENTITY__H
#define PERSON_IDENTITY__H

#include "accessors.h"
#include "global-types.h"

#include "mfns.h"

#include <QDate>


MFNS_(Identity)

class Person_Identity
{

 QString gender_;
 QString usual_name_;
 QStringList other_names_;
 QString full_name_;
 QString first_name_;

 QDate date_of_birth_;


public:

 Person_Identity();

 ACCESSORS(QString ,gender)
 ACCESSORS(QString ,usual_name)
 ACCESSORS(QStringList ,other_names)
 ACCESSORS(QString ,full_name)
 ACCESSORS(QString ,first_name)

 ACCESSORS(QDate ,date_of_birth)


};

_MFNS(Identity)


#endif // PERSON_IDENTITY__H

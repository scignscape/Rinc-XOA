
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)




#ifndef NRE_VM_GENERATOR__H
#define NRE_VM_GENERATOR__H


#include <QFile>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>

#include <QRegularExpression>

#include <QDir>

#include "otns.h"

OTNS_(AMPATH_NRE)

class NRE_VM_Generator
{
 enum class Node_Type {
  N_A, Form_Root
 };

 void process_form_node(const QJsonObject& qjo, QString key = {}, Node_Type nt = Node_Type::N_A);

public:

 NRE_VM_Generator();


};

_OTNS(AMPATH_NRE)


#endif // NRE_VM_GENERATOR__H

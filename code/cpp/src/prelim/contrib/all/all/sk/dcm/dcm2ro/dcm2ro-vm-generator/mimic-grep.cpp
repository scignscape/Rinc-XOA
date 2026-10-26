

//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)




#include <QString>
#include <QStringList>
#include <QDirIterator>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QDebug>


// Mimics grep -r. Supports both plain text and regex matching.
QVector<QString> qtGrepSearch(QString folder_path, QString pattern)
{
 Qt::CaseSensitivity cs = Qt::CaseSensitive;

 QVector<QString> results;

 QDirIterator it(folder_path, QDir::Files, QDirIterator::Subdirectories);


 while (it.hasNext())
 {
  QString file_path = it.next();
  QFile file(file_path);

  QFileInfo qfi(file_path);
  if(qfi.suffix() != "xml")
    continue;


  // Open file in text mode; skip files that can't be read (like binaries or permission-denied)
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    continue;
  }

  QTextStream in(&file);
  int lineNumber = 0;

  while (!in.atEnd())
  {
   lineNumber++;
   QString line = in.readLine();
   if (line.contains(pattern, cs))
   {
    results.append(file_path);
    break;
   }
  }
 }

 return results;
}

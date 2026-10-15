
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "asa-module.h"


#include <QDebug>

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(DCM2RO)

ASA_Module::ASA_Module()
 :  _Module_Base{"ASA"}
{

}

void ASA_Module::path_group_id_string_auto(QString id)
{
 path_group_ids_[current_paths_] = id;
 current_paths_.clear();
}

void ASA_Module::path_group_id(QVList<u2> paths)
{
 current_paths_ = paths;
}

void ASA_Module::path_id(u2 path)
{
 current_paths_ = {path};
}


void ASA_Module::path_id_string_auto(QString id)
{
 path_ids_[current_paths_.takeFirst()] = id;
}


void ASA_Module::load_svg_file(QString file_path)
{
 QFile file(file_path);
 if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
 {
  qDebug() << "SVG file error";
  return;
 }

 if (!the_svg_.setContent(&file))
   qDebug() << "XML parse error";

 file.close();
 return;
}


void ASA_Module::save_svg_file(QString file_path)
{
 save_file(file_path, the_svg_.toString());
}

void ASA_Module::prepare_svg_file()
{
 QDomNodeList paths = the_svg_.elementsByTagName("path");

 for(auto const& [path, id] : path_ids_.MAP_KV())
 {
  paths.item(path - 1).toElement().setAttribute("id", id);
 }

 for(auto const& [group, id] : path_group_ids_.MAP_KV())
 {
  QDomElement gnode = the_svg_.createElement("g");
  gnode.toElement().setAttribute("id", id);
  u2 path = group.first();
  paths.item(path - 1).parentNode().insertBefore(gnode, paths.item(path - 1));
  for(u2 i = 0;; path = group[i])
  {
   gnode.appendChild(paths.item(path - 1));
   if(++i == group.size())
     break;
  }
 }

}




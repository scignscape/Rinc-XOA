
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "asa-module.h"

#include "tsl/ordered_map.h"

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
 path_group_ids_and_glyphs_[current_paths_].push_front(id);
 current_paths_.clear();
}

void ASA_Module::path_group_glyphs(QVList<QString> glyphs)
{
 path_group_ids_and_glyphs_[current_paths_] = glyphs;
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

// //  google!
QDomElement findElementByTagAndId(const QDomDocument &doc, const QString &tagName, const QString &id)
{
 QDomNodeList list = doc.elementsByTagName(tagName);
 for (int i = 0; i < list.size(); ++i)
 {
  QDomElement el = list.at(i).toElement();
  if (el.attribute("id") == id)
    return el;
 }
 return QDomElement();
}

void ASA_Module::prepare_svg_file()
{
 QDomElement s1e = findElementByTagAndId(the_svg_, "g", "surface1");
 QDomNodeList paths = s1e.elementsByTagName("path");
 QDomNodeList gs = s1e.elementsByTagName("g");

 for(auto const& [path, id] : path_ids_.MAP_KV())
 {
  paths.item(path - 1).toElement().setAttribute("id", id);
 }

 tsl::ordered_map<QString, QDomNode> glyphs_as_children;

 for(auto& [group, glyphs] : path_group_ids_and_glyphs_.MAP_KV())
 {
  QString id = glyphs.takeFirst();
  QDomElement gnode = the_svg_.createElement("g");

  for(QString glyph_id: glyphs)
  {
   glyphs_as_children[glyph_id] = gnode;
  }

  gnode.toElement().setAttribute("id", id);
  u2 path = group.first();
  paths.item(path - 1).parentNode().insertBefore(gnode, paths.item(path - 1));
  for(u2 i = 0;; path = group[i])
  {
   gnode.appendChild(paths.item(path - 1));
   if(++i == group.size())
     break;
  }

  for(u2 i = 0; i < gs.length(); ++i)
  {
   QDomNode n = gs.item(i);
   QString xlh = n.toElement().attribute("xlink:href", "?").mid(1);
   if(xlh.isEmpty())
     continue;
   if(glyphs_as_children.contains(xlh))
   {
    glyphs_as_children[xlh].appendChild(n);
   }


  }

 }

}




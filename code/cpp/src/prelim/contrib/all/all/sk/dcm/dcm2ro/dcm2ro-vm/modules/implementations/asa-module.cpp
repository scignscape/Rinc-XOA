
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
 :  _Module_Base{"ASA"}, em_path_counts_(0), em_group_counts_(0)
{

}

void ASA_Module::path_group_id_string_auto(QString id)
{
 ++em_group_counts_;
 path_group_ids_and_glyphs_[current_paths_].push_front("%1-%2"_qt.arg(id).arg(em_group_counts_));
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
 ++em_path_counts_;
 path_ids_[current_paths_.takeFirst()] = "%1-%2"_qt.arg(id).arg(em_path_counts_);
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

void ASA_Module::load_html_template(QString file_path)
{
 html_template_ = load_file(file_path);
}

void ASA_Module::prepare_html_file()
{
 html_text_ = html_template_;

 QString event_listeners = "// //  Auto Generated \n";
 QString check_boxes = "\n\n<!-- Auto Generated -->\n";

 for(auto const& [id, region_or_label] : toggle_ids_)
 {
  event_listeners += "\nset_event_listener('toggle-%1','%1');"_qt.arg(id);

  check_boxes += "\n<label><input type='checkbox' id='toggle-%1' "
    "checked='true'><span>Hide</span> %2</label>"_qt.arg(id).arg(region_or_label);
 }

 html_text_.replace("%EVENT_LISTENERS%", event_listeners);
 html_text_.replace("%CHECK_BOXES%", check_boxes);
 html_text_.replace("%SVG%", the_svg_.toString());
}

void ASA_Module::save_html_file(QString file_path)
{
 save_file(file_path, html_text_);
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

 u2 label_counts;
 u2 region_counts;

 u2 first_region_index = 0;
 u2 first_label_index = 0;

 for(auto const& [path, id] : path_ids_.MAP_KV())
 {
  paths.item(path - 1).toElement().setAttribute("id", id);
  ++region_counts;
  if(region_counts == 1)
  {
   first_region_index = toggle_ids_.size();
   toggle_ids_.push_back({id, "Region"});
  }
  else if(region_counts == 2)
  {
   toggle_ids_.push_back({id, "Regions"});
   toggle_ids_[first_region_index].second = toggle_ids_[first_region_index].second + "s";
  }
  else
  {
   toggle_ids_.push_back({id, "Regions"});
  }
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

  ++label_counts;
  if(label_counts == 1)
  {
   first_region_index = toggle_ids_.size();
   toggle_ids_.push_back({id, "Label"});
  }
  else if(label_counts == 2)
  {
   toggle_ids_.push_back({id, "Labels"});
   toggle_ids_[first_label_index].second = toggle_ids_[first_label_index].second + "s";
  }
  else
  {
   toggle_ids_.push_back({id, "Labels"});
  }

  u2 path = group.first();
  paths.item(path - 1).parentNode().insertBefore(gnode, paths.item(path - 1));
  for(u2 i = 0;; path = group[i])
  {
   gnode.appendChild(paths.item(path - 1));
   if(++i == group.size())
     break;
  }
 }

 for(u2 i = 0; i < gs.length(); ++i)
 {
  QDomNode n = gs.item(i);
  QString xlh;
  QDomNodeList uses = n.toElement().elementsByTagName("use");

  for(u2 j = 0; j < uses.length(); ++j)
  {
   QDomElement use = uses.item(j).toElement();
   xlh = use.attribute("xlink:href"); //.mid(1);
   if(xlh.isEmpty())
     continue;
   xlh = xlh.mid(1);
   break;
  }
  if(xlh.isEmpty())
    continue;
  if(glyphs_as_children.contains(xlh))
  {
   glyphs_as_children[xlh].appendChild(n);
  }


 }


}




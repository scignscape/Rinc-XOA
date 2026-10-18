
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "asa-module.h"

#include "asa-module/asa-graphic-element.h"

#include "tsl/ordered_map.h"

#include <QDebug>

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(DCM2RO)

ASA_Module::ASA_Module()
 :  _Module_Base{"ASA"}, em_path_counts_(0), em_group_counts_(0), gel_counts_(0)
{

}

void ASA_Module::graphic_element_interpretation(QString ei)
{
 current_graphic_element_->set_interpretation(ei.split("|"));
}

void ASA_Module::graphic_element_characteristic(QString ec)
{
 element_characteritics_keys_.push_back(ec);
}


template<typename Type_for_QVariant>
void ASA_Module::_graphic_element_value(Type_for_QVariant v)
{
 current_graphic_element_->characteristic_values(element_characteritics_keys_, QVariant(v));
 element_characteritics_keys_.clear();
}

void ASA_Module::graphic_element_value_u1(u1 ev)
{
 _graphic_element_value(ev);
}

void ASA_Module::graphic_element_value_str(QString ev)
{
 _graphic_element_value(ev);
}

void ASA_Module::path_group_id_string_auto(QString id)
{
 ++em_group_counts_;
 current_graphic_element_->path_group_ids_and_glyphs()[current_paths_].push_front("%1-%2"_qt.arg(id).arg(em_group_counts_));
 current_paths_.clear();
}

void ASA_Module::path_group_glyphs(QVList<QString> glyphs)
{
 current_graphic_element_->path_group_ids_and_glyphs()[current_paths_] = glyphs;
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
 current_graphic_element_->path_ids()[current_paths_.takeFirst()] = "%1-%2"_qt.arg(id).arg(em_path_counts_);
}

void ASA_Module::gel_id_string_auto(QString id)
{
 ++gel_counts_;
 current_graphic_element_->set_svg_id("%1-%2"_qt.arg(id).arg(gel_counts_));
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

// :characteristic $ internalStructure ;.
// :value-str $ soft-tissue ;.
// :characteristic $ calcification ;.
// :value-u1 1# 6 ;.
// :characteristic $ sphericity ;.
// :value-u1 1# 5 ;.
// :characteristic $ margin ;.
// :value-u1 1# 5 ;.
// :characteristic $ lobulation ;.
// :value-u1 1# 5 ;.
// :characteristic $ spiculation ;.
// :value-u1 1# 5 ;.
// :characteristic $ texture ;.
// :value-u1 1# 5 ;.
// :characteristic $ malignancy ;.
// :value-u1 1# 5 ;.

 QString event_listeners = "// //  Auto Generated \n";
 QString check_boxes = "<!-- Auto Generated -->";
 static QString graphic_data = R"(

<!-- Graphic %1 data -->
<p><details><summary>Graphic #%1:</summary>
<dl>
<dt><span>Internal Structure</span></dt>
<dd>%2</dd>
<dt><span>Calcification</span></dt>
<dd>%3</dd>
<dt><span>Sphericity</span></dt>
<dd>%4</dd>
<dt><span>Margin</span></dt>
<dd>%5</dd>
<dt><span>Lobulation</span></dt>
<dd>%6</dd>
<dt><span>Spiculation</span></dt>
<dd>%7</dd>
<dt><span>Texture</span></dt>
<dd>%8</dd>
<dt><span>Malignancy</span></dt>
<dd>%9</dd>
</dl>
 )";

 static QVariant missing = QVariant("?");


 for(ASA_Graphic_Element* gel : graphic_elements_)
 {
  check_boxes += graphic_data.arg(gel->index_in_document()) // // 1
    .arg(gel->get_characteristic("internalStructure", missing).toString()) // // 2
    .arg(gel->get_characteristic("calcification", missing).toString()) // // 3
    .arg(gel->get_characteristic("sphericity", missing).toString()) // // 4
    .arg(gel->get_characteristic("margin", missing).toString()) // // 5
    .arg(gel->get_characteristic("lobulation", missing).toString()) // // 6
    .arg(gel->get_characteristic("spiculation", missing).toString()) // // 7
    .arg(gel->get_characteristic("texture", missing).toString()) // // 8
    .arg(gel->get_characteristic("malignancy", missing).toString()) // // 9
  ;

  check_boxes += "<div style='margin-bottom:10pt;border-bottom:ridge cyan 3pt'>";

  for(auto const& [id, element_kind] : gel->toggle_ids())
  {
   event_listeners += "\nset_event_listener('toggle-%1','%1');"_qt.arg(id);

   check_boxes += "\n<label><input type='checkbox' id='toggle-%1' "
     "checked='true'><span>Hide</span> %2</label>"_qt.arg(id).arg(element_kind);
  }

  check_boxes += "\n</div></details></p>";
 }

 html_text_.replace("%EVENT_LISTENERS%", event_listeners);
 html_text_.replace("%CHECK_BOXES%", check_boxes);
 html_text_.replace("%SVG%", the_svg_.toString());

}

void ASA_Module::new_graphic_element()
{
 current_graphic_element_ = new ASA_Graphic_Element;
}

void ASA_Module::finalize_graphic_element()
{
 graphic_elements_.push_back(current_graphic_element_);
 current_graphic_element_->set_index_in_document(graphic_elements_.size());
 current_graphic_element_ = nullptr;
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

 tsl::ordered_map<QString, QDomNode> glyphs_as_children;

 for(ASA_Graphic_Element* gel : graphic_elements_)
 {
  u2 label_counts = 0;
  u2 region_counts = 0;

  u2 first_region_index = 0;
  u2 first_label_index = 0;

  QDomElement gel_el = the_svg_.createElement("g");
  gel_el.setAttribute("id", gel->svg_id());
  gel->toggle_ids().push_back({gel->svg_id(), "Graphic"});


  for(auto const& [path, id] : gel->path_ids().MAP_KV())
  {
   paths.item(path - 1).toElement().setAttribute("id", id);
   ++region_counts;
   if(region_counts == 1)
   {
    paths.item(path - 1).parentNode().insertBefore(gel_el, paths.item(path - 1));
    gel_el.appendChild(paths.item(path - 1));

    first_region_index = gel->toggle_ids().size();
    gel->toggle_ids().push_back({id, "Region"});
   }
   else if(region_counts == 2)
   {
    gel->toggle_ids().push_back({id, "Regions"});
    gel->toggle_ids()[first_region_index].second = gel->toggle_ids()[first_region_index].second + "s";
   }
   else
   {
    gel->toggle_ids().push_back({id, "Regions"});
   }
  }

  for(auto& [group, glyphs] : gel->path_group_ids_and_glyphs().MAP_KV())
  {
   QString id = glyphs.takeFirst();
   QDomElement ginner = the_svg_.createElement("g");

   for(QString glyph_id: glyphs)
   {
    glyphs_as_children[glyph_id] = ginner;
   }

   ginner.setAttribute("id", id);

   ++label_counts;
   if(label_counts == 1)
   {
    first_label_index = gel->toggle_ids().size();
    gel->toggle_ids().push_back({id, "Label"});
   }
   else if(label_counts == 2)
   {
    gel->toggle_ids().push_back({id, "Labels"});
    gel->toggle_ids()[first_label_index].second = gel->toggle_ids()[first_label_index].second + "s";
   }
   else
   {
    gel->toggle_ids().push_back({id, "Labels"});
   }

   u2 path = group.first();
   gel_el.appendChild(ginner);
//?   paths.item(path - 1).parentNode().insertBefore(ginner, paths.item(path - 1));
   for(u2 i = 0;; path = group[i])
   {
    ginner.appendChild(paths.item(path - 1));
    if(++i == group.size())
      break;
   }
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




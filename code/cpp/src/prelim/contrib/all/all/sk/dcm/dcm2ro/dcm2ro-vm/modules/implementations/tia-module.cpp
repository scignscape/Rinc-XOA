
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#include "tia-module.h"

#include "tia-module/tia-compound-graphic.h"
#include "tia-module/tia-graphic-fill-style.h"
#include "tia-module/tia-graphic-layer.h"
#include "tia-module/tia-fill-pattern.h"
#include "tia-module/tia-graphic-element.h"

#include <bit>

#include <QDebug>

#include "textio.h"

USING_KANS(TextIO)

USING_OTNS(DCM2RO)

TIA_Module::TIA_Module()
 :  _Module_Base{"TIA"}, current_graphic_element_(nullptr)
{

}


void TIA_Module::load_base_file(QString path)
{
 base_file_path_ = path;
}

void TIA_Module::graphic_element_interpretation(QString ei)
{
 current_graphic_element_->set_interpretation(ei.split("|"));
}

void TIA_Module::graphic_element_characteristic(QString ec)
{
 element_characteritics_keys_.push_back(ec);
}


void TIA_Module::graphic_element_value_u1(u1 ev)
{
 current_graphic_element_->characteristic_values(element_characteritics_keys_, QVariant(ev));
 element_characteritics_keys_.clear();
}


void TIA_Module::new_graphic_element()
{
 current_graphic_element_ = new TIA_Graphic_Element;
}

void TIA_Module::finalize_graphic_element()
{

}


void TIA_Module::point_xy(u4 x, u4 y)
{
 points_xy_.push_back({x, y});
}





void TIA_Module::new_fill_pattern()
{
 TIA_Fill_Pattern* tfp = new TIA_Fill_Pattern;
}

void TIA_Module::finalize_fill_pattern()
{

}

void TIA_Module::new_graphic_layer()
{
 TIA_Graphic_Layer* tgl = new TIA_Graphic_Layer;
}

void TIA_Module::finalize_graphic_layer()
{

}

void TIA_Module::new_graphic_fill_style()
{
 TIA_Graphic_Fill_Style* tgfs = new TIA_Graphic_Fill_Style;
}

void TIA_Module::finalize_graphic_fill_style()
{

}

void TIA_Module::new_compound_graphic()
{
 TIA_Compound_Graphic* tgc = new TIA_Compound_Graphic;
}

void TIA_Module::finalize_compound_graphic()
{

}


void TIA_Module::load_tikz_template(QString file_path)
{

}

void TIA_Module::save_tikz_file(QString file_path)
{

}

void TIA_Module::fill_pattern_mode(QString mode)
{

}

void TIA_Module::compound_graphic_tick_details(QString details)
{

}

void TIA_Module::compound_graphic_units(QString units)
{

}

void TIA_Module::compound_graphic_type(QString type)
{

}

void TIA_Module::spatial_rotation(QString rotation)
{

}

void TIA_Module::graphic_layer_strid(QString id)
{

}

void TIA_Module::graphic_layer_description(QString description)
{

}


void TIA_Module::point_group()
{

}

void TIA_Module::point_graphic()
{

}

void TIA_Module::polyline_graphic()
{

}

void TIA_Module::interpolated_graphic()
{

}

void TIA_Module::circle_graphic()
{

}

void TIA_Module::ellipse_graphic()
{

}

void TIA_Module::graphic_filled_yes()
{

}

void TIA_Module::graphic_filled_no()
{

}

void TIA_Module::graphic_fill_style_pattern_on_color()
{

}

void TIA_Module::graphic_fill_style_pattern_off_color()
{

}

void TIA_Module::compound_graphic_rotation_point()
{

}

void TIA_Module::graphic_layer_recommended_cielab()
{

}

void TIA_Module::graphic_layer_recommended_grayscale(u2 intensity)
{

}

void TIA_Module::size_d1(u4 length)
{

}

void TIA_Module::size_wh(u4 width, u4 height)
{

}


void TIA_Module::fill_pattern_mask(u4 v1, u4 v2, u4 v3, u4 v4)
{

}


void TIA_Module::compound_graphic_gap_length(r4 length)
{

}

void TIA_Module::compound_graphic_diameter_of_visibility(r4 diameter)
{

}


void TIA_Module::fill_pattern_on_off_opacity(r4 on, r4 off)
{

}


void TIA_Module::compound_graphic_group_id(n8 id)
{

}


void TIA_Module::color_cielab(r4 l, r4 a, r4 b)
{

}

void TIA_Module::color_pcs(u2 l, u2 a, u2 b)
{

}




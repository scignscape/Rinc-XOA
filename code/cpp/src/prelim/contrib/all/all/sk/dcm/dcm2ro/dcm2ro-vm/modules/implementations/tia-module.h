
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef TIA_MODULE__H
#define TIA_MODULE__H

#include <QTextStream>

#include "global-types.h"

#include "accessors.h"

#include "vm-reader.h"
#include "vm-opstatement.h"

#include "../module-base.h"

#include "otns.h"

OTNS_(DCM2RO)

//class TIA_Compound_Graphic;
//class TIA_Fill_Pattern;
//class TIA_Graphic_Layer;
//class TIA_Graphic_Fill_Style;


class TIA_Module : public _Module_Base
{

public:

 TIA_Module();

 void new_compound_graphic();
 void finalize_compound_graphic();


 void new_fill_pattern();
 void finalize_fill_pattern();

 void new_graphic_layer();
 void finalize_graphic_layer();

 void new_graphic_fill_style();
 void finalize_graphic_fill_style();


 void load_tikz_template(QString file_path);
 void save_tikz_file(QString file_path);
 void fill_pattern_mode(QString mode);
 void compound_graphic_tick_details(QString details);
 void compound_graphic_units(QString units);
 void compound_graphic_type(QString type);
 void spatial_rotation(QString rotation);
 void graphic_layer_strid(QString id);
 void graphic_layer_description(QString description);

 void point_group();
 void point_graphic();
 void polyline_graphic();
 void interpolated_graphic();
 void circle_graphic();
 void ellipse_graphic();
 void graphic_filled_yes();
 void graphic_filled_no();
 void graphic_fill_style_pattern_on_color();
 void graphic_fill_style_pattern_off_color();
 void compound_graphic_rotation_point();
 void graphic_layer_recommended_cielab();
 void graphic_layer_recommended_grayscale(u2 intensity);
 void size_d1(u4 length);
 void size_wh(u4 width, u4 height);
 void point_xy(u4 x, u4 y);
 void fill_pattern_mask(u4 v1, u4 v2, u4 v3, u4 v4);

 void compound_graphic_gap_length(r4 length);
 void compound_graphic_diameter_of_visibility(r4 diameter);

//{"tia-compound-graphic:gap-length", (methods_R4x1) &TIA_Module::compound_graphic_gap_length},
//{"tia-compound-graphic:diameter-of-visibility", (methods_R4x1) &TIA_Module::compound_graphic_diameter_of_visibility},


 void fill_pattern_on_off_opacity(r4 on, r4 off);

 void compound_graphic_group_id(n8 id);

 void color_cielab(r4 l, r4 a, r4 b);
 void color_pcs(u2 l, u2 a, u2 b);

//{"tia-fill-pattern:on-off-opacity", (methods_U4x2) &TIA_Module::fill_pattern_on_off_opacity},

//#elif METHODS_N8x1
//{"tia-compound-graphic:group-id", (methods_String) &TIA_Module::compound_graphic_group_id},


//#elif METHODS_R8x3
//{"tia-color-cielab", (methods_R4x3) &TIA_Module::color_cielab},


#if METHODS_Empty
{"tia-point-group", (methods_x0) &TIA_Module::point_group},
{"tia-point-graphic", (methods_x0) &TIA_Module::point_graphic},
{"tia-polyline-graphic", (methods_x0) &TIA_Module::polyline_graphic},
{"tia-interpolated-graphic", (methods_x0) &TIA_Module::interpolated_graphic},
{"tia-circle-graphic", (methods_x0) &TIA_Module::circle_graphic},
{"tia-ellipse-graphic", (methods_x0) &TIA_Module::ellipse_graphic},
{"tia-graphic-filled:yes", (methods_x0) &TIA_Module::graphic_filled_yes},
{"tia-graphic-filled:no", (methods_x0) &TIA_Module::graphic_filled_no},
{"tia-graphic-fill-style:pattern-on-color", (methods_x0) &TIA_Module::graphic_fill_style_pattern_on_color},
{"tia-graphic-fill-style:pattern-off-color", (methods_x0) &TIA_Module::graphic_fill_style_pattern_off_color},
{"tia-compound-graphic:rotation-point", (methods_x0) &TIA_Module::compound_graphic_rotation_point},
{"tia-graphic-layer:recommended-cielab", (methods_x0) &TIA_Module::graphic_layer_recommended_cielab},


  //{"tia-fill-pattern:mode", (methods_String) &TIA_Module::fill_pattern_mode},
  //{"tia-compound-graphic:tick-details", (methods_String) &TIA_Module::compound_graphic_tick_details},
  // {"tia-compound-graphic:units", (methods_String) &TIA_Module::compound_graphic_units},
  //{"tia-compound-graphic:type", (methods_String) &TIA_Module::compound_graphic_type},
  // //  H0, H90, H180, H270, N0, N90, N180, N270 -- H = horizontal flip
  //{"tia-spatial-rotation", (methods_String) &TIA_Module::spatial_rotation},
  //{"tia-graphic-layer:strid", (methods_String) &TIA_Module::graphic_layer_strid},
  //{"tia-graphic-layer:description", (methods_String) &TIA_Module::graphic_layer_description},

#elif METHODS_Empty
{"tia-point-group", (methods_x0) &TIA_Module::point_group},
{"tia-point-graphic", (methods_x0) &TIA_Module::point_graphic},
{"tia-polyline-graphic", (methods_x0) &TIA_Module::polyline_graphic},
{"tia-interpolated-graphic", (methods_x0) &TIA_Module::interpolated_graphic},
{"tia-circle-graphic", (methods_x0) &TIA_Module::circle_graphic},
{"tia-ellipse-graphic", (methods_x0) &TIA_Module::ellipse_graphic},
{"tia-graphic-filled:yes", (methods_x0) &TIA_Module::graphic_filled_yes},
{"tia-graphic-filled:no", (methods_x0) &TIA_Module::graphic_filled_no},
{"tia-graphic-fill-style:pattern-on-color", (methods_x0) &TIA_Module::graphic_fill_style_pattern_on_color},
{"tia-graphic-fill-style:pattern-off-color", (methods_x0) &TIA_Module::graphic_fill_style_pattern_off_color},
{"tia-compound-graphic:rotation-point", (methods_x0) &TIA_Module::compound_graphic_rotation_point},
{"tia-graphic-layer:recommended-cielab", (methods_x0) &TIA_Module::graphic_layer_recommended_cielab},

#elif METHODS_U2x1
{"tia-graphic-layer:recommended-grayscale", (methods_U2x1) &TIA_Module::graphic_layer_recommended_grayscale},

#elif METHODS_U4x1
{"tia-size-d1", (methods_U4x1) &TIA_Module::size_d1},
{"tia-fill-pattern:mask", (methods_R4x1) &TIA_Module::fill_pattern_mask},

#elif METHODS_U4x2
{"tia-point-xy", (methods_U4x2) &TIA_Module::point_xy},
{"tia-size-wh", (methods_U4x2) &TIA_Module::size_wh},

#elif METHODS_R4x1
{"tia-compound-graphic:gap-length", (methods_R4x1) &TIA_Module::compound_graphic_gap_length},
{"tia-compound-graphic:diameter-of-visibility", (methods_R4x1) &TIA_Module::compound_graphic_diameter_of_visibility},

#elif METHODS_R4x2
{"tia-fill-pattern:on-off-opacity", (methods_U4x2) &TIA_Module::fill_pattern_on_off_opacity},

#elif METHODS_N8x1
{"tia-compound-graphic:group-id", (methods_String) &TIA_Module::compound_graphic_group_id},


#elif METHODS_R8x3
{"tia-color-cielab", (methods_R4x3) &TIA_Module::color_cielab},

#endif


};


_OTNS(DCM2RO)

#endif // TIA_MODULE__H

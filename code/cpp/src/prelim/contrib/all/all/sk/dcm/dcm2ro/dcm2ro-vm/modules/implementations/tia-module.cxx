
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#if METHODS_String
   {"tia-load-tikz-template", (methods_String) &TIA_Module::load_tikz_template},
   {"tia-save-tikz-file", (methods_String) &TIA_Module::save_tikz_file},
   {"tia-fill-pattern:mode", (methods_String) &TIA_Module::fill_pattern_mode},
   {"tia-compound-graphic:tick-details", (methods_String) &TIA_Module::compound_graphic_tick_details},
   {"tia-compound-graphic:units", (methods_String) &TIA_Module::compound_graphic_units},
   {"tia-compound-graphic:type", (methods_String) &TIA_Module::compound_graphic_type},
   // //  H0, H90, H180, H270, N0, N90, N180, N270 -- H = horizontal flip
   {"tia-spatial-rotation", (methods_String) &TIA_Module::spatial_rotation},
   {"tia-graphic-layer:strid", (methods_String) &TIA_Module::graphic_layer_strid},
   {"tia-graphic-layer:description", (methods_String) &TIA_Module::graphic_layer_description},

#elif METHODS_Empty

   {"tia-new-compound-graphic", (methods_x0) &TIA_Module::new_compound_graphic},
   {"tia-finalize-compound-graphic", (methods_x0) &TIA_Module::finalize_compound_graphic},

   {"tia-new-fill-pattern", (methods_x0) &TIA_Module::new_fill_pattern},
   {"tia-finalize-fill-pattern", (methods_x0) &TIA_Module::finalize_fill_pattern},

   {"tia-new-graphic-layer", (methods_x0) &TIA_Module::new_graphic_layer},
   {"tia-finalize-graphic-layer", (methods_x0) &TIA_Module::finalize_graphic_layer},

   {"tia-new-graphic-fill-style", (methods_x0) &TIA_Module::new_graphic_fill_style},
   {"tia-finalize-graphic-fill-style", (methods_x0) &TIA_Module::finalize_graphic_fill_style},

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

#elif METHODS_U4x2
   {"tia-point-xy", (methods_U4x2) &TIA_Module::point_xy},
   {"tia-size-wh", (methods_U4x2) &TIA_Module::size_wh},

#elif METHODS_U4x4
   {"tia-fill-pattern:mask", (methods_U4x4) &TIA_Module::fill_pattern_mask},

#elif METHODS_R4x1
   {"tia-compound-graphic:gap-length", (methods_R4x1) &TIA_Module::compound_graphic_gap_length},
   {"tia-compound-graphic:diameter-of-visibility", (methods_R4x1) &TIA_Module::compound_graphic_diameter_of_visibility},

#elif METHODS_R4x2
   {"tia-fill-pattern:on-off-opacity", (methods_R4x2) &TIA_Module::fill_pattern_on_off_opacity},

#elif METHODS_N8x1
   {"tia-compound-graphic:group-id", (methods_N8x1) &TIA_Module::compound_graphic_group_id},

#elif METHODS_U2x3
   {"tia-color-pcs", (methods_U2x3) &TIA_Module::color_pcs},

#elif METHODS_R4x3
   {"tia-color-cielab", (methods_R4x3) &TIA_Module::color_cielab},

#endif





//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)




//asa-path-id 2# 1 ;.
//asa-path-id-string-auto $ em-node ;.

//asa-path-group-id 2## 2 3 ;.
//asa-path-group-id-string-auto $ em-node ;.



//asa-save-svg-file $ /home/nlevisrael/gits/pnp-dev/rinc-xoa/RedPatch/dev/dcm2ro/tikz/ia.svg ;.


#if METHODS_String
   {"asa-load-svg-file", (methods_String) &ASA_Module::load_svg_file},
   {"asa-save-svg-file", (methods_String) &ASA_Module::save_svg_file},
   {"asa-path-id-string-auto", (methods_String) &ASA_Module::path_id_string_auto},
   {"asa-path-group-id-string-auto", (methods_String) &ASA_Module::path_group_id_string_auto},

#elif METHODS_Empty
   {"asa-prepare-svg-file", (methods_U2x1) &ASA_Module::prepare_svg_file},

#elif METHODS_U2x1
   {"asa-path-id", (methods_U2x1) &ASA_Module::path_id},

#elif METHODS_U2xL
   {"asa-path-group-id", (methods_U2xL) &ASA_Module::path_group_id},


#elif METHODS_U4x1

#elif METHODS_U4x2

#elif METHODS_R4x1

#elif METHODS_R4x2

#elif METHODS_N4x4

#elif METHODS_N8x1

#elif METHODS_R8x3

#endif




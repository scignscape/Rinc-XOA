
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#if METHODS_String
   {"rcs-file-name-shortcut", (methods_String) &RCS_Module::file_name_shortcut},
   {"rcs-first-name", (methods_String) &RCS_Module::first_name},
   {"rcs-last-name", (methods_String) &RCS_Module::last_name},
#elif METHODS_StringList
   {"rcs-add-manifest-uris", (methods_StringList) &RCS_Module::add_manifest_uris},
#elif METHODS_Empty
   {"rcs-single-author", (methods_x0) &RCS_Module::single_author},
#elif METHODS_R8x1
   {"rcs-global-baseline-skip", (methods_R8x1) &RCS_Module::global_baseline_skip},
#endif




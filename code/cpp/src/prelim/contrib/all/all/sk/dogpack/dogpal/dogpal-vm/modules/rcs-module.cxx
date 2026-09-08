
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#if METHODS_String
   {"file-name-shortcut", (methods_String) &RCS_Module::file_name_shortcut},
   {"first-name", (methods_String) &TAO_Module::first_name},
   {"last-name", (methods_String) &TAO_Module::last_name},
#elif METHODS_StringList
   {"rcs-add-manifest-uris", (methods_StringList) &RCS_Module::add_manifest_uris},
#elif METHODS_x0
   {"rcs-single-author", (methods_StringList) &RCS_Module::single_author},
#endif




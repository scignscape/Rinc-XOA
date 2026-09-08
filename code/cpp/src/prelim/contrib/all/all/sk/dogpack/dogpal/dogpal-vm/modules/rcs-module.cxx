
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#if METHODS_String
   {"tao-leave-element", (methods_String) &TAO_Module::leave_element},
   {"tao-primary-acc-cached", (methods_String) &TAO_Module::primary_acc},
   {"tao-primary-acc", (methods_String) &TAO_Module::primary_acc},
   {"tao-end-sentence", (methods_String) &TAO_Module::end_sentence},
   {"tao-restrict-to-layer", (methods_String) &TAO_Module::restrict_to_layer},
   {"tao-unrestrict-from-layer", (methods_String) &TAO_Module::restrict_to_layer},
#elif METHODS_StringList


#elif METHODS_x0
   {"leave-subparagraph-with-continue", (methods_String) &TAO_Module::leave_subparagraph_with_continue},
#elif METHODS_U4x1
#elif METHODS_N8x1
{"tao-primary-acc-spaces", (methods_N8x1) &TAO_Module::primary_acc_spaces},
#elif METHODS_U2x2
{"tao-tpos", (methods_U2x2) &TAO_Module::tpos},
#endif




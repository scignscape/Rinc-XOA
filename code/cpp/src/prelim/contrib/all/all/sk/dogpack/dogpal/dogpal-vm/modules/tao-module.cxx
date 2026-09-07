
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#ifdef METHOD_String

   {"tao-leave-element", (methods_String) &TAO_Module::leave_element},
   {"tao-primary-acc-cached", (methods_String) &TAO_Module::primary_acc},
   {"tao-primary-acc", (methods_String) &TAO_Module::primary_acc},
   {"tao-end-sentence", (methods_String) &TAO_Module::end_sentence},
   {"tao-restrict-to-layer", (methods_String) &TAO_Module::restrict_to_layer},
   {"tao-unrestrict-from-layer", (methods_String) &TAO_Module::restrict_to_layer},

#endif // METHOD_String


// ------------------


#ifdef METHOD_x0

   {"leave-subparagraph-with-continue", (methods_String) &TAO_Module::leave_subparagraph_with_continue},

#endif // METHOD_x0


// ------------------


#ifdef METHOD_U4x1


#endif // METHOD_U4x1


// ------------------


#ifdef METHOD_N8x1

{"tao-primary-acc-spaces", (methods_N8x1) &TAO_Module::primary_acc_spaces},

#endif // METHOD_N8x1


// ------------------


#ifdef METHOD_U4x4


#endif // METHOD_U4x4



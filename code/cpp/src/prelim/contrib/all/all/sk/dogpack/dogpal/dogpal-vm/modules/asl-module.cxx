
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#if METHODS_String
   {"sdi-sentence-end-punctuation", (methods_String) &SDI_Module::sentence_end_punctuation},
   {"sdi-sentence-text", (methods_String) &SDI_Module::sentence_text},
#elif METHODS_x0
#elif METHODS_U4x1
   {"sdi-new-sentence", (methods_U4x1) &SDI_Module::new_sentence},
#elif METHODS_U4x4
   {"sdi-sentence-end-pos", (methods_U4x4) &SDI_Module::sentence_end_pos},
   {"sdi-sentence--end-pos", (methods_U4x4) &SDI_Module::sentence__end_pos},
   {"sdi-sentence-switch-pos", (methods_U4x4) &SDI_Module::sentence_switch_pos},

#endif



#ifdef METHOD_String

   {"sdi-sentence-end-punctuation", (methods_String) &SDI_Module::sentence_end_punctuation},
   {"sdi-sentence-text", (methods_String) &SDI_Module::sentence_text},

#endif // METHOD_String


// ------------------


#ifdef METHOD_x0


#endif // METHOD_x0


// ------------------


#ifdef METHOD_U4x1

   {"sdi-new-sentence", (methods_U4x1) &SDI_Module::new_sentence}

#endif // METHOD_U4x1


// ------------------


#ifdef METHOD_U4x4

   {"sdi-sentence-end-pos", (methods_U4x4) &SDI_Module::sentence_end_pos},
   {"sdi-sentence--end-pos", (methods_U4x4) &SDI_Module::sentence__end_pos},
   {"sdi-sentence-switch-pos", (methods_U4x4) &SDI_Module::sentence_switch_pos},

#endif // METHOD_U4x4



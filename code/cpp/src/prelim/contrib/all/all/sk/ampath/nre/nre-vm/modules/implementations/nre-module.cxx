
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#if METHODS_String
   {"nre-save-header-file", (methods_String) &NRE_Module::save_header_file},
   {"nre-save-implementation-file", (methods_String) &NRE_Module::save_implementation_file},
   {"nre-set-current-class-name", (methods_String) &NRE_Module::set_current_class_name},
   {"nre-form:processor", (methods_String) &NRE_Module::form_processor},
   {"nre-form:uuid", (methods_String) &NRE_Module::form_uuid},
   {"nre-page:label", (methods_String) &NRE_Module::page_label},
   {"nre-section:label", (methods_String) &NRE_Module::section_label},
   {"nre-question:label", (methods_String) &NRE_Module::question_label},
   {"nre-question:type", (methods_String) &NRE_Module::question_type},
   {"nre-question:concept", (methods_String) &NRE_Module::question_concept},
   {"nre-question:rendering", (methods_String) &NRE_Module::question_rendering},
   {"nre-question:default", (methods_String) &NRE_Module::question_default},
   {"nre-answer:label", (methods_String) &NRE_Module::answer_label},
   {"nre-answer:concept", (methods_String) &NRE_Module::answer_concept},
#elif METHODS_Empty
   {"nre-write-class-header-lead", (methods_x0) &NRE_Module::write_class_header_lead},
   {"nre-write-class-implementation-lead", (methods_x0) &NRE_Module::write_class_implementation_lead},
   {"nre-new-form", (methods_x0) &NRE_Module::new_form},
   {"nre-finalize-form", (methods_x0) &NRE_Module::finalize_form},
   {"nre-new-page", (methods_x0) &NRE_Module::new_page},
   {"nre-finalize-page", (methods_x0) &NRE_Module::finalize_page},
   {"nre-new-section", (methods_x0) &NRE_Module::new_section},
   {"nre-finalize-section", (methods_x0) &NRE_Module::finalize_section},
   {"nre-new-question", (methods_x0) &NRE_Module::new_question},
   {"nre-finalize-question", (methods_x0) &NRE_Module::finalize_question},
   {"nre-question:required?-f", (methods_x0) &NRE_Module::question_unset_required},
   {"nre-new-answer", (methods_x0) &NRE_Module::new_answer},
   {"nre-finalize-answer", (methods_x0) &NRE_Module::finalize_answer},
   {"nre-answer:yes", (methods_x0) &NRE_Module::answer_yes},
   {"nre-answer:no", (methods_x0) &NRE_Module::answer_no},
#elif METHODS_U2x1
   {"nre-form:version", (methods_U2x1) &NRE_Module::form_version},
#elif METHODS_R8x1

#endif




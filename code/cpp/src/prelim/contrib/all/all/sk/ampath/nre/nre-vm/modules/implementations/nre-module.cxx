
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#if METHODS_String
   {"nre-aux--b", (methods_String) &NRE_Module::aux_B},
#elif METHODS_Empty
   {"nre-dim-pt", (methods_x0) &NRE_Module::dim_pt},
#elif METHODS_U4x1
   {"nre-aux--p", (methods_U4x1) &NRE_Module::aux_P},
   {"nre-aux--h", (methods_U4x1) &NRE_Module::aux_H},
   {"nre-aux-sp", (methods_U4x1) &NRE_Module::aux_sp},
   {"nre-aux-sh", (methods_U4x1) &NRE_Module::aux_sh},
   {"nre-aux-id", (methods_U4x1) &NRE_Module::aux_id},
#elif METHODS_R8x1
   {"nre-global-baseline-skip", (methods_R8x1) &NRE_Module::global_baseline_skip},
   {"nre-global-baseline-stretch", (methods_R8x1) &NRE_Module::global_baseline_stretch},


#endif




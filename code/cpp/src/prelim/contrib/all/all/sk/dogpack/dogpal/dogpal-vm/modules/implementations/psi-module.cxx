
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#if METHODS_String
   {"psi-aux--b", (methods_String) &PSI_Module::aux_B},
#elif METHODS_Empty
   {"psi-dim-pt", (methods_x0) &PSI_Module::dim_pt},
#elif METHODS_U4x1
   {"psi-aux--p", (methods_U4x1) &PSI_Module::aux_P},
   {"psi-aux--h", (methods_U4x1) &PSI_Module::aux_H},
   {"psi-aux-sp", (methods_U4x1) &PSI_Module::aux_sp},
   {"psi-aux-sh", (methods_U4x1) &PSI_Module::aux_sh},
   {"psi-aux-id", (methods_U4x1) &PSI_Module::aux_id},
#elif METHODS_R8x1
   {"psi-global-baseline-skip", (methods_R8x1) &PSI_Module::global_baseline_skip},
   {"psi-global-baseline-stretch", (methods_R8x1) &PSI_Module::global_baseline_stretch},


#endif




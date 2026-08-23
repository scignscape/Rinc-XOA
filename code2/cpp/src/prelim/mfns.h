
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef MFNS__H
#define MFNS__H



// // this is defined by default;
 //   for most cases it should stay so...
 //   Should be defined via compiler flag by qmake.
 //   If that is edited from the project files
 //   uncomment this as needed ...
 //   #define USE_MFNS

#ifdef USE_MFNS

#define MFNS_(X) \
 namespace MFq { namespace X {

#define _MFNS(X) \
 } }


#define MFNS_CLASS_DECLARE(X ,C) \
 namespace MFq { namespace X { class C; } }



#define USING_MFNS(x) \
 using namespace MFq::x;


#else

#define MFNS_(X) \

#define _MFNS(X) \

#define USING_MFNS(x) \

#define MFNS_CLASS_DECLARE(X ,C) \
  class C;

#endif


#endif //MFNS__H


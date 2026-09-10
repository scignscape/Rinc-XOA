
//           Copyright Nathaniel Christen 2026.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef MODULE_MACROS__H
#define MODULE_MACROS__H


#define MODULE_LIST_PAIRED(X) MODULE_LIST(X, PAIRED)
#define MODULE_LIST_UC(X) MODULE_LIST(X, ODDS)
#define MODULE_LIST_LC(X) MODULE_LIST(X, EVENS)
#define MODULE_LIST_LC_INDEXED(X) MODULE_LIST(X, EVENS_INDEXED)

#define MODULE_LIST_LC_GET1(X) MODULE_LIST(X, EVENS_GET1)
#define MODULE_LIST_LC_GET2(X) MODULE_LIST(X, EVENS_GET2)
#define MODULE_LIST_LC_GET3(X) MODULE_LIST(X, EVENS_GET3)
#define MODULE_LIST_LC_GET4(X) MODULE_LIST(X, EVENS_GET4)
#define MODULE_LIST_LC_GET5(X) MODULE_LIST(X, EVENS_GET5)
#define MODULE_LIST_LC_GET6(X) MODULE_LIST(X, EVENS_GET6)



#endif MODULE_MACROS__H



//          Copyright Nathaniel Christen 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef unless
#define unless(x) if(!(x))
#endif

#ifndef block_init_2
#define block_init_2(x, y) x = [&]() ->decltype(x) {decltype(x) y;
#endif

#ifndef block_init_1
#define block_init_1(x) x = [&]() ->decltype(x) {decltype(x) _;
#endif

#ifndef block_init
#define block_init(...) _preproc_CONCAT(block_init_, _preproc_NUM_ARGS(__VA_ARGS__))(__VA_ARGS__)
#endif


#ifndef block_result_
#define block_result_(x) return x; }();
#endif

#ifndef block_result
#define block_result return _; }();
#endif

#include "preproc-concat.h"

#define MACRO_EXPAND_1(X, a1) X(a1)
#define MACRO_EXPAND_2(X, a1, a2) X(a1) X(a2)
#define MACRO_EXPAND_3(X, a1, a2, a3) X(a1) X(a2) X(a3)
#define MACRO_EXPAND_4(X, a1, a2, a3, a4) X(a1) X(a2) X(a3) X(a4)
#define MACRO_EXPAND_5(X, a1, a2, a3, a4, a5) X(a1) X(a2) X(a3) X(a4) X(a5)
#define MACRO_EXPAND_6(X, a1, a2, a3, a4, a5, a6) X(a1) X(a2) X(a3) X(a4) X(a5) X(a6)
#define MACRO_EXPAND_7(X, a1, a2, a3, a4, a5, a6, a7) X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7)
#define MACRO_EXPAND_8(X, a1, a2, a3, a4, a5, a6, a7, a8) X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8)

#define MACRO_EXPAND_9(X, a1, a2, a3, a4, a5, a6, a7, a8, a9) \
   X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8) X(a9)

#define MACRO_EXPAND_10(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
   X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8) X(a9) X(a10)

#define MACRO_EXPAND_11(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) \
   X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8) X(a9) X(a10) X(a11)

#define MACRO_EXPAND_12(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) \
   X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8) X(a9) X(a10) X(a11) x(a12)

#define MACRO_EXPAND_13(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13) \
   X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8) X(a9) X(a10) X(a11) x(a12) x(a13)

#define MACRO_EXPAND_14(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) \
   X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8) X(a9) X(a10) X(a11) x(a12) x(a13) x(a14)

#define MACRO_EXPAND_15(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15) \
   X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8) X(a9) X(a10) X(a11) x(a12) x(a13) x(a14) x(a15)

#define MACRO_EXPAND_16(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16) \
   X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8) X(a9) X(a10) X(a11) x(a12) x(a13) x(a14) x(a15) x(a16)

#define _MACRO_EXPAND(X, ...) _preproc_CONCAT(MACRO_EXPAND_, _preproc_NUM_ARGS(__VA_ARGS__))(X, __VA_ARGS__)




#define MACRO_EXPAND_1(X, a1) X(a1)
#define MACRO_EXPAND_2(X, a1, a2) X(a1) X(a2)
#define MACRO_EXPAND_3(X, a1, a2, a3) X(a1) X(a2) X(a3)
#define MACRO_EXPAND_4(X, a1, a2, a3, a4) X(a1) X(a2) X(a3) X(a4)
#define MACRO_EXPAND_5(X, a1, a2, a3, a4, a5) X(a1) X(a2) X(a3) X(a4) X(a5)
#define MACRO_EXPAND_6(X, a1, a2, a3, a4, a5, a6) X(a1) X(a2) X(a3) X(a4) X(a5) X(a6)
#define MACRO_EXPAND_7(X, a1, a2, a3, a4, a5, a6, a7) X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7)
#define MACRO_EXPAND_8(X, a1, a2, a3, a4, a5, a6, a7, a8) X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8)

#define MACRO_EXPAND_9(X, a1, a2, a3, a4, a5, a6, a7, a8, a9) \
   X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8) X(a9)

#define MACRO_EXPAND_10(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
   X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8) X(a9) X(a10)

#define MACRO_EXPAND_11(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) \
   X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8) X(a9) X(a10) X(a11)

#define MACRO_EXPAND_12(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) \
   X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8) X(a9) X(a10) X(a11) x(a12)

#define MACRO_EXPAND_13(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13) \
   X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8) X(a9) X(a10) X(a11) x(a12) x(a13)

#define MACRO_EXPAND_14(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) \
   X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8) X(a9) X(a10) X(a11) x(a12) x(a13) x(a14)

#define MACRO_EXPAND_15(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15) \
   X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8) X(a9) X(a10) X(a11) x(a12) x(a13) x(a14) x(a15)

#define MACRO_EXPAND_16(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16) \
   X(a1) X(a2) X(a3) X(a4) X(a5) X(a6) X(a7) X(a8) X(a9) X(a10) X(a11) x(a12) x(a13) x(a14) x(a15) x(a16)

#define _MACRO_EXPAND(X, ...) _preproc_CONCAT(MACRO_EXPAND_, _preproc_NUM_ARGS(__VA_ARGS__))(X, __VA_ARGS__)



#define MACRO_EXPAND_PAIRED_2(X, a1, a2) X(a1, a2)
#define MACRO_EXPAND_PAIRED_INDEXED_2(X, a1, a2) X(1, a1, a2)
#define MACRO_EXPAND_ODDS_2(X, a1, a2) X(a1)
#define MACRO_EXPAND_EVENS_2(X, a1, a2) X(a2)
#define MACRO_EXPAND_EVENS_INDEXED_2(X, a1, a2) X(1, a2)
#define MACRO_EXPAND_EVENS_INCLUDES_2(X, a1, a2) #include X(a2)

#define MACRO_EXPAND_PAIRED_4(X, a1, a2, a3, a4) X(a1, a2) X(a3, a4)
#define MACRO_EXPAND_PAIRED_INDEXED_4(X, a1, a2, a3, a4) X(1, a1, a2) X(2, a3, a4)
#define MACRO_EXPAND_ODDS_4(X, a1, a2, a3, a4) X(a1) X(a3)
#define MACRO_EXPAND_EVENS_4(X, a1, a2, a3, a4) X(a2) X(a4)
#define MACRO_EXPAND_EVENS_INDEXED_4(X, a1, a2, a3, a4) X(1, a2) X(2, a4)

#define MACRO_EXPAND_PAIRED_6(X, a1, a2, a3, a4, a5, a6) X(a1, a2) X(a3, a4) X(a5, a6)
#define MACRO_EXPAND_PAIRED_INDEXED_6(X, a1, a2, a3, a4, a5, a6) X(1, a1, a2) X(2, a3, a4) X(3, a5, a6)
#define MACRO_EXPAND_ODDS_6(X, a1, a2, a3, a4, a5, a6) X(a1) X(a3) X(a5)
#define MACRO_EXPAND_EVENS_6(X, a1, a2, a3, a4, a5, a6) X(a2) X(a4) X(a6)
#define MACRO_EXPAND_EVENS_INDEXED_6(X, a1, a2, a3, a4, a5, a6) X(1, a2) X(2, a4) X(3, a6)

#define MACRO_EXPAND_PAIRED_8(X, a1, a2, a3, a4, a5, a6, a7, a8) X(a1, a2) X(a3, a4) X(a5, a6) X(a7, a8)
#define MACRO_EXPAND_PAIRED_INDEXED_8(X, a1, a2, a3, a4, a5, a6, a7, a8) \
   X(1, a1, a2) X(2, a3, a4) X(3, a5, a6) X(4, a7, a8)
#define MACRO_EXPAND_ODDS_8(X, a1, a2, a3, a4, a5, a6, a7, a8) X(a1) X(a3) X(a5) X(a7)
#define MACRO_EXPAND_EVENS_8(X, a1, a2, a3, a4, a5, a6, a7, a8) X(a2) X(a4) X(a6) X(a8)
#define MACRO_EXPAND_EVENS_INDEXED_8(X, a1, a2, a3, a4, a5, a6, a7, a8) X(1, a2) X(2, a4) X(3, a6) X(4, a8)
#define MACRO_EXPAND_EVENS_INCLUDES_8(X, a1, a2) \
#include X(a2) \
#include X(a4) \
#include X(a6) \
#include X(a8) \

#define MACRO_EXPAND_PAIRED_10(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
   X(a1, a2) X(a3, a4) X(a5, a6) X(a7, a8) X(a9, a10)
#define MACRO_EXPAND_ODDS_10(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
   X(a1) X(a3) X(a5) X(a7) X(a9)
#define MACRO_EXPAND_EVENS_10(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) \
   X(a2) X(a4) X(a6) X(a8) X(a10)

#define MACRO_EXPAND_PAIRED_12(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) \
   X(a1, a2) X(a3, a4) X(a5, a6) X(a7, a8) X(a9, a10) X(a11, a12)
#define MACRO_EXPAND_ODDS_12(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) \
   X(a1) X(a3) X(a5) X(a7) X(a9) X(a11)
#define MACRO_EXPAND_EVENS_12(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) \
   X(a2) X(a4) X(a6) X(a8) X(a10) x(a12)

#define MACRO_EXPAND_PAIRED_14(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) \
   X(a1, a2) X(a3, a4) X(a5, a6) X(a7, a8) X(a9, a10) X(a11, a12) x(a13, a14)
#define MACRO_EXPAND_ODDS_14(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) \
   X(a1) X(a3) X(a5) X(a7) X(a9) X(a11) x(a13)
#define MACRO_EXPAND_EVENS_14(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) \
   X(a2) X(a4) X(a6) X(a8) X(a10) X(a12) x(a14)

#define MACRO_EXPAND_PAIRED_16(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16) \
   X(a1, a2) X(a3, a4) X(a5, a6) X(a7, a8) X(a9, a10) X(a11, a12) x(a13, a14) x(a15, a16)
#define MACRO_EXPAND_ODDS_16(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16) \
   X(a1) X(a3) X(a5) X(a7) X(a9) X(a11) x(a13) x(a15)
#define MACRO_EXPAND_EVENS_16(X, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16) \
   X(a2) X(a4) X(a6) X(a8) X(a10) X(a12) x(a14) x(a16)


#define _MACRO_EXPAND_PAIRED(X, ...) \
 _preproc_CONCAT(MACRO_EXPAND_PAIRED_, _preproc_NUM_ARGS(__VA_ARGS__))(X, __VA_ARGS__)

#define _MACRO_EXPAND_PAIRED_INDEXED(X, ...) \
 _preproc_CONCAT(MACRO_EXPAND_PAIRED__INDEXED_, _preproc_NUM_ARGS(__VA_ARGS__))(X, __VA_ARGS__)

#define _MACRO_EXPAND_ODDS(X, ...) \
 _preproc_CONCAT(MACRO_EXPAND_ODDS_, _preproc_NUM_ARGS(__VA_ARGS__))(X, __VA_ARGS__)

#define _MACRO_EXPAND_EVENS(X, ...) \
 _preproc_CONCAT(MACRO_EXPAND_EVENS_, _preproc_NUM_ARGS(__VA_ARGS__))(X, __VA_ARGS__)

#define _MACRO_EXPAND_EVENS_INDEXED(X, ...) \
 _preproc_CONCAT(MACRO_EXPAND_EVENS_INDEXED_, _preproc_NUM_ARGS(__VA_ARGS__))(X, __VA_ARGS__)

#define _MACRO_EXPAND_EVENS_INCLUDES(X, ...) \
 _preproc_CONCAT(MACRO_EXPAND_EVENS_INCLUDES_, _preproc_NUM_ARGS(__VA_ARGS__))(X, __VA_ARGS__)

//#define MACRO_EXPAND_ALT_8(X, a1, a2, a3, a4, a5, a6, a7, a8) X(a1, a2) X(a3, a4) X(a5, a6) X(a7, a8)

#define _MACRO_EXPAND_ALT(X, ALT, ...) \
 _preproc_CONCAT(MACRO_EXPAND_##ALT##_, _preproc_NUM_ARGS(__VA_ARGS__))(X, __VA_ARGS__)

#define MACRO_STRINGIFY(x) #x


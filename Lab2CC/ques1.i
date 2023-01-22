# 0 "ques1.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4

# 1 "/usr/include/stdc-predef.h" 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */

/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
# 56 "/usr/include/stdc-predef.h" 3 4
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
# 0 "<command-line>" 2
# 1 "ques1.c"
# 1 "/usr/lib/gcc/x86_64-redhat-linux/12/include/float.h" 1 3 4
/* Copyright (C) 2002-2022 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  5.2.4.2.2  Characteristics of floating types <float.h>
 */




/* Radix of exponent representation, b. */



/* Number of base-FLT_RADIX digits in the significand, p.  */







/* Number of decimal digits, q, such that any floating-point number with q
   decimal digits can be rounded into a floating-point number with p radix b
   digits and back again without change to the q decimal digits,

	p * log10(b)			if b is a power of 10
	floor((p - 1) * log10(b))	otherwise
*/







/* Minimum int x such that FLT_RADIX**(x-1) is a normalized float, emin */







/* Minimum negative integer such that 10 raised to that power is in the
   range of normalized floating-point numbers,

	ceil(log10(b) * (emin - 1))
*/







/* Maximum int x such that FLT_RADIX**(x-1) is a representable float, emax.  */







/* Maximum integer such that 10 raised to that power is in the range of
   representable finite floating-point numbers,

	floor(log10((1 - b**-p) * b**emax))
*/







/* Maximum representable finite floating-point number,

	(1 - b**-p) * b**emax
*/







/* The difference between 1 and the least value greater than 1 that is
   representable in the given floating point type, b**1-p.  */







/* Minimum normalized positive floating-point number, b**(emin - 1).  */







/* Addition rounds to 0: zero, 1: nearest, 2: +inf, 3: -inf, -1: unknown.  */
/* ??? This is supposed to change with calls to fesetround in <fenv.h>.  */





/* The floating-point expression evaluation method.  The precise
   definitions of these values are generalised to include support for
   the interchange and extended types defined in ISO/IEC TS 18661-3.
   Prior to this (for C99/C11) the definitions were:

	-1  indeterminate
	 0  evaluate all operations and constants just to the range and
	    precision of the type
	 1  evaluate operations and constants of type float and double
	    to the range and precision of the double type, evaluate
	    long double operations and constants to the range and
	    precision of the long double type
	 2  evaluate all operations and constants to the range and
	    precision of the long double type

   The TS 18661-3 definitions are:

	-1  indeterminate
	 0  evaluate all operations and constants, whose semantic type has
	    at most the range and precision of float, to the range and
	    precision of float; evaluate all other operations and constants
	    to the range and precision of the semantic type.
	 1  evaluate all operations and constants, whose semantic type has
	    at most the range and precision of double, to the range and
	    precision of double; evaluate all other operations and constants
	    to the range and precision of the semantic type.
	 2  evaluate all operations and constants, whose semantic type has
	    at most the range and precision of long double, to the range and
	    precision of long double; evaluate all other operations and
	    constants to the range and precision of the semantic type.
	 N  where _FloatN  is a supported interchange floating type
	    evaluate all operations and constants, whose semantic type has
	    at most the range and precision of the _FloatN type, to the
	    range and precision of the _FloatN type; evaluate all other
	    operations and constants to the range and precision of the
	    semantic type.
	 N + 1, where _FloatNx is a supported extended floating type
	    evaluate operations and constants, whose semantic type has at
	    most the range and precision of the _FloatNx type, to the range
	    and precision of the _FloatNx type; evaluate all other
	    operations and constants to the range and precision of the
	    semantic type.

   The compiler predefines two macros:

      __FLT_EVAL_METHOD__
      Which, depending on the value given for
      -fpermitted-flt-eval-methods, may be limited to only those values
      for FLT_EVAL_METHOD defined in C99/C11.

     __FLT_EVAL_METHOD_TS_18661_3__
      Which always permits the values for FLT_EVAL_METHOD defined in
      ISO/IEC TS 18661-3.

     Here we want to use __FLT_EVAL_METHOD__, unless
     __STDC_WANT_IEC_60559_TYPES_EXT__ is defined, in which case the user
     is specifically asking for the ISO/IEC TS 18661-3 types, so we use
     __FLT_EVAL_METHOD_TS_18661_3__.

   ??? This ought to change with the setting of the fp control word;
   the value provided by the compiler assumes the widest setting.  */







/* Number of decimal digits, n, such that any floating-point number in the
   widest supported floating type with pmax radix b digits can be rounded
   to a floating-point number with n decimal digits and back again without
   change to the value,

	pmax * log10(b)			if b is a power of 10
	ceil(1 + pmax * log10(b))	otherwise
*/







/* Versions of DECIMAL_DIG for each floating-point type.  */







/* Whether types support subnormal numbers.  */







/* Minimum positive values, including subnormals.  */
# 2 "ques1.c" 2


# 3 "ques1.c"
int main()
{
    int a = 5;
    int b = 10;
    int c = a + b;
    int d = c - b;
    float e = a * b;
    float f = (float)a / b;
    int g = a & b;
    int h = a | b;
}

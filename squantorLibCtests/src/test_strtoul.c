/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <errno.h>
#include <stdlib.h>
#include <strto_internal.h>
#include <limits.h>

MINUNIT_ADD(testStrtoulNormal) 
{
    char * endptr;
    /* this, to base 36, overflows even a 256 bit integer */
    char overflow[] = "-ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ_";
    /* tricky border case */
    char tricky[] = "+0xz";
    errno = 0;
    /* basic functionality */
    minUnitCheck(strtoul("123", NULL, 10) == 123);
    /* proper detecting of default base 10 */
    minUnitCheck(strtoul("456", NULL, 0) == 456);
    /* proper functioning to smaller base */
    minUnitCheck(strtoul("14", NULL, 8) == 12);
    /* proper autodetecting of octal */
    minUnitCheck(strtoul("016", NULL, 0) == 14);
    /* proper autodetecting of hexadecimal, lowercase 'x' */
    minUnitCheck(strtoul("0xFF", NULL, 0) == 255);
    /* proper autodetecting of hexadecimal, uppercase 'X' */
    minUnitCheck(strtoul("0Xa1", NULL, 0) == 161);
    /* proper handling of border case: 0x followed by non-hexdigit */
    minUnitCheck(strtoul(tricky, &endptr, 0) == 0);
    minUnitCheck(endptr == tricky + 2);
    /* proper handling of border case: 0 followed by non-octdigit */
    minUnitCheck(strtoul(tricky, &endptr, 8) == 0);
    minUnitCheck(endptr == tricky + 2);
    /* errno should still be 0 */
    minUnitCheck(errno == 0);
    /* overflowing subject sequence must still return proper endptr */
    minUnitCheck(strtoul(overflow, &endptr, 36) == ULONG_MAX);
    minUnitCheck(errno == ERANGE);
    minUnitCheck((endptr - overflow) == 53);
    /* same for positive */
    errno = 0;
    minUnitCheck(strtoul(overflow + 1, &endptr, 36) == ULONG_MAX);
    minUnitCheck(errno == ERANGE);
    minUnitCheck((endptr - overflow) == 53);
    /* testing skipping of leading whitespace */
    minUnitCheck(strtoul(" \n\v\t\f789", NULL, 0) == 789);
    /* testing conversion failure */
    minUnitCheck(strtoul(overflow, &endptr, 10) == 0);
    minUnitCheck(endptr == overflow);
    endptr = NULL;
    minUnitCheck(strtoul(overflow, &endptr, 0) == 0);
    minUnitCheck(endptr == overflow);
    /* TODO: These tests assume two-complement, but conversion should work */
    /* for one-complement and signed magnitude just as well. Anyone having */
    /* a platform to test this on?                                         */
    errno = 0;
/* long -> 32 bit */
#if ULONG_MAX >> 31 == 1
    /* testing "even" overflow, i.e. base is power of two */
    mu_check(strtoul("4294967295", NULL, 0) == ULONG_MAX);
    mu_check(errno == 0);
    errno = 0;
    mu_check(strtoul("4294967296", NULL, 0) == ULONG_MAX);
    mu_check(errno == ERANGE);
    /* TODO: test "odd" overflow, i.e. base is not power of two */
/* long -> 64 bit */
#elif ULONG_MAX >> 63 == 1
    /* testing "even" overflow, i.e. base is power of two */
    minUnitCheck(strtoul("18446744073709551615", NULL, 0) == ULONG_MAX);
    minUnitCheck(errno == 0);
    errno = 0;
    minUnitCheck(strtoul("18446744073709551616", NULL, 0) == ULONG_MAX);
    minUnitCheck(errno == ERANGE);
    /* TODO: test "odd" overflow, i.e. base is not power of two */
#else
#error Unsupported width of 'long' (neither 32 nor 64 bit).
#endif
}

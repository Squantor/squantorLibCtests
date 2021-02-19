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

MINUNIT_ADD(testStrtolNormal) 
{
    char * endptr;
    /* this, to base 36, overflows even a 256 bit integer */
    char overflow[] = "-ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ_";
    /* tricky border case */
    char tricky[] = "+0xz";
    errno = 0;
    /* basic functionality */
    minUnitCheck(strtol("123", NULL, 10) == 123);
    /* proper detecting of default base 10 */
    minUnitCheck(strtol("456", NULL, 0) == 456);
    /* proper functioning to smaller base */
    minUnitCheck(strtol("14", NULL, 8) == 12);
    /* proper autodetecting of octal */
    minUnitCheck(strtol("016", NULL, 0) == 14);
    /* proper autodetecting of hexadecimal, lowercase 'x' */
    minUnitCheck(strtol("0xFF", NULL, 0) == 255);
    /* proper autodetecting of hexadecimal, uppercase 'X' */
    minUnitCheck(strtol("0Xa1", NULL, 0) == 161);
    /* proper handling of border case: 0x followed by non-hexdigit */
    minUnitCheck(strtol(tricky, &endptr, 0) == 0);
    minUnitCheck(endptr == tricky + 2);
    /* proper handling of border case: 0 followed by non-octdigit */
    minUnitCheck(strtol(tricky, &endptr, 8) == 0);
    minUnitCheck(endptr == tricky + 2);
    /* errno should still be 0 */
    minUnitCheck(errno == 0);
    /* overflowing subject sequence must still return proper endptr */
    minUnitCheck(strtol(overflow, &endptr, 36) == LONG_MIN);
    minUnitCheck(errno == ERANGE);
    minUnitCheck((endptr - overflow) == 53);
    /* same for positive */
    errno = 0;
    minUnitCheck(strtol(overflow + 1, &endptr, 36) == LONG_MAX);
    minUnitCheck(errno == ERANGE);
    minUnitCheck((endptr - overflow) == 53);
    /* testing skipping of leading whitespace */
    minUnitCheck(strtol(" \n\v\t\f789", NULL, 0) == 789);
    /* testing conversion failure */
    minUnitCheck(strtol(overflow, &endptr, 10) == 0);
    minUnitCheck(endptr == overflow);
    endptr = NULL;
    minUnitCheck(strtol(overflow, &endptr, 0) == 0);
    minUnitCheck(endptr == overflow);
    errno = 0;
#if LONG_MAX >> 30 == 1
    /* testing "even" overflow, i.e. base is power of two */
    mu_check(strtol("2147483647", NULL, 0) == 0x7fffffff);
    mu_check(errno == 0);
    errno = 0;
    mu_check(strtol("2147483648", NULL, 0) == LONG_MAX);
    mu_check(errno == ERANGE);
    errno = 0;
    mu_check(strtol("-2147483647", NULL, 0) == (long)0x80000001);
    mu_check(errno == 0);
    errno = 0;
    mu_check(strtol("-2147483648", NULL, 0) == LONG_MIN);
    mu_check(errno == 0);
    errno = 0;
    mu_check(strtol("-2147483649", NULL, 0) == LONG_MIN);
    mu_check(errno == ERANGE);
    /* TODO: test "odd" overflow, i.e. base is not power of two */
#elif LONG_MAX >> 62 == 1
    /* testing "even" overflow, i.e. base is power of two */
    minUnitCheck(strtol("9223372036854775807", NULL, 0) == 0x7fffffffffffffff);
    minUnitCheck(errno == 0);
    errno = 0;
    minUnitCheck(strtol("9223372036854775808", NULL, 0) == LONG_MAX);
    minUnitCheck(errno == ERANGE);
    errno = 0;
    minUnitCheck(strtol("-9223372036854775807", NULL, 0) == (long)0x8000000000000001);
    minUnitCheck(errno == 0);
    errno = 0;
    minUnitCheck(strtol("-9223372036854775808", NULL, 0) == LONG_MIN);
    minUnitCheck(errno == 0);
    errno = 0;
    minUnitCheck(strtol("-9223372036854775809", NULL, 0) == LONG_MIN);
    minUnitCheck(errno == ERANGE);
    /* TODO: test "odd" overflow, i.e. base is not power of two */
#else
#error Unsupported width of 'long' (neither 32 nor 64 bit).
#endif
}

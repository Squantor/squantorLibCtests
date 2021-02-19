/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <errno.h>
#include <strto_internal.h>

MINUNIT_ADD(testStrtoMainNormal) 
{
    const char * p;
    char test[] = "123_";
    char fail[] = "xxx";
    char sign = '-';
    /* basic functionality */
    p = test;
    errno = 0;
    minUnitCheck(strto_main(&p, 10u, (uintmax_t)999, (uintmax_t)12, 3, &sign) == 123);
    minUnitCheck(errno == 0);
    minUnitCheck(p == &test[3]);
    /* proper functioning to smaller base */
    p = test;
    minUnitCheck(strto_main(&p, 8u, (uintmax_t)999, (uintmax_t)12, 3, &sign) == 0123);
    minUnitCheck(errno == 0);
    minUnitCheck(p == &test[3]);
    /* overflowing subject sequence must still return proper endptr */
    p = test;
    minUnitCheck(strto_main(&p, 4u, (uintmax_t)999, (uintmax_t)1, 2, &sign) == 999);
    minUnitCheck(errno == ERANGE);
    minUnitCheck(p == &test[3]);
    minUnitCheck(sign == '+');
    /* testing conversion failure */
    errno = 0;
    p = fail;
    sign = '-';
    minUnitCheck(strto_main(&p, 10u, (uintmax_t)999, (uintmax_t)99, 8, &sign) == 0);
    minUnitCheck(p == NULL);
}

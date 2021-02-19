/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <strto_internal.h>

MINUNIT_ADD(testStrtoPreInvalid) 
{
    int base = 1;
    char sign = '\0';
    char test3[] = "\v-0x123";
    minUnitCheck(strto_pre(test3, &sign, &base) == NULL);
    base = 37;
    minUnitCheck(strto_pre(test3, &sign, &base) == NULL);
}

MINUNIT_ADD(testStrtoPrePositive) 
{
    int base = 0;
    char sign = '\0';
    char test1[] = "  123";
    char test2[] = "\t+0123";
    minUnitCheck(strto_pre(test1, &sign, &base) == &test1[2]);
    minUnitCheck(sign == '+');
    minUnitCheck(base == 10);
    base = 0;
    sign = '\0';
    minUnitCheck(strto_pre(test2, &sign, &base) == &test2[3]);
    minUnitCheck(sign == '+');
    minUnitCheck(base == 8);
}

MINUNIT_ADD(testStrtoPreNegative) 
{
    int base = 0;
    char sign = '\0';
    char test3[] = "\v-0x123";
    base = 0;
    sign = '\0';
    minUnitCheck(strto_pre(test3, &sign, &base) == &test3[4]);
    minUnitCheck(sign == '-');
    minUnitCheck(base == 16);
    base = 10;
    sign = '\0';
    minUnitCheck(strto_pre(test3, &sign, &base) == &test3[2]);
    minUnitCheck(sign == '-');
    minUnitCheck(base == 10);
}

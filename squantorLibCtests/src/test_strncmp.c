/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <string.h>
#include <MinUnit.h>
#include <strings.h>

MINUNIT_ADD(testStrncmpNormal) 
{
    char cmpabcde[] = "abcde\0f";
    char cmpabcd_[] = "abcde\xfc";
    char empty[] = "";
    char x[] = "x";
    minUnitCheck(strncmp(abcde, cmpabcde, 5) == 0);
    minUnitCheck(strncmp(abcde, cmpabcde, 10) == 0);
    minUnitCheck(strncmp(abcde, abcdx, 5) < 0);
    minUnitCheck(strncmp(abcdx, abcde, 5) > 0);
    minUnitCheck(strncmp(empty, abcde, 5) < 0);
    minUnitCheck(strncmp(abcde, empty, 5) > 0);
    minUnitCheck(strncmp(abcde, abcdx, 4) == 0);
    minUnitCheck(strncmp(abcde, x, 0) == 0);
    minUnitCheck(strncmp(abcde, x, 1) < 0);
    minUnitCheck(strncmp(abcde, cmpabcd_, 10) < 0);
}

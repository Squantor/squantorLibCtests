/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <string.h>

MINUNIT_ADD(testStrstrNormal) 
{
    char s[] = "abcabcabcdabcde";
    minUnitCheck(strstr(s, "x") == NULL);
    minUnitCheck(strstr(s, "xyz") == NULL);
    minUnitCheck(strstr(s, "a") == &s[0]);
    minUnitCheck(strstr(s, "abc") == &s[0]);
    minUnitCheck(strstr(s, "abcd") == &s[6]);
    minUnitCheck(strstr(s, "abcde") == &s[10]);
}

/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <string.h>
#include <strings.h>

MINUNIT_ADD(testStrncpyNormal) 
{
    char s[] = "xxxxxxx";
    minUnitCheck(strncpy(s, "", 1) == s);
    minUnitCheck(s[0] == '\0');
    minUnitCheck(s[1] == 'x');
    minUnitCheck(strncpy(s, abcde, 6) == s);
    minUnitCheck(s[0] == 'a');
    minUnitCheck(s[4] == 'e');
    minUnitCheck(s[5] == '\0');
    minUnitCheck(s[6] == 'x');
    minUnitCheck(strncpy(s, abcde, 6) == s);
    minUnitCheck(s[6] == '\0');
    minUnitCheck(strncpy(s, "xxxx", 5) == s);
    minUnitCheck(s[0] == 'x');
    minUnitCheck(s[2] == 'x');
    minUnitCheck(s[3] == 'd');
}

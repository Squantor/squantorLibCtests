/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <string.h>
#include <strings.h>

MINUNIT_ADD(testStrcpyNormal) 
{
    char s[] = "xxxxx";
    minUnitCheck(strcpy(s, "") == s);
    minUnitCheck(s[0] == '\0');
    minUnitCheck(s[1] == 'x');
    minUnitCheck(strcpy(s, abcde) == s);
    minUnitCheck(s[0] == 'a');
    minUnitCheck(s[4] == 'e');
    minUnitCheck(s[5] == '\0');
}

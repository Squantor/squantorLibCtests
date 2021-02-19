/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <strings.h>
#include <string.h>

MINUNIT_ADD(testStrcatNormal) 
{
    char s[] = "xx\0xxxxxx";
    minUnitCheck(strcat(s, abcde) == s);
    minUnitCheck(s[2] == 'a');
    minUnitCheck(s[6] == 'e');
    minUnitCheck(s[7] == '\0');
    minUnitCheck(s[8] == 'x');
    s[0] = '\0';
    minUnitCheck(strcat(s, abcdx) == s);
    minUnitCheck(s[4] == 'x');
    minUnitCheck(s[5] == '\0');
    minUnitCheck(strcat(s, "\0") == s);
    minUnitCheck(s[5] == '\0');
    minUnitCheck(s[6] == 'e');
}

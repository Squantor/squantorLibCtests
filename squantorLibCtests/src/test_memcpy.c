/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <string.h>
#include <strings.h>

MINUNIT_ADD(testMemcpyNormal) 
{
    char s[] = "xxxxxxxxxxx";

    minUnitCheck(memcpy(s, abcde, 6) == s);
    minUnitCheck(s[4] == 'e');
    minUnitCheck(s[5] == '\0');
}

MINUNIT_ADD(testMemcpyPartial) 
{
    char s[] = "xxxxxxxxxxx";
    minUnitCheck(memcpy(s + 5, abcde, 5) == s + 5);
    minUnitCheck(s[9] == 'e');
    minUnitCheck(s[10] == 'x');
}

/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <string.h>

MINUNIT_ADD(testMemmoveOverlapLower)
{
    static char s[] = "xxxxabcde";
    minUnitCheck(memmove(s, s + 4, 5) == s);
    minUnitCheck(s[0] == 'a');
    minUnitCheck(s[4] == 'e');
    minUnitCheck(s[5] == 'b');
}

MINUNIT_ADD(testMemmoveOverlapHigher)
{
    static char s[] = "abcdexxxx";
    minUnitCheck(memmove(s + 4, s, 5) == s + 4);
    minUnitCheck(s[4] == 'a');
}

/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <string.h>
// disable some warnings in gcc
//#pragma GCC diagnostic ignored "-Wmemset-transposed-args"

MINUNIT_ADD(testMemsetNormal) 
{
    char s[] = "xxxxxxxxx";
    minUnitCheck(memset(s, 'o', 10) == s);
    minUnitCheck(s[9] == 'o' );
}

MINUNIT_ADD(testMemsetNoOverwrite)
{
    char s[] = "xxxxxxxxx";
    minUnitCheck(memset(s, '_', 0) == s);
    minUnitCheck(s[0] == 'x');
}

MINUNIT_ADD(testMemsetPartialOverwrite)
{
    char s[] = "xxxxxxxxx";
    minUnitCheck(memset(s, '_', 1) == s);
    minUnitCheck(s[0] == '_');
    minUnitCheck(s[1] == 'x');
}

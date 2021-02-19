/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <strings.h>
#include <string.h>

MINUNIT_ADD(testStrpbrkNormal) 
{
    minUnitCheck(strpbrk(abcde, "x") == NULL);
    minUnitCheck(strpbrk(abcde, "xyz") == NULL);
    minUnitCheck(strpbrk(abcdx, "x") == &abcdx[4]);
    minUnitCheck(strpbrk(abcdx, "xyz") == &abcdx[4]);
    minUnitCheck(strpbrk(abcdx, "zyx") == &abcdx[4]);
    minUnitCheck(strpbrk(abcde, "a") == &abcde[0]);
    minUnitCheck(strpbrk(abcde, "abc") == &abcde[0]);
    minUnitCheck(strpbrk(abcde, "cba") == &abcde[0]);
}

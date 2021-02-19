/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <strings.h>
#include <string.h>

MINUNIT_ADD(testStrspnNormal) 
{
    minUnitCheck(strspn(abcde, "abc") == 3);
    minUnitCheck(strspn(abcde, "b") == 0);
    minUnitCheck(strspn(abcde, abcde) == 5);
}
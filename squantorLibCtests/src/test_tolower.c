/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <ctype.h>

void testToLowerSetup(void) 
{
}

void testToLowerTeardown(void) 
{
}

MINUNIT_ADD(testToLowerNormal) 
{
    minUnitCheck(tolower('A') == 'a');
    minUnitCheck(tolower('Z') == 'z');
    minUnitCheck(tolower('a') == 'a');
    minUnitCheck(tolower('z') == 'z');
    minUnitCheck(tolower('@') == '@');
    minUnitCheck(tolower('[') == '[');
}

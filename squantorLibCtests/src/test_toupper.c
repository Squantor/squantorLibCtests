/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <ctype.h>

MINUNIT_ADD(testToUpperNormal) 
{
    minUnitCheck(toupper('a') == 'A');
    minUnitCheck(toupper('z') == 'Z');
    minUnitCheck(toupper('A') == 'A');
    minUnitCheck(toupper('Z') == 'Z');
    minUnitCheck(toupper('@') == '@');
    minUnitCheck(toupper('[') == '[');
}

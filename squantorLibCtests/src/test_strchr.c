/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <string.h>

void testStrchrSetup(void) 
{
    
}

void testStrchrTeardown(void) 
{

}

MINUNIT_ADD(testStrchrNormal) 
{
    char abccd[] = "abccd";
    minUnitCheck(strchr(abccd, 'x') == NULL);
    minUnitCheck(strchr(abccd, 'a') == &abccd[0]);
    minUnitCheck(strchr(abccd, 'd') == &abccd[4]);
    minUnitCheck(strchr(abccd, '\0') == &abccd[5]);
    minUnitCheck(strchr(abccd, 'c') == &abccd[2]);
}

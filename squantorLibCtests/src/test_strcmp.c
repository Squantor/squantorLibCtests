/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <string.h>
#include <MinUnit.h>
#include <strings.h>

void testStrcmpSetup(void) 
{
    
}

void testStrcmpTeardown(void) 
{

}

MINUNIT_ADD(testStrcmpNormal) 
{

    char cmpabcde[] = "abcde";
    char cmpabcd_[] = "abcd\xfc";
    char empty[] = "";
    minUnitCheck(strcmp(abcde, cmpabcde) == 0);
    minUnitCheck(strcmp(abcde, abcdx) < 0);
    minUnitCheck(strcmp(abcdx, abcde) > 0);
    minUnitCheck(strcmp(empty, abcde) < 0);
    minUnitCheck(strcmp(abcde, empty) > 0);
    minUnitCheck(strcmp(abcde, cmpabcd_) < 0);
}

/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <string.h>
#include <strings.h>

MINUNIT_ADD(testMemcmpEquals)
{

    minUnitCheck(memcmp(abcde, abcdx, 4) == 0);
    minUnitCheck(memcmp(abcde, xxxxx, 0) == 0);
}

MINUNIT_ADD(testMemcmpNotEquals) 
{
    minUnitCheck(memcmp(abcde, abcdx, 5) < 0);
    minUnitCheck(memcmp(xxxxx, abcde, 1) > 0);    
}

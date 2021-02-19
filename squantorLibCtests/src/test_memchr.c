/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <string.h>
#include <strings.h>

MINUNIT_ADD(testMemchrNormal) 
{
    minUnitCheck(memchr(abcde, 'c', 5) == &abcde[2]);
    minUnitCheck(memchr(abcde, 'a', 1) == &abcde[0]);
    minUnitCheck(memchr(abcde, '\0', 6) == &abcde[5]);
}

MINUNIT_ADD(testMemchrEdges) 
{
    minUnitCheck(memchr(abcde, 'a', 0) == NULL);
    minUnitCheck(memchr(abcde, '\0', 5) == NULL);
}

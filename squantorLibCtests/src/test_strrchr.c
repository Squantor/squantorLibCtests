/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <strings.h>
#include <string.h>

MINUNIT_ADD(testStrrchrNormal) 
{
    char abccd[] = "abccd";
    minUnitCheck(strrchr(abcde, '\0') == &abcde[5]);
    minUnitCheck(strrchr(abcde, 'e') == &abcde[4]);
    minUnitCheck(strrchr(abcde, 'a') == &abcde[0]);
    minUnitCheck(strrchr(abccd, 'c') == &abccd[3]);
}

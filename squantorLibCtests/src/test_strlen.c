/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <string.h>

static const char strlenTestLength[] = "TestString";
static const char strlenTestEmpty[] = "";
static const char strnlenTestInvalid[5] = {'a', 'b', 'c', 'd', 'e' };

MINUNIT_ADD(testStrlenNormal) 
{
    minUnitCheck(10 == strlen(strlenTestLength));
}

MINUNIT_ADD(testStrlenEmpty) 
{
    minUnitCheck(0 == strlen(strlenTestEmpty));
}

MINUNIT_ADD(testStrnlenNormal) 
{
    minUnitCheck(10 == strnlen(strlenTestLength, sizeof(strlenTestLength)));
}

MINUNIT_ADD(testStrnlenEmpty) 
{
    minUnitCheck(0 == strnlen(strlenTestEmpty, sizeof(strlenTestEmpty)));
}

MINUNIT_ADD(testStrnlenInvalid) 
{
    minUnitCheck(sizeof(strnlenTestInvalid) == strnlen(strnlenTestInvalid, sizeof(strnlenTestInvalid)));
}
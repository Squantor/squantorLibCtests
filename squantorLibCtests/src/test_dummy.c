/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>

void testDummySetup(void) 
{
    
}

void testDummyTeardown(void) 
{

}

MINUNIT_ADD(testDummyNormal) 
{
    testDummySetup();
    testDummyTeardown();
}

/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>

static const char strstol_test_dec[] = "123";
static const char strstol_test_decpostjunk[] = "89771  junkystuff";
static const char strstol_test_negdec[] = "-8944";
static const char strstol_test_spacedec[] = " \t245";
static const char strstol_test_hex[] = "0xdEaDf00D";
static const char strstol_test_spacehex[] = "  0x155Ab87";

void test_strto_setup(void) 
{
    
}

void test_strto_teardown(void) 
{

}

MINUNIT_ADD(test_sqstrstol_positivedecimal) 
{
    mu_assert_int_eq(123, sqstrstol(strstol_test_dec));
}

MINUNIT_ADD(test_sqstrstol_positivedecimal_junk) 
{
    mu_assert_int_eq(89771, sqstrstol(strstol_test_decpostjunk));
}

MINUNIT_ADD(test_sqstrstol_negativedecimal)
{
    mu_assert_int_eq(-8944, sqstrstol(strstol_test_negdec));
} 

MINUNIT_ADD(test_sqstrstol_positivedecimal_spaces) 
{
    mu_assert_int_eq(245, sqstrstol(strstol_test_spacedec));
}

MINUNIT_ADD(test_sqstrstol_hex) 
{
    mu_assert_int_eq(0xdEaDf00D, sqstrstol(strstol_test_hex));
}

MINUNIT_ADD(test_sqstrstol_hex_spaces) 
{  
    mu_assert_int_eq(0x155Ab87, sqstrstol(strstol_test_spacehex));
}

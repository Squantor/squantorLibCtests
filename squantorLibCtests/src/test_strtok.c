/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
#include <MinUnit.h>
#include <string.h>

static const char strtok_whitespaces[] = " \n\r\t";
static char strtok_test_empty[] = "";
static char strtok_test_no_tok[] = "    \t   \r";
static char strtok_test_tokonly[] = "foo";
static char strtok_test_tokspaced[] = "   baz    ";
static char strtok_test_multitokspaced[] = " neodymium    foo\t zapfff\tmoo \n\r";

MINUNIT_ADD(test_sqstrstok_r_emptys)
{
    char *strtok_state;
    mu_assert(sqstrtok_r(strtok_test_empty, strtok_whitespaces, &strtok_state) == NULL, "sqstrtok(strtok_test_empty, strtok_whitespaces) != NULL");
    mu_assert(sqstrtok_r(strtok_test_no_tok, strtok_whitespaces, &strtok_state) == NULL, "sqstrtok(strtok_test_empty, strtok_whitespaces) != NULL");
}

MINUNIT_ADD(test_sqstrstok_r_singletok)
{
    char *strtok_state;
    char *token;
    
    token = sqstrtok_r(strtok_test_tokonly, strtok_whitespaces, &strtok_state);
    mu_assert(token != NULL, "sqstrtok(strtok_test_tokonly, strtok_whitespaces) == NULL");
    mu_assert_string_eq("foo", token);
    
    token = sqstrtok_r(strtok_test_tokspaced, strtok_whitespaces, &strtok_state);
    mu_assert(token != NULL, "sqstrtok(strtok_test_tokspaced, strtok_whitespaces) == NULL");
    mu_assert_string_eq("baz", token); 
}

MINUNIT_ADD(test_sqstrstok_r_multitoken) 
{
    char *strtok_state;
    char *token;  
    token = sqstrtok_r(strtok_test_multitokspaced, strtok_whitespaces, &strtok_state);
    mu_assert(token != NULL, "sqstrtok(strtok_test_multitokspaced, strtok_whitespaces) == NULL");
    mu_assert_string_eq("neodymium", token);
    token = sqstrtok_r(NULL, strtok_whitespaces, &strtok_state);
    mu_assert(token != NULL, "sqstrtok(NULL, strtok_whitespaces) == NULL");
    mu_assert_string_eq("foo", token);
    token = sqstrtok_r(NULL, strtok_whitespaces, &strtok_state);
    mu_assert(token != NULL, "sqstrtok(NULL, strtok_whitespaces) == NULL");
    mu_assert_string_eq("zapfff", token);
    token = sqstrtok_r(NULL, strtok_whitespaces, &strtok_state);
    mu_assert(token != NULL, "sqstrtok(NULL, strtok_whitespaces) == NULL");
    mu_assert_string_eq("moo", token);
}
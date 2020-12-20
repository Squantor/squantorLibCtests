/*
MIT License

Copyright (c) 2019 Bart Bilos

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
/*
*/
#include <sqMinUnitC.h>
#include <test_strto_pre.h>
#include <strto_internal.h>

void testStrtoPreSetup(void) 
{
    
}

void testStrtoPreTeardown(void) 
{

}

MU_TEST(testStrtoPreInvalid) 
{
    int base = 1;
    char sign = '\0';
    char test3[] = "\v-0x123";
    mu_check(strto_pre(test3, &sign, &base) == NULL);
    base = 37;
    mu_check(strto_pre(test3, &sign, &base) == NULL);
}

MU_TEST(testStrtoPrePositive) 
{
    int base = 0;
    char sign = '\0';
    char test1[] = "  123";
    char test2[] = "\t+0123";
    mu_check(strto_pre(test1, &sign, &base) == &test1[2]);
    mu_check(sign == '+');
    mu_check(base == 10);
    base = 0;
    sign = '\0';
    mu_check(strto_pre(test2, &sign, &base) == &test2[3]);
    mu_check(sign == '+');
    mu_check(base == 8);
}

MU_TEST(testStrtoPreNegative) 
{
    int base = 0;
    char sign = '\0';
    char test3[] = "\v-0x123";
    base = 0;
    sign = '\0';
    mu_check(strto_pre(test3, &sign, &base) == &test3[4]);
    mu_check(sign == '-');
    mu_check(base == 16);
    base = 10;
    sign = '\0';
    mu_check(strto_pre(test3, &sign, &base) == &test3[2]);
    mu_check(sign == '-');
    mu_check(base == 10);
}

MU_TEST_SUITE(testStrtoPre) 
{
    MU_SUITE_CONFIGURE(&testStrtoPreSetup, &testStrtoPreTeardown);
    MU_RUN_TEST(testStrtoPreInvalid);
    MU_RUN_TEST(testStrtoPrePositive);
    MU_RUN_TEST(testStrtoPreNegative);
}

void testStrtoPreSuite()
{
    MU_RUN_SUITE(testStrtoPre);
}
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
#include <test_strto_main.h>
#include <errno.h>
#include <strto_internal.h>

void testStrtoMainSetup(void) 
{
    
}

void testStrtoMainTeardown(void) 
{

}

MU_TEST(testStrtoMainNormal) 
{
    const char * p;
    char test[] = "123_";
    char fail[] = "xxx";
    char sign = '-';
    /* basic functionality */
    p = test;
    errno = 0;
    mu_check(strto_main(&p, 10u, (uintmax_t)999, (uintmax_t)12, 3, &sign) == 123);
    mu_check(errno == 0);
    mu_check(p == &test[3]);
    /* proper functioning to smaller base */
    p = test;
    mu_check(strto_main(&p, 8u, (uintmax_t)999, (uintmax_t)12, 3, &sign) == 0123);
    mu_check(errno == 0);
    mu_check(p == &test[3]);
    /* overflowing subject sequence must still return proper endptr */
    p = test;
    mu_check(strto_main(&p, 4u, (uintmax_t)999, (uintmax_t)1, 2, &sign) == 999);
    mu_check(errno == ERANGE);
    mu_check(p == &test[3]);
    mu_check(sign == '+');
    /* testing conversion failure */
    errno = 0;
    p = fail;
    sign = '-';
    mu_check(strto_main(&p, 10u, (uintmax_t)999, (uintmax_t)99, 8, &sign) == 0);
    mu_check(p == NULL);
}

MU_TEST_SUITE(testStrtoMain) 
{
    MU_SUITE_CONFIGURE(&testStrtoMainSetup, &testStrtoMainTeardown);
    MU_RUN_TEST(testStrtoMainNormal);
}

void testStrtoMainSuite()
{
    MU_RUN_SUITE(testStrtoMain);
}
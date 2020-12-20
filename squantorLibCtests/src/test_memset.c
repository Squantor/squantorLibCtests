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
#include <test_memset.h>
#include <string.h>
// disable some warnings in gcc
#pragma GCC diagnostic ignored "-Wmemset-transposed-args"

void testMemsetSetup(void) 
{
    
}

void testMemsetTeardown(void) 
{

}

MU_TEST(testMemsetNormal) 
{
    char s[] = "xxxxxxxxx";
    mu_check(memset(s, 'o', 10) == s);
    mu_check(s[9] == 'o' );
}

MU_TEST(testMemsetNoOverwrite)
{
    char s[] = "xxxxxxxxx";
    mu_check(memset(s, '_', 0) == s);
    mu_check(s[0] == 'x');
}

MU_TEST(testMemsetPartialOverwrite)
{
    char s[] = "xxxxxxxxx";
    mu_check(memset(s, '_', 1) == s);
    mu_check(s[0] == '_');
    mu_check(s[1] == 'x');
}

MU_TEST_SUITE(testMemset) 
{
    MU_SUITE_CONFIGURE(&testMemsetSetup, &testMemsetTeardown);
    MU_RUN_TEST(testMemsetNormal);
    MU_RUN_TEST(testMemsetNoOverwrite);
    MU_RUN_TEST(testMemsetPartialOverwrite);
}

void testMemsetSuite()
{
    MU_RUN_SUITE(testMemset);
}
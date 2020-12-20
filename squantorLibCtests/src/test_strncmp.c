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
#include <string.h>
#include <sqMinUnitC.h>
#include <test_strncmp.h>
#include <strings.h>

void testStrncmpSetup(void) 
{
    
}

void testStrncmpTeardown(void) 
{

}

MU_TEST(testStrncmpNormal) 
{
    char cmpabcde[] = "abcde\0f";
    char cmpabcd_[] = "abcde\xfc";
    char empty[] = "";
    char x[] = "x";
    mu_check(strncmp(abcde, cmpabcde, 5) == 0);
    mu_check(strncmp(abcde, cmpabcde, 10) == 0);
    mu_check(strncmp(abcde, abcdx, 5) < 0);
    mu_check(strncmp(abcdx, abcde, 5) > 0);
    mu_check(strncmp(empty, abcde, 5) < 0);
    mu_check(strncmp(abcde, empty, 5) > 0);
    mu_check(strncmp(abcde, abcdx, 4) == 0);
    mu_check(strncmp(abcde, x, 0) == 0);
    mu_check(strncmp(abcde, x, 1) < 0);
    mu_check(strncmp(abcde, cmpabcd_, 10) < 0);
}

MU_TEST_SUITE(testStrncmp) 
{
    MU_SUITE_CONFIGURE(&testStrncmpSetup, &testStrncmpTeardown);
    MU_RUN_TEST(testStrncmpNormal);
}

void testStrncmpSuite()
{
    MU_RUN_SUITE(testStrncmp);
}
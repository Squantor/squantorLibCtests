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
#include <test_strstr.h>
#include <string.h>

void testStrstrSetup(void) 
{
    
}

void testStrstrTeardown(void) 
{

}

MU_TEST(testStrstrNormal) 
{
    char s[] = "abcabcabcdabcde";
    mu_check(strstr(s, "x") == NULL);
    mu_check(strstr(s, "xyz") == NULL);
    mu_check(strstr(s, "a") == &s[0]);
    mu_check(strstr(s, "abc") == &s[0]);
    mu_check(strstr(s, "abcd") == &s[6]);
    mu_check(strstr(s, "abcde") == &s[10]);
}

MU_TEST_SUITE(testStrstr) 
{
    MU_SUITE_CONFIGURE(&testStrstrSetup, &testStrstrTeardown);
    MU_RUN_TEST(testStrstrNormal);
}

void testStrstrSuite()
{
    MU_RUN_SUITE(testStrstr);
}
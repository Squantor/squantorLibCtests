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
#include <test_strncpy.h>
#include <string.h>
#include <strings.h>

void testStrncpySetup(void) 
{
    
}

void testStrncpyTeardown(void) 
{

}

MU_TEST(testStrncpyNormal) 
{
    char s[] = "xxxxxxx";
    mu_check(strncpy(s, "", 1) == s);
    mu_check(s[0] == '\0');
    mu_check(s[1] == 'x');
    mu_check(strncpy(s, abcde, 6) == s);
    mu_check(s[0] == 'a');
    mu_check(s[4] == 'e');
    mu_check(s[5] == '\0');
    mu_check(s[6] == 'x');
    mu_check(strncpy(s, abcde, 6) == s);
    mu_check(s[6] == '\0');
    mu_check(strncpy(s, "xxxx", 5) == s);
    mu_check(s[0] == 'x');
    mu_check(s[2] == 'x');
    mu_check(s[3] == 'd');
}

MU_TEST_SUITE(testStrncpy) 
{
    MU_SUITE_CONFIGURE(&testStrncpySetup, &testStrncpyTeardown);
    MU_RUN_TEST(testStrncpyNormal);
}

void testStrncpySuite()
{
    MU_RUN_SUITE(testStrncpy);
}
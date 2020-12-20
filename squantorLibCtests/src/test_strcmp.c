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
#include <test_strcmp.h>
#include <strings.h>

void testStrcmpSetup(void) 
{
    
}

void testStrcmpTeardown(void) 
{

}

MU_TEST(testStrcmpNormal) 
{

    char cmpabcde[] = "abcde";
    char cmpabcd_[] = "abcd\xfc";
    char empty[] = "";
    mu_check(strcmp(abcde, cmpabcde) == 0);
    mu_check(strcmp(abcde, abcdx) < 0);
    mu_check(strcmp(abcdx, abcde) > 0);
    mu_check(strcmp(empty, abcde) < 0);
    mu_check(strcmp(abcde, empty) > 0);
    mu_check(strcmp(abcde, cmpabcd_) < 0);
}

MU_TEST_SUITE(testStrcmp) 
{
    MU_SUITE_CONFIGURE(&testStrcmpSetup, &testStrcmpTeardown);
    MU_RUN_TEST(testStrcmpNormal);
}

void testStrcmpSuite()
{
    MU_RUN_SUITE(testStrcmp);
}
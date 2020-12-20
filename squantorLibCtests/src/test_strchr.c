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
#include <test_strchr.h>
#include <string.h>

void testStrchrSetup(void) 
{
    
}

void testStrchrTeardown(void) 
{

}

MU_TEST(testStrchrNormal) 
{
    char abccd[] = "abccd";
    mu_check(strchr(abccd, 'x') == NULL);
    mu_check(strchr(abccd, 'a') == &abccd[0]);
    mu_check(strchr(abccd, 'd') == &abccd[4]);
    mu_check(strchr(abccd, '\0') == &abccd[5]);
    mu_check(strchr(abccd, 'c') == &abccd[2]);
}

MU_TEST_SUITE(testStrchr) 
{
    MU_SUITE_CONFIGURE(&testStrchrSetup, &testStrchrTeardown);
    MU_RUN_TEST(testStrchrNormal);
}

void testStrchrSuite()
{
    MU_RUN_SUITE(testStrchr);
}
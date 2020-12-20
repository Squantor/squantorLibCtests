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
#include <test_memcpy.h>
#include <string.h>
#include <strings.h>

void testMemcpySetup(void) 
{
    
}

void testMemcpyTeardown(void) 
{

}

MU_TEST(testMemcpyNormal) 
{
    char s[] = "xxxxxxxxxxx";

    mu_check(memcpy(s, abcde, 6) == s);
    mu_check(s[4] == 'e');
    mu_check(s[5] == '\0');
}

MU_TEST(testMemcpyPartial) 
{
    char s[] = "xxxxxxxxxxx";
    mu_check(memcpy(s + 5, abcde, 5) == s + 5);
    mu_check(s[9] == 'e');
    mu_check(s[10] == 'x');
}

MU_TEST_SUITE(testMemcpy) 
{
    MU_SUITE_CONFIGURE(&testMemcpySetup, &testMemcpyTeardown);
    MU_RUN_TEST(testMemcpyNormal);
    MU_RUN_TEST(testMemcpyPartial);
}

void testMemcpySuite()
{
    MU_RUN_SUITE(testMemcpy);
}
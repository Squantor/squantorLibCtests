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
#include <test_memmove.h>
#include <string.h>

void testMemmoveSetup(void) 
{
    
}

void testMemmoveTeardown(void) 
{

}

MU_TEST(testMemmoveOverlapLower)
{
    static char s[] = "xxxxabcde";
    mu_check(memmove(s, s + 4, 5) == s);
    mu_check(s[0] == 'a');
    mu_check(s[4] == 'e');
    mu_check(s[5] == 'b');
}

MU_TEST(testMemmoveOverlapHigher)
{
    static char s[] = "abcdexxxx";
    mu_check(memmove(s + 4, s, 5) == s + 4);
    mu_check(s[4] == 'a');
}

MU_TEST_SUITE(testMemmove) 
{
    MU_SUITE_CONFIGURE(&testMemmoveSetup, &testMemmoveTeardown);
    MU_RUN_TEST(testMemmoveOverlapLower);
    MU_RUN_TEST(testMemmoveOverlapHigher);
}

void testMemmoveSuite()
{
    MU_RUN_SUITE(testMemmove);
}
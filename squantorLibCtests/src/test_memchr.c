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
#include <test_memchr.h>
#include <string.h>
#include <strings.h>

void testMemchrSetup(void) 
{
    
}

void testMemchrTeardown(void) 
{

}

MU_TEST(testMemchrNormal) 
{
    mu_check(memchr(abcde, 'c', 5) == &abcde[2]);
    mu_check(memchr(abcde, 'a', 1) == &abcde[0]);
    mu_check(memchr(abcde, '\0', 6) == &abcde[5]);
}

MU_TEST(testMemchrEdges) 
{
    mu_check(memchr(abcde, 'a', 0) == NULL);
    mu_check(memchr(abcde, '\0', 5) == NULL);
}

MU_TEST_SUITE(testMemchr) 
{
    MU_SUITE_CONFIGURE(&testMemchrSetup, &testMemchrTeardown);
    MU_RUN_TEST(testMemchrNormal);
    MU_RUN_TEST(testMemchrEdges);
}

void testMemchrSuite()
{
    MU_RUN_SUITE(testMemchr);
}
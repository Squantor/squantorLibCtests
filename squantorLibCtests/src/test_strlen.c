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
#include <test_strlen.h>
#include <string.h>

static const char strlenTestLength[] = "TestString";
static const char strlenTestEmpty[] = "";
static const char strnlenTestInvalid[5] = {'a', 'b', 'c', 'd', 'e' };

void testStrlenSetup(void) 
{
    
}

void testStrlenTeardown(void) 
{

}

MU_TEST(testStrlenNormal) 
{
    mu_check(10 == strlen(strlenTestLength));
}

MU_TEST(testStrlenEmpty) 
{
    mu_check(0 == strlen(strlenTestEmpty));
}

MU_TEST(testStrnlenNormal) 
{
    mu_check(10 == strnlen(strlenTestLength, sizeof(strlenTestLength)));
}

MU_TEST(testStrnlenEmpty) 
{
    mu_check(0 == strnlen(strlenTestEmpty, sizeof(strlenTestEmpty)));
}

MU_TEST(testStrnlenInvalid) 
{
    mu_check(sizeof(strnlenTestInvalid) == strnlen(strnlenTestInvalid, sizeof(strnlenTestInvalid)));
}

MU_TEST_SUITE(testStrlen) 
{
    MU_SUITE_CONFIGURE(&testStrlenSetup, &testStrlenTeardown);
    
    MU_RUN_TEST(testStrlenNormal);
    MU_RUN_TEST(testStrlenEmpty);
    MU_RUN_TEST(testStrnlenNormal);
    MU_RUN_TEST(testStrnlenEmpty);
    MU_RUN_TEST(testStrnlenInvalid);
}

void testStrlenSuite()
{
    MU_RUN_SUITE(testStrlen);
}
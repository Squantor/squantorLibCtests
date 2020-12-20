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
#include <test_strtol.h>
#include <errno.h>
#include <stdlib.h>
#include <strto_internal.h>
#include <limits.h>

void testStrtolSetup(void) 
{
    
}

void testStrtolTeardown(void) 
{

}

MU_TEST(testStrtolNormal) 
{
    char * endptr;
    /* this, to base 36, overflows even a 256 bit integer */
    char overflow[] = "-ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ_";
    /* tricky border case */
    char tricky[] = "+0xz";
    errno = 0;
    /* basic functionality */
    mu_check(strtol("123", NULL, 10) == 123);
    /* proper detecting of default base 10 */
    mu_check(strtol("456", NULL, 0) == 456);
    /* proper functioning to smaller base */
    mu_check(strtol("14", NULL, 8) == 12);
    /* proper autodetecting of octal */
    mu_check(strtol("016", NULL, 0) == 14);
    /* proper autodetecting of hexadecimal, lowercase 'x' */
    mu_check(strtol("0xFF", NULL, 0) == 255);
    /* proper autodetecting of hexadecimal, uppercase 'X' */
    mu_check(strtol("0Xa1", NULL, 0) == 161);
    /* proper handling of border case: 0x followed by non-hexdigit */
    mu_check(strtol(tricky, &endptr, 0) == 0);
    mu_check(endptr == tricky + 2);
    /* proper handling of border case: 0 followed by non-octdigit */
    mu_check(strtol(tricky, &endptr, 8) == 0);
    mu_check(endptr == tricky + 2);
    /* errno should still be 0 */
    mu_check(errno == 0);
    /* overflowing subject sequence must still return proper endptr */
    mu_check(strtol(overflow, &endptr, 36) == LONG_MIN);
    mu_check(errno == ERANGE);
    mu_check((endptr - overflow) == 53);
    /* same for positive */
    errno = 0;
    mu_check(strtol(overflow + 1, &endptr, 36) == LONG_MAX);
    mu_check(errno == ERANGE);
    mu_check((endptr - overflow) == 53);
    /* testing skipping of leading whitespace */
    mu_check(strtol(" \n\v\t\f789", NULL, 0) == 789);
    /* testing conversion failure */
    mu_check(strtol(overflow, &endptr, 10) == 0);
    mu_check(endptr == overflow);
    endptr = NULL;
    mu_check(strtol(overflow, &endptr, 0) == 0);
    mu_check(endptr == overflow);
    errno = 0;
#if LONG_MAX >> 30 == 1
    /* testing "even" overflow, i.e. base is power of two */
    mu_check(strtol("2147483647", NULL, 0) == 0x7fffffff);
    mu_check(errno == 0);
    errno = 0;
    mu_check(strtol("2147483648", NULL, 0) == LONG_MAX);
    mu_check(errno == ERANGE);
    errno = 0;
    mu_check(strtol("-2147483647", NULL, 0) == (long)0x80000001);
    mu_check(errno == 0);
    errno = 0;
    mu_check(strtol("-2147483648", NULL, 0) == LONG_MIN);
    mu_check(errno == 0);
    errno = 0;
    mu_check(strtol("-2147483649", NULL, 0) == LONG_MIN);
    mu_check(errno == ERANGE);
    /* TODO: test "odd" overflow, i.e. base is not power of two */
#elif LONG_MAX >> 62 == 1
    /* testing "even" overflow, i.e. base is power of two */
    mu_check(strtol("9223372036854775807", NULL, 0) == 0x7fffffffffffffff);
    mu_check(errno == 0);
    errno = 0;
    mu_check(strtol("9223372036854775808", NULL, 0) == LONG_MAX);
    mu_check(errno == ERANGE);
    errno = 0;
    mu_check(strtol("-9223372036854775807", NULL, 0) == (long)0x8000000000000001);
    mu_check(errno == 0);
    errno = 0;
    mu_check(strtol("-9223372036854775808", NULL, 0) == LONG_MIN);
    mu_check(errno == 0);
    errno = 0;
    mu_check(strtol("-9223372036854775809", NULL, 0) == LONG_MIN);
    mu_check(errno == ERANGE);
    /* TODO: test "odd" overflow, i.e. base is not power of two */
#else
#error Unsupported width of 'long' (neither 32 nor 64 bit).
#endif
}

MU_TEST_SUITE(testStrtol) 
{
    MU_SUITE_CONFIGURE(&testStrtolSetup, &testStrtolTeardown);
    MU_RUN_TEST(testStrtolNormal);
}

void testStrtolSuite()
{
    MU_RUN_SUITE(testStrtol);
}
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
#include <test_strtoul.h>
#include <errno.h>
#include <stdlib.h>
#include <strto_internal.h>
#include <limits.h>

void testStrtoulSetup(void) 
{
    
}

void testStrtoulTeardown(void) 
{

}

MU_TEST(testStrtoulNormal) 
{
    char * endptr;
    /* this, to base 36, overflows even a 256 bit integer */
    char overflow[] = "-ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ_";
    /* tricky border case */
    char tricky[] = "+0xz";
    errno = 0;
    /* basic functionality */
    mu_check(strtoul("123", NULL, 10) == 123);
    /* proper detecting of default base 10 */
    mu_check(strtoul("456", NULL, 0) == 456);
    /* proper functioning to smaller base */
    mu_check(strtoul("14", NULL, 8) == 12);
    /* proper autodetecting of octal */
    mu_check(strtoul("016", NULL, 0) == 14);
    /* proper autodetecting of hexadecimal, lowercase 'x' */
    mu_check(strtoul("0xFF", NULL, 0) == 255);
    /* proper autodetecting of hexadecimal, uppercase 'X' */
    mu_check(strtoul("0Xa1", NULL, 0) == 161);
    /* proper handling of border case: 0x followed by non-hexdigit */
    mu_check(strtoul(tricky, &endptr, 0) == 0);
    mu_check(endptr == tricky + 2);
    /* proper handling of border case: 0 followed by non-octdigit */
    mu_check(strtoul(tricky, &endptr, 8) == 0);
    mu_check(endptr == tricky + 2);
    /* errno should still be 0 */
    mu_check(errno == 0);
    /* overflowing subject sequence must still return proper endptr */
    mu_check(strtoul(overflow, &endptr, 36) == ULONG_MAX);
    mu_check(errno == ERANGE);
    mu_check((endptr - overflow) == 53);
    /* same for positive */
    errno = 0;
    mu_check(strtoul(overflow + 1, &endptr, 36) == ULONG_MAX);
    mu_check(errno == ERANGE);
    mu_check((endptr - overflow) == 53);
    /* testing skipping of leading whitespace */
    mu_check(strtoul(" \n\v\t\f789", NULL, 0) == 789);
    /* testing conversion failure */
    mu_check(strtoul(overflow, &endptr, 10) == 0);
    mu_check(endptr == overflow);
    endptr = NULL;
    mu_check(strtoul(overflow, &endptr, 0) == 0);
    mu_check(endptr == overflow);
    /* TODO: These tests assume two-complement, but conversion should work */
    /* for one-complement and signed magnitude just as well. Anyone having */
    /* a platform to test this on?                                         */
    errno = 0;
/* long -> 32 bit */
#if ULONG_MAX >> 31 == 1
    /* testing "even" overflow, i.e. base is power of two */
    mu_check(strtoul("4294967295", NULL, 0) == ULONG_MAX);
    mu_check(errno == 0);
    errno = 0;
    mu_check(strtoul("4294967296", NULL, 0) == ULONG_MAX);
    mu_check(errno == ERANGE);
    /* TODO: test "odd" overflow, i.e. base is not power of two */
/* long -> 64 bit */
#elif ULONG_MAX >> 63 == 1
    /* testing "even" overflow, i.e. base is power of two */
    mu_check(strtoul("18446744073709551615", NULL, 0) == ULONG_MAX);
    mu_check(errno == 0);
    errno = 0;
    mu_check(strtoul("18446744073709551616", NULL, 0) == ULONG_MAX);
    mu_check(errno == ERANGE);
    /* TODO: test "odd" overflow, i.e. base is not power of two */
#else
#error Unsupported width of 'long' (neither 32 nor 64 bit).
#endif
}

MU_TEST_SUITE(testStrtoul) 
{
    MU_SUITE_CONFIGURE(&testStrtoulSetup, &testStrtoulTeardown);
    MU_RUN_TEST(testStrtoulNormal);
}

void testStrtoulSuite()
{
    MU_RUN_SUITE(testStrtoul);
}
/*
 * Copyright © 2017 Oystein Myrmo
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that copyright
 * notice and this permission notice appear in supporting documentation, and
 * that the name of the copyright holders not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no representations
 * about the suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */
#include "simple_bezier.h"
#include "assert.h"

#define ASSERT_BINOMIAL_COEFFICIENT(N, pos, val) \
    SB_ASSERT(Bezier::Bezier<N>::binomialCoefficients[pos] == val);

void binomial_tests()
{
    SB_ASSERT(Bezier::Bezier<0>::binomialCoefficients.size() == 1);
    SB_ASSERT(Bezier::Bezier<1>::binomialCoefficients.size() == 2);
    SB_ASSERT(Bezier::Bezier<2>::binomialCoefficients.size() == 3);
    SB_ASSERT(Bezier::Bezier<3>::binomialCoefficients.size() == 4);
    SB_ASSERT(Bezier::Bezier<4>::binomialCoefficients.size() == 5);
    SB_ASSERT(Bezier::Bezier<5>::binomialCoefficients.size() == 6);
    SB_ASSERT(Bezier::Bezier<10>::binomialCoefficients.size() == 11);
    SB_ASSERT(Bezier::Bezier<15>::binomialCoefficients.size() == 16);
    SB_ASSERT(Bezier::Bezier<20>::binomialCoefficients.size() == 21);
    SB_ASSERT(Bezier::Bezier<50>::binomialCoefficients.size() == 51);

    // N = 0 --> [1]
    ASSERT_BINOMIAL_COEFFICIENT(0, 0, 1);

    // N = 1 --> [1 1]
    ASSERT_BINOMIAL_COEFFICIENT(1, 0, 1);
    ASSERT_BINOMIAL_COEFFICIENT(1, 1, 1);

    // N = 2 --> [1 2 1]
    ASSERT_BINOMIAL_COEFFICIENT(2, 0, 1);
    ASSERT_BINOMIAL_COEFFICIENT(2, 1, 2);
    ASSERT_BINOMIAL_COEFFICIENT(2, 2, 1);

    // N = 3 --> [1 3 3 1]
    ASSERT_BINOMIAL_COEFFICIENT(3, 0, 1);
    ASSERT_BINOMIAL_COEFFICIENT(3, 1, 3);
    ASSERT_BINOMIAL_COEFFICIENT(3, 2, 3);
    ASSERT_BINOMIAL_COEFFICIENT(3, 3, 1);

    // N = 4 --> [1 4 6 4 1]
    ASSERT_BINOMIAL_COEFFICIENT(4, 0, 1);
    ASSERT_BINOMIAL_COEFFICIENT(4, 1, 4);
    ASSERT_BINOMIAL_COEFFICIENT(4, 2, 6);
    ASSERT_BINOMIAL_COEFFICIENT(4, 3, 4);
    ASSERT_BINOMIAL_COEFFICIENT(4, 4, 1);

    // N = 5 --> [1 5 10 10 5 1]
    ASSERT_BINOMIAL_COEFFICIENT(5, 0, 1);
    ASSERT_BINOMIAL_COEFFICIENT(5, 1, 5);
    ASSERT_BINOMIAL_COEFFICIENT(5, 2, 10);
    ASSERT_BINOMIAL_COEFFICIENT(5, 3, 10);
    ASSERT_BINOMIAL_COEFFICIENT(5, 4, 5);
    ASSERT_BINOMIAL_COEFFICIENT(5, 5, 1);

    // N = 10 --> [1 10 45 120 210 252 210 120 45 10 1]
    ASSERT_BINOMIAL_COEFFICIENT(10, 0, 1);
    ASSERT_BINOMIAL_COEFFICIENT(10, 1, 10);
    ASSERT_BINOMIAL_COEFFICIENT(10, 2, 45);
    ASSERT_BINOMIAL_COEFFICIENT(10, 3, 120);
    ASSERT_BINOMIAL_COEFFICIENT(10, 4, 210);
    ASSERT_BINOMIAL_COEFFICIENT(10, 5, 252);
    ASSERT_BINOMIAL_COEFFICIENT(10, 6, 210);
    ASSERT_BINOMIAL_COEFFICIENT(10, 7, 120);
    ASSERT_BINOMIAL_COEFFICIENT(10, 8, 45);
    ASSERT_BINOMIAL_COEFFICIENT(10, 9, 10);
    ASSERT_BINOMIAL_COEFFICIENT(10, 10, 1);

    // N = 10 --> [1 10 45 120 210 252 210 120 45 10 1]
    ASSERT_BINOMIAL_COEFFICIENT(10, 0, 1);
    ASSERT_BINOMIAL_COEFFICIENT(10, 1, 10);
    ASSERT_BINOMIAL_COEFFICIENT(10, 2, 45);
    ASSERT_BINOMIAL_COEFFICIENT(10, 3, 120);
    ASSERT_BINOMIAL_COEFFICIENT(10, 4, 210);
    ASSERT_BINOMIAL_COEFFICIENT(10, 5, 252);
    ASSERT_BINOMIAL_COEFFICIENT(10, 6, 210);
    ASSERT_BINOMIAL_COEFFICIENT(10, 7, 120);
    ASSERT_BINOMIAL_COEFFICIENT(10, 8, 45);
    ASSERT_BINOMIAL_COEFFICIENT(10, 9, 10);
    ASSERT_BINOMIAL_COEFFICIENT(10, 10, 1);
    ASSERT_BINOMIAL_COEFFICIENT(10, 6, 210);
    ASSERT_BINOMIAL_COEFFICIENT(10, 7, 120);
    ASSERT_BINOMIAL_COEFFICIENT(10, 8, 45);
    ASSERT_BINOMIAL_COEFFICIENT(10, 9, 10);
    ASSERT_BINOMIAL_COEFFICIENT(10, 10, 1);

    // N = 15 --> [1 15 105 455 1365 3003 5005 6435 6435 5005 3003 1365 455 105 15 1]
    ASSERT_BINOMIAL_COEFFICIENT(15, 0, 1);
    ASSERT_BINOMIAL_COEFFICIENT(15, 1, 15);
    ASSERT_BINOMIAL_COEFFICIENT(15, 2, 105);
    ASSERT_BINOMIAL_COEFFICIENT(15, 3, 455);
    ASSERT_BINOMIAL_COEFFICIENT(15, 4, 1365);
    ASSERT_BINOMIAL_COEFFICIENT(15, 5, 3003);
    ASSERT_BINOMIAL_COEFFICIENT(15, 6, 5005);
    ASSERT_BINOMIAL_COEFFICIENT(15, 7, 6435);
    ASSERT_BINOMIAL_COEFFICIENT(15, 8, 6435);
    ASSERT_BINOMIAL_COEFFICIENT(15, 9, 5005);
    ASSERT_BINOMIAL_COEFFICIENT(15, 10, 3003);
    ASSERT_BINOMIAL_COEFFICIENT(15, 11, 1365);
    ASSERT_BINOMIAL_COEFFICIENT(15, 12, 455);
    ASSERT_BINOMIAL_COEFFICIENT(15, 13, 105);
    ASSERT_BINOMIAL_COEFFICIENT(15, 14, 15);
    ASSERT_BINOMIAL_COEFFICIENT(15, 15, 1);

    // N = 20 --> [1 20 190 1140 4845 15504 38760 77520 125970 167960 184756 167960 125970 77520 38760 15504 4845 1140 190 20 1]
    ASSERT_BINOMIAL_COEFFICIENT(20, 0, 1);
    ASSERT_BINOMIAL_COEFFICIENT(20, 1, 20);
    ASSERT_BINOMIAL_COEFFICIENT(20, 2, 190);
    ASSERT_BINOMIAL_COEFFICIENT(20, 3, 1140);
    ASSERT_BINOMIAL_COEFFICIENT(20, 4, 4845);
    ASSERT_BINOMIAL_COEFFICIENT(20, 5, 15504);
    ASSERT_BINOMIAL_COEFFICIENT(20, 6, 38760);
    ASSERT_BINOMIAL_COEFFICIENT(20, 7, 77520);
    ASSERT_BINOMIAL_COEFFICIENT(20, 8, 125970);
    ASSERT_BINOMIAL_COEFFICIENT(20, 9, 167960);
    ASSERT_BINOMIAL_COEFFICIENT(20, 10, 184756);
    ASSERT_BINOMIAL_COEFFICIENT(20, 11, 167960);
    ASSERT_BINOMIAL_COEFFICIENT(20, 12, 125970);
    ASSERT_BINOMIAL_COEFFICIENT(20, 13, 77520);
    ASSERT_BINOMIAL_COEFFICIENT(20, 14, 38760);
    ASSERT_BINOMIAL_COEFFICIENT(20, 15, 15504);
    ASSERT_BINOMIAL_COEFFICIENT(20, 16, 4845);
    ASSERT_BINOMIAL_COEFFICIENT(20, 17, 1140);
    ASSERT_BINOMIAL_COEFFICIENT(20, 18, 190);
    ASSERT_BINOMIAL_COEFFICIENT(20, 19, 20);
    ASSERT_BINOMIAL_COEFFICIENT(20, 20, 1);
}

int main()
{
    binomial_tests();

    return 0;
}


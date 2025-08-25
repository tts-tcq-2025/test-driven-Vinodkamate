#include "gtest/gtest.h"
TEST(StringCalculatorTest, EmptyStringReturnsZero) {
    StringCalculator calc;
    EXPECT_EQ(calc.Add(""), 0);
}

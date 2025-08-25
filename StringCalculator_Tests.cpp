#include <gtest/gtest.h>
#include "StringCalculator.h"

// Step 1: Write the smallest possible failing test
TEST(StringCalculatorTest, EmptyStringReturnsZero) {
    StringCalculator calc;
    EXPECT_EQ(calc.Add(""), 0);
}

TEST(StringCalculatorTest, SingleNumberReturnsValue) {
    StringCalculator calc;
    EXPECT_EQ(calc.Add("1"), 1);
}

TEST(StringCalculatorTest, TwoNumbersCommaDelimitedReturnsSum) {
    StringCalculator calc;
    EXPECT_EQ(calc.Add("1,2"), 3);
}

TEST(StringCalculatorTest, UnknownAmountOfNumbersCommaDelimited) {
    StringCalculator calc;
    EXPECT_EQ(calc.Add("1,2,3,4"), 10);
}

TEST(StringCalculatorTest, HandlesNewLinesBetweenNumbers) {
    StringCalculator calc;
    EXPECT_EQ(calc.Add("1\n2,3"), 6);
}

TEST(StringCalculatorTest, CustomSingleCharacterDelimiter) {
    StringCalculator calc;
    EXPECT_EQ(calc.Add("//;\n1;2"), 3);
}

TEST(StringCalculatorTest, CustomDelimiterOfAnyLength) {
    StringCalculator calc;
    EXPECT_EQ(calc.Add("//[***]\n1***2***3"), 6);
}

TEST(StringCalculatorTest, NegativeNumberThrowsExceptionSingle) {
    StringCalculator calc;
    try {
        calc.Add("1,-2,3");
        FAIL() << "Expected exception";
    } catch (const std::runtime_error& e) {
        EXPECT_STREQ(e.what(), "negatives not allowed: -2");
    } catch (...) {
        FAIL() << "Expected std::runtime_error";
    }
}

TEST(StringCalculatorTest, NegativeNumbersThrowExceptionMultiple) {
    StringCalculator calc;
    try {
        calc.Add("1,-2,-3");
        FAIL() << "Expected exception";
    } catch (const std::runtime_error& e) {
        EXPECT_STREQ(e.what(), "negatives not allowed: -2, -3");
    } catch (...) {
        FAIL() << "Expected std::runtime_error";
    }
}

TEST(StringCalculatorTest, NumbersGreaterThan1000AreIgnored) {
    StringCalculator calc;
    EXPECT_EQ(calc.Add("2,1001"), 2);
}

TEST(StringCalculatorTest, DelimiterAnyLengthWithNumbersGreaterThan1000) {
    StringCalculator calc;
    EXPECT_EQ(calc.Add("//[***]\n1***2***1001"), 3);
}

TEST(StringCalculatorTest, MultipleDelimiters) {
    StringCalculator calc;
    EXPECT_EQ(calc.Add("//[*][%]\n1*2%3"), 6);
}

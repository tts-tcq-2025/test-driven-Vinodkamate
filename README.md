# TDD Driven StringCalculator

Build a StringCalculator functionality that can take up to two numbers, separated by commas, and will return their sum. 
for example “” or “1” or “1,2” as inputs.

> DO NOT jump into implementation! Read the example and the starting task below.

- For an empty string it will return 0
- Allow the Add method to handle an unknown amount of numbers
- Allow the Add method to handle new lines between numbers (instead of commas).
  - the following input is ok: “1\n2,3” (will equal 6)
  - the following input is NOT ok: “1,\n” (not need to prove it - just clarifying)
- Support different delimiters : to change a delimiter, the beginning of the string will contain a separate line that looks like this: “//[delimiter]\n[numbers…]” for example “//;\n1;2” should return three where the default delimiter is ‘;’ .
the first line is optional. all existing scenarios should still be supported
- Calling Method with a negative number will throw an exception “negatives not allowed” - and the negative that was passed. if there are multiple negatives, show all of them in the exception message.
- Numbers bigger than 1000 should be ignored, so adding 2 + 1001 = 2
- Delimiters can be of any length with the following format: “//[delimiter]\n” for example: “//[***]\n1***2***3” should return 6

## Test Specifications for StringCalculator

Empty String Returns 0

Input: ""
Output: 0
Single Number Returns Value

Input: "1"
Output: 1
Two Numbers, Comma Delimited, Returns Sum

Input: "1,2"
Output: 3
Unknown Amount of Numbers, Comma Delimited

Input: "1,2,3,4"
Output: 10
Handles New Lines Between Numbers

Input: "1\n2,3"
Output: 6
Custom Single-Character Delimiter

Input: "//;\n1;2"
Output: 3
Custom Delimiter of Any Length

Input: "//[***]\n1***2***3"
Output: 6
Multiple Delimiters (if supported)

Input: "//[*][%]\n1*2%3"
Output: 6
Negative Numbers Throw Exception

Input: "1,-2,3"

Output: Exception with message "negatives not allowed: -2"

Input: "1,-2,-3"

Output: Exception with message "negatives not allowed: -2, -3"

Numbers Greater Than 1000 Are Ignored

Input: "2,1001"
Output: 2
Delimiter Edge Cases

Input: "//[***]\n1***2***1001"
Output: 3
Invalid Input (Clarification)

Input: "1,\n"
Output: (Not required to handle, just clarified as invalid)


## In Gherkin language
Feature: String Calculator

  Scenario: Empty string returns 0
    Given the input is ""
    When I call Add
    Then the result should be 0

  Scenario: Single number returns its value
    Given the input is "1"
    When I call Add
    Then the result should be 1

  Scenario: Two numbers, comma delimited, returns sum
    Given the input is "1,2"
    When I call Add
    Then the result should be 3

  Scenario: Unknown amount of numbers, comma delimited
    Given the input is "1,2,3,4"
    When I call Add
    Then the result should be 10

  Scenario: Handles new lines between numbers
    Given the input is "1\n2,3"
    When I call Add
    Then the result should be 6

  Scenario: Custom single-character delimiter
    Given the input is "//;\n1;2"
    When I call Add
    Then the result should be 3

  Scenario: Custom delimiter of any length
    Given the input is "//[***]\n1***2***3"
    When I call Add
    Then the result should be 6

  Scenario: Negative numbers throw exception with single negative
    Given the input is "1,-2,3"
    When I call Add
    Then an exception should be thrown with message "negatives not allowed: -2"

  Scenario: Negative numbers throw exception with multiple negatives
    Given the input is "1,-2,-3"
    When I call Add
    Then an exception should be thrown with message "negatives not allowed: -2, -3"

  Scenario: Numbers greater than 1000 are ignored
    Given the input is "2,1001"
    When I call Add
    Then the result should be 2

  Scenario: Delimiter of any length with numbers greater than 1000
    Given the input is "//[***]\n1***2***1001"
    When I call Add
    Then the result should be 3

## Tabular Form

	| Scenario Description                                   | Input                    | Expected Output / Exception Message                |
|--------------------------------------------------------|--------------------------|----------------------------------------------------|
| Empty string returns 0                                 | `""`                     | `0`                                                |
| Single number returns its value                        | `"1"`                    | `1`                                                |
| Two numbers, comma delimited, returns sum              | `"1,2"`                  | `3`                                                |
| Unknown amount of numbers, comma delimited             | `"1,2,3,4"`              | `10`                                               |
| Handles new lines between numbers                      | `"1\n2,3"`               | `6`                                                |
| Custom single-character delimiter                      | `"//;\n1;2"`             | `3`                                                |
| Custom delimiter of any length                         | `"//[***]\n1***2***3"`   | `6`                                                |
| Negative number throws exception (single negative)     | `"1,-2,3"`               | Exception: `negatives not allowed: -2`             |
| Negative numbers throw exception (multiple negatives)  | `"1,-2,-3"`              | Exception: `negatives not allowed: -2, -3`         |
| Numbers greater than 1000 are ignored                  | `"2,1001"`               | `2`                                                |
| Delimiter any length with numbers >1000                | `"//[***]\n1***2***1001"`| `3`                                                |

## Tasks



Establish quality parameters:

- Ensure  maximum complexity (CCN) per function == 3

- Ensure 100% line and branch coverage at every step

  

Start Test-driven approach

1. Write the smallest possible failing test: give input `"" assert output to be 0 ` .
2. Write the minimum amount of code that'll make it pass.
3. Refactor any assumptions, continue to pass this test. Do not add any code without a corresponding test.

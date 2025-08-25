#include "StringCalculator.h"
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>

int StringCalculator::Add(const std::string& numbers) {
    if (numbers.empty()) return 0;

    std::string delimiters = ",\n";
    std::string nums = numbers;
    std::vector<std::string> customDelims;

    // Handle custom delimiter
    if (nums.rfind("//", 0) == 0) {
        size_t delimEnd = nums.find('\n');
        if (nums[2] == '[') {
            size_t pos = 2;
            while (pos < delimEnd) {
                size_t open = nums.find('[', pos);
                size_t close = nums.find(']', open);
                if (open == std::string::npos || close == std::string::npos || close > delimEnd) break;
                customDelims.push_back(nums.substr(open + 1, close - open - 1));
                pos = close + 1;
            }
        } else {
            customDelims.push_back(std::string(1, nums[2]));
        }
        nums = nums.substr(delimEnd + 1);
    }

    // Replace all custom delimiters with ','
    for (const auto& d : customDelims) {
        size_t pos = 0;
        while ((pos = nums.find(d, pos)) != std::string::npos) {
            nums.replace(pos, d.length(), ",");
            pos += 1;
        }
    }
    // Replace default delimiters with ','
    for (char d : delimiters) {
        std::replace(nums.begin(), nums.end(), d, ',');
    }

    std::vector<int> negatives;
    int sum = 0;
    std::stringstream ss(nums);
    std::string token;
    while (std::getline(ss, token, ',')) {
        if (token.empty()) continue;
        int n = std::stoi(token);
        if (n < 0) negatives.push_back(n);
        if (n <= 1000) sum += n;
    }
    if (!negatives.empty()) {
        std::string msg = "negatives not allowed: ";
        for (size_t i = 0; i < negatives.size(); ++i) {
            msg += std::to_string(negatives[i]);
            if (i + 1 < negatives.size()) msg += ", ";
        }
        throw std::runtime_error(msg);
    }
    return sum;
}


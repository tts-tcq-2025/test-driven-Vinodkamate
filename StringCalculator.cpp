#include "StringCalculator.h"
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <cstdio>

namespace {
    void ReplaceAll(std::string& str, const std::string& from, const std::string& to) {
        size_t pos = 0;
        while ((pos = str.find(from, pos)) != std::string::npos) {
            str.replace(pos, from.length(), to);
            pos += to.length();
        }
    }
    void ReplaceAllChars(std::string& str, const std::string& chars, char to) {
        for (char c : chars) std::replace(str.begin(), str.end(), c, to);
    }
    std::string JoinNegatives(const std::vector<int>& negatives) {
        std::string msg = "negatives not allowed: ";
        char buf[32];
        for (size_t i = 0; i < negatives.size(); ++i) {
            std::sprintf(buf, "%d", negatives[i]);
            msg += buf;
            if (i + 1 < negatives.size()) msg += ", ";
        }
        return msg;
    }
}

int StringCalculator::Add(const std::string& numbers) {
    if (numbers.empty()) return 0;
    std::string delimiters = ",\n";
    std::string nums = numbers;
    std::vector<std::string> customDelims;
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
    for (const auto& d : customDelims) ReplaceAll(nums, d, ",");
    ReplaceAllChars(nums, delimiters, ',');
    std::vector<int> negatives;
    int sum = 0;
    std::stringstream ss(nums);
    std::string token;
    while (std::getline(ss, token, ',')) {
        if (token.empty()) continue;
        int n = std::atoi(token.c_str());
        if (n < 0) negatives.push_back(n);
        if (n <= 1000) sum += n;
    }
    if (!negatives.empty()) throw std::runtime_error(JoinNegatives(negatives));
    return sum;
}

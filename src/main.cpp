#include "Solution/question.h"

int main() {
    Solution sol;
    vector<int> vec = {1};

    auto rev = sol.goodDaysToRobBank(vec, 5);
    for (auto &it : rev) {
        cout << it << ",";
    }
}
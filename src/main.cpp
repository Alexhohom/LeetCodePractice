#include "Solution/question.h"

int main() {
    Solution sol;
    // vector<int> vec;
    uint32_t a = 0B11111111111111111111111111111101;
    uint32_t b = 0B10;
    uint32_t n = 0B00000010100101000001111010011100;
    cout << sol.reverseBits(n) << endl;
}
#include <iostream>
#include <stack>
#include <stdint.h>
#include <vector>

using std::cout;
using std::endl;
using std::stack;
using std::vector;
class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        int n = nums.size();
        vector<int> minLeft(n), minRight(n), maxLeft(n), maxRight(n);
        stack<int> minStack, maxStack;
        for (int i = 0; i < n; i++) {
            while (!minStack.empty() && nums[minStack.top()] > nums[i]) {
                minStack.pop();
            }
            minLeft[i] = minStack.empty() ? -1 : minStack.top();
            minStack.push(i);

            // 如果 nums[maxStack.top()] == nums[i], 那么根据定义，
            // nums[maxStack.top()] 逻辑上小于 nums[i]，因为 maxStack.top() < i
            while (!maxStack.empty() && nums[maxStack.top()] <= nums[i]) {
                maxStack.pop();
            }
            maxLeft[i] = maxStack.empty() ? -1 : maxStack.top();
            maxStack.push(i);
        }
        minStack = stack<int>();
        maxStack = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            // 如果 nums[minStack.top()] == nums[i], 那么根据定义，
            // nums[minStack.top()] 逻辑上大于 nums[i]，因为 minStack.top() > i
            while (!minStack.empty() && nums[minStack.top()] >= nums[i]) {
                minStack.pop();
            }
            minRight[i] = minStack.empty() ? n : minStack.top();
            minStack.push(i);

            while (!maxStack.empty() && nums[maxStack.top()] < nums[i]) {
                maxStack.pop();
            }
            maxRight[i] = maxStack.empty() ? n : maxStack.top();
            maxStack.push(i);
        }

        long long sumMax = 0, sumMin = 0;
        for (int i = 0; i < n; i++) {
            sumMax += static_cast<long long>(maxRight[i] - i) *
                      (i - maxLeft[i]) * nums[i];
            sumMin += static_cast<long long>(minRight[i] - i) *
                      (i - minLeft[i]) * nums[i];
        }
        return sumMax - sumMin;
    }
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        for (int i = 0; i < 32; ++i) {
            rev <<= 1;
            rev += n & 1; // rev 加上个位数
            n >>= 1;
        }
        return rev;
    }
    /*     bool judge(vector<int> &vec, int start, int end, bool isUp) {
            int rec = vec[start];
            for (; start <= end; ++start) {
                if (!isUp) {
                    if (rec < vec[start])
                        return false;
                    rec = vec[start];
                } else {
                    if (rec > vec[start])
                        return false;
                    rec = vec[start];
                }
            }
            return true;
        } */
    vector<int> goodDaysToRobBank(vector<int> &security, int time) {
        int size = security.size();
        // vec 长度没有两倍time长
        if (security.size() < time * 2)
            return {};
        vector<int> left(size, 0);
        vector<int> right(size, 0);
        for (int i = 1; i < size; ++i) {
            if (security[i] <= security[i - 1])
                left[i] = left[i - 1] + 1;
            if (security[size - i - 1] <= security[size - i])
                right[size - i - 1] = right[size - i] + 1;
        }
        vector<int> rev;
        for (int i = time; i < size - time; ++i) {
            if (left[i] >= time && right[i] >= time)
                rev.emplace_back(i);
        }
        return rev;
    }
};
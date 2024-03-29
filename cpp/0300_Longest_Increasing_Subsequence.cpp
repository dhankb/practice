#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ret = 1;

        for (int i = 1; i < nums.size(); i++) {
            // Binary search
            int l = 0, r = ret, m = 0;
            while (l < r) {
                m = l + (r - l) / 2;
                if (nums[m] >= nums[i]) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }

            // Insert
            nums[l] = nums[i];
            ret = max(ret, l + 1);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;

    // Input: nums = [10,9,2,5,3,7,101,18]
    // Output: 4
    nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << solution.lengthOfLIS(nums) << endl;

    // Input: nums = [0,1,0,3,2,3]
    // Output: 4
    nums = {0, 1, 0, 3, 2, 3};
    cout << solution.lengthOfLIS(nums) << endl;

    // Input: nums = [7,7,7,7,7,7,7]
    // Output: 1
    nums = {7, 7, 7, 7, 7, 7, 7};
    cout << solution.lengthOfLIS(nums) << endl;

    return 0;
}

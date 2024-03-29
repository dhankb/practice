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
    int countSubstrings(string s) {
        int ret = 0;
        int l, r;

        for (int i = 0; i < s.length(); i++) {
            ret++;

            l = i; r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                ret++;
                l--; r++;
            }

            l = i - 1; r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                ret++;
                l--; r++;
            }
        }

        return ret;
    }
};

/*
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        for (int i = 0; i < s.length(); i++)
            dp[i][i] = true;

        int ret = s.length();
        for (int i = s.length() - 2; i >= 0; i--) {
            for (int j = i + 1; j < s.length(); j++) {
                if (s[i] == s[j]) {
                    if (j - i == 1 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        ret++;
                    }
                }
            }
        }

        return ret;
    }
};
*/

int main(int argc, char *argv[]) {
    Solution solution;
    string s;

    // Input: s = "abc"
    // Output: 3
    s = "abc";
    cout << solution.countSubstrings(s) << endl;

    // Input: s = "aaa"
    // Output: 6
    s = "aaa";
    cout << solution.countSubstrings(s) << endl;

    return 0;
}

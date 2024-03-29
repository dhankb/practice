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
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += (dp[j] * dp[i - 1 - j]);
            }
        }

        return dp[n];
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    for (int i = 1; i < 20; i++) {
        printf("%2u: %d\n", i, solution.numTrees(i));
    }

    return 0;
}

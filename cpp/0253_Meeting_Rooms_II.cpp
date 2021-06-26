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
    static bool comp(vector<int>& a, vector<int>& b) {
        return (a[0] != b[0]) ? (a[0] < b[0]) : (a[1] < b[1]);
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector <int>> record;

        for (auto i : intervals) {
            bool addon = false;
            for (auto &r : record) {
                if (r[1] <= i[0]) {
                    r[1] = i[1];
                    addon = true;
                    break;
                }
            }

            if (!addon)
                record.push_back({i[0], i[1]});
        }

        return record.size();
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<int>> intervals;

    // Input: intervals = [[0,30],[5,10],[15,20]]
    // Output: 2
    intervals = {{0, 30}, {5, 10}, {15, 20}};
    cout << solution.minMeetingRooms(intervals) << endl;

    // Input: intervals = [[7,10],[2,4]]
    // Output: 1
    intervals = {{7, 10}, {2, 4}};
    cout << solution.minMeetingRooms(intervals) << endl;

    return 0;
}

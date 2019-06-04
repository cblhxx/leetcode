#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret {};

        int i = 0;
        while(i < intervals.size() && intervals[i][1] < newInterval[0])
            ret.push_back(intervals[i++]);

        ret.push_back(newInterval);
        while(i < intervals.size() && intervals[i][0] <= ret.back()[1]) {
            ret.back()[0] = min(ret.back()[0], intervals[i][0]);
            ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            i++;
        }

        while(i < intervals.size())
            ret.push_back(intervals[i++]);
        return ret;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals {{1,2}, {3,5}, {6,7}, {8,10}, {12, 16}};
    vector<int> newInterval = {4, 8};
    auto ret = s.insert(intervals, newInterval);

    for (auto &interval : ret) {
        for (auto num : interval) {
            cout << num << " ";
        }
        cout << endl;
    }


  return 0;
}

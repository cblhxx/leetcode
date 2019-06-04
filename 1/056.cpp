#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
                [](const vector<int>& a, const vector<int> &b) -> bool {
                    return a[0] < b[0];
                });

        vector<vector<int>> ret {};
        if (intervals.size() == 0)
            return ret;

        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start <= ret.back()[1])
                ret.back()[1] = std::max(end, ret.back()[1]);
            else
                ret.push_back(intervals[i]);
        }

        return ret;
    }
};

int main() {
    vector<vector<int>> intervals{{1,3}, {2,6}, {8,10}, {15,18}};
    Solution s;
    auto ret = s.merge(intervals);
    for (auto &interval : ret) {
        for (auto num : interval) {
            cout << num << " ";
        }
        cout << endl;
    }


  return 0;
}

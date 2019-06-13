#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void _combine(int n, int k, vector<int> &one, vector<vector<int>> &ret) {
        int pos = one.size();
        if (pos == k) {
            ret.push_back(one);
            return;
        }

        int begin = (one.size() == 0? 1: one.back() + 1);
        int end = n + pos - k + 1;
        while (begin <= end) {
            one.push_back(begin);
            _combine(n, k, one, ret);
            one.pop_back();
            begin++;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> one;
        if (n <= 0 || k <= 0)
            return ret;

        _combine(n, k, one, ret);

        return ret;
    }

};

int main() {
    Solution s;
    auto ret = s.combine(4,2);
    for (auto p : ret) {
        for (auto n : p) {
            cout << n << " ";
        }
        cout << endl;
    }


  return 0;
}

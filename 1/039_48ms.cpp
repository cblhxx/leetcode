#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> __combinationSum(vector<int>& candidates, int target, int idx) {
        vector<vector<int>> ret {};
        //cout << idx << " " << target << endl;
        if (idx >= candidates.size() || candidates[idx] > target)
            return ret;
        if (candidates[idx] == target)
            return vector<vector<int>>{{candidates[idx]}};

        vector<vector<int>> cans;
        vector<vector<int>> cans1 = this->__combinationSum(candidates, target - candidates[idx], idx);
        vector<vector<int>> cans3 = this->__combinationSum(candidates, target, idx+1);
        for (auto &can : cans1) {
            vector<int> tmp;
            tmp.push_back(candidates[idx]);
            for (auto &n : can) {
                tmp.push_back(n);
            }
            cans.push_back(tmp);
        }
        for (auto &can : cans3) {
            cans.push_back(can);
        }
        return cans;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return __combinationSum(candidates, target, 0);
    }
};

int main() {
    Solution s;
    vector<int> candidates {2, 3, 5};
    auto combs = s.combinationSum(candidates, 8);
    for (auto &can : combs) {
        for (auto num : can) {
            cout << num << " ";
        }
        cout << endl;
    }



  return 0;
}

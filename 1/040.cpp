#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& combination, int l) {
        if (target == 0) {
            //cout << "got match" <<  l << " " << target << endl;
            res.push_back(combination);
            return;
        }

        for (int i = l; i < candidates.size() && candidates[i] <= target; i++) {
            if (i != l && candidates[i] == candidates[i-1])
                continue;
            //cout << l << " " << i << " " << target << " c1:" << candidates[i] << " c2:" << candidates[i-1] << endl;
            combination.push_back(candidates[i]);
            this->dfs(candidates, target-candidates[i], res, combination, i+1);
            combination.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res{};
        vector<int> combination{};
        sort(candidates.begin(), candidates.end());

        //for (auto num : candidates) { cout << num << " "; } cout << endl;
        this->dfs(candidates, target, res, combination, 0);
        return res;
    }
};


int main() {
    Solution s;
    vector<int> candidates {10, 1, 2, 7, 5, 1, 6};
    auto combs = s.combinationSum2(candidates, 8);
    cout << combs.size() << endl;
    for (auto &can : combs) {
        for (auto num : can) {
            cout << num << " ";
        }
        cout << endl;
    }

  return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map{};

        for (auto const &str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            map[tmp].push_back(str);
        }

        vector<vector<string>> ret;
        for (auto const &line: map) {
            ret.push_back(line.second);
        }

        return ret;
    }
};

int main() {
    Solution s;
    vector<string> strs {"abc", "bcd", "abcc", "cba"};
    auto ret = s.groupAnagrams(strs);
    for (auto &group : ret) {
        for (auto &str : group) {
            cout << str << " ";
        }
        cout << endl;
    }


  return 0;
}

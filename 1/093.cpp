#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void solve(string s, vector<string> &ret, vector<int> &curr, int pos) {
        if (curr.size() == 3) {
            if (pos >= s.length())
                return;
            if (s.length() - pos > 3)
                return;
            if (s[pos] == '0' && pos != (s.length() - 1))
                return;
            auto n = stol(s.substr(pos, s.length() - pos));
            if (n <= 255) {
                stringstream ss;
                ss << curr[0] << "." << curr[1] << "." << curr[2] << "." << n;
                ret.push_back(ss.str());
            }
            return;
        }

        for (int i = 0; i < 3 && pos + i < s.length(); i++) {
            auto n = stol(s.substr(pos, i+1));
            if (n <= 255) {
                curr.push_back(n);
                solve(s, ret, curr, pos+i+1);
                curr.pop_back();
            }
            if (n == 0)
                break;
        }

    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret{};
        vector<int> curr{};
        solve(s, ret, curr, 0);
        return ret;
    }
};

int main() {
    Solution s;
    auto ret = s.restoreIpAddresses("00000");
    for (auto ip: ret) {
        cout << ip << endl;
    }


  return 0;
}

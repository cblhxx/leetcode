#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        int n = path.size();
        size_t l = 0;
        string word;
        string ret;

        while (l < path.length()) {
            auto pos = path.find('/', l);
            if (pos == l) {
                l++;
                continue;
            }
            if (pos == string::npos)
                pos = path.length();
            word = path.substr(l, pos - l);
            //cout << l << " " << pos << " " << word << endl;
            if (word == "." || (word == ".." && dirs.size() == 0)) {
                l = pos + 1;
                continue;
            }
            if (word == "..")
                dirs.pop_back();
            else
                dirs.push_back(word);
            l = pos + 1;
        }

        for (auto &w: dirs) {
            ret += "/" + w;
        }
        if (ret.length() == 0)
            ret = "/";
        return ret;
    }
};

inline void TEST(string path) {
    Solution s;
    cout << path << "        " << s.simplifyPath(path) << endl;
}
int main() {
    TEST("../c/");
    TEST("/home/");
    TEST("/../");
    TEST("/home//foo/");
    TEST("/a/./b/../../c/");
    TEST("/a/../../b/../c//.//");
    TEST("/a//b////c/d//././/..");


  return 0;
}

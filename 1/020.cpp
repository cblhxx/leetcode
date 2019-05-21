#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, int> dict{{'(', 1}, {')', 1}, {'[', 2}, {']', 2}, {'{', 3}, {'}', 3}};
class Solution {
public:
    bool isValid(string s) {
        vector<int> stack;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push_back(dict[c]);
                continue;
            }

            if (stack.size() == 0)
                return false;
            if (dict[c] != stack.back())
                return false;
            stack.pop_back();
        }
        if (stack.size() > 0)
            return false;

        return true;
    }
};

int main() {
    Solution s;
    cout << s.isValid("()") << endl;
    cout << s.isValid("(())") << endl;
    cout << s.isValid("(([]){}){}") << endl;
    cout << s.isValid("(([])}{){}") << endl;


  return 0;
}

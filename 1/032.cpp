#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack;
        int max_len = 0;

        int i = 0;
        while (i < s.length()) {
            while(s[i] == ')') i++;
            int l = i;
            int r = i;

            for (r = i; r < s.length(); r++) {
                //cout << i << " "<< r << endl;
                if (s[r] == '(')
                    stack.push_back(r);
                else if (s[r] == ')' && stack.size() > 0) {
                    int front = l;
                    stack.pop_back();
                    if (stack.size() > 0)
                        front = stack.back() + 1;
                    max_len = max(max_len, r - front + 1);
                }
                else {
                    stack.erase(stack.begin(), stack.end());
                    break;
                }
            }
            i = r + 1;
        }

        return max_len;
    }
};

int main() {
    Solution s;
    string str = "(()(()";

    cout << s.longestValidParentheses(str) << endl;


  return 0;
}

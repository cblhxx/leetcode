#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len_h = haystack.size();
        int len_n = needle.size();
        if (len_n == 0)
            return 0;
        if (len_n > len_h)
            return -1;

        for (int i = 0; i < len_h - len_n + 1; i++) {
            int j = 0;
            for (j = 0; j < len_n; j++) {
                if (needle[j] != haystack[i+j])
                    break;
            }
            if (j == len_n)
                return i;
        }
        return -1;

    }
};

int main() {
    Solution s;
    string haystack = "hello";
    string needle = "ll";
    cout << s.strStr(haystack, needle) << endl;


  return 0;
}

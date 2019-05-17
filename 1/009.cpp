#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        stringstream ss;
        ss << x;
        auto str = ss.str();
        size_t len = str.size();
        int i = (len - 1) / 2, j = ceil((len - 1) / 2.0);
        while(i >= 0 && str[i] == str[j]) {
            i--;
            j++;
        }
        if (i < 0)
            return true;
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(-121) << endl;
    cout << s.isPalindrome(123) << endl;;


  return 0;
}

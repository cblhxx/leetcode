#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows);
        int row = 0;
        bool down = true;

        if (numRows == 1)
            return s;

        //for (int i = 0; i < s.size(); i++) {
        for (auto& c : s) {
            v[row] += c;
            if (row == 0)
                down = true;
            if (row == v.size() - 1)
                down = false;
            if (down)
                row++;
            else
                row--;
        }
        string ret;
        for (auto& line : v)
            ret += line;
        return ret;
    }
};

int main() {
    Solution s;
    string str = "LEETCODEISHIRING";
    cout << s.convert(str, 1) << endl;
    cout << s.convert(str, 2) << endl;
    cout << s.convert(str, 3) << endl;
    cout << s.convert(str, 4) << endl;


  return 0;
}

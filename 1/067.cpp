#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string &str_long = (a.size() > b.size() ? a : b);
        string &str_short = (a.size() <= b.size() ? a : b);
        size_t n_long = str_long.size();
        size_t n_short = str_short.size();

        int carry = 0;
        for (size_t i = 1; i <= n_short; i++) {
            if (str_short[n_short-i] != str_long[n_long-i]) {
                str_long[n_long-i] = '1' - carry;
            }
            else if (str_long[n_long-i] == '1') {
                str_long[n_long-i] = '0' + carry;
                carry = 1;
            }
            else if (str_long[n_long-i] == '0' && carry == 1) {
                carry = 0;
                str_long[n_long-i] = '1';
            }
        }

        //cout << str_long << " " << str_short << endl;
        //cout << n_long << " " << n_short << endl;
        for (int i = n_long - n_short - 1; i >= 0 && carry > 0; i--) {
            if (str_long[i] == '1') {
                str_long[i] = '0';
            }
            else {
                str_long[i] = '1';
                carry = 0;
            }
        }
        if (carry == 1)
            str_long.insert(str_long.begin(), '1');

        return str_long;
    }
};

int main() {
    Solution s;
    cout << s.addBinary("10001010", "1011") << endl;
    cout << s.addBinary("1010", "1011") << endl;


  return 0;
}

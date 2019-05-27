#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string ret;
        if (num2 == "0" || num1 == "0")
            return "0";

        int carry = 0;
        int pos = 0;
        for (int i = num2.size()-1; i >=0; i--) {
            string tmp;
            int n2 = num2[i] - '0';
            for (int j = num1.size()-1; j >= 0; j--) {
                int n1 = num1[j] - '0';
                tmp.push_back((n1 * n2 + carry) % 10 + '0');
                carry = (n1 * n2 + carry) / 10;
            }
            if (carry > 0)
                tmp.push_back((carry) % 10 + '0');
            carry = 0;
            for (int j = ret.size(); j < pos; j++) {
                ret.push_back('0');
            }
            for (int j = 0; j < tmp.size(); j++) {
                int a = tmp[j] - '0';
                int b = 0;
                if (pos + j < ret.size()) {
                    b = ret[pos+j] - '0';
                }
                int c = (a + b + carry) % 10;
                carry = (a + b + carry) / 10;
                //cout << "a:" << a << " b:" << b << " c:" << c << " carry: " << carry << endl;
                if (pos + j >= ret.size()) {
                    ret.push_back(c + '0');
                }
                else {
                    ret[pos + j] = c + '0';
                }
                //cout << pos << " " << j << " " << ret[pos + j] << endl;
            }
            for (int k = pos + tmp.size(); carry > 0; k++) {
                if (k >= ret.size()) {
                    ret.push_back(carry + '0');
                    carry = 0;
                }
                else {
                    ret[k] = (ret[k] - '0' + carry) % 10 + '0';
                    carry = (ret[k] - '0' + carry) / 10;
                }
            }
            pos++;
            carry = 0;
            //reverse(tmp.begin(), tmp.end());
            //cout << tmp << endl;
            //cout << ret << endl;
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};

int main() {
    Solution s;
    cout << s.multiply("456", "123") << endl;


  return 0;
}

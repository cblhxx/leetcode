#include <iostream>

using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        if (n <= 1)
            return "1";

        string say = "1";
        while (n > 1) {
            string str = say;
            char num = str[0];
            int count = 1;
            say = "";

            for (int i = 1; i <= str.length(); i++) {
                if (i < str.length() && str[i] == num)
                    count++;
                else {
                    say += ('0' + count);
                    say += num;
                    num = str[i];
                    count = 1;
                }
            }
            n--;
        }
        return say;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(1) << endl;
    cout << s.countAndSay(2) << endl;
    cout << s.countAndSay(3) << endl;
    cout << s.countAndSay(4) << endl;
    cout << s.countAndSay(5) << endl;
    cout << s.countAndSay(6) << endl;


  return 0;
}

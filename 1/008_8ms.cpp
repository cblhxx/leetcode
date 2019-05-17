#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int int32_max = 0x7fffffff;
int int32_min = 0x80000000;

class Solution {
public:
    bool addToValue(int64_t& v, const int64_t num, const bool negtive) {
        if (!negtive) {
            v += num;
            if (v > int32_max) {
                v = int32_max;
                return true;
            }
        }
        else {
            v -= num;
            if (v < int32_min) {
                v = int32_min;
                return true;
            }
        }
        return false;

    }

    int myAtoi(string str) {
        bool negtive = false;
        int head = 0;
        int tail = 0;
        int64_t v = 0;
        int pos = 0;

        //cout << str << endl;

        if (str.size() == 0)
            return 0;
        while (str[head] == ' ' && head < str.size())
            head++;

        if (head < str.size() && str[head] == '-') {
            negtive = true;
            head++;
        }
        else if (head < str.size() && str[head] == '+') {
            head++;
        }

        while (head < str.size() && str[head] == '0')
            head++;

        tail = head;
        while (tail < str.size() && str[tail] >= '0' && str[tail] <= '9')
            tail++;

        if (tail - head > 10 && negtive) {
            return int32_min;
        }
        else if (tail - head > 10) {
            return int32_max;
        }

        for (int i = tail-1; i >= head; i--) {
            //cout << (int)str[i] << " " << (int)'0' << " " << (int)'9' << endl;
            if (str[i] < '0' || str[i] > '9') {
                break;
            }
            bool overflow = addToValue(v, (str[i] - '0') * pow(10, pos++), negtive);
            if (overflow) {
                break;
            }
        }

        return v;
    }
};

int main() {
    Solution s;
    cout << s.myAtoi("+-2") << endl;
    cout << s.myAtoi("   42") << endl;
    cout << s.myAtoi("   words  -42") << endl;
    cout << s.myAtoi("   words  -42   words") << endl;
    cout << s.myAtoi("   -42   words") << endl;
    cout << s.myAtoi("   words") << endl;
    cout << s.myAtoi("-91283472332") << endl;

  return 0;
}

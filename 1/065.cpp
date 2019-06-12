#include <iostream>

using namespace std;

enum NumStat { UNKNOWN, POSITIVE, NEGTIVE, INT, FLOATE, FLOATEE, FLOATX, EXPE, EXPEE, EXPX, END, ERROR };
class Solution {
public:
    bool isNumber(string s) {
        NumStat stat = UNKNOWN;
        size_t pos = 0;
        for (auto c: s) {
            switch (stat) {
                case UNKNOWN:
                    if (c == ' ')
                        stat = UNKNOWN;
                    else if (c == '-')
                        stat = NEGTIVE;
                    else if (c == '+')
                        stat = POSITIVE;
                    else if (c <= '9' && c >= '0')
                        stat = INT;
                    else if (c == '.')
                        stat = FLOATE;
                    else
                        stat = ERROR;
                    break;
                case POSITIVE:
                case NEGTIVE:
                    if (c <= '9' && c >= '0')
                        stat = INT;
                    else if (c == '.')
                        stat = FLOATE;
                    else
                        stat = ERROR;
                    break;
                case INT:
                    if (c <= '9' && c >= '0')
                        stat = INT;
                    else if (c == ' ')
                        stat = END;
                    else if (c == '.')
                        stat = FLOATEE;
                    else if (c == 'e')
                        stat = EXPE;
                    else
                        stat = ERROR;
                    break;
                case FLOATE:
                    if (c <= '9' && c >= '0')
                        stat = FLOATX;
                    else
                        stat = ERROR;
                    break;
                case FLOATEE:
                    if (c <= '9' && c >= '0')
                        stat = FLOATX;
                    else if (c == 'e')
                        stat = EXPE;
                    else if (c == ' ')
                        stat = END;
                    else
                        stat = ERROR;
                    break;
                case EXPE:
                    if (c == '-' || c == '+')
                        stat = EXPEE;
                    else if (c <= '9' && c >= '0')
                        stat = EXPX;
                    else
                        stat = ERROR;
                    break;
                case EXPEE:
                    if (c <= '9' && c >= '0')
                        stat = EXPX;
                    else
                        stat = ERROR;
                    break;
                case FLOATX:
                    if (c <= '9' && c >= '0')
                        stat = FLOATX;
                    else if (c == ' ')
                        stat = END;
                    else if (c == 'e')
                        stat = EXPE;
                    else
                        stat = ERROR;
                    break;
                case EXPX:
                    if (c <= '9' && c >= '0')
                        stat = EXPX;
                    else if (c == ' ')
                        stat = END;
                    else
                        stat = ERROR;
                    break;
                case END:
                    if (c != ' ')
                        stat = ERROR;
                    break;
                default:
                    return false;
            }
            //cout << c << " " << stat << endl;
            if (stat == ERROR)
                return false;
        }
        //cout << stat << endl;
        return (stat == INT || stat == EXPX || stat == FLOATX || stat == END || stat == FLOATEE);
    }
};

int main() {
    Solution s;
    cout << s.isNumber(". ") << endl;
    /*
    cout << s.isNumber(" 0") << endl;
    cout << s.isNumber(" 0.1") << endl;
    cout << s.isNumber("2e10") << endl;
    cout << s.isNumber("6e-1") << endl;
    cout << s.isNumber("53.5e93") << endl;
    cout << s.isNumber("abc") << endl;
    cout << s.isNumber("1 a") << endl;
    cout << s.isNumber("1e") << endl;
    cout << s.isNumber("e3") << endl;
    cout << s.isNumber("99e2.3") << endl;
    cout << s.isNumber("--6") << endl;
    cout << s.isNumber("+-6") << endl;
    */


  return 0;
}

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int l = 0, r = 0;
        int total = 0;
        int space = 0;
        string line;
        vector<string> ret;

        while(r < words.size()) {
            total += words[r].length();
            if ((total + (r - l)) > maxWidth) {
                //cout << l << " " << r << endl;
                line = "";
                total -= words[r].length();
                r = r - 1;
                space = maxWidth - total;
                while(l <= r) {
                    line += words[l];
                    //cout << space << " " << l << " "<< r << endl;
                    int distance = (r == l? space: std::ceil(((double)space) / (r-l)));
                    space -= distance;
                    line += string(distance, ' ');
                    l++;
                }
                ret.push_back(line);
                r++;
                l = r;
                total = 0;
            }
            else
                r++;
        }

        line = "";
        while (l < words.size() - 1) {
            line += words[l];
            line += ' ';
            l++;
        }

        if (l == (words.size() - 1)) {
            line += words[l];
            int len = line.length();
            line += string(maxWidth - len, ' ');
            ret.push_back(line);
        }

        return ret;
    }
};

int main() {
    Solution s;
    vector<string> words{"What","must","be","acknowledgment","shall","be"};
    auto ret = s.fullJustify(words, 16);
    for (auto &line : ret) {
        cout << line << endl;
    }


  return 0;
}

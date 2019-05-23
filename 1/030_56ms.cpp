#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> ret;
        if (s.length() == 0 || words.size() == 0)
            return ret;

        int sl = s.length();
        int wl = words[0].length();
        int wn = words.size();

        unordered_map<string, int> dict;
        for (auto &w : words) {
            dict[w]++;
        }

        for (int i = 0; i < wl; i++) {
            unordered_map<string, int> tdict;
            int left = i;
            int count = 0;
            for (int j = i; j <= sl - wl; j+=wl) {
                string str = s.substr(j, wl);
                //cout << str << " " << left << " " << j << " " << count <<endl;
                if (dict.find(str) != dict.end()) {
                    tdict[str]++;
                    count++;
                    //cout << "aa " << count << " " << wn << " " << tdict[str] << " " << dict[str]<< endl;
                    while (tdict[str] > dict[str]) {
                        string ts = s.substr(left, wl);
                        tdict[ts]--;
                        left += wl;
                        count--;
                    }
                    if (count == wn) {
                        ret.push_back(left);
                        str = s.substr(left, wl);
                        left += wl;
                        count--;
                        //cout << "pushE:" << str << " " << tdict[str]<< endl;
                        tdict[str]--;
                        //cout << "pushX:" << str << " " << tdict[str]<< endl;
                    }
                    //cout << "bb" << str << " " << left << " " << j << " " << tdict["foo"] << endl;
                }
                else {
                    tdict.clear();
                    left = j + wl;
                    count = 0;
                }
            }
        }

        return ret;
    }
};

int main() {
    Solution s;
    string str = "wordgoodgoodgoodbestword";
    cout << str << endl;
    //vector<string> words {"foo", "bar"};
    vector<string> words {"word","good","good", "best"};
    for (auto i : s.findSubstring(str, words)) {
        cout << i << " ";
    }
    cout << endl;

  return 0;
}

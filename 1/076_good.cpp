#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    inline bool is_match(unordered_map<char, int> &curr, unordered_map<char, int> &target, const string &s, string &ret, int l, int r, int &minl) {
        for (auto &pair : target) {
            if (curr[pair.first] < pair.second)
                return false;
        }
        if (r - l + 1< minl) {
            minl = r - l + 1;
            ret = s.substr(l, r - l + 1);
        }

        return true;
    }
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size()){
            if(map[s[end++]]-->0) counter--; //in t
            while(counter==0){ //valid
                if(end-begin<d)  d=end-(head=begin);
                if(map[s[begin++]]++==0) counter++;  //make it invalid
            }
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
};

int main() {
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << s.minWindow("ADOBECODEBANC", "AABC") << endl;
    cout << s.minWindow("ADOBECODEBANC", "ABBC") << endl;
    cout << s.minWindow("ADOBECODEBANC", "ABCC") << endl;


  return 0;
}

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>s;
        if(n==0)
            return s;
        dfs("",s,n,n);
        return s;
    }
    void dfs(string tmp,vector<string>&s,int l,int r){
        //cout << tmp << " " << l << " " << r << endl;
        if(l==0 && r==0) {
            s.push_back(tmp);
            return;
        }
        if(r>l) {
            dfs(tmp+")",s,l,r-1);
        }
        if(l>0) {
            dfs(tmp+"(",s,l-1,r);
        }
    }
};

int main() {
    Solution s;
    vector<string> ret = s.generateParenthesis(3);
    for (auto &str : ret) {
        cout << str << endl;
    }

  return 0;
}

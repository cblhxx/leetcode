#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string str;
        for (int i = 1; i <= n; i++) {
            str.push_back('0' + i);
        }
        while (k-- > 1) {
            int i = n - 1, j = n - 1;
            while (i > 0 && str[i-1] > str[i]) i--;
            while (i > 0 && j > i && str[j] < str[i-1]) j--;
            //cout << i << " " <<j << endl;
            if (i > 0)
                std::swap(str[i-1], str[j]);
            sort(str.begin() + i, str.end());
        }
        return str;
    }
};

int main() {
    Solution s;
    //cout << s.getPermutation(9,926) << endl;
    cout << s.getPermutation(3,1) << endl;
    cout << s.getPermutation(3,2) << endl;
    cout << s.getPermutation(3,3) << endl;
    cout << s.getPermutation(3,4) << endl;
    cout << s.getPermutation(3,5) << endl;
    cout << s.getPermutation(3,6) << endl;
    cout << s.getPermutation(3,7) << endl;


  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string str;
        int cap = 1;
        for (int i = 1; i <= n; i++) {
            str.push_back('0' + i);
            cap *= i;
        }
        k--;
        k = k % cap;
        cap /= n;
        for (int i = 0; i < n - 1; i++) {
            int j = k / cap;
            k = k % cap;
            //cout << n << " " << i << " " << cap << endl;
            cap /= (n - i - 1);
            //cout << str << " " << i << " " << j << endl;
            swap(str[i], str[i+j]);
            sort(str.begin() + i + 1, str.end());
            //cout << str << " " << i << " " << j << endl;
        }
        return str;
    }
};

int main() {
    Solution s;
    //cout << s.getPermutation(9,926) << endl;
    //cout << s.getPermutation(3,3) << endl;
    cout << s.getPermutation(3,1) << endl;
    cout << s.getPermutation(3,2) << endl;
    cout << s.getPermutation(3,3) << endl;
    cout << s.getPermutation(3,4) << endl;
    cout << s.getPermutation(3,5) << endl;
    cout << s.getPermutation(3,6) << endl;
    cout << s.getPermutation(3,7) << endl;


  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0 && carry > 0; i--) {
            digits[i] = (digits[i] + carry) % 10;
            carry = (digits[i] == 0? 1: 0);
        }
        if (carry == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    vector<int> nums {9,9,9};
    Solution s;
    auto ret = s.plusOne(nums);
    for (auto num : ret)
        cout << num << " ";
    cout << endl;

  return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>

using namespace std;

class Solution {
    void utils(bitset<32>& bits, vector<int>& result, int k){
        if (k==0) {
            result.push_back(bits.to_ulong());
        }
        else {
            utils(bits, result, k-1);
            bits.flip(k-1);
            utils(bits, result, k-1);
        }
    }
public:
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> result;
        utils(bits, result, n);
        return result;
    }
};

int main() {
    Solution s;

    auto nums = s.grayCode(2);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;


  return 0;
}

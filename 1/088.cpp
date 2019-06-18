#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size = m + n;
        nums1.resize(size);
        for (int i = m-1; i >= 0; i--) {
            nums1[i+n] = nums1[i];
        }

        int i = n, j = 0, curr = 0;
        while (j < n) {
            if (i < size && nums1[i] < nums2[j]) {
                nums1[curr++] = nums1[i];
                i++;
            }
            else {
                nums1[curr++] = nums2[j];
                j++;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums1{1,2,3,0,0,0};
    vector<int> nums2{2,5,6};

    s.merge(nums1, 3, nums2, 3);

    for (auto n : nums1) {
        cout << n << " ";
    }
    cout << endl;


  return 0;
}

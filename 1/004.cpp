#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      size_t l1 = nums1.size();
      size_t l2 = nums2.size();
      size_t j1 = 0, j2 = 0;
      size_t len = l1 + l2;
      size_t mid = len / 2;
      int v1 = 0, v2 = 0;

      for (size_t i = 0; i <= mid; i++) {
        if (j2 >= l2 || (j1 < l1 && nums1[j1] <= nums2[j2])) {
          v1 = v2;
          v2 = nums1[j1];
          j1++;
        }
        else {
          v1 = v2;
          v2 = nums2[j2];
          j2++;
        }
      }

      if (len % 2 == 0)
        return double((v1 + v2)) / 2;
      return v2;
    }
};

int main() {
  Solution s;
  vector<int> n1{2};
  vector<int> n2{};

  std::cout << s.findMedianSortedArrays(n1, n2) << std::endl;

  return 0;
}

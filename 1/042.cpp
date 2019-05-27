#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height)
    {
        int l = 0;
        int r = height.size() - 1;
        int lmax = 0, rmax = 0;
        int sum = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                height[l] >= lmax ? lmax = height[l] : sum += (lmax - height[l]);
                l++;
            }
            else {
                height[r] >= rmax? rmax = height[r]: sum += (rmax - height[r]);
                r--;
            }
        }
        return sum;
    }
};

int main() {
    vector<int> hs{0,1,0,2,1,0,1,3,2,1,2};
    //vector<int> hs{5,2,1,2,1,5};
    Solution s;
    cout << s.trap(hs) << endl;


  return 0;
}

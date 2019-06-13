#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        int current = 1;           //新数组中有效位置的最后一位，新加入的数据应当写到current+1
        for (int i = 2; i < nums.size();i++) //从第三位开始循环，前两位无论如何都是要加入新数组的
        {
            if (nums[i] != nums[current - 1])  //符合条件，加入新数组
            {
                current += 1;
                nums[current] = nums[i];
            }
        }
        return current+1;
    }
};

int main() {
    Solution s;
    vector<int> nums{0,0,1,1,1,1,1,1,1,1,2,3,3};
    cout << s.removeDuplicates(nums) << endl;
    for (auto n : nums)
        cout << n << " ";
    cout << endl;


  return 0;
}

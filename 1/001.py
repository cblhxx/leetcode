#!/usr/bin/env python

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        ret = []
        d = {}
        l = len(nums)
        for i in range(l):
            d[nums[i]] = i
        for i in range(l):
            print i
            j = target - nums[i];
            if j in d and d[j] != i:
                print 'ret'
                print d[j]
                ret = [i, d[j]]
                break
        return ret

s = Solution()
print s.twoSum([2,7,3,9], 9)

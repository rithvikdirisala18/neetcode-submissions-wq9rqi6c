class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        for i, n in enumerate(nums):
            if n > 0:
                break
            if i > 0 and nums[i-1]==n:
                continue
            l = i+1
            r = len(nums)-1
            while l < r:
                sum = nums[l]+nums[r]+n
                if sum==0:
                    res.append([n, nums[l], nums[r]])
                    l+=1
                    r-=1
                    while l < r and nums[l]==nums[l-1]:
                        l+=1
                    while l < r and nums[r]==nums[r+1]:
                        r-=1
                elif sum > 0:
                    r-=1
                else:
                    l+=1
        return res
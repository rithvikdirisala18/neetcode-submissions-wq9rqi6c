class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [1]*n
        i = 1
        while i < n:
            res[i] = nums[i-1]*res[i-1]
            i+=1
        i = n-2
        temp = nums[n-1]
        while i >= 0:
            res[i] *= temp
            temp *= nums[i]
            i-=1
        return res

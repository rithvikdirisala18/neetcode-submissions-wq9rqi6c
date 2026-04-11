class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        l = set(nums)
        res = 0
        for n in nums:
            if not n-1 in l:
                cnt = 0
                curr = n
                while curr in l:
                    curr+=1
                    cnt+=1
                res = max(res, cnt)
        return res
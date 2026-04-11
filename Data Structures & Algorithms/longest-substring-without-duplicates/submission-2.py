class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        loc = {}
        res = 0
        curr = 0

        for ind in range(len(s)):
            if s[ind] in loc:
                curr = max(loc[s[ind]]+1, curr)
            loc[s[ind]] = ind
            res = max(res, ind-curr+1)
        return res
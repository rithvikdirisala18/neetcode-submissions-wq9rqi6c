class Solution:
    def trap(self, height: List[int]) -> int:
        l, r = 0, len(height)-1
        res = 0
        leftMax = 0
        rightMax = 0
        while l < r:
            if height[l]<leftMax:
                res+=leftMax-height[l]
            if height[r]<rightMax:
                res+=rightMax-height[r]
            leftMax = max(height[l], leftMax)
            rightMax = max(height[r], rightMax)
            if leftMax > rightMax:
                r-=1
            else:
                l+=1
        return res
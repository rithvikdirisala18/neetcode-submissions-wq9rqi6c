class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False

        charCount = [0]*26

        for i in range(len(s)):
            charCount[ord(s[i])-ord('a')]+=1
            charCount[ord(t[i])-ord('a')]-=1

        for c in charCount:
            if c != 0:
                return False
        return True
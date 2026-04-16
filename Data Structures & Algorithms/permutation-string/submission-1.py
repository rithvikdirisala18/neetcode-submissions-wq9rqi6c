class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        dict1 = [0]*26
        dict2 = [0]*26
        r = 0
        while r < len(s1):
            dict1[ord(s1[r])-ord('a')]+=1
            dict2[ord(s2[r])-ord('a')]+=1
            r+=1

        if dict1==dict2:
            return True
        while r < len(s2):
            dict2[ord(s2[r])-ord('a')]+=1
            dict2[ord(s2[r-len(s1)])-ord('a')]-=1
            if dict1==dict2:
                return True
            r+=1
        return False
        
        
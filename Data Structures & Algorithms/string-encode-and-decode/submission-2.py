class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            res+= str(len(s)) + "!" + s
        return res

    def decode(self, s: str) -> List[str]:
        res = []
        ind = 0
        while ind < len(s):
            j = ind
            while(s[j]!="!"):
                j+=1
            length = int(s[ind:j])
            ind = j+1
            j = ind +length
            res.append(s[ind:j])
            ind =j
        
        return res

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        for n in nums:
            count[n] = 1 + count.get(n, 0)
        
        pq = []
        for num in count.keys():
            heapq.heappush(pq, (count[num], num))
            if len(pq) > k:
                heapq.heappop(pq)

        res = []
        for i in range(k):
            res.append(heapq.heappop(pq)[1])
        return res
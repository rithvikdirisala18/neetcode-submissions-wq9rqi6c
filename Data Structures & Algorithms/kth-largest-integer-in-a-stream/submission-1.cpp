class KthLargest {
public:
    int sz;
    priority_queue<int, vector<int>, greater<>> pq;
    KthLargest(int k, vector<int>& nums) {
        sz = k;
        for(const int&i: nums){
            pq.push(i);
            if(pq.size()>sz) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>sz)pq.pop();
        return pq.top();
    }
};

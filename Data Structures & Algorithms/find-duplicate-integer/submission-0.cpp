class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast) break;
        }

        int s2 = 0;
        while (true){
            slow = nums[slow];
            s2 = nums[s2];
            if(slow==s2) return slow;
        }
        return 0;
    }
};

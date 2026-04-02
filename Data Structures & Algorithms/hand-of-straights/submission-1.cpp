class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        map<int, int> freq;
        for(const int& i: hand){
            freq[i]++;
        }
        for(int i = 0; i<hand.size()/groupSize; i++){
            int sz = 0;
            int smallest = (freq.begin()->first);
            while(sz<groupSize){
                if(!freq.count(smallest)) return false;
                freq[smallest]--;
                if(freq[smallest]==0){
                    freq.erase(smallest);
                }
                smallest++;
                sz++;
            }
        }
        return true;
    }
};

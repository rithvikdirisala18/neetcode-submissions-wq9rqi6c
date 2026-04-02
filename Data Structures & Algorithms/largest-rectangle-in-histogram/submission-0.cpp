class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int res = 0;
        for(int i = 0; i < heights.size(); i++){
            if(st.empty()){
                st.push({heights[i], i});
                continue;
            }

            if(st.top().first==heights[i]) continue;
            else if(st.top().first < heights[i]){
                st.push({heights[i], i});
            }
            else{
                int ind = i;
                while(!st.empty() && st.top().first>=heights[i]){
                    int rect = (i-st.top().second)*st.top().first;
                    res = max(res, rect);
                    ind = st.top().second;
                    st.pop();
                }
                st.push({heights[i], ind});
            }
        }
        while(!st.empty()){
            cout << st.top().first << " " << st.top().second << endl;
            int rect = (heights.size()-st.top().second)*st.top().first;
            res = max(res, rect);
            st.pop();
        }
        return res;
    }
};

// 1 2 4 --> push new

// 1 2 2 --> continue forward dont push

// 1 2 3 1 --> pop until current is >= top or st empty
// update res if rectangle formed from popping is larger

class Solution {
public:
    vector<int> picks;
    Solution(vector<int>& w) {
        int sum = 0;
        for(int i=0; i<w.size(); i++){
            sum += w[i];
            picks.push_back(sum);
        }//for
    }
    
    int pickIndex() {
        int r = rand() % picks[picks.size() - 1];
        int left = 0, right = picks.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if((r < picks[mid] && mid - 1 < 0) || (r < picks[mid] && r >= picks[mid-1]))
                return mid;
            if(r < picks[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }//while
        return 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

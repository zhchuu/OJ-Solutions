/*
  Weekly Contest 191
  1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
*/
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        int maxH = horizontalCuts[0];
        for(int i=0; i<horizontalCuts.size()-1; i++)
            maxH = max(maxH, horizontalCuts[i+1] - horizontalCuts[i]);
        maxH = max(maxH, h - horizontalCuts[horizontalCuts.size() - 1]);

        sort(verticalCuts.begin(), verticalCuts.end());
        int maxW = verticalCuts[0];
        for(int i=0; i<verticalCuts.size()-1; i++)
            maxW = max(maxW, verticalCuts[i+1] - verticalCuts[i]);
        maxW = max(maxW, w - verticalCuts[verticalCuts.size() - 1]);

        long long mh = maxH;
        long long mw = maxW;
        long long area = mh * mw;
        int ans = area % int(pow(10, 9) + 7);
        
        return ans;
        
    }
};

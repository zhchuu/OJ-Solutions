// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
	int ans;
 public:
	int firstBadVersion(int n) {
		binSearch(n, 1, n);
		return ans;
	}

	void binSearch(int n, int from, int to){
		int lo = from;
		int hi = to;
		while(lo <= hi){
			int mid = lo + (hi - lo) / 2;
			if(isBadVersion(mid)){
				if(mid==1 || !isBadVersion(mid-1)){
					ans = mid;
					return;
				}
				hi = mid - 1;
			}else
				lo = mid + 1;
		}//while
	}
};

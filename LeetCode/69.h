class Solution {
 public:
	int mySqrt(int x) {
		if(x == 0)
			return 0;
		long long lo = 1;
		long long hi = x/2 + 1;
		while(lo<hi){
			long long mid = lo + (hi - lo)/2;
			long long pow = mid*mid;
			if(pow == x)
				return mid;
			if(pow > x)
				hi = mid;
			else
				lo = mid+1;
		}
		if(lo*lo > x)
			return lo-1;
		return lo;
	}
};

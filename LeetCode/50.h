class Solution {
 public:
	double myPow(double x, int n) {
		long long N = n;
		if(n < 0){
			x = 1/x;
			N = N*(-1);
		}
		return power(x, N);
	}

	double power(double x, long long n){
		if(n==0)
			return 1.0;
		double sqr = power(x, n/2);
		if(n%2 == 0)
			return sqr*sqr;
		else
			return sqr*sqr*x;
	}
};

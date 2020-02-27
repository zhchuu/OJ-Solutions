/*
 * Lanqiao ALGO-3
 * Hint: DP
 * */

import java.util.*;
import java.math.*;

public class Main{
	static int K;
	static int L;
	static long[][] dp;
	static long mod = 1000000007;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		K = sc.nextInt();
		L = sc.nextInt();
		dp = new long[110][110];// dp[i][j] means the greatest number when i position place number j
		long result = dp();
		System.out.println(result);
	}
	protected static long dp(){
		for(int i=0;i<K;i++){
			dp[1][i] = 1;
		}//Only one k-good-number when there is a single number
		
		for(int i=2;i<L;i++){//from 2 to L-1
			for(int j=0;j<K;j++){
				long cnt = 0;
				for(int r=0;r<K;r++){
					if(j-1 == r || j+1 ==r)
						continue;
					cnt = (cnt + dp[i-1][r]) % mod;
				}//for
				dp[i][j] = cnt;
			}//for
		}//for

		long sum = 0;
		for(int j=1;j<K;j++){//Judge the highest weight position
			long cnt = 0;
			for(int r=0;r<K;r++){
				if(j-1 == r || j+1 == r)
					continue;
				cnt = (cnt + dp[L-1][r]) % mod;
			}//for
			sum = (sum + cnt) % mod;
		}//for
		return sum;
	}
}

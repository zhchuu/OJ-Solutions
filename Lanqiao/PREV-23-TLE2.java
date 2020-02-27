/*
 * Lanqiao PREV-23
 * Use BigInteger still TLE
 * */

import java.util.*;
import java.math.*;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int T = sc.nextInt();
		BigInteger sum = BigInteger.ONE;
		int idx = 1;
		BigInteger two = BigInteger.valueOf(2);
		for(int t=1;t<T;t++){
			idx = idx + n;
			BigInteger N = BigInteger.valueOf(idx-1);
			BigInteger number = BigInteger.ONE.add((BigInteger.ONE.add(N)).multiply(N).divide(two));
			number = number.mod(BigInteger.valueOf(k));
			//long number = (1+(1+N)*N/2)%k;
			sum = sum.add(number);
		}
		System.out.println(sum);
	}
}

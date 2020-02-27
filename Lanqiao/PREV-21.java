/*
 * Lanqiao PREV-21
 * */

import java.util.*;
import java.math.*;

public class Main{
	static int num;
	static List<Integer> results;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		num = sc.nextInt();
		results = new ArrayList<>();
		find();
		if(results.isEmpty())
			System.out.println(-1);
		else{
			for(int re : results)
				System.out.println(re);
		}
	}

	protected static void find(){
		for(int i=10000;i<999999;i++){
			if(sum(i) != num)
				continue;
			if(isPalindrome(i))
				results.add(i);
		}//for
	}//fun

	protected static int sum(int n){
		int ret = 0;
		while(n != 0){
			ret += n%10;
			n /= 10;
		}//while
		return ret;
	}//fun

	protected static boolean isPalindrome(int n){
		String str = String.valueOf(n);
		int start = 0, end = str.length()-1;
		while(start < end){
			if(str.charAt(start) != str.charAt(end))
				return false;
			start++;
			end--;
		}//while
		return true;
	}//fun
}

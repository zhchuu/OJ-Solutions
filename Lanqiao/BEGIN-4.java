/*
 * Lanqiao BEGIN-4
 * Hint: Fibonacci
 * */

import java.util.*;
import java.math.*;

public class Main{
	static List<Integer> fib = new ArrayList<>();
	static int N;
	public static void main(String[] args){
		init();
		//System.out.println("init done");
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			N = Integer.parseInt(sc.next());
			System.out.println(fib.get(N));
		}//while
	}
	private static void init(){
		fib.add(0);
		fib.add(1);
		fib.add(1);
		for(int i=3;i<=1000000;i++){
			int res = fib.get(i-1) + fib.get(i-2);
			fib.add(res%10007);
		}
	}
}

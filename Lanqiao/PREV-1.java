/*
 * Lanqiao PREV-1
 * */

import java.util.*;
import java.math.*;

public class Main{
	static int a,b,c;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			a = sc.nextInt();
			b = sc.nextInt();
			c = sc.nextInt();
			int ans = find(a, b, c);
			System.out.println(ans);
		}//while
	}
	private static int find(int a, int b, int c){
		int max = a*b*c;
		int start;
		if(a >= b){
			if( a >= c)
				start = a;
			else
				start = c;
		}
		else{
			if(b >= c)
				start = b;
			else
				start = c;
		}
		int i =start;
		for(; i<= max; i++){
			if(i%a==0 && i%b==0 && i%c==0)
				break;
		}
		return i;
	}
}

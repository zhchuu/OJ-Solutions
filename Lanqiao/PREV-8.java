/*
 * Lanqiao PREV-8
 * */

import java.util.*;
import java.math.*;

public class Main{
	static int INF = 10000000;
	static boolean table[];
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		table = new boolean[INF+5];
		table[a] = true;
		table[b] = true;
		int max = (a>b)? a:b;
		for(int i=max+1;i<=INF;i++){
			if(table[i-a] || table[i-b]){
				table[i] = true;
			}
		}
		for(int j=INF-1;j>=max;j--){
			if(!table[j]){
				System.out.println(j);
				break;
			}
		}
	}
}

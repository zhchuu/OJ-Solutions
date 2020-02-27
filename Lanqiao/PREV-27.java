/*
 * Lanqiao PREV-27
 * */

import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int total = sc.nextInt();
		int sick = Math.abs(sc.nextInt());
		int res = 1;
		int t;
		for(int i=1;i<total;i++){
			t = sc.nextInt();
			if((Math.abs(t)<sick && t>0) || (Math.abs(t)>sick && t<0))
				res++;
		}
		System.out.println(res);
	}
}

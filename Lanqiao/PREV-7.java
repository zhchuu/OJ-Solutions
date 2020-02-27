/*
 * Lanqiao PREV-7
 * */

import java.util.*;
import java.math.*;

public class Main{
	static List<Integer> l;
	static int ans;
	static List<Integer> temp;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		l = new ArrayList<>();
		ans = 0;
		int	N = sc.nextInt();
		for(int i=1; i<=N; i++){
			l.add(sc.nextInt());
		}//for
		for(int i=0;i<N;i++){
			int max = l.get(i);
			int min = l.get(i);
			for(int j=i;j<N;j++){
				if(l.get(j) > max)
					max = l.get(j);
				if(l.get(j) < min)
					min = l.get(j);
				if((max-min+1) == j-i+1){
					ans++;
				}
			}//for
		}//for
		//ans = ans + l.size();
		System.out.println(ans);
	}
}

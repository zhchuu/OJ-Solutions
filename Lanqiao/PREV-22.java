/*
 * Lanqiao PREV-22
 * Hints: Union-find Sets, Reverse
 * TLE
 * */

import java.util.*;
import java.math.*;

public class Main{
	static int island = 10000;
	static int bridge;
	static int[] par;
	static List<info> list;
	public static void main(String[] args){
		list = new ArrayList<>();
		Scanner sc = new Scanner(System.in);
		island = sc.nextInt();
		bridge = sc.nextInt();
		initPar();
		for(int i=1;i<=bridge;i++){
			int s = sc.nextInt();
			int e = sc.nextInt();
			int d = sc.nextInt();
			list.add(new info(s, e, d));
		}//for
		Collections.sort(list);
		int preDays = 0;//The day of previous bridge
		int ans = 0;
		for(info in : list){
			int st = in.getStart();
			int en = in.getEnd();
			int da = in.getDays();
			int rootOfSt = find(st);
			int rootOfEn = find(en);
			if(rootOfSt != rootOfEn){
				par[rootOfEn] = par[rootOfSt];
				if(preDays != da){
					ans++;
					preDays = da;
				}
			}
		}//for
		System.out.println(ans);
	}

	public static class info implements Comparable<info>{
		int start;
		int end;
		int days;
		public info(int start, int end, int days){
			this.start = start;
			this.end = end;
			this.days = days;
		}
		public int compareTo(info in){
			return in.getDays() - this.days;
		}
		public int getStart(){	return start;}
		public int getEnd(){	return end;}
		public int getDays(){	return days;}
		public String toString(){
			return start + " " + end + " " + days;
		}
	}

	public static void initPar(){
		par = new int[island + 1];
		for(int i=1;i<island+1;i++)
			par[i] = i;
	}

	public static int find(int idx){
		if(par[idx] == idx)
			return idx;
		return find(par[idx]);
	}
}

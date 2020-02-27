/*
 * Lanqiao ALGO-6
 * Hint: Kruskal, line 48(trap, Use parent[t2] = t1 instead of parent[e] = s)
 * TLE
 * */

import java.util.*;
import java.math.*;

public class Main{
	static int N;
	static int P;
	static Stack<path> list;
	static int[] cost;
	static int[] parent;
	static List<path> ans;
	public static void main(String[] args){
		list = new Stack<>();
		ans = new ArrayList<>();
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		P = sc.nextInt();
		cost = new int[N+1];
		parent = new int[N+1];
		int min = 10000;
		for(int i=1;i<=N;i++){
			cost[i] = sc.nextInt();
			if(cost[i] < min)
				min = cost[i];
		}
		for(int i=0;i<P;i++){
			int s = sc.nextInt();
			int e = sc.nextInt();
			int t = sc.nextInt();
			list.push(new path(s, e, 2*t + cost[s] + cost[e]));
		}
		Collections.sort(list);
		while(!list.isEmpty()){
			path temp = list.pop();
			int s = temp.getStart();
			int e = temp.getEnd();
			int t = temp.getTime();
			int p1 = find(s);
			int p2 = find(e);
			if(p1 == p2)
				continue;
			ans.add(temp);
			parent[p2] = p1;
		}//while
		int result = 0;
		for(path p: ans)
			result += p.getTime();
		result += min;
		System.out.println(result);
	}

	public static int find(int n){
		if(parent[n] == 0)
			return n;
		return find(parent[n]);
	}

	public static class path implements Comparable<path>{
		int start;
		int end;
		int time;
		public path(int start, int end, int time){
			this.start = start;
			this.end = end;
			this.time = time;
		}

		public int compareTo(path p){
			if(p.getTime() > this.time)
				return 1;
			else
				return -1;
		}

		public int getStart(){	return start;}

		public int getEnd(){	return end;}

		public int getTime(){	return time;}

		public String toString(){
			return start + " " + end + " " + time;
		}
	}
}



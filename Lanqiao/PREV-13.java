/*
 * Lanqiao PREV-13
 * Hint: dfs
 * TLE
 * */

import java.util.*;
import java.math.*;

public class Main{
	static int pnts;
	static int num;
	static boolean path[][];
	static boolean visit[];
	static int from;
	static int to;
	static int ans;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		pnts = sc.nextInt();
		num = sc.nextInt();
		path = new boolean[pnts+1][pnts+1];
		visit = new boolean[pnts+1];
		for(int i=0;i<num;i++){
			from = sc.nextInt();
			to = sc.nextInt();
			path[from][to] = true;
			path[to][from] = true;
		}//for
		ans = 0;
		for(int i=1;i<=pnts;i++)
			dfs(i, i, 0);
		System.out.println(ans);
	}
	protected static void dfs(int start, int now, int times){
		if(times == 3){
			ans++;
			return;
		}
		for(int i=1;i<=pnts;i++){
			if((times==0 || times==1) && i==start)
				continue;
			if(path[now][i] && !visit[i]){
				visit[i] = true;
				times++;
				dfs(start, i, times);
				times--;
				visit[i] = false;
			}
		}//for
	}//fun
}

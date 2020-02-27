/*
 * Lanqiao PREV-9
 * Hint: dfs
 * TLE
 * */

import java.util.*;
import java.math.*;

public class Main{
	static boolean visit[];
	static int N;
	static int dis[][];
	static int ans[][];
	static int INF = 10000;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		visit = new boolean[N+1];
		dis = new int[N+1][N+1];
		ans = new int[N+1][N+1];
		for(int i=0; i<N-1; i++){
			int from = sc.nextInt();
			int to = sc.nextInt();
			dis[from][to] = sc.nextInt();
			dis[to][from] = dis[from][to];
		}//for
		visit[1] = true;
		dfs(1,1,0);
		visit[1] = false;
		int max = 0;
		int next = 0;
		for(int i=1;i<N+1;i++){
			if(ans[1][i] > max){
				max = ans[1][i];
				next = i;
			}
		}
		visit[next] = true;
		dfs(next,next,0);
		visit[next] = false;
		max = 0;
		for(int i=1;i<N+1;i++)
			if(ans[next][i] > max){
				max = ans[next][i];
			}
		int res = 0;
		for(int i = 1;i<=max;i++){
			res = 10+i+res;
		}
		System.out.println(res);
	}
	static void dfs(int start, int now, int len){
		for(int i=1; i<=N; i++){
			if(dis[now][i] != 0 && !visit[i]){
				ans[start][i] = len + dis[now][i];
				visit[i] = true;
				dfs(start, i, len + dis[now][i]);
				visit[i] = false;
			}//if
		}//for
	}
}

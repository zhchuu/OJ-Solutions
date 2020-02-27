/*
 * Lanqiao PREV-17
 * Hint: dfs, Game-theory
 * TLE
 * */

import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	static List<Integer> cards;
	static List<Integer> select;
	static List<List<Integer>> toChoose;
	static int num[];
	static int visit[];
	public static void main(String[] args) throws Exception{
		cards = new ArrayList<>();
		select = new ArrayList<>();
		toChoose = new ArrayList<List<Integer>>();
		num = new int[101];
		//input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] data = br.readLine().split(" ");
		for(String str : data)
			cards.add(Integer.parseInt(str));
		data = br.readLine().split(" ");
		for(String str : data)
			select.add(Integer.parseInt(str));
		visit = new int[cards.size()];
		Collections.sort(cards);
		Collections.sort(select);
		//init
		for(int i=0;i<cards.size();i++)
			num[cards.get(i)]++;
		for(int i=1;i<=100;i++){
			List<Integer> temp = new ArrayList<>();
			for(int j=1;j<=100;j++){
				if(i%j==0 || j%i==0)
					temp.add(j);
			}//for
			toChoose.add(temp);
		}//for
		//run
		int ret = 0;
		int flag = 0;
		for(int i=0;i<select.size();i++){
			int n = select.get(i);
			num[n]--;
			int res = dfs(n);
			if(res==1){//win
				ret = n;
				flag = 1;
				break;
			}
			num[n]++;
		}//for
		if(flag == 0)
			System.out.println(-1);
		else
			System.out.println(ret);
	}
	protected static int dfs(int x){
		for(int i = cards.size()-1;i>=0;i--){//from larger
			int nber = cards.get(i);
			if(num[nber]!=0 && toChoose.get(x-1).contains(nber)){
				num[nber]--;
				int t = dfs(nber);
				num[nber]++;
				if(t == 1)//the one who takes nber win. That mean the one who takes x lose.
					return -1;
			}
		}//for
		return 1;//can pick next card, the one who takes x win.
	}
}

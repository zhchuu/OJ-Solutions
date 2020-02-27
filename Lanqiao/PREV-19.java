/*
 * PREV-19
 * Hint: bfs
 * TLE
 * */

import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	static String begin;
	static String end;
	static List<List<Integer>> moveable;
	static Set<String> pass;
	static Queue<Map<String, Integer>> nows;
	static int ans = -1;
	public static void main(String[] args) throws IOException{
		init();
		pass = new HashSet<>();
		nows = new LinkedList<Map<String, Integer>>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		begin = br.readLine();
		end = br.readLine();
		Map<String, Integer> map = new HashMap<>();
		map.put(begin, 0);
		nows.add(map);
		bfs();
		System.out.println(ans);
	}
	static void bfs(){
		while(!nows.isEmpty()){
			Map<String, Integer> map = nows.remove();
			String now = "";
			int steps = 0;
			//
			for(String key:map.keySet())
				now = key;
			for(Integer val:map.values())
				steps = val;
			//
			if(now.equals(end)){
				ans = steps;
				return;
			}
			//System.out.println("add");
			int space = now.indexOf('.');
			List<Integer> choices = moveable.get(space);
			for(int cho : choices){
				StringBuilder strBuilder = new StringBuilder(now);
				char s = now.charAt(cho);
				strBuilder.setCharAt(space, s);
				strBuilder.setCharAt(cho, '.');
				String str = strBuilder.toString();
				if(pass.contains(str))
					continue;
				pass.add(now);
				Map<String, Integer> temp = new HashMap<>();
				temp.put(str, steps+1);
				nows.add(temp);
			}//for
		}//while
		return;
	}//bfs
	static void init(){
		moveable = new ArrayList<>();
		// 0
		List<Integer> temp = new ArrayList<>();
		temp.add(1);
		temp.add(3);
		moveable.add(temp);
		// 1
		temp = new ArrayList<>();
		temp.add(0);
		temp.add(2);
		temp.add(4);
		moveable.add(temp);
		// 2
		temp = new ArrayList<>();
		temp.add(1);
		temp.add(5);
		moveable.add(temp);
		// 3
		temp = new ArrayList<>();
		temp.add(0);
		temp.add(4);
		temp.add(6);
		moveable.add(temp);
		// 4
		temp = new ArrayList<>();
		temp.add(1);
		temp.add(3);
		temp.add(5);
		temp.add(7);
		moveable.add(temp);
		// 5
		temp = new ArrayList<>();
		temp.add(2);
		temp.add(4);
		temp.add(8);
		moveable.add(temp);
		// 6
		temp = new ArrayList<>();
		temp.add(3);
		temp.add(7);
		moveable.add(temp);
		// 7
		temp = new ArrayList<>();
		temp.add(4);
		temp.add(6);
		temp.add(8);
		moveable.add(temp);
		// 8
		temp = new ArrayList<>();
		temp.add(5);
		temp.add(7);
		moveable.add(temp);
	}//bfs
}

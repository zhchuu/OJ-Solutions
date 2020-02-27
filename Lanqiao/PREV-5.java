/*
 * Lanqiao PREV-5
 * */

import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	static Set<Integer> set;
	static List<Integer> list;
	static int lines;
	static int brk;
	static int rep;
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		set = new HashSet<>();
		list = new ArrayList<>();
		int temp;
		lines = Integer.parseInt(reader.readLine());
		set.clear();
		list.clear();
		for(int i=0;i<lines;i++){
			String[] data = reader.readLine().split(" ");
			for(String str : data){
				temp = Integer.parseInt(str);
				if(set.contains(temp))
					rep = temp;
				else{
					set.add(temp);
					list.add(temp);
				}
			}
		}//for
		Collections.sort(list);
		int size = list.size();
		for(int i=0;i<size-1;i++){
			if(list.get(i+1) - list.get(i) != 1){
				brk = list.get(i)+1;
				break;
			}
		}
		System.out.println(brk + " " +rep);
	}
}

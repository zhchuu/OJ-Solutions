/*
 * Lanqiao PREV-14
 * Hint: NIM-Pick, Game theor
 * */

import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	static List<Integer> nums;
	static List<Integer> left;
	public static void main(String[] args) throws Exception{
		nums = new ArrayList<>();
		left = new ArrayList<>();
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String[] data = reader.readLine().split(" ");
		for(String str : data)
			nums.add(Integer.valueOf(str));
		left = getLeft(nums);
		int ans[] = getAns();
		if(ans[0] == -1)
			System.out.println(-1);
		else
			System.out.println(ans[0] + " " +ans[1]);
		//System.out.println(left);
	}
	protected static List<Integer> getLeft(List<Integer> list){
		List<Integer> ret = new ArrayList<>();
		int len = list.size();
		for(int i=1;i<len;i++)
			ret.add(list.get(i) - list.get(i-1) - 1);
		return ret;
	}
	protected static int xor(List<Integer> list){
		int ret = list.get(0);
		int len = list.size();
		for(int i=2;i<len;i=i+2)
			ret ^=list.get(i);
		return ret;
	}
	protected static int[] getAns(){
		int ret[] = new int[2];
		int len = left.size();
		if(xor(left) == 0){
			ret[0] = -1;
			return ret;
		}else{
			for(int i=0;i<len;i++){
				for(int j=1;nums.get(i)+j<nums.get(i+1);j++){
					left.set(i, left.get(i) -j);
					if(i != 0)
						left.set(i-1, left.get(i-1)+j);
					if(xor(left) == 0){
						ret[0] = nums.get(i);
						ret[1] = nums.get(i) + j;
						return ret;
					}
					left.set(i, left.get(i) +j);
					if(i != 0)
						left.set(i-1, left.get(i-1)-j);
				}//for
			}//for
		}//if-else
		return ret;
	}
}

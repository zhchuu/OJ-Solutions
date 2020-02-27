/*
 * Lanqiao BASCI-12
 * */

import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	static String hex;
	static Map<Character, Integer> map;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		hex = sc.next();
		map = new HashMap<Character, Integer>();
		init();
		long result = cal();
		System.out.println(result);
	}

	protected static long cal(){
		int size = hex.length();
		long mul = 1;
		long ret = 0;
		for(int i=size-1; i>=0; i--){
			int num = map.get(hex.charAt(i));
			ret += num*mul;
			mul *= 16;
		}//for
		return ret;
	}

	protected static void init(){
		map.put('0', 0);
		map.put('1', 1);
		map.put('2', 2);
		map.put('3', 3);
		map.put('4', 4);
		map.put('5', 5);
		map.put('6', 6);
		map.put('7', 7);
		map.put('8', 8);
		map.put('9', 9);
		map.put('A', 10);
		map.put('B', 11);
		map.put('C', 12);
		map.put('D', 13);
		map.put('E', 14);
		map.put('F', 15);
	}
}

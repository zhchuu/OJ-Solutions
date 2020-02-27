/*
 * KMP
 * */

import java.util.*;
import java.math.*;
import java.io.*;

public class KMP {
	static String aim;
	static String pattern;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		aim = br.readLine();
		pattern = br.readLine();
		System.out.println(kmp(aim, pattern));
	}

	protected static int kmp(String a, String p){
		int next[] = getNext(p);
		int i = 0,j = 0;
		while(i < a.length()){
			if(j == -1 || a.charAt(i) == p.charAt(j)){
				i++;
				j++;
			}else
				j = next[j];
			if(j == p.length())
				return i - p.length();
		}//while
		return -1;
	}

	protected static int[] getNext(String p){
		int[] next = new int[p.length()];
		next[0] = -1;
		int k=-1, j=0;
		while(j < pattern.length() - 1){
			if(k == -1 || p.charAt(j) == p.charAt(k)){
				j++;
				k++;
				next[j] = k;
			}else{
				k = next[k];
			}
		}//while
		return next;
	}
}

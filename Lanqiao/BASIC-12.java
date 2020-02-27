/*
 * Lanqiao BASIC-12
 * */

import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	static int n;
	static List<String> hexs;

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		hexs = new ArrayList<>();
		for(int i=0;i<n;i++)
			hexs.add(sc.next());
		for(String str : hexs){
			System.out.println(bin2oct(hex2bin(str)));
		}
	}

	protected static String hex2bin(String s){
		StringBuilder sb = new StringBuilder();
		int len = s.length();
		for(int i=0;i<len;i++){
			char c = s.charAt(i);
			switch(c){
				case '0': sb.append("0000"); break;
                case '1': sb.append("0001"); break;
                case '2': sb.append("0010"); break;
                case '3': sb.append("0011"); break;
                case '4': sb.append("0100"); break;
                case '5': sb.append("0101"); break;
                case '6': sb.append("0110"); break;
                case '7': sb.append("0111"); break;
                case '8': sb.append("1000"); break;
                case '9': sb.append("1001"); break;
                case 'A': sb.append("1010"); break;
                case 'B': sb.append("1011"); break;
                case 'C': sb.append("1100"); break;
                case 'D': sb.append("1101"); break;
                case 'E': sb.append("1110"); break;
                case 'F': sb.append("1111"); break;
                default: break;
			}
		}//for
		return sb.toString();
	}

	protected static String bin2oct(String s){
		while(s.length() % 3 != 0)
			s = "0" + s;
		StringBuilder sb = new StringBuilder();
		for(int i=0, len=s.length();i<len;i=i+3){
			String current = s.substring(i, i+3);
			if(current.equals("000")) sb.append("0");
			else if(current.equals("001")) sb.append("1");
			else if(current.equals("010")) sb.append("2");
			else if(current.equals("011")) sb.append("3");
			else if (current.equals("100")) sb.append("4");
            else if (current.equals("101")) sb.append("5");
            else if (current.equals("110")) sb.append("6");
            else if (current.equals("111")) sb.append("7");
		}
		if(sb.charAt(0) == '0')
			sb.deleteCharAt(0);
		return sb.toString();
	}
}

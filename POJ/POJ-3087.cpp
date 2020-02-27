/*
 * POJ-3087
 * G++
 */
#include<stdio.h>
#include<string.h>
#include<cstring>
#include<iostream>
using namespace std;

const int maxl = 100+10;
int kase, len, ans;
bool found;

int main(){
	scanf("%d", &kase);
	for(int k=1; k<=kase; k++){
		// Init
		ans = 0;
		found = false;
		// Input
		char a[maxl], b[maxl], tmp[2*maxl];
		scanf("%d", &len);
		scanf("%s", a);
		scanf("%s", b);
		scanf("%s", tmp);
		// Convert to string
		string aim, s1, s2;
		for(int i=0; i<2*len; i++)
			aim += tmp[i];
		for(int i=0; i<len; i++){
			s1 += a[i];
			s2 += b[i];
		}
		// Get first stack
		string first;
		for(int i=0; i<len; i++){
			first += b[i];
			first += a[i];
		}
		ans += 1;
		// Simulation
		string shuf = first;
		while(shuf != aim){
			s1.clear();
			s2.clear();
			for(int i=0; i<len; i++){
				s1 += shuf[i];
				s2 += shuf[i+len];
			}
			shuf.clear();
			for(int i=0; i<len; i++){
				shuf += s2[i];
				shuf += s1[i];
			}
			ans += 1;
			if(shuf == first){
				ans = -1;
				break;
			}
		}
		printf("%d %d\n", k, ans);
	}
	return 0;
}

/*
 * PAT L2-010
 * */

#include<stdio.h>
#include<memory.h>

int parFri[100+1];
int ene[100+1][100+1];

int findFri(int idx){
	if(parFri[idx] == -1)
		return idx;
	return findFri(parFri[idx]);
}
void init(){
	memset(parFri, -1, sizeof(parFri));
	memset(ene, 0, sizeof(ene));
}
int main(){
	init();
	int N,M,K;
	scanf("%d" "%d" "%d",&N,&M,&K);
	for(int i=1;i<=M;i++){
		int a,b,st;
		scanf("%d" "%d" "%d",&a,&b,&st);
		if(st == -1)
			ene[a][b] = ene[b][a] = 1;
		else{
			int f1 = findFri(a);
			int f2 = findFri(b);
			if(f1 != f2)
				parFri[f1] = f2;
		}
	}
	for(int i=1;i<=K;i++){
		int a,b;
		scanf("%d %d", &a,&b);
		bool fri = (findFri(a) == findFri(b));
		if(ene[a][b]){
			if(fri)
				printf("OK but...\n");
			else
				printf("No way\n");
		}else{
			if(fri)
				printf("No problem\n");
			else
				printf("OK\n");
		}
	}
	return 0;
}

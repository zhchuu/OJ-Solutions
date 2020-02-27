/*
 * PAT L1-030
 * */

#include<stdio.h>
#include<string.h>
#include<memory>
#include<iostream>
using namespace std;

int const MAX = 50;
int total;
int choose[MAX];
string name[MAX];
int sex[MAX];

int main(){
	memset(choose, 0, sizeof(choose));
	//scanf("%d", &total);
	cin>>total;
	for(int i=0;i<total;i++)
		//scanf("%d %s",&sex[i],&name[i]);
		cin>>sex[i]>>name[i];
	for(int i=0;i<total && !choose[i];i++){
		int se = sex[i];
		//cout<<name[i];
		int j = total-1;
		while(j>=0){
			if(j>=0 && !choose[j] && se!=sex[j]){
				cout<<name[i]<<" "<<name[j]<<endl;
				choose[j] = 1;
				break;
			}
			j--;
		}
		choose[i] = 1;
	}//for
	return 0;
}

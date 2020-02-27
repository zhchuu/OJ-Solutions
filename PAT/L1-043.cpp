/*
 * PAT L1-043
 * */

#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
		
int main(){
	int id[1005], hh[1005], mm[1005], kase;
	memset(id, 0, sizeof(id));
	scanf("%d", &kase);
	while(kase--){
		int book, hour, minute, cnt = 0, sum = 0;
		char type;
		while(~scanf("%d %c %d:%d", &book,&type,&hour,&minute)){
			if(book == 0)
				break;
			if(type == 'S'){//borrow
				id[book] = 1;
				hh[book] = hour;
				mm[book] = minute;
			}else if(type == 'E'){//return
				if(id[book] == 0)
					continue;
				else{
					id[book] = 0;
					cnt++;
					sum += (hour - hh[book])*60 + (minute - mm[book]);
				}
			}//elseif
		}//while
		if(cnt == 0)
			printf("0 0\n");
		else{
			int output = (int)round((double(sum)/double(cnt)));	
			printf("%d %d\n", cnt, output);
		}
	}//while
	return 0;
}

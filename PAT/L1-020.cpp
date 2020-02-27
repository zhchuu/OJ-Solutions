/*
 * PAT L1-020
 * */

#include<stdio.h>
#include<set>
#include<map>
using namespace std;
map<int,int>cir;
bool find(int x)
{
  if ((cir.count(x) == 0) || (cir.count(x) != 0 && cir[x] == 1))
    return true;
  else
    return false;
}
int main()
{
  int kase, frids, chk, num, times;//
  set<int>handsome;
  bool allnohandsome = true;
  scanf("%d", &kase);
  for (int i = 0; i < kase; i++) {
    int isOnlyOne = 0;//
    scanf("%d", &times);//
    if (times == 1)
      isOnlyOne = 1;
    for (int j = 1; j <= times; j++) {
      scanf("%d", &num);
      if (cir.count(num) != 0 && cir[num] == 0 && isOnlyOne == 1)//
        continue;
      cir[num] = isOnlyOne;
    }//2for
  }//1for
  scanf("%d", &frids);//
  bool isfirst = true;
  for (int i = 0; i < frids; i++) {
    scanf("%d", &chk);
    bool flag = false;//
    flag = find(chk);
    if (flag) {//
      allnohandsome = false;
      int k = handsome.count(chk);
      if (k == 0)//
      {  
        if (!isfirst)//
          printf(" ");
        else
          isfirst = false;
        printf("%05d", chk);//
        handsome.insert(chk); 
      }
    }
  }//1for
  if (allnohandsome)
    printf("No one is handsome\n");
  else
    printf("\n");
  return 0;
}

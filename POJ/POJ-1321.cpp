/*
 * POJ-1321
 */
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn = 10;
char map[maxn][maxn];
bool tag[maxn];
int ans, n, k;

void dfs(int row, int left){
  if(left <= 0){
    ans += 1;
    return;
  }
  if(row > n || n-row+1 < left)//pruning
    return;
  // do not place in this row
  dfs(row+1, left);
  for(int col=1; col<=n; col++){
    if(map[row][col] == '.' || tag[col] == true)//pruning
      continue;
    tag[col] = true;
    dfs(row+1, left-1);
    tag[col] = false;
  }
}

int main(){
  while(scanf("%d %d", &n, &k) && n != -1 && k != -1){
    for(int i=1; i<=n; i++)
      scanf("%s", &map[i][1]);
    ans = 0;
    memset(tag, 0, sizeof(tag));
    dfs(1, k);
    printf("%d\n", ans);
  }
  return 0;
}

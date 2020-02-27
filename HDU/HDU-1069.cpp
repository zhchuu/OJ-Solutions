/*
 * HDU-1069
 * Hint: dp
 * */
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

struct Node{
    int len, wid, hei, base;
    Node(){}
    Node(int a, int b, int c){
        len = a;
        wid = b;
        hei = c;
        base = len*wid;
    }
};

bool cmp(Node a, Node b){
    return a.base > b.base;
}

const int maxn = 200+5;
int dp[maxn], n;
vector<Node> nodes;

void init(){
    nodes.clear();
    memset(dp, 0, sizeof(dp));
}

int work(){
    int ret = -1;//it's safer to use this way
    sort(nodes.begin(), nodes.end(), cmp);
    for(int i=1; i<nodes.size(); i++){
        dp[i] = nodes[i].hei;
        for(int j=0; j<i; j++){
            if(nodes[j].base <= nodes[i].base || nodes[j].len <= nodes[i].len || nodes[j].wid <= nodes[i].wid)
                continue;
            dp[i] = max(dp[i], dp[j] + nodes[i].hei);
        }
        ret = max(ret, dp[i]);
    }//for
    return ret;
}

Node getObject(int a, int b, int c){
    Node tmp(a, b, c);
    return tmp;
}

int main(){
    int a,b,c, cnt=1;
    Node tmp;
    while(~scanf("%d", &n) && n){
        init();
        for(int i=0; i<n; i++){
            scanf("%d%d%d", &a, &b, &c);
            tmp = getObject(a, b, c);
            nodes.push_back(tmp);
            tmp = getObject(a, c, b);
            nodes.push_back(tmp);
            tmp = getObject(b, a, c);
            nodes.push_back(tmp);
            tmp = getObject(b, c, a);
            nodes.push_back(tmp);
            tmp = getObject(c, a, b);
            nodes.push_back(tmp);
            tmp = getObject(c, b, a);
            nodes.push_back(tmp);
        }//for-input
        int ans = work();
        printf("Case %d: maximum height = %d\n", cnt++, ans);
    }//while
    return 0;
}

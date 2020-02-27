/*
 * HDU-1004
 * */
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<map>
#include<set>
#include<iostream>
#include<string>
using namespace std;

int n;
map<string, int> mm;
set<string> balloon;

int main(){
    string tmp;
    while(~scanf("%d", &n) && n){
        mm.clear();
        balloon.clear();
        for(int i=0; i<n; i++){
            cin>>tmp;
            if(balloon.count(tmp) == 0){
                balloon.insert(tmp);
                mm[tmp] = 1;
            }else{
                mm[tmp] += 1;
            }
        }//input
        string ans;
        int cnt = 0;;
        for(map<string, int>::iterator it = mm.begin(); it!=mm.end(); it++){
            if(it->second > cnt){
                cnt = it->second;
                ans = it->first;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

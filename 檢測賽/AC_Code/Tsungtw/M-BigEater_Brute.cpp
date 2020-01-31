#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100

int weight[MAX_N+4],value[MAX_N+4],bounded[MAX_N+4];
int n,m;
void init(){
    scanf("%d%d",&n,&m);
    m*=1000;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&weight[i],&value[i],&bounded[i]);
    }
}
void solve(){
    int ans=0;
    int now_full=0;
    //吃不下跳出
    while(now_full<m){
        bool flag=false;
        int ind=-1,maxi=-1;
        //找當前CP值最高的食物
        for(int i=0;i<n;i++){
            //還可以吃，而且CP值比較高就更新
            if(bounded[i] && value[i]/weight[i]>maxi){
                maxi=value[i]/weight[i];
                ind=i;
            }
        }
        //都沒有食物了，break
        if(ind==-1) break;

        
        bounded[ind]--;
        if(now_full+weight[ind]<=m){
            ans+=value[ind];
            now_full+=weight[ind];
        }
        else{
            int diff=m-now_full;
            ans+=diff*value[ind]/weight[ind];
            now_full=m;
        }
    }
    printf("%d\n",ans);
}
int main(){
    init();
    solve();
}
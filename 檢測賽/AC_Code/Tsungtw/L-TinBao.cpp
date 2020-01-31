#include<bits/stdc++.h>
using namespace std;
#define MAX_W 100000
#define MAX_N 100
#define inf 0x3f3f3f3f

/*
    這是一題經典的換零錢問題。
    需要透過動態規劃（Dynamic Programming）去解題目，詳情Google“找零錢 動態規劃”
*/

int m,n,k;
int dp[MAX_W+5];
int dp_food[MAX_W+5];
int used[MAX_N+5];
int food[MAX_N+5];
void init(){
    scanf("%d%d%d",&m,&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&food[i]);
        if(i) food[i]+=food[i-1];
    }
    memset(dp,inf,sizeof(dp));
    memset(dp_food,-1,sizeof(dp_food));
    memset(used,0,sizeof(used));

}
void solve(){
    for(int i=0;i<n;i++){
        food[i]*=k;
    }
    
    //動態規劃
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=food[i];j<=m;j++){
            //如果我換這個零錢比較好就更新
            if(dp[j-food[i]]+1<dp[j]){
                dp[j]=dp[j-food[i]]+1;
                dp_food[j]=i; //紀錄j元是用第幾種零錢換得的
            }
        }
    }
    while(dp_food[m]<0) m--; //找最接近飽足度的解

    //計算數量
    while(m){
        used[dp_food[m]]++;
        m-=food[dp_food[m]];
    }
    int cnt;
    for(int i=0;i<n;i++){
        if(used[i]>0){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    for(int i=0;i<n;i++){
        if(used[i]>0) printf("%d ",food[i]/k);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        if(used[i]>0) printf("%d ",used[i]);
    }
    printf("\n");
}
int main(){
    init();
    solve();
}
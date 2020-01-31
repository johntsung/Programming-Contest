#include<bits/stdc++.h>
using namespace std;
#define MAX_N 50


/*
    魔王題，屬於max clique的裸題。
    考驗如何建邊、遞迴列舉以及回溯法的思考
*/
int adj[MAX_N+5][MAX_N+5]; //相鄰矩陣
int like[MAX_N+5]; //喜歡的陣列
int x,y,n,m;
int ans;
void init(){
    //非輸入型的變數，都應該要記得初始化
    memset(adj,0,sizeof(adj)); //初始化
    scanf("%d%d%d",&x,&y,&m);
    n=x+y;
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u][v]=1; //有邊為1，沒有為0
        adj[v][u]=1;
    }
    for(int i=0;i<x;i++){
        scanf("%d",&like[i]);
    }
}
void dfs(int now,int in_list[],int num){
    if(num+(n-now)<=ans) return ; //如果已經不能比原來的答案大，就return。這行是本題的關鍵點！
    if(now==n){
        if(ans<num){
            ans=num; //如果當前數量比較好就更新。
        }
        return ;
    }
    bool flag=true;
    //檢查當前這個點，是不是跟目前團隊裡面的人都有邊
    for(int i=0;i<num;i++){
        if(!adj[now][in_list[i]]){
            flag=false;
            break;
        }
    }
    //如果有才能選進去
    if(flag){
        in_list[num]=now;
        dfs(now+1,in_list,num+1); //選
    }
    dfs(now+1,in_list,num); //不選
}
int max_clique(){
    //再怎麼小都可以跟自己一組
    ans=1;
    int in_list[MAX_N+5];
    dfs(0,in_list,0); //開始遞迴暴搜
    return ans;
}
void solve(){
    for(int i=0;i<x;i++){
        if(like[i]==-1) continue;
        for(int j=i+1;j<x;j++){
            //如果喜歡同一個女生，就把邊拿掉。
            if(like[i]==like[j]){
                adj[i][j]=0;
                adj[j][i]=0;
            }
        }
    }
    printf("%d\n",max_clique());
}
int main(){
    init();
    solve();
}
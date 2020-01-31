#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100

int weight[MAX_N+4],value[MAX_N+4],bounded[MAX_N+4];
int n,m;
void bubble_sort(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(value[j]/weight[j]<value[j+1]/weight[j+1]){
                swap(value[j],value[j+1]);
                swap(weight[j],weight[j+1]);
                swap(bounded[j],bounded[j+1]);
            }
        }
    }
}
void init(){
    scanf("%d%d",&n,&m);
    m*=1000;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&weight[i],&value[i],&bounded[i]);
    }
}
void solve(){
    bubble_sort();
    int ans=0;
    int now_full=0;
    for(int i=0;i<n;i++){
        while(now_full<m && bounded[i]>0){
            if(now_full+weight[i]<=m){
                ans+=value[i];
                now_full+=weight[i];
            }
            else{
                int remain=m-now_full;
                ans+=remain*value[i]/weight[i];
                now_full=m;
            }
            bounded[i]--;
        }
    }
    printf("%d\n",ans);
}
int main(){
    init();
    solve();
}
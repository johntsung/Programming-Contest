#include<bits/stdc++.h>
using namespace std;

stack<int> in_hole;
int n;
void init(){
    while(!in_hole.empty()) in_hole.pop(); //養成初始化的好習慣
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        in_hole.push(temp);
    }
}
void solve(){
    //倒著輸出
    while(!in_hole.empty()){
        printf("%d ",in_hole.top());
        in_hole.pop();
    }
    printf("\n");
}
int main(){
    int ncase;
    scanf("%d",&ncase);
    while(ncase--){
        init();
        solve();
    }
}
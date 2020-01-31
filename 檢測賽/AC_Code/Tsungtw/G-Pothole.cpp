#include<bits/stdc++.h>
using namespace std;
#define MAX_N 1000

/*
    超級大水題，倒著輸出就可以了。
    也可以使用 stack 詳見stack版本
*/

int a[MAX_N+5];
int n;
void init(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void solve(){
    //倒著輸出
    for(int i=n-1;i>=0;i--){
        printf("%d ",a[i]);
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
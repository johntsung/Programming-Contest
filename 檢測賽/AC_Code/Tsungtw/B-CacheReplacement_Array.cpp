#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100000


int n,q;
bool in_cache[MAX_N+5]; //使用陣列紀錄
int que[MAX_N+5],head,tail,sz; //用陣列實作queue
void init(){
    scanf("%d%d",&n,&q);
    memset(in_cache,false,sizeof(in_cache));
    head=-1;
    tail=-1;
    sz=0;
}
void solve(){
    int hit=0;
    while(q--){
        int inp;
        scanf("%d",&inp);
        //如果在快取記憶體裡面就hit
        if(in_cache[inp]){
            hit++;
        }
        else if(sz>=n){ //如果超過size就把最前面的丟掉
            int temp=que[++head];  //先取最前面的
            in_cache[temp]=false; //拿掉
            que[++tail]=inp; //把現在這個放進去
            in_cache[inp]=true; 
        }
        else{ //沒有超過size
            que[++tail]=inp; //放進去
            in_cache[inp]=true; 
            sz++;
        }
    }
    printf("%d\n",hit);
}
int main(){
    init();
    solve();
}
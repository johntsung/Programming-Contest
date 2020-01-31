#include<bits/stdc++.h>
using namespace std;

/*
    實作題，考queue的應用
    當然不一定要使用STL的queue，也可以用陣列，詳細請見陣列版本。
    這題測資有10^5，所以會擋O(n^2)的解
*/

int n,q;
set<int> in_cache; //偷懶用set去紀錄，本題可以使用陣列去紀錄即可
void init(){
    scanf("%d%d",&n,&q);
}
void solve(){
    queue<int> que;
    int hit=0;
    while(q--){
        int inp;
        scanf("%d",&inp);
        //如果在快取記憶體裡面就hit
        if(in_cache.count(inp)){
            hit++;
        }
        else if((int)in_cache.size()>=n){ //如果超過size就把最前面的丟掉
            int temp=que.front();  //先取最前面的
            que.pop(); //拿掉
            in_cache.erase(temp); //拿掉
            que.push(inp); //把現在這個放進去
            in_cache.insert(inp); 
        }
        else{ //沒有超過size
            que.push(inp); //放進去
            in_cache.insert(inp); 
        }
    }
    printf("%d\n",hit);
}
int main(){
    init();
    solve();
}
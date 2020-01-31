#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

/*
    bit operation 的基本題
    如果看不懂，可以自己設法轉成二進位，然後紙筆推演，很快就懂了。

*/

int n;
unsigned int k;
void init(){
    cin >> dec >> n >> k;
}
void solve(){
    for(int i=0;i<n;i++){
        unsigned temp;
        //使用 hex 讀入 16 進位數
        cin >> hex >> temp;
        temp^=k;
        for(int j=3;j>=0;j--){
            //將 temp 向右 shift j個bytes 然後跟 0xff做and 就會是每個字元要取的byte
            cout << (char)((temp>>j*8)&(0xff));
        }
    }
    cout << '\n';
}
int main(){
    init();
    solve();
}
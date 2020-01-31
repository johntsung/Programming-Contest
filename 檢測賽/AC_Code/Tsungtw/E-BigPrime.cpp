#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
#define LOW 50
#define UP 54

/*
    本題是想騙騙那些，以為要建立質數表的人。
    主要是想要告訴大家，有些時候，試一下就對了！
    只要你知道，「找質數只需要做到開根號」這件事情，這題就不會有問題了！
*/

void init(){

}
void solve(){
    // 運用位元運算直接計算2^50 （也可以先計算好）
    for(lint i=(1ll << LOW)+1;i<(1ll << UP);i+=2){
        lint temp=i;
        bool flag=false;
        for(lint j=2;j*j<=temp;j++){
            if(temp%j==0){
                flag=true;
                break;
            }
        
        }
        if(!flag){
            printf("%lld\n",i);
            exit(0);
        }
    }
}
int main(){
    init();
    solve();
}
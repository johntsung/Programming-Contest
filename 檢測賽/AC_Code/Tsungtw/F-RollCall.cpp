#include<bits/stdc++.h>
using namespace std;

/*
    純set實作題，會C++ set直接解決
    不會也可以用sorting + binary search 詳見二分搜版本
*/
int n,m,q;
set<string> all,fri;
void init(){
    cin >> n >> m >> q;
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        all.insert(temp);
    }
    for(int i=0;i<m;i++){
        string temp;
        cin >> temp;
        fri.insert(temp);
    }
}
void solve(){
    bool flag1=false,flag2=false;
    while(q--){
        string temp;
        cin >> temp;
        //不在名單上就直接結束
        if(!all.count(temp)){
            flag1=true;
            break;
        }
        //朋友被點到先標記起來
        if(fri.count(temp)){
            flag2=true;
        }
    }
    if(flag1){
        cout << "Teacher is Blind !\n"; 
    }
    else if(flag2){
        cout << "Cheat\n";
    }
    else{
        cout << "Safe\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    solve();
}
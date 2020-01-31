#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100000

/*
    考sorting應用
    我自己一開始沒想到可以用pair
    後來聽出題者說才發現可以使用pair
    但個人比較偏好 pair<int,string>，因為題目要分學院，string才能比較容易找到學院的element
*/

int n;
//各個學院的vector。第一個放root，第二個放學號（先比root才比學號）
vector<pair<int,string> > student_data[8]; //各個學院的vector

//找個位數相加總和
int root(int value){
    if(value<10) return value;
    int cnt=0;
    while(value){
        cnt+=value%10;
        value/=10;
    }
    return root(cnt);

}
int root(string value){
    int cnt=0;
    for(int i=0;i<value.size();i++){
        cnt+=value[i]-'0';
    }    
    return root(cnt);
}
void init(){
    cin >> n;
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        int rt=root(temp);
        //temp[3]-'0'代表學院的編號，放進該編號的vector裡面
        student_data[temp[3]-'0'].push_back({rt,temp});
    }
}
void solve(){
    for(int i=1;i<=7;i++){
        //排序。不用compare function，pair有內建比較運算子
        sort(student_data[i].begin(),student_data[i].end());
    }
    string list[8];
    list[1]="College of Humanities";
    list[2]="College of Sciences";
    list[3]="College of Social Sciences";
    list[4]="College of Engineering";
    list[5]="College of Management";
    list[6]="College of Law";
    list[7]="College of Teacher Education";

    for(int i=1;i<=7;i++){
        cout << list[i] << '\n';
        for(auto x:student_data[i]){
            cout << x.second << ' ';
        }
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    solve();
}
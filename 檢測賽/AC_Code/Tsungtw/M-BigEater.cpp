#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100 //餐點最大數量

/*
    由於題目有說，每一份都可以有剩餘的食物，可以輕鬆地知道，這題是使用Greedy思維。
    對於每個餐點的CP值由大至小做排序，只要最大的那個還能繼續吃就一直吃，吃到上限為止才換下一種食物。
    直到不能再吃為止。
*/


//建立食物的Structure
struct Food{
    int weight,value,bounded;
};
int n,m;
Food food[MAX_N+4];

//對CP值做Compare Function
bool cmp(Food a,Food b){
    if(a.value/a.weight == b.value/b.weight) return a.bounded > b.bounded;
    return a.value/a.weight > b.value/b.weight;
}
void init(){
    scanf("%d%d",&n,&m);
    m*=1000;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&food[i].weight,&food[i].value,&food[i].bounded);
    }
}
void solve(){
    sort(food,food+n,cmp); //對CP值做排序

    int ans=0;
    int now_full=0;
    for(int i=0;i<n;i++){
        //如果還能吃，而且此種食物還不會吃膩，就吃。
        while(now_full<m && food[i].bounded>0){
            if(now_full+food[i].weight<=m){
                ans+=food[i].value;
                now_full+=food[i].weight;
            }
            else{
                int remain=m-now_full;
                ans+=remain*food[i].value/food[i].weight;
                now_full=m;
            }
            food[i].bounded--;
        }
    }
    printf("%d\n",ans);
}
int main(){
    init();
    solve();
}
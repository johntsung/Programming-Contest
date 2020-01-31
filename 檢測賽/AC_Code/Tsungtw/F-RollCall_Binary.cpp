#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100000
#define MAX_LENG 20

int n,m,q;
char all[MAX_N+5][MAX_LENG+5];
char fri[MAX_N+5][MAX_LENG+5];
int cmp(const void *a,const void *b){
    char *c=(char*)a;
    char *d=(char*)b;
    return strcmp(c,d);
}
bool binary(char obj[][MAX_LENG+5],char str[]){
    int mid,ll=0,lr=n;
    while(lr-ll>1){
        mid=(lr+ll)/2;
        if(strcmp(str,obj[mid])<0){
            lr=mid;
        }
        else if(strcmp(str,obj[mid])>0){
            ll=mid;
        }
        else return true;
    }
    if(strcmp(str,obj[ll])==0) return true;
    return false;
}
void init(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++){
        scanf("%s",all[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%s",fri[i]);
    }
}
void solve(){
    qsort(all,n,sizeof(char)*(MAX_LENG+5),cmp);
    qsort(fri,n,sizeof(char)*(MAX_LENG+5),cmp);
    bool flag1=false,flag2=false;
    while(q--){
        char temp[MAX_LENG+5];
        scanf("%s",temp);
        if(flag1) continue;
        //不在名單上就直接結束
        if(!binary(all,temp)){
            flag1=true;
            continue;
        }
        if(flag2) continue;
        //朋友被點到先標記起來
        if(binary(fri,temp)){
            flag2=true;
        }
        
    }
    if(flag1){
        printf("Teacher is blind !\n");
    }
    else if(flag2){
        printf("Cheat\n");
    }
    else{
        printf("Safe\n");
    }
}
int main(){
    init();
    solve();
}
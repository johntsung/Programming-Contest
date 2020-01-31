#include<bits/stdc++.h>
using namespace std;

int a[100100][20];
int n,q;

void rmq_st(int n){
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++){
			if(i+(1<<j)-1<=n){
				a[i][j]=min(a[i][j-1],a[i+(1<<(j-1))][j-1]);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i][0]);
	}
	rmq_st(n);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int k=log2(r-l+1);
		printf("%d ",min(a[l][k],a[r-(1<<k)+1][k]));
	}
}

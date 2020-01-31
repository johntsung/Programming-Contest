#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long lint;

//unorder_set is better.
map<lint,int> mp;
lint fp(lint x,lint y,lint p){
	lint t=1;
	while(y){
		if(y&1){
			t*=x;
			t%=p;
		}
		x*=x;
		x%=p;
		y>>=1;
	}
	return t;
}
lint bsgs(lint a,lint b,lint p){
	int i;
	if(p%a==0) return -1;
	lint m=ceil(sqrt(p));
	lint l=b;
	mp[l]=1;
	for(int i=1;i<=m;i++){
		l*=a;
		l%=p;
		mp[l]=i+1;
	}
	l=fp(a,m,p);
	lint r=l;
	for(int i=1;i<=m;i++){
		if(mp[r]){
			lint ans=i*m-mp[r]+1;
			mp.clear();
			return ans;
		}
		r*=l;
		r%=p;
	}
	mp.clear();
	return -1;
}
int main(){
	lint p,b,n;
	while(scanf("%lld%lld%lld",&p,&b,&n)!=EOF){
		lint ans=bsgs(b,n,p);
		if(ans==-1) printf("no solution\n");
		else printf("%lld\n",ans);
	}
	return 0;
}

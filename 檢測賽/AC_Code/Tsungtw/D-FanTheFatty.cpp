#include<bits/stdc++.h>
using namespace std;
#define MAX_BUF 300
#define MAX_N 100

/*
    C++ 用字串實作大數
    Java 用 BigInteger 做大數
    python3 直接算
*/

string big_add(string _a,string _b){
	int a[100]={0},b[100]={0};
    //先轉成整數陣列
	for(int i=0;i<(int)_a.size();i++){
		a[i]=_a[i]-'0';
	}
	for(int i=0;i<(int)_b.size();i++){
		b[i]=_b[i]-'0';
	}
	reverse(a,a+(int)_a.size()); //用reverse讓位數對齊（也可以自己刻一個reverse）
	reverse(b,b+(int)_b.size());
	int digit=max((int)_a.size(),(int)_b.size());
	int c[100]={0};
	for(int i=0;i<digit;i++){
		c[i]=a[i]+b[i];
	}
	for(int i=0;i<digit;i++){
        //進位
		if(c[i]>=10){
			c[i+1]+=c[i]/10;
			c[i]%=10;
			if(i==digit-1) digit++;
		}
	}
	string res;
	for(int i=0;i<digit;i++){
		res+=c[i]+'0';
	}
	reverse(res.begin(),res.end());
	return res;
}
string big_sub(string _a,string _b){
	int a[100]={0},b[100]={0};
	for(int i=0;i<(int)_a.size();i++){
		a[i]=_a[i]-'0';
	}
	for(int i=0;i<(int)_b.size();i++){
		b[i]=_b[i]-'0';
	}
	reverse(a,a+(int)_a.size());
	reverse(b,b+(int)_b.size());
	int digit=max((int)_a.size(),(int)_b.size());
	int c[100]={0};
	for(int i=0;i<digit;i++){
		c[i]=a[i]-b[i];
	}
	for(int i=0;i<digit;i++){
        //借位
		if(c[i]<0){
			c[i+1]--;
			c[i]+=10;
		}
	}
	while(c[digit-1]==0) digit--; //去除leading zero
	string res;
	for(int i=0;i<digit;i++){
		res+=c[i]+'0';
	}
	//if(digit==0) res="0";
	reverse(res.begin(),res.end());
	return res;
}
void solve(int N){
    char buf[MAX_BUF+5];
		char a[MAX_N+5],b[MAX_N+5];
		bool flag=false;
		scanf("%s",buf);
		int leng=strlen(buf);
		if(leng==1 && (buf[0]=='+' || buf[0]=='-')){
			scanf("%s%s",a,b);
			flag=true;
		}
		else{
			strcpy(a,buf);
			scanf("%s",b);
		}
		string ans;
		if(flag && buf[0]=='-'){
			ans=big_sub(a,b);
		}
		else{
			ans=big_add(a,b);
		}
		cout << N << '\n';
		cout << ans << '\n';
}

int main(){
    int ncase;
    scanf("%d",&ncase);
    for(int i=1;i<=ncase;i++){
        //init();
        solve(i);
    }
}
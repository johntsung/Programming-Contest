#include<bits/stdc++.h>
using namespace std;

bool p[10010000];
vector<int> prime;
void prime_table(){
	for(int i=2;i<10010000;i++){
		if(!p[i]){
			for(int j=i+i;j<10010000;j+=i){
				p[j]=true;
			}
		}
	}
	for(int i=2;i<=10010000;i++){
		if(!p[i]) prime.push_back(i);
	}
}


int main(){
	prime_table();
}

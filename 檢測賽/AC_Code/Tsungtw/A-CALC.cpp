#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

/*
    超級實作題不解釋
	小心0跟overflow的陷阱
*/


vector<string> ans_list[5];
lint a,b,ans;
char symbol;
void add_equation(char in_char){
    if(in_char=='0'){
		ans_list[0].push_back(".*****.");
		ans_list[1].push_back(".*...*.");
		ans_list[2].push_back(".*...*.");
		ans_list[3].push_back(".*...*.");
		ans_list[4].push_back(".*****.");
	}
	if(in_char=='1'){
		ans_list[0].push_back(".***...");
		ans_list[1].push_back("...*...");
		ans_list[2].push_back("...*...");
		ans_list[3].push_back("...*...");
		ans_list[4].push_back(".*****.");
	}
	if(in_char=='2'){
		ans_list[0].push_back(".*****.");
		ans_list[1].push_back(".....*.");
		ans_list[2].push_back(".*****.");
		ans_list[3].push_back(".*.....");
		ans_list[4].push_back(".*****.");
	}
	if(in_char=='3'){
		ans_list[0].push_back(".*****.");
		ans_list[1].push_back(".....*.");
		ans_list[2].push_back(".*****.");
		ans_list[3].push_back(".....*.");
		ans_list[4].push_back(".*****.");
	}
	if(in_char=='4'){
		ans_list[0].push_back(".*...*.");
		ans_list[1].push_back(".*...*.");
		ans_list[2].push_back(".*****.");
		ans_list[3].push_back(".....*.");
		ans_list[4].push_back(".....*.");
	}
	if(in_char=='5'){
		ans_list[0].push_back(".*****.");
		ans_list[1].push_back(".*.....");
		ans_list[2].push_back(".*****.");
		ans_list[3].push_back(".....*.");
		ans_list[4].push_back(".*****.");
	}
	if(in_char=='6'){
		ans_list[0].push_back(".*****.");
		ans_list[1].push_back(".*.....");
		ans_list[2].push_back(".*****.");
		ans_list[3].push_back(".*...*.");
		ans_list[4].push_back(".*****.");
	}
	if(in_char=='7'){
		ans_list[0].push_back(".*****.");
		ans_list[1].push_back(".*...*.");
		ans_list[2].push_back(".*...*.");
		ans_list[3].push_back(".....*.");
		ans_list[4].push_back(".....*.");
	}
	if(in_char=='8'){
		ans_list[0].push_back(".*****.");
		ans_list[1].push_back(".*...*.");
		ans_list[2].push_back(".*****.");
		ans_list[3].push_back(".*...*.");
		ans_list[4].push_back(".*****.");
	}
	if(in_char=='9'){
		ans_list[0].push_back(".*****.");
		ans_list[1].push_back(".*...*.");
		ans_list[2].push_back(".*****.");
		ans_list[3].push_back(".....*.");
		ans_list[4].push_back(".*****.");
	}
	if(in_char=='+'){
		ans_list[0].push_back("...*...");
		ans_list[1].push_back("...*...");
		ans_list[2].push_back(".*****.");
		ans_list[3].push_back("...*...");
		ans_list[4].push_back("...*...");
	}
	if(in_char=='-'){
		ans_list[0].push_back(".......");
		ans_list[1].push_back(".......");
		ans_list[2].push_back(".*****.");
		ans_list[3].push_back(".......");
		ans_list[4].push_back(".......");
	}
	if(in_char=='*'){
		ans_list[0].push_back(".*...*.");
		ans_list[1].push_back("..*.*..");
		ans_list[2].push_back("...*...");
		ans_list[3].push_back("..*.*..");
		ans_list[4].push_back(".*...*.");
	}
	if(in_char=='='){
		ans_list[0].push_back(".......");
		ans_list[1].push_back(".*****.");
		ans_list[2].push_back(".......");
		ans_list[3].push_back(".*****.");
		ans_list[4].push_back(".......");
	}
}
void init(){
    for(int i=0;i<5;i++) ans_list[i].clear();
    scanf("%lld %c %lld",&a,&symbol,&b);
}
void print_ans(){
    for(int i=0;i<5;i++){
        for(int j=0;j<(int)ans_list[i].size();j++){
            cout << ans_list[i][j];
        }
        cout << '\n';
    }
}
void solve(){
    if(symbol=='+') ans = a+b;
    if(symbol=='-') ans = a-b;
    if(symbol=='*') ans = a*b;
    char ans_line[100];
    sprintf(ans_line,"%lld%c%lld=%lld\0",a,symbol,b,ans);
    int leng=strlen(ans_line);
    for(int i=0;i<leng;i++){
        add_equation(ans_line[i]);
    }
    print_ans();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ncase;
    scanf("%d",&ncase);
    while(ncase--){
        init();
        solve();
    }
}
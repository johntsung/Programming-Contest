#include<bits/stdc++.h>
using namespace std;

/*
    對不會C++ map 的肯定是魔王題了
    會 map 的，建表然後把所有條件都考慮進去，就可以完成了
    這份Code為了增加可讀性集合了C++ Map的精髓
    Code行數有點高，大家慢慢品嚐。
*/

//定義Code39的 structure
struct CODE39{
    string bar,space;
};
//定義相對值的 structure
struct VALUE{
    char symbol;
    int value;
};
//定義CODE39的比較運算子（用在map裡面，因為map必須要定義，不然不能用struct）
struct CMP{
    bool operator () (const CODE39 &lhs,const CODE39 &rhs) const{
        return lhs.bar==rhs.bar && lhs.space==rhs.space; 
    }
};
struct CODE39_Hash{
    size_t operator()(const CODE39 & code) const{
        return hash<string>()(code.bar) ^  hash<string>()(code.space);
    }
};
unordered_map<CODE39,VALUE,CODE39_Hash,CMP> table;
string code;
void make_table();
void init();
void solve();
VALUE getcode(int,string);
void wrong_format();
void print_ans(string);
void wrong_check(int);


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //建表
    make_table();
    int ncase;
    cin >> ncase;
    while(ncase--){
        init();
        solve();
    }
    return 0;
}
void make_table(){
    table.insert({{"00110","0100"},{'0',0}});
    table.insert({{"10001","0100"},{'1',1}});
    table.insert({{"01001","0100"},{'2',2}});
    table.insert({{"11000","0100"},{'3',3}});
    table.insert({{"00101","0100"},{'4',4}});
    table.insert({{"10100","0100"},{'5',5}});
    table.insert({{"01100","0100"},{'6',6}});
    table.insert({{"00011","0100"},{'7',7}});
    table.insert({{"10010","0100"},{'8',8}});
    table.insert({{"01010","0100"},{'9',9}});

    table.insert({{"10001","0010"},{'A',10}});
    table.insert({{"01001","0010"},{'B',11}});
    table.insert({{"11000","0010"},{'C',12}});
    table.insert({{"00101","0010"},{'D',13}});
    table.insert({{"10100","0010"},{'E',14}});
    table.insert({{"01100","0010"},{'F',15}});
    table.insert({{"00011","0010"},{'G',16}});
    table.insert({{"10010","0010"},{'H',17}});
    table.insert({{"01010","0010"},{'I',18}});
    table.insert({{"00110","0010"},{'J',19}});

    table.insert({{"10001","0001"},{'K',20}});
    table.insert({{"01001","0001"},{'L',21}});
    table.insert({{"11000","0001"},{'M',22}});
    table.insert({{"00101","0001"},{'N',23}});
    table.insert({{"10100","0001"},{'O',24}});
    table.insert({{"01100","0001"},{'P',25}});
    table.insert({{"00011","0001"},{'Q',26}});
    table.insert({{"10010","0001"},{'R',27}});
    table.insert({{"01010","0001"},{'S',28}});
    table.insert({{"00110","0001"},{'T',29}});

    table.insert({{"10001","1000"},{'U',30}});
    table.insert({{"01001","1000"},{'V',31}});
    table.insert({{"11000","1000"},{'W',32}});
    table.insert({{"00101","1000"},{'X',33}});
    table.insert({{"10100","1000"},{'Y',34}});
    table.insert({{"01100","1000"},{'Z',35}});
    table.insert({{"00011","1000"},{'-',36}});
    table.insert({{"10010","1000"},{'.',37}});
    table.insert({{"01010","1000"},{' ',38}});
    table.insert({{"00110","1000"},{'*',43}});

    table.insert({{"00000","1110"},{'$',39}});
    table.insert({{"00000","1101"},{'/',40}});
    table.insert({{"00000","1011"},{'+',41}});
    table.insert({{"00000","0111"},{'%',42}});

}
void init(){
    cin >> code;
}

//抓取一個code
VALUE getcode(int ind,string obj){
    string bar="",space="";
    bar+=obj[ind+0];
    bar+=obj[ind+2];
    bar+=obj[ind+4];
    bar+=obj[ind+6];
    bar+=obj[ind+8];
    
    space+=obj[ind+1];
    space+=obj[ind+3];
    space+=obj[ind+5];
    space+=obj[ind+7];
    //如果這個code不再表裡面，就回傳沒有
    if(!table.count({bar,space})){
        return {'\0',-1};
    }
    return table[{bar,space}];
}
void wrong_format(){
    cout << "Wrong format!\n";
}
void print_ans(string ans){
    cout << ans << '\n';
}
void wrong_check(int cnt){
    cout << "Wrong check code! Correct check code is " << cnt << "!\n";
}

void solve(){
    //如果長度不是9的倍數，或是長度小於9則格式錯誤。
    if((int)code.size()%9!=0 || (int)code.size()<=9){
        wrong_format();
        return ;
    }
    //抓取頭的 code
    VALUE head=getcode(0,code);
    //如果頭不是'*'就格式錯誤
    if(head.symbol!='*'){
        wrong_format();
        return ;
    }
    int i;
    bool wrong_flag=true,find_tail=false;//是不是格式錯誤。有沒有找到尾巴
    string ans="";
    int cnt=0;

    for(i=9;i<(int)code.size();i+=9){
        VALUE temp=getcode(i,code);
        //如果是'*'而且是結尾，break
        if(temp.value==43 && (i==(int)code.size()-18 || i==(int)code.size()-9)){
            i+=9;
            find_tail=true;
            break;
        }
        if(temp.value<0 || temp.value>42){
            wrong_flag=false;
            wrong_format();
            return;
        }
        ans+=temp.symbol;
        cnt+=temp.value;
    }
    //沒有尾巴'*'
    if(!find_tail){
        wrong_format();
        return ;
    }
    VALUE check;
    //如果沒有檢查碼，直接輸出答案
    if(i==(int)code.size()){
        print_ans(ans);
        return ;
    }
    else{ 
        //有檢查碼，確認檢查碼是否正確。
        check=getcode(i,code);
        if((cnt%43)==check.value){
            print_ans(ans);
        }
        else{
            wrong_check(cnt%43);
        }
    }
}

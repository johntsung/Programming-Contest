#include<cstdio>
#include<iostream>
using namespace std;

/*
    在struct的基礎中 C , C++ 兩者最大的差別應該是
    C++ 不需要 typedef
*/
struct Point_2D{
    int x,y;
};
int main(){
    Point_2D value_name;  //If use gcc, error!
}

/*
    結論：
        不需要做typedef方便許多。
*/
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

/*
    1. C++ 中，可以在 struct 內定義屬於該 struct 的副函式（有點像 public）
    2. C++ 中，可以在 struct 內定義屬於該 struct 的“運算子”
*/

//////////////////////////////////////////////////////////////////////////


struct Point_2D{
    int x,y;
    // 自己寫一個離原點距離的 Function
    int distance_with_origin_square(){
        return x*x+y*y;
    }
    float distance_with_origin(){
        return sqrt(this->distance_with_origin_square());
    }

    //自己定義大於 等於 小於
    bool operator < (Point_2D &rhs){
        return this->distance_with_origin() < rhs.distance_with_origin();
    }
    bool operator == (Point_2D &rhs){
        return this->distance_with_origin_square() == rhs.distance_with_origin_square();
    }
    bool operator > (Point_2D &rhs){
        return this->distance_with_origin() > rhs.distance_with_origin();
    }

    //自己定義加法
    
    Point_2D& operator += (Point_2D &rhs){
        x+=rhs.x;
        y+=rhs.y;
        return *this;
    }
    Point_2D operator + (Point_2D &rhs){
        Point_2D temp={x,y};
        temp+=rhs;
        return temp;
    }
};
int main(){
    Point_2D point1,point2;
    cin >> point1.x >> point1.y;
    cin >> point2.x >> point2.y;
    cout << "The distance between point and origin is " << point1.distance_with_origin() << endl;
    cout << "The distance between point and origin is " << point2.distance_with_origin() << endl;

    if(point1<point2){
        cout << "point1 < point2" << endl;
    }
    else if(point1==point2){
        cout << "point1 = point2" << endl;
    }
    else{
        cout << "point1 > point2" << endl;
    }
    point1=point1+point2;
    cout << "After + operation point1 x = " << point1.x << " , y = " <<  point1.y << endl;
}


/*
    自己定義 function 的好處
    不會跟別的 function 不小心混用、可讀性也比較高。
    對初學來說，最最最困難的，是如何分辨 “自己” 跟 “外來”。
    不過用久了以後，就發現這並沒有什麼好困難的

    自己定義 operator 的好處，可以直接使用運算子，不需要一直做很多複雜的判斷。
    另外、定義小於，在使用C++ sort的時候，就不需要額外Call Compare Function
*/
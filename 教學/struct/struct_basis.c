#include<stdio.h>



/*
    struct 中文叫 “結構”。
    可以自己組合一些已經定義的型態，形成一個自己定義的“新型態”。
*/

//////////////////////////////////////////////////////////////////////////

/*
    定義方式：
    struct 結構名稱{
        ......
    };

    struct + 結構名稱 才是“型態”
    如下面例子， “struct Point_2D” 才是型態 
*/
struct Point_2D{
    int x,y;
};


/*
    struct + 結構名稱 實在是太長了，
    C語言中經常會使用 typedef 來重新命名，
    如下面的例子 “P2D” 就代表了 “struct Point_2D” 的個型態
*/
typedef struct Point_2D P2D;



int main(){
    /*
        如何宣告？
        ”struct + 結構名稱“ + “變數名稱”;
        就跟宣告一般的型態一樣
        型態 + 變數名稱
    */
   struct Point_2D value_name1;
   // 或是
   P2D value_name2;


    /*
        如何取出 struct 裡面的值呢？
        用 '.' 這個符號
        像是下面的例子
    */
   printf("Please Input Two Integer: ");
   scanf("%d%d",&value_name1.x,&value_name1.y);
   printf("Point_2D x = %d , y = %d\n",value_name1.x,value_name1.y);
}

/*
    結論：
        使用 struct 的優點是，能夠自己定義不同的型態包裝起來，
        不需要一直用很多不同的變數存取，可讀性也比較高。
*/
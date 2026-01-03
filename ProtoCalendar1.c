//カレンダーの試作（構造体あり）
#include <stdio.h>

//=== 日付 ===//
typedef struct {
   int y;    //年
   int m;    //月
   int d;    //日
} Date;

//閏年か平年かを判定する関数(閏年なら1、平年なら0を返す)
int year(int y)
{
    if (y % 400 == 0)
    return 1;

    else if (y % 4 == 0 && y % 100 != 0)
    return 1;

    else
    return 0;

}

//末日が何日までか判定する関数(その月の末日の値を返す)
int day(int y, int m)
{
    if (year(y) == 1) {
        if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;

        else if (m == 2)
        return 29;

        else
        return 31;
    }

    else
    if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;

        else if (m == 2)
        return 28;

        else
        return 31;
}

//入力された年月日がおかしい場合の表示
void er(void)
{
    printf("正しい年月日を入力してください。");
}

//入力された年月日がおかしくないかどうか判定する関数
int YMD_jud(Date d1)
{
    if (d1.y < 1 || d1.m > 12 || d1.m < 1 || d1.d < 1) {
    er();
    return 0;}

    else if (day(d1.d, d1.m) < d1.d) {
    er();
    return 0;}

    else
    return 1;
}

//入力された日の前日を表示する関数
int decrement_date(Date d1)
{
    if (d1.m == 1 && d1.d == 1) {
        d1.y = d1.y - 1;
        d1.m = 12;
        d1.d = 31;
    }

    else if (d1.d == 1) {
        d1.m = d1.m - 1;
        d1.d = day(d1.y, d1.m);
    }

    else
    d1.d = d1.d - 1;
 
    printf("前の日付は%d年%d月%d日です。\n", d1.y, d1.m, d1.d);

    return 1;
}

//入力された日の次の日を表示する関数
int increment_date(Date d1) {

        if (d1.m == 12 && d1.d == 31) {
            d1.y = d1.y + 1;
            d1.m = 1;
            d1.d = 1;
        }

        else if (day(d1.y, d1.m) == d1.d) {
            d1.m = d1.m + 1;
            d1.d = 1;
        }

        else
        d1.d = d1.d + 1;

    printf("次の日付は%d年%d月%d日です。\n", d1.y, d1.m, d1.d);

    return 1;
}

int main(void)
{
    Date d1;

    printf("年 : "); scanf("%d", &d1.y);
    printf("月 : "); scanf("%d", &d1.m);
    printf("日 : "); scanf("%d", &d1.d);

    if (YMD_jud(d1) == 0)
    return 0;

    decrement_date(d1);
    increment_date(d1);

    return 0;
}
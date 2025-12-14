//Try1の改善版その１

#include <stdio.h>

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
int YMD_jud(int y, int m, int d)
{
    if (y < 1 || m > 12 || m < 1 || d < 1) {
    er();
    return 0;}

    else if (day(y, m) < d) {
    er();
    return 0;}

    else
    return 1;
}

//入力された日の前日を表示する関数
int decrement_date(int *y, int *m, int *d)
{
    if (*m == 1 && *d == 1) {
        *y = *y - 1;
        *m = 12;
        *d = 31;
    }

    else if (*d == 1) {
        *m = *m - 1;
        *d = day(*y, *m);
    }

    else
    *d = *d - 1;
 
    printf("前の日付は%d年%d月%d日です。\n", *y, *m, *d);

    return 1;
}

//入力された日の次の日を表示する関数
int increment_date(int *y, int *m, int *d) {

        if (*m == 12 && *d == 31) {
            *y = *y + 1;
            *m = 1;
            *d = 1;
        }

        else if (day(*y, *m) == *d) {
            *m = *m + 1;
            *d = 1;
        }

        else
        *d = *d + 1;

    printf("次の日付は%d年%d月%d日です。\n", *y, *m, *d);

    return 1;
}

int main(void)
{
    int y, m, d;

    printf("年 : "); scanf("%d", &y);
    printf("月 : "); scanf("%d", &m);
    printf("日 : "); scanf("%d", &d);

    if (YMD_jud(y, m, d) == 0)
    return 0;

    int y2 = y;
    int m2 = m;
    int d2 = d;

    decrement_date(&y, &m, &d);
    increment_date(&y2, &m2, &d2);

    return 0;
}

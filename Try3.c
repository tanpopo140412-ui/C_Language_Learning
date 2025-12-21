#include <stdio.h>

//入力された日付の曜日を表示するカレンダー

//ツェラーの公式による曜日計算
void Tu(int y, int m, int d)
{
    int D;

    if (m == 1) {
        y = y - 1;
        m = 13;
    }

    else if (m == 2) {
        y = y - 1;
        m = 14;
    }


    D = (y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7;

    switch (D) {
        case 0 : printf("日曜日"); break;
        case 1 : printf("月曜日"); break;
        case 2 : printf("火曜日"); break;
        case 3 : printf("水曜日"); break;
        case 4 : printf("木曜日"); break;
        case 5 : printf("金曜日"); break;
        case 6 : printf("土曜日"); break;

        default :  break;
    }
    
}

int main(void)
{
    int y, m, d;

    printf("年 : "); scanf("%d", &y);
    printf("月 : "); scanf("%d", &m);
    printf("日 : "); scanf("%d", &d);

    printf("%d年%d月%d日は", y, m , d);

    Tu(y, m, d);

    printf("です。\n");

    return 0;
}
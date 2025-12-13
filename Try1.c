#include <stdio.h>

//--- 前の日の日付に変更 ---//
void decrement_date(int *y, int *m, int *d)
{
    if (*y < 0 || *m > 12 || *m < 1 || *d > 31 || *d < 1)
        printf("正しい年月日を入力してください。\n");
    else if (*m == 1 && *d == 1) {
        *y = *y - 1;
        *m = 12;
        *d = 31;
    }

    else if (*y % 4 == 0 && *y % 100 != 0) {
        if (*m == 4 || *m == 9 || *m == 11) {
            if (*d > 30)
            printf("正しい年月日を入力してください。\n");

            if (*d == 1) {
            *m = *m - 1;
            *d = 31;}

            else
            *d = *d - 1;
        }

        else if (*m != 3) {
            if (*d == 1) {
                *m = *m - 1;
                *d = 30; 
            }

            else
            *d = *d - 1;
        }

        else if (*m == 3) {
            if (*d == 1) {
                *m = *m - 1;
                *d = 29;
            }

            else *d = *d - 1;
        }
    }

    else if (*y % 4 != 0)
    {
        if (*m == 4 || *m == 9 || *m == 11) {
            if (*d > 30)
            printf("正しい年月日を入力してください。\n");

            if (*d == 1) {
            *m = *m - 1;
            *d = 31;}

            else
            *d = *d - 1;
        }

        else if (*m != 3) {
            if (*d == 1) {
                *m = *m - 1;
                *d = 30; 
            }

            else
            *d = *d - 1;
        }

        else if (*m == 3) {
            if (*d == 1) {
                *m = *m - 1;
                *d = 28;
            }

            else *d = *d - 1;
        }

    }

    else if (*y % 400 == 0) {
        
        if (*m == 4 || *m == 9 || *m == 11) {
            if (*d > 30)
            printf("正しい年月日を入力してください。\n");

            else if (*d == 1) {
            *m = *m - 1;
            *d = 31;}

            else
            *d = *d - 1;
        }

        else if (*m != 3) {
            if (*d == 1) {
                *m = *m - 1;
                *d = 30; 
            }

            else
            *d = *d - 1;
        }

        else if (*m == 3) {
            if (*d == 1) {
                *m = *m - 1;
                *d = 29;
            }
            else *d = *d - 1;
        }

    }
    printf("%d年 %d月 %d日\n", *y, *m, *d);
}

//--- 次の日の日付に変更 ---//
void increment_date(int *y, int *m, int *d) {
    if (*y < 0 || *m > 12 || *m < 1 || *d > 31 || *d < 1)
        printf("正しい年月日を入力してください。\n");

    else if (*m == 12 && *d == 31) {
        *y = *y + 1;
        *m = 1;
        *d = 1;
    }

    else if (*y % 4 == 0 && *y % 100 != 0) {
        if (*m == 4 || *m == 9 || *m == 11) {
            if (*d > 30)
            printf("正しい年月日を入力してください。\n");

            if (*d == 30) {
            *m = *m + 1;
            *d = 1;}

            else
            *d = *d + 1;
        }

        else if (*m != 2) {
            if (*d == 31) {
                *m = *m + 1;
                *d = 1; 
            }
            else
            *d = *d + 1;
        }

        else if (*m == 2) {
            if (*d > 29)
            printf("正しい年月日を入力してください。\n");
            else if (*d == 29) {
                *m = *m + 1;
                *d = 1;
            }
            else
            *d = *d + 1;
        }


    }

        else if (*y % 400 == 0) {
        if (*m == 4 || *m == 9 || *m == 11) {
            if (*d > 30)
            printf("正しい年月日を入力してください。\n");
            else if (*d == 30) {
            *m = *m + 1;
            *d = 1;}

            else
            *d = *d + 1;
        }

        else if (*m != 2) {
            if (*d == 31) {
                *m = *m + 1;
                *d = 1;
            }

            else
            *d = *d + 1;
        }

        else if (*m == 2) {
            if (*d > 28)
            printf("正しい年月日を入力してください。\n");
            else if (*d == 28) {
                *m = *m + 1;
                *d = 1;
            }
            else
            *d = *d + 1;
        }

    }

    else if (*y % 4 != 0)
    {
        if (*m == 4 || *m == 9 || *m == 11) {
            if (*d > 30)
            printf("正しい年月日を入力してください。\n");
            else if (*d == 30) {
            *m = *m + 1;
            *d = 1;}

            else
            *d = *d + 1;
        }

        else if (*m != 2) {
            if (*d == 30) {
                *m = *m + 1;
                *d = 1; 
            }

            else
            *d = *d + 1;
        }

        else if (*m == 2) {
            if (*d > 28)
            printf("正しい年月日を入力してください。\n");
            else if (*d == 28) {
                *m = *m + 1;
                *d = 1;
            }
            else
            *d = *d + 1;
        }

    }
    printf("%d年 %d月 %d日\n", *y, *m, *d);
}

int main(void)
{
    //年月日
    int y, m, d;

    printf("年を入力 : "); scanf("%d", &y);
    printf("月を入力 : "); scanf("%d", &m);
    printf("日を入力 : "); scanf("%d", &d);

        //日付のコピー
    int y2 = y;
    int m2 = m;
    int d2 = d;

    printf("前の日付 :");
    decrement_date(&y, &m, &d);
    

    printf("次の日付 : ");
    increment_date(&y2, &m2, &d2);

    return 0;
}
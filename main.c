#define _CRT_SECURE_NO_WARNINGS
#include "lr.h"

int main()
{
    printf("Laboratory work or additional task? \n");
    int M;
    int choice;
    int number;
    scanf("%d", &M);

    if (M == 1)
    {
        printf("1. After what time will the pool be empty.\n");
        printf("2. Calculate the sum of the first elements of the series.\n");
        printf("3. Determine if all the words from the character stream are words of the same length.\n");
        printf("4. Delete all numbers in the character string..\n");
        printf("5. Reset the elements with odd numbers if their sum is less. Otherwise, reinstall the items with even numbers.\n");
        printf("6. Reset the rows whose arithmetic mean is less than the arithmetic mean for the entire array..\n");
        printf("7. Swap the binary digits in the mirror order.\n");
        printf("Enter your choice. \n");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice)
        {
        case 1:
            laba1();
            break;
        case 2:
            laba2();
            break;
        case 3:
            laba3();
            break;
        case 4:
            laba4();
            break;
        case 5:
            laba5();
            break;
        case 6:
            laba6();
            break;
        case 7:
            laba7();
            break;
        }
    }

    else if (M == 2)
    {
        printf("1. -.\n");
        printf("2. Working cycle for.\n");
        printf("3. Break point.\n");
        printf("4. -.\n");
        printf("5. A structure that contains: int, float, char.\n");
        printf("6. Sorting algorithm.\n");
        printf("7. .\n");
        scanf("%d", &number);
        while (getchar() != '\n');
        switch (number)
        {
        case 2:
            dopzd2();
            break;
        case 3:
            dopzd3();
            break;
        case 5:
            dopzd5();
            break;
        case 6:
            dopzd6();
            break;
        }
    }
    system("pause");

    return 0;
}
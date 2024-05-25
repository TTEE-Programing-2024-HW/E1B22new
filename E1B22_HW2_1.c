#include <stdio.h>
#include <stdlib.h> // 用於system()函數

int main() {
    int password = 2024;
    int input_pwd;
    int attempts = 0;

    // 步驟1: 輸入密碼
    while (1) {
        printf("請輸入4位數密碼: ");
        scanf("%d", &input_pwd);
        attempts++;

        if (input_pwd == password) {
            printf("密碼正確！\n");
            break;
        } else if (attempts >= 3) {
            printf("您已連續輸入錯誤三次，程式結束。\n");
            return 0;
        } else {
            printf("密碼錯誤，請重新輸入。\n");
        }
    }

    char choice;

    // 步驟2: 主選單
    while (1) {
        system("cls"); // 清除螢幕
        printf("+-----------------------+\n");
        printf("|                       |\n");
        printf("|       我是E1B22       |\n");
        printf("|                       |\n");
        printf("|       I`m E1B22       |\n");
        printf("|                       |\n");
        printf("|    I am a slacker     |\n");
        printf("|                       |\n");
        printf("|      我是一個懶鬼     |\n");
        printf("|                       |\n");
        printf("+-----------------------+\n");
        printf("+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("|                       |\n");
        printf("+-----------------------+\n");
        printf("|                       |\n");
        printf("|  a. 畫出直角三角形    |\n");
        printf("|  b. 顯示乘法表        |\n");
        printf("|  c. 結束              |\n");
        printf("|                       |\n");
        printf("+-----------------------+\n");
        printf("|                       |\n");
        printf("+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("|                       |\n");
        printf("+-----------------------+\n");
        //個人風格顯示屏 

        printf("請選擇操作: ");
        choice = getchar();
        getchar(); // 清除緩衝區中的換行符

        switch (choice) {
            case 'a':
            case 'A':
                // 步驟3: 畫出直角三角形
                system("cls");
                char triangle_choice;
                printf("請輸入'a'到'n'之間的字元: ");
                triangle_choice = getchar();
                getchar(); // 清除緩衝區中的換行符
                if (triangle_choice >= 'a' && triangle_choice <= 'n') {
                    // 根據輸入字元顯示直角三角形
                    printf("您輸入的字元是: %c\n", triangle_choice);
                    int height = triangle_choice - 'a' + 1;
                    for (int i = 1; i <= height; ++i) {
                        for (int j = 1; j <= i; ++j) {
                            printf("*");
                        }
                        printf("\n");
                    }
                    printf("按任意鍵返回主選單...");
                    getchar(); // 等待用戶按下任意鍵
                } else {
                    printf("請輸入'a'到'n'之間的字元。\n");
                    printf("按任意鍵返回主選單...");
                    getchar(); // 等待用戶按下任意鍵
                }
                break;
            case 'b':
            case 'B':
                // 步驟4: 顯示乘法表
                system("cls");
                int n;
                printf("請輸入1至9的整數n: ");
                scanf("%d", &n);
                getchar(); // 清除緩衝區中的換行符
                if (n >= 1 && n <= 9) {
                    // 顯示乘法表
                    printf("乘法表如下:\n");
                    for (int i = 1; i <= n; ++i) {
                        for (int j = 1; j <= n; ++j) {
                            printf("%d\t", i * j);
                        }
                        printf("\n");
                    }
                    printf("按任意鍵返回主選單...");
                    getchar(); // 等待用戶按下任意鍵
                } else {
                    printf("請輸入1至9的整數n。\n");
                    printf("按任意鍵返回主選單...");
                    getchar(); // 等待用戶按下任意鍵
                }
                break;
            case 'c':
            case 'C':
                // 步驟5: 結束或繼續
                printf("\nContinue? (y/n): ");
                choice = getchar();
                getchar(); // 清除緩衝區中的換行符
                if (choice == 'y' || choice == 'Y') {
                    break; // 回到主選單
                } else if (choice == 'n' || choice == 'N') {
                    printf("\n程式結束。\n");
                    return 0; // 結束程式
                } else {
                    printf("\n請輸入'y'或'n'。\n");
                    printf("按任意鍵返回主選單...");
                    getchar(); // 等待用戶按下任意鍵
                }
                break;
            default:
                printf("\n請輸入有效的選項。\n");
                printf("按任意鍵返回主選單...");
                getchar(); // 等待用戶按下任意鍵
                break;
        }
    }

    return 0;
}

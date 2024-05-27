#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <conio.h> // Windows下使用
#define CLEAR "cls"
#else
#include <termios.h>
#include <unistd.h>
#define CLEAR "clear"

void reset_terminal_mode() {
    struct termios tty;
    tcgetattr(0, &tty);
    tty.c_lflag |= ICANON;
    tty.c_lflag |= ECHO;
    tcsetattr(0, TCSANOW, &tty);
}

void set_conio_terminal_mode() {
    struct termios tty;
    tcgetattr(0, &tty);
    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &tty);
    atexit(reset_terminal_mode);
}

int getch() {
    int r;
    unsigned char c;
    set_conio_terminal_mode();
    r = read(0, &c, 1);
    return c;
}
#endif

#define PASSWORD 2024

void showWelcomeScreen();
int verifyPassword();
void showMainMenu();
void drawRightTriangle();
void displayMultiplicationTable();
void exitProgram();

int main() {
    int attempts = 0;

    showWelcomeScreen();

    while (attempts < 3) {
        if (verifyPassword()) {
            showMainMenu();
            break;
        } else {
            attempts++;
            printf("密碼錯誤。剩餘次數：%d\n", 3 - attempts);
        }
    }

    if (attempts == 3) {
        printf("密碼錯誤次數過多。程式結束。\n");
        return 0;
    }

    return 0;
}

// 1. 顯示歡迎畫面並驗證密碼
void showWelcomeScreen() {
    printf("**********************************************\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                   歡迎使用                 *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("**********************************************\n");
    printf("          E1B22             請輸入四位數密碼：\n");
}

int verifyPassword() {
    int input_password;
    printf("輸入密碼：");
    scanf("%d", &input_password);
    return input_password == PASSWORD;
}

// 2. 顯示主選單
void showMainMenu() {
    char choice;

    while (1) {
        system(CLEAR); // 使用 system(CLEAR)
        printf("+---------------------------+\n");
        printf("|  a. 畫出直角三角形        |\n");
        printf("|  b. 顯示乘法表            |\n");
        printf("|  c. 結束                  |\n");
        printf("+---------------------------+\n");
        printf("請選擇：");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
            case 'A':
                drawRightTriangle();
                break;
            case 'b':
            case 'B':
                displayMultiplicationTable();
                break;
            case 'c':
            case 'C':
                exitProgram();
                break;
            default:
                printf("無效選擇。請重新選擇。\n");
        }
    }
}

// 3. 畫出直角三角形
void drawRightTriangle() {
    char ch;
    int i, j;
    system(CLEAR); // 使用 system(CLEAR)
    printf("請輸入一個'a'到'n'的字元：");
    while (1) {
        scanf(" %c", &ch);
        if (ch >= 'a' && ch <= 'n') {
            break;
        } else {
            printf("輸入無效。請輸入'a'到'n'的字元：");
        }
    }

    int height = ch - 'a' + 1;
    for (i = 1; i <= height; i++) {
        for (j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("按任意鍵返回主選單...\n");
    getch(); // 等待使用者按任意鍵
}

// 4. 顯示乘法表
void displayMultiplicationTable() {
    int n;
    int i, j;
    system(CLEAR); // 使用 system(CLEAR)
    printf("請輸入一個1至9的整數：");
    while (1) {
        scanf("%d", &n);
        if (n >= 1 && n <= 9) {
            break;
        } else {
            printf("輸入無效。請輸入1至9的整數：");
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d*%d=%2d ", i, j, i * j);
        }
        printf("\n");
    }

    printf("按任意鍵返回主選單...\n");
    getch(); // 等待使用者按任意鍵
}

// 5. 退出系統
void exitProgram() {
    char confirm;
    printf("Continue? (y/n)：");
    while (1) {
        scanf(" %c", &confirm);
        if (confirm == 'n' || confirm == 'N') {
            showMainMenu();
            break;
        } else if (confirm == 'y' || confirm == 'Y') {
            printf("系統結束。再見！\n");
            return 0;
        } else {
            printf("無效輸入。請輸入 'y' 或 'n'：");
        }
    }
}


//本次的作業難的地方不是題目本身，而是繳交的方式；如果改回tronclass繳交我們應該很容易就能拿到分數了。 

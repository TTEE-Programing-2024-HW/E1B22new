#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定義學生結構
struct Student {
    char name[50];
    int studentID;
    float mathGrade;
    float physicsGrade;
    float englishGrade;
    float averageGrade;
};

// 函式原型宣告
void displayMainMenu();
void enterGrades();
void displayGrades();
void searchGrades();
void gradeRanking();
void exitSystem();
void clearBuffer(); // 新增函式宣告

// 全局變數
struct Student students[10]; // 學生陣列，最多 10 個學生
int numStudents = 0; // 目前學生數量

int main() {
    // 建立個人風格的畫面
    printf("歡迎使用簡易成績系統！\n");
    printf("++++++++++++++++++++++++\n");
    printf("------------------------\n");
    printf("++++++++++++++++++++++++\n");
    printf("------------------------\n");
    printf("------------------------\n");
    printf("++++++++++++++++++++++++\n");
    printf("------------------------\n");
    printf("++++++++++++++++++++++++\n");
    printf("------------------------\n");
    printf("++++++++++++++++++++++++\n");
    printf("------------------------\n");
    printf("++++++++++++++++++++++++\n");
    printf("------------------------\n");
    printf("++++++++++++++++++++++++\n");
    printf("------------------------\n");
    printf("++++++++++++++++++++++++\n");
    printf("------------------------\n");
    printf("++++++++++++++++++++++++\n");
    printf("------------------------\n");
    printf("-+E1B22E1B22E1B22E1B22+-\n");
    printf("請輸入密碼：\n");

    int password = 2024;
    int inputPassword;
    int attempt = 0;

    // 驗證密碼
    while (attempt < 3) {
        scanf("%d", &inputPassword);
        clearBuffer(); // 清除緩衝區
        if (inputPassword == password) {
            printf("密碼正確，歡迎使用！\n");
            displayMainMenu();
            break;
        } else {
            attempt++;
            printf("密碼錯誤，請重新輸入：\n");
        }
    }

    if (attempt == 3) {
        printf("已連續輸入錯誤三次，請稍後再試！\n");
        exit(0);
    }

    return 0;
}

void displayMainMenu() {
    char option;
    printf("\n------------[Grade System]----------\n");
    printf("| a. Enter student grades          |\n");
    printf("| b. Display student grades        |\n");
    printf("| c. Search for student grades     |\n");
    printf("| d. Grade ranking                 |\n");
    printf("| e. Exit system                   |\n");
    printf("------------------------------------\n");

    printf("請選擇功能：\n");
    scanf(" %c", &option);
    clearBuffer(); // 清除緩衝區

    switch(option) {
        case 'a':
            enterGrades();
            break;
        case 'b':
            displayGrades();
            break;
        case 'c':
            searchGrades();
            break;
        case 'd':
            gradeRanking();
            break;
        case 'e':
            exitSystem();
            break;
        default:
            printf("輸入無效，請重新選擇功能！\n");
            displayMainMenu();
    }
}

void enterGrades() {
    int n;
    printf("請輸入學生數量 n (5~10)：\n");
    scanf("%d", &n);
    clearBuffer(); // 清除緩衝區

    if (n < 5 || n > 10) {
        printf("輸入無效，請輸入 5 到 10 之間的數字！\n");
        enterGrades();
        return;
    }

    int i;
    for (i = 0; i < n; i++) {
        printf("請輸入第 %d 位學生的姓名：\n", i + 1);
        scanf("%s", students[numStudents].name);
        clearBuffer(); // 清除緩衝區
        printf("請輸入學號：\n");
        scanf("%d", &students[numStudents].studentID);
        clearBuffer(); // 清除緩衝區
        printf("請輸入數學成績：\n");
        scanf("%f", &students[numStudents].mathGrade);
        clearBuffer(); // 清除緩衝區
        printf("請輸入物理成績：\n");
        scanf("%f", &students[numStudents].physicsGrade);
        clearBuffer(); // 清除緩衝區
        printf("請輸入英文成績：\n");
        scanf("%f", &students[numStudents].englishGrade);
        clearBuffer(); // 清除緩衝區
        students[numStudents].averageGrade = (students[numStudents].mathGrade + students[numStudents].physicsGrade + students[numStudents].englishGrade) / 3.0;
        numStudents++;
    }

    printf("資料輸入完畢！\n");
    displayMainMenu();
}

void displayGrades() {
    printf("\n學生姓名\t學號\t數學\t物理\t英文\t平均成績\n");
    int i;
    for (i = 0; i < numStudents; i++) {
        printf("%s\t\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", students[i].name, students[i].studentID, students[i].mathGrade, students[i].physicsGrade, students[i].englishGrade, students[i].averageGrade);
    }
    printf("\n按任意鍵返回主選單...\n");
    getchar();
    getchar(); // 暫停畫面
    displayMainMenu();
}

void searchGrades() {
    char searchName[50];
    printf("請輸入要搜尋的姓名：\n");
    scanf("%s", searchName);
    clearBuffer(); // 清除緩衝區

    int found = 0;
    int i;
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("\n姓名\t學號\t數學\t物理\t英文\t平均成績\n");
            printf("%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", students[i].name, students[i].studentID, students[i].mathGrade, students[i].physicsGrade, students[i].englishGrade, students[i].averageGrade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("資料不存在！\n");
    }

    printf("\n按任意鍵返回主選單...\n");
    getchar();
    getchar(); // 暫停畫面
    displayMainMenu();
}

void gradeRanking() {
    // 清除螢幕
    system("clear");

    // 排序學生資料依平均成績
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (students[i].averageGrade < students[j].averageGrade) {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    // 顯示排名
    printf("\n學生姓名\t學號\t平均成績\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s\t\t%d\t%.1f\n", students[i].name, students[i].studentID, students[i].averageGrade);
    }

    printf("\n按任意鍵返回主選單...\n");
    getchar();
    getchar(); // 暫停畫面

    // 清除螢幕
    system("clear");

    displayMainMenu();
}

void exitSystem() {
    char confirm;
    printf("確定離開？ (y/n)\n");
    scanf(" %c", &confirm);
    clearBuffer(); // 清除緩衝區

    if (confirm == 'y') {
        printf("程式結束！\n");
        exit(0);
    } else if (confirm == 'n') {
        displayMainMenu();
    } else {
        printf("輸入無效，請重新選擇功能！\n");
        exitSystem();
    }
}

// 清除緩衝區
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
//心得：本次的作業比起前面幾次的已經可以逐漸的上手了，這一次的作業比起前面的兩次，處理起來感覺起來更為游刃有餘。 

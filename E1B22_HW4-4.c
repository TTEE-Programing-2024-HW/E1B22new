#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �w�q�ǥ͵��c
struct Student {
    char name[50];
    int studentID;
    float mathGrade;
    float physicsGrade;
    float englishGrade;
    float averageGrade;
};

// �禡�쫬�ŧi
void displayMainMenu();
void enterGrades();
void displayGrades();
void searchGrades();
void gradeRanking();
void exitSystem();
void clearBuffer(); // �s�W�禡�ŧi

// �����ܼ�
struct Student students[10]; // �ǥͰ}�C�A�̦h 10 �Ӿǥ�
int numStudents = 0; // �ثe�ǥͼƶq

int main() {
    // �إ߭ӤH���檺�e��
    printf("�w��ϥ�²�����Z�t�ΡI\n");
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
    printf("�п�J�K�X�G\n");

    int password = 2024;
    int inputPassword;
    int attempt = 0;

    // ���ұK�X
    while (attempt < 3) {
        scanf("%d", &inputPassword);
        clearBuffer(); // �M���w�İ�
        if (inputPassword == password) {
            printf("�K�X���T�A�w��ϥΡI\n");
            displayMainMenu();
            break;
        } else {
            attempt++;
            printf("�K�X���~�A�Э��s��J�G\n");
        }
    }

    if (attempt == 3) {
        printf("�w�s���J���~�T���A�еy��A�աI\n");
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

    printf("�п�ܥ\��G\n");
    scanf(" %c", &option);
    clearBuffer(); // �M���w�İ�

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
            printf("��J�L�ġA�Э��s��ܥ\��I\n");
            displayMainMenu();
    }
}

void enterGrades() {
    int n;
    printf("�п�J�ǥͼƶq n (5~10)�G\n");
    scanf("%d", &n);
    clearBuffer(); // �M���w�İ�

    if (n < 5 || n > 10) {
        printf("��J�L�ġA�п�J 5 �� 10 �������Ʀr�I\n");
        enterGrades();
        return;
    }

    int i;
    for (i = 0; i < n; i++) {
        printf("�п�J�� %d ��ǥͪ��m�W�G\n", i + 1);
        scanf("%s", students[numStudents].name);
        clearBuffer(); // �M���w�İ�
        printf("�п�J�Ǹ��G\n");
        scanf("%d", &students[numStudents].studentID);
        clearBuffer(); // �M���w�İ�
        printf("�п�J�ƾǦ��Z�G\n");
        scanf("%f", &students[numStudents].mathGrade);
        clearBuffer(); // �M���w�İ�
        printf("�п�J���z���Z�G\n");
        scanf("%f", &students[numStudents].physicsGrade);
        clearBuffer(); // �M���w�İ�
        printf("�п�J�^�妨�Z�G\n");
        scanf("%f", &students[numStudents].englishGrade);
        clearBuffer(); // �M���w�İ�
        students[numStudents].averageGrade = (students[numStudents].mathGrade + students[numStudents].physicsGrade + students[numStudents].englishGrade) / 3.0;
        numStudents++;
    }

    printf("��ƿ�J�����I\n");
    displayMainMenu();
}

void displayGrades() {
    printf("\n�ǥͩm�W\t�Ǹ�\t�ƾ�\t���z\t�^��\t�������Z\n");
    int i;
    for (i = 0; i < numStudents; i++) {
        printf("%s\t\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", students[i].name, students[i].studentID, students[i].mathGrade, students[i].physicsGrade, students[i].englishGrade, students[i].averageGrade);
    }
    printf("\n�����N���^�D���...\n");
    getchar();
    getchar(); // �Ȱ��e��
    displayMainMenu();
}

void searchGrades() {
    char searchName[50];
    printf("�п�J�n�j�M���m�W�G\n");
    scanf("%s", searchName);
    clearBuffer(); // �M���w�İ�

    int found = 0;
    int i;
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("\n�m�W\t�Ǹ�\t�ƾ�\t���z\t�^��\t�������Z\n");
            printf("%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", students[i].name, students[i].studentID, students[i].mathGrade, students[i].physicsGrade, students[i].englishGrade, students[i].averageGrade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("��Ƥ��s�b�I\n");
    }

    printf("\n�����N���^�D���...\n");
    getchar();
    getchar(); // �Ȱ��e��
    displayMainMenu();
}

void gradeRanking() {
    // �M���ù�
    system("clear");

    // �ƧǾǥ͸�ƨ̥������Z
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (students[i].averageGrade < students[j].averageGrade) {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    // ��ܱƦW
    printf("\n�ǥͩm�W\t�Ǹ�\t�������Z\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s\t\t%d\t%.1f\n", students[i].name, students[i].studentID, students[i].averageGrade);
    }

    printf("\n�����N���^�D���...\n");
    getchar();
    getchar(); // �Ȱ��e��

    // �M���ù�
    system("clear");

    displayMainMenu();
}

void exitSystem() {
    char confirm;
    printf("�T�w���}�H (y/n)\n");
    scanf(" %c", &confirm);
    clearBuffer(); // �M���w�İ�

    if (confirm == 'y') {
        printf("�{�������I\n");
        exit(0);
    } else if (confirm == 'n') {
        displayMainMenu();
    } else {
        printf("��J�L�ġA�Э��s��ܥ\��I\n");
        exitSystem();
    }
}

// �M���w�İ�
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
//�߱o�G�������@�~��_�e���X�����w�g�i�H�v�����W��F�A�o�@�����@�~��_�e�����⦸�A�B�z�_�ӷPı�_�ӧ󬰴�b���l�C 

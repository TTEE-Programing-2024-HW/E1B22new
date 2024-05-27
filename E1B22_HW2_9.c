#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <conio.h> // Windows�U�ϥ�
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
            printf("�K�X���~�C�Ѿl���ơG%d\n", 3 - attempts);
        }
    }

    if (attempts == 3) {
        printf("�K�X���~���ƹL�h�C�{�������C\n");
        return 0;
    }

    return 0;
}

// 1. ����w��e�������ұK�X
void showWelcomeScreen() {
    printf("**********************************************\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("*                   �w��ϥ�                 *\n");
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
    printf("          E1B22             �п�J�|��ƱK�X�G\n");
}

int verifyPassword() {
    int input_password;
    printf("��J�K�X�G");
    scanf("%d", &input_password);
    return input_password == PASSWORD;
}

// 2. ��ܥD���
void showMainMenu() {
    char choice;

    while (1) {
        system(CLEAR); // �ϥ� system(CLEAR)
        printf("+---------------------------+\n");
        printf("|  a. �e�X�����T����        |\n");
        printf("|  b. ��ܭ��k��            |\n");
        printf("|  c. ����                  |\n");
        printf("+---------------------------+\n");
        printf("�п�ܡG");
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
                printf("�L�Ŀ�ܡC�Э��s��ܡC\n");
        }
    }
}

// 3. �e�X�����T����
void drawRightTriangle() {
    char ch;
    int i, j;
    system(CLEAR); // �ϥ� system(CLEAR)
    printf("�п�J�@��'a'��'n'���r���G");
    while (1) {
        scanf(" %c", &ch);
        if (ch >= 'a' && ch <= 'n') {
            break;
        } else {
            printf("��J�L�ġC�п�J'a'��'n'���r���G");
        }
    }

    int height = ch - 'a' + 1;
    for (i = 1; i <= height; i++) {
        for (j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("�����N���^�D���...\n");
    getch(); // ���ݨϥΪ̫����N��
}

// 4. ��ܭ��k��
void displayMultiplicationTable() {
    int n;
    int i, j;
    system(CLEAR); // �ϥ� system(CLEAR)
    printf("�п�J�@��1��9����ơG");
    while (1) {
        scanf("%d", &n);
        if (n >= 1 && n <= 9) {
            break;
        } else {
            printf("��J�L�ġC�п�J1��9����ơG");
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d*%d=%2d ", i, j, i * j);
        }
        printf("\n");
    }

    printf("�����N���^�D���...\n");
    getch(); // ���ݨϥΪ̫����N��
}

// 5. �h�X�t��
void exitProgram() {
    char confirm;
    printf("Continue? (y/n)�G");
    while (1) {
        scanf(" %c", &confirm);
        if (confirm == 'n' || confirm == 'N') {
            showMainMenu();
            break;
        } else if (confirm == 'y' || confirm == 'Y') {
            printf("�t�ε����C�A���I\n");
            return 0;
        } else {
            printf("�L�Ŀ�J�C�п�J 'y' �� 'n'�G");
        }
    }
}


//�������@�~�����a�褣�O�D�إ����A�ӬOú�檺�覡�F�p�G��^tronclassú��ڭ����ӫܮe���N�ள����ƤF�C 

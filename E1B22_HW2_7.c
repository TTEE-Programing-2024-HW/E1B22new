#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // �Ω�getch()���

// �D�{���J�f
int main() {
    // �B�J�@�G�]�m�K�X���ҥ\��
    int password = 2024; // �w�]�K�X
    int input_password; // �Τ��J���K�X
    int attempts = 0; // ���զ���

    // ��ܭӤH���檺�e��
    for (int i = 0; i < 20; i++) {
        printf("�o�O�� %d ��ӤH���檺�e��\n", i+1);
    }
    printf("�K�X�Ȭ�: %d\n", password); // ��ܱK�X�ȥH�K�ˬd

    // �K�X���Ҵ`��
    while (attempts < 3) {
        printf("�п�J4��ƱK�X�G");
        scanf("%d", &input_password);

        if (input_password == password) {
            break; // �K�X���T�A���X�`��
        } else {
            attempts++;
            printf("�K�X���~�A�Э��աA�٦� %d �����վ��|�C\n", 3 - attempts);
            if (attempts == 3) {
                printf("�z�w�s����~�T���A�еy��A�աC\a\n");
                return 1; // �����{��
            }
        }
    }

    // �B�J�G�G��ܥD���
    char choice;
    do {
        system("cls"); // �M�ſù�
        printf("+------------------------------------------+\n");
        printf("|                                          |\n");
        printf("|                                          |\n");
        printf("|             a.�e�X�����T����             |\n");
        printf("|                                          |\n");
        printf("|                                          |\n");
        printf("+------------------------------------------+\n");
        printf("|                                          |\n");
        printf("|                                          |\n");
        printf("|               b.��ܭ��k��               |\n");
        printf("|                                          |\n");
        printf("|                                          |\n");
        printf("+------------------------------------------+\n");
        printf("|                                          |\n");
        printf("|                                          |\n");
        printf("|                   c.����                 |\n");
        printf("|                                          |\n");
        printf("|                                          |\n");
        printf("+------------------------------------------+\n");
        printf("|                                          |\n");
        printf("| E1B22E1B22E1B22E1B22E1B22E1B22E1B22E1B22 |\n");
        printf("|                                          |\n");
        printf("+------------------------------------------+\n");

        // Ū���Τ���
        printf("�п�ܾާ@�G");
        scanf(" %c", &choice);

        // �B�J�T�G�B�z�����T���Υ\��
        if (choice == 'a' || choice == 'A') {
            system("cls"); // �M�ſù�
            printf("�п�J�@�Ӧr��(a��n)�G");
            char char_input;
            scanf(" %c", &char_input);

            // �ˬd��J�O�_�b�X�k�d��
            if (char_input < 'a' || char_input > 'n') {
                printf("�п�Ja~n�������r���C\n");
            } else {
                // �L�X�����T����
                for (char c = 'a'; c <= char_input; c++) {
                    for (char d = 'a'; d <= c; d++) {
                        printf("%c", d);
                    }
                    printf("\n");
                }
                printf("�Ы����N���~��...");
                getch(); // ���ݥ��N���J
            }
        }
        // �B�J�|�G�B�z���k��\��
        else if (choice == 'b' || choice == 'B') {
            system("cls"); // �M�ſù�
            int n;
            printf("�п�J�@��1~9����ơG");
            scanf("%d", &n);

            // �ˬd��J�O�_�b�X�k�d��
            if (n < 1 || n > 9) {
                printf("�п�J1~9��������ơC\n");
            } else {
                // �L�X���k��
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        printf("%3d ", i * j);
                    }
                    printf("\n");
                }
                printf("�Ы����N���~��...");
                getch(); // ���ݥ��N���J
            }
        }
        // �B�J���G�B�z�~��ﶵ
        else if (choice == 'c' || choice == 'C') {
            char continue_choice;
            printf("Continue�H(y/n): ");
            scanf(" %c", &continue_choice);
            if (continue_choice == 'y' || continue_choice == 'Y') {
                continue; // �^�D���
            } else if (continue_choice == 'n' || continue_choice == 'N') {
                break; // �����{��
            } else {
                printf("�п�Jy��n�C\n");
            }
        }
        // �B�z�L�Ŀﶵ
        else {
            printf("�п�J���Ŀﶵ�C\n");
        }
    } while (1); // �L���`������Τ��ܰh�X

    return 0;
}

//�������@�~�����a�褣�O�D�إ����A�ӬOú�檺�覡�F�p�G��^tronclassú��ڭ����ӫܮe���N�ள����ƤF�C 

#include <stdio.h>
#include <stdlib.h> // �Ω�system()���

int main() {
    int password = 2024;
    int input_pwd;
    int attempts = 0;

    // �B�J1: ��J�K�X
    while (1) {
        printf("�п�J4��ƱK�X: ");
        scanf("%d", &input_pwd);
        attempts++;

        if (input_pwd == password) {
            printf("�K�X���T�I\n");
            break;
        } else if (attempts >= 3) {
            printf("�z�w�s���J���~�T���A�{�������C\n");
            return 0;
        } else {
            printf("�K�X���~�A�Э��s��J�C\n");
        }
    }

    char choice;

    // �B�J2: �D���
    while (1) {
        system("cls"); // �M���ù�
        printf("+-----------------------+\n");
        printf("|                       |\n");
        printf("|       �ڬOE1B22       |\n");
        printf("|                       |\n");
        printf("|       I`m E1B22       |\n");
        printf("|                       |\n");
        printf("|    I am a slacker     |\n");
        printf("|                       |\n");
        printf("|      �ڬO�@���i��     |\n");
        printf("|                       |\n");
        printf("+-----------------------+\n");
        printf("+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("|                       |\n");
        printf("+-----------------------+\n");
        printf("|                       |\n");
        printf("|  a. �e�X�����T����    |\n");
        printf("|  b. ��ܭ��k��        |\n");
        printf("|  c. ����              |\n");
        printf("|                       |\n");
        printf("+-----------------------+\n");
        printf("|                       |\n");
        printf("+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("|                       |\n");
        printf("+-----------------------+\n");
        //�ӤH������ܫ� 

        printf("�п�ܾާ@: ");
        choice = getchar();
        getchar(); // �M���w�İϤ��������

        switch (choice) {
            case 'a':
            case 'A':
                // �B�J3: �e�X�����T����
                system("cls");
                char triangle_choice;
                printf("�п�J'a'��'n'�������r��: ");
                triangle_choice = getchar();
                getchar(); // �M���w�İϤ��������
                if (triangle_choice >= 'a' && triangle_choice <= 'n') {
                    // �ھڿ�J�r����ܪ����T����
                    printf("�z��J���r���O: %c\n", triangle_choice);
                    int height = triangle_choice - 'a' + 1;
                    for (int i = 1; i <= height; ++i) {
                        for (int j = 1; j <= i; ++j) {
                            printf("*");
                        }
                        printf("\n");
                    }
                    printf("�����N���^�D���...");
                    getchar(); // ���ݥΤ���U���N��
                } else {
                    printf("�п�J'a'��'n'�������r���C\n");
                    printf("�����N���^�D���...");
                    getchar(); // ���ݥΤ���U���N��
                }
                break;
            case 'b':
            case 'B':
                // �B�J4: ��ܭ��k��
                system("cls");
                int n;
                printf("�п�J1��9�����n: ");
                scanf("%d", &n);
                getchar(); // �M���w�İϤ��������
                if (n >= 1 && n <= 9) {
                    // ��ܭ��k��
                    printf("���k��p�U:\n");
                    for (int i = 1; i <= n; ++i) {
                        for (int j = 1; j <= n; ++j) {
                            printf("%d\t", i * j);
                        }
                        printf("\n");
                    }
                    printf("�����N���^�D���...");
                    getchar(); // ���ݥΤ���U���N��
                } else {
                    printf("�п�J1��9�����n�C\n");
                    printf("�����N���^�D���...");
                    getchar(); // ���ݥΤ���U���N��
                }
                break;
            case 'c':
            case 'C':
                // �B�J5: �������~��
                printf("\nContinue? (y/n): ");
                choice = getchar();
                getchar(); // �M���w�İϤ��������
                if (choice == 'y' || choice == 'Y') {
                    break; // �^��D���
                } else if (choice == 'n' || choice == 'N') {
                    printf("\n�{�������C\n");
                    return 0; // �����{��
                } else {
                    printf("\n�п�J'y'��'n'�C\n");
                    printf("�����N���^�D���...");
                    getchar(); // ���ݥΤ���U���N��
                }
                break;
            default:
                printf("\n�п�J���Ī��ﶵ�C\n");
                printf("�����N���^�D���...");
                getchar(); // ���ݥΤ���U���N��
                break;
        }
    }

    return 0;
}

#include <stdio.h>
#include <conio.h> // �Ω�getch()���

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

        printf("�п�ܾާ@: ");
        choice = getch();

        switch (choice) {
            case 'a':
            case 'A':
                // �B�J3: �e�X�����T����
                system("cls");
                char triangle_choice;
                printf("�п�J'a'��'n'�������r��: ");
                triangle_choice = getch();
                if (triangle_choice >= 'a' && triangle_choice <= 'n') {
                    // �ھڿ�J�r����ܪ����T���ΡA�o�̻ݭn�ۦ��{
                    printf("�z��J���r���O: %c\n", triangle_choice);
                    printf("�o�̮ھڿ�J���r����ܬ����������T����\n");
                    getch(); // ���ݥΤ���U���N��
                } else {
                    printf("�п�J'a'��'n'�������r���C\n");
                    getch(); // ���ݥΤ���U���N��
                }
                break;
            case 'b':
            case 'B':
                // �B�J4: ��ܭ��k��
                system("cls");
                int n;
                printf("�п�J1��9�����n: ");
                scanf("%d", &n);
                if (n >= 1 && n <= 9) {
                    // ��ܭ��k��A�o�̻ݭn�ۦ��{
                    printf("���k��p�U:\n");
                    for (int i = 1; i <= n; ++i) {
                        for (int j = 1; j <= n; ++j) {
                            printf("%d\t", i * j);
                        }
                        printf("\n");
                    }
                    getch(); // ���ݥΤ���U���N��
                } else {
                    printf("�п�J1��9�����n�C\n");
                    getch(); // ���ݥΤ���U���N��
                }
                break;
            case 'c':
            case 'C':
                // �B�J5: �������~��
                printf("\nContinue? (y/n): ");
                choice = getch();
                if (choice == 'y' || choice == 'Y') {
                    break; // �^��D���
                } else if (choice == 'n' || choice == 'N') {
                    printf("\n�{�������C\n");
                    return 0; // �����{��
                } else {
                    printf("\n�п�J'y'��'n'�C\n");
                    getch(); // ���ݥΤ���U���N��
                }
                break;
            default:
                printf("\n�п�J���Ī��ﶵ�C\n");
                getch(); // ���ݥΤ���U���N��
                break;
        }
    }

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<conio.h> //這是Windows環境下的標頭文件，用於控制台輸入輸出//

int main(){
	//步驟一.設置密碼驗證功能
	int password=2023;
	int input_password;
	int attempts=0;
	
	while(attempts<3){
		system("cls");//清空螢幕 
		printf("請輸入密碼：");
		scanf("%d",&input_password);
		
		if(input_password==password){
			break;//正確的密碼，跳出驗證循環 
		}else{
			attempts++;
			printf("密碼錯誤，請重試，還有%d次嘗試機會。\n",3-attempts);//密碼錯誤，跳出信息請使用者重新嘗試，並累加一次錯誤次數 
			if(attempts==3){
				printf("您已連續錯誤三次，請稍後再試。\a\n");//密碼連續錯誤達到三次，跳出警告信息 
				return 1;//結束程式 
			}
		}
	}
	//步驟二：顯示主選單
	char choice;
	do{
		system("cls");//清空螢幕
		printf("+------------------------------------------+\n");
		printf("|                                          |\n");
		printf("|                                          |\n");
		printf("|             a.畫出直角三角形             |\n");
		printf("|                                          |\n");
		printf("|                                          |\n");
		printf("+------------------------------------------+\n");
		printf("|                                          |\n");
		printf("|                                          |\n");
		printf("|               b.顯示乘法表               |\n");
		printf("|                                          |\n");
		printf("|                                          |\n");
		printf("+------------------------------------------+\n");
		printf("|                                          |\n");
		printf("|                                          |\n");
		printf("|                   c.結束                 |\n");
		printf("|                                          |\n");
		printf("|                                          |\n");
		printf("+------------------------------------------+\n");
		printf("|                                          |\n");
		printf("| E1B22E1B22E1B22E1B22E1B22E1B22E1B22E1B22 |\n");
		printf("|                                          |\n");
		printf("+------------------------------------------+\n");//個人風格主選單 

        // 讀取用戶選擇
        printf("請選擇操作：");
        scanf(" %c", &choice);
        
        // 步驟三.處理直角三角形功能
        if (choice == 'a' || choice == 'A'){
            system("cls");//清空螢幕
            printf("請輸入一個字元(a到n)：");
            char char_input;
            scanf(" %c", &char_input);
            
            //檢查輸入是否在合法範圍內
            if(char_input<'a'||char_input>'n'){
                printf("請輸入a~n之間的字元。\n");
            }else{
                //印出直角三角形
                for(char c='a';c<=char_input;c++){
                    for(char d='a';d<=c;d++){
                        printf("%c",d);
                    }
                    printf("\n");
                }
                printf("請按任意鍵繼續...");
                getch();//等待任意鍵輸入 
            }
        }
        //步驟四.處理乘法表功能
        else if(choice=='b'||choice=='B'){
            system("cls");//清空螢幕
            int n;
            printf("請輸入一個1~9的整數：");
            scanf("%d",&n);
            //檢查輸入是否在合法範圍內
            if(n<1||n>9){
                printf("請輸入1~9之間的整數。\n");
            }else{
                //印出乘法表
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        printf("%3d",i*j);
                    }
                    printf("\n");
                }
                printf("請按任意鍵繼續...");
                getch();//等待任意鍵輸入 
            }
        }
        //步驟五.處理繼續選項
        else if(choice=='c'||choice=='C'){
            char continue_choice;
            printf("Continue？(y/n)");
            scanf(" %c",&continue_choice);
            if(continue_choice=='y'||continue_choice=='Y'){
                continue;//回主選單 
            }else if(continue_choice=='n'||continue_choice=='N'){
                break;//結束程式 
            }else{
                printf("請輸入y或n。\n");
            }
        }
        //處理無效選項
        else{
            printf("請輸入有效選項。\n");
        }
	} 
	while(1);//無限循環直到用戶選擇退出
	return 0; 
}
//本次的作業難的地方不是題目本身，而是繳交的方式；如果改回tronclass繳交我們應該很容易就能拿到分數了。 

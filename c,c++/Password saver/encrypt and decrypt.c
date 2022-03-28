#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

int i;

COORD coord = 
{
  0,
  0
};
void gotoxy(int x, int y) {
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



int home();
int welcome();
int ext();
void ENCRYPT_password();
int please_wait();
void DECRYPT_password();






void SetColor(int ForgC) 
{
  WORD wColor;
  
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

 
  if (GetConsoleScreenBufferInfo(hStdOut, & csbi)) {
    
    wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
    SetConsoleTextAttribute(hStdOut, wColor);
  }
//  return 0;
}





int welcome() 
{
  SetColor(14);
  printf("\n\n\n\t\t                               WELCOME TO                           \n");
  printf("\t                                      PASSWORD SAVER                         \n\n\n");
  return 0;
}





int main() 
{
  home();
  return 0;
}


int home() 
{
  char hswitch;
  system("cls");
  welcome();
  SetColor(45);
  printf("\n\n");
  
  printf("\t\t\t\t\t ==> 1. GENERATE password \n");
  printf("\t\t\t\t\t ==> 2. ENCRYPT password  \n");
  printf("\t\t\t\t\t ==> 3. DECRYPT password \n");
  printf("\t\t\t\t\t ==> 4. EXIT Software\n\n");
  SetColor(11);
  printf("\t\t\t\t\t Select an Option:");
  SetColor(12);
  gotoxy(70, 25);
  SetColor(45);
  gotoxy(59, 14);
  hswitch = getche();
  switch (hswitch) {
  case '1':
//    GENERATE_password();
    break;
  case '2':
  	please_wait();
    ENCRYPT_password();
    break;
  case '3':
    please_wait();
    DECRYPT_password();
    break;
  case '4':
    ext();
    break;
  default:
    printf("\n  INVALID KEYWORD. TRY AGAIN\n");
    Sleep(1000);
    home();
  }
  return 0;

}



void ENCRYPT_password()
{
	system("cls");
	int i, x;
    char str[100];
  
    printf("\n\n\n");
    SetColor(14);
    printf("\n\n\t\t\t\t\t    ===Encrypt Portal===\n\n\n\n\n");
     SetColor(45);

   printf("\t\t\t\t\t Please enter a password:");
   SetColor(15);
   gets(str);
   
   for(i = 0; (i < 100 && str[i] != '\0'); i++)
   {
   	  str[i] = str[i] + 3;
   }
   
   printf("\n");
        
    SetColor(2);

    printf("\t\t\t\t\t Encrypted password is: %s\n", str);
    
    SetColor(45);
    

}




void DECRYPT_password()
{
	system("cls");
	int i, x;
    char str[100];
  
    printf("\n\n\n");
    SetColor(14);
    printf("\n\n\t\t\t\t\t    ===Decrypt Portal===\n\n\n\n\n");
     SetColor(45);

   printf("\t\t\t\t\t Please enter a password:");
   SetColor(15);
   gets(str);
   
   for(i = 0; (i < 100 && str[i] != '\0'); i++)
   {
   	  str[i] = str[i] - 3;
   }
   
   printf("\n");
        
    SetColor(2);

    printf("\t\t\t\t\t Decrypted password is: %s\n", str);
    
    SetColor(45);
   
   

}






int please_wait() 
{
  for (i = 0; i < 2; i++) {
    SetColor(14);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease Wait.");
    Sleep(300);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease Wait..");
    Sleep(300);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease Wait...");
    Sleep(300);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease Wait....");
    Sleep(300);
    system("cls");
    SetColor(45);
  }
}






int ext() 
{
  system("cls");
  
  SetColor(14);
  printf("\n\n\t\t\t\t\t  ===EXIT PAGE=== \n\n\n\n\n");
  SetColor(15);
  char c_exit;
  fflush(stdin);
  printf("\t\t\t\t\t Press 1 Cancel Exit \n");
  printf("\t\t\t\t\t Press 0 For Exit Software\n");
  SetColor(45);
  c_exit = getche();
  switch (c_exit) {
  case '1':
    home();
    break;
  case '0':
  	
  	printf("\n\n");
  	SetColor(7);
    printf("\t\t\t\t\t THANKS FOR USING PASSWORD SAVER \n");
    SetColor(45);
    printf("\t\t\t\t\t Press Any Key To EXIT......");
    _getch();
    exit(EXIT_SUCCESS);
    break;
  default:
    printf("INVALID KEYWORD\n");
    Sleep(1000);
    ext();
  }
  return 0;
}




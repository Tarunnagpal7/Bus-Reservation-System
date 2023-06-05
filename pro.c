#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
//global variables
char bus[5][100] = {"vadodara-ahmendabad express","vadodara-surat express","Gujarat Tour","Saurashtra Express","vad-aanad terminus"};//array of bus names
int bsno;
char name[32][100]={'\0'};
char number[32][3]={'\0'};
int num[32]={0};
char str1[80]="32";
void login();
void list();
void book();
void name_number_list(int booking,char namstr[10]);
void status_1(int bsno);
void read_name(int bsno);
int read_number(int bsno);
void cancelation();
void status();
int main(){
    int choice;
    login();
   do{
    aa:
    system("cls");
    printf("---------------------------------WELCOME!!!----------------------------------\n");
    printf("                           BUS RESEREVATION SYSTEM                           \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                             [1]--> BUS LISTS                                \n");
    printf("                             [2]--> BOOK TICKETS                             \n");
    printf("                             [3]--> CANCELATION TICKETS                      \n");
    printf("                             [4]--> BUS BOARD INFO                           \n");
    printf("                             [5]--> EXIT                                     \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("Enter your choice:");
    scanf("%d",&choice);

    if(choice>5||choice<=0){
        printf("\n\t\t\t\tWRONG CHOICE");
        getch();
         goto aa;
    }
    switch (choice)
    {
    case 1 : list();
            break;
    case 2 : book();
            break;
    case 3 : cancelation();
            break;  
    case 4: status();
             break;
    }
    getch();
   }
    while(choice!=5);
    system("cls");
    printf("THANKS FOR USING THIS SYSTEM!!\n");
    printf("HAVE A GODD DAY!!\n");
    printf("CREATED BY TARUN NAGPAL AND RAJNISH KURALIA");
    getch();
    exit(0);
    return 0;
}

//prints the list of bus
void list(){
    system("cls");
    int i;
    printf("-------------------------------------------------------------------------------\n");
    printf("                                   BUS LISTS                                   \n");
    printf("------------------------------------------------------------------------------- \n");
    for(i=0;i<5;i++){
    printf("                           [%d]--> %s                          \n\n",i+1,bus[i]);
    }
    printf("------------------------------------------------------------------------------- \n");
}

//this function used to book the tickets by user
void book(){
  system("cls");
  list();
  printf("\nEnter the number of bus :--  ");
  scanf("%d",&bsno);
  system("cls");  
  printf("--------------------------------------- BUS RESERVATION SYSTEM ---------------------------------------\n");
  printf("\t\tYour Bus Number is %d ###### %s",bsno,bus[bsno-1]);
  status_1(bsno);
  FILE *f1,*fopen();
  char numstr[100];
  int seat1,booking=0;
  //read the seats 
  if(bsno == 1)
{
 f1 = fopen("tr1.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(bsno == 2)
{
 f1 = fopen("tr2.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(bsno == 3)
{
 f1 = fopen("tr3.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(bsno == 4)
{
 f1 = fopen("tr4.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(bsno == 5)
{
 f1 = fopen("tr5.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
seat1=atoi(str1);//covert the string into number
if(seat1 <= 0)
{
 printf("There is no blank seat in this bus ");
}else
{
printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n",seat1);
printf("\n\t\t\t\tNumber of Tickets:----->");
scanf("%d",&booking);
printf("\n");

seat1=seat1-booking;
itoa(bsno,numstr,10);//convert the int to string
name_number_list(booking,numstr);//read the seat number and name from the user
printf("\n\t\t\t\tThe Total booking amount is %d",200*booking);
itoa(seat1, str1, 10);
//for reading the seats from the user.
if(bsno == 1)
{
 f1 = fopen("tr1.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
else if(bsno == 2)
{
 f1 = fopen("tr2.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(bsno == 3)
{
 f1 = fopen("tr3.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(bsno == 4)
{
 f1 = fopen("tr4.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(bsno == 5)
{
 f1 = fopen("tr5.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
}
}

//used to take seat number and name of a user
void name_number_list(int booking , char namstr[100]){
  char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
  int number;
  FILE *a,*b;
  int i;
  strcat(namstr,".txt");
  strcat(tempstr1,namstr);
  strcat(tempstr2,namstr);
  b=fopen(tempstr1,"a");
  a=fopen(tempstr2,"a");
  for(i=0;i<booking;i++){
    printf("\n------------------------------------------------------------------------------- \n");
    printf("\t\t\t\t Enter the details for ticket no. %d",i+1);
    printf("\n------------------------------------------------------------------------------- \n");
    printf("\t\t\tEnter the seat number ::-->> ");
    scanf("%d",&number);
    printf("\t\t\tEnter the name of person::-->> ");
    scanf("%s",name[number-1]);
    printf("\n");
    itoa(number,tempstr,10);
    
    fprintf(b,"%s ",name[number-1]);
    fprintf(a,"%s ",tempstr);
  }
  fclose(a);
  fclose(b);
}

//used to read number of booked seats and read it
int read_number(int bsno)//for putting the numeric value in the array
{
char tempstr2[12]="number";
FILE *a;
char numstr[100];
int i=0,j=0,k;
itoa(bsno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");//for open the file to write the name in the file
   while(!feof(a))
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}

//read the name of booked user.
void read_name(int bsno)//for putting the numeric value in the array
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(bsno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");//for open the file to write the name in the file
   while(!feof(b))
   {
      name[i][j] = fgetc(b);
 
      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}

//show the list of seats 
void status_1(int bsno){
  system("cls");
  printf("--------------------------------------- BUS RESERVATION SYSTEM ---------------------------------------\n");
  printf("\t  Your Bus Number is %d ###### %s",bsno,bus[bsno-1]);
  printf("\n--------------------------------------------------------------------------------------------------- \n");
  int i,j,index=0;
  j=read_number(bsno);
  read_name(bsno);
  char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
  for(i=0;i<j;i++){
    strcpy(tempname[num[i]],name[i]);
  }
  for(i=0;i<8;i++){
    printf("\t\t\t\t");
    for(j=0;j<4;j++){
      printf("[%d]>>%s\t",index+1,tempname[index+1]);
      index++;
    }
    printf("\n");
  }
}

//status of bus seats
void status(){
  system("cls");
  int bsno,index=0;
 printf("--------------------------------------------------------------------------------------------------- \n");
  printf("\t\t\tENter the Number of train ::-->>");
  scanf("%d",&bsno);
  printf("\n--------------------------------------------------------------------------------------------------- \n");
  int i,j,k;
  j=read_number(bsno);
  read_name(bsno);
  printf("--------------------------------------------------------------------------------------------------- \n");
  printf("  \t\t\t\t BUS NO. : %d--> %s",bsno,bus[bsno-1]);
  printf("\n--------------------------------------------------------------------------------------------------- \n");
  char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
  for(i=0;i<j;i++){
    strcpy(tempname[num[i]],name[i]);
  }
  for(i=0;i<8;i++){
    printf("\t\t\t\t");
    for(j=0;j<4;j++){
       printf("[%d]>>%s\t",index+1,tempname[index+1]);
        index++;
    }
    printf("\n");
  }
}

//cancel the tickets and preserve the cancel ticket to bus.
 void cancelation(){
  system("cls");
  int seat_no,i,j;
 char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
 printf("Enter the bus number:---->");
 scanf("%d",&bsno);
 itoa(bsno,numstr,10);
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 strcat(tempstr2,numstr);
 read_number(bsno);
 read_name(bsno);
 status_1(bsno);
 printf("Enter the seat number:--->");
 scanf("%d",&seat_no);
 FILE *a,*b;
 a = fopen(tempstr1,"w+");
 b = fopen(tempstr2,"w+");
 for(i=0; i<32; i++){
     if(num[i] == seat_no){
      for(j=0; j<32; j++)
       {
          if(num[j] != seat_no && num[j] != 0){
                fprintf(b,"%d ",num[j]);
                fprintf(a,"%s",name[j]);
          }
          else if(num[j] == seat_no && num[j] != 0){
           strcpy(name[j],"Empty ");
          }
        }
     }
 }
fclose(a);
fclose(b);
printf("\n\n");
    printf("======================================================================================================\n");
 printf("\t\t\t\tYour 200 rupees has been Returned\t\t\t\n");
    printf("======================================================================================================\n");
  FILE *f1;
  int seatnumber=0;
  if(bsno==1){
    f1=fopen("tr1.txt","r");
    fgets(str1,80,f1);
    fclose(f1);
  }else if(bsno==2){
    f1=fopen("tr2.txt","r");
    fgets(str1,80,f1);
    fclose(f1);
  }if(bsno==3){
    f1=fopen("tr3.txt","r");
    fgets(str1,80,f1);
    fclose(f1);
  }if(bsno==4){
    f1=fopen("tr4.txt","r");
    fgets(str1,80,f1);
    fclose(f1);
  }if(bsno==5){
    f1=fopen("tr5.txt","r");
    fgets(str1,80,f1);
    fclose(f1);
  }
  seatnumber = atoi(str1);
  seatnumber = seatnumber+1;
  itoa(seatnumber,str1,10);
  if(bsno==1){
    f1=fopen("tr1.txt","w");
    fputs(str1,f1);
    fclose(f1);
  }if(bsno==2){
    f1=fopen("tr2.txt","w");
    fputs(str1,f1);
    fclose(f1);
  }if(bsno==3){
    f1=fopen("tr3.txt","w");
    fputs(str1,f1);
    fclose(f1);
  }if(bsno==4){
    f1=fopen("tr4.txt","w");
    fputs(str1,f1);
    fclose(f1);
  }if(bsno==5){
    f1=fopen("tr5.txt","w");
    fputs(str1,f1);
    fclose(f1);
  }
}

//login to proceed into system. 
void login(){
    int i=0,a=0;
    char name[100];
    char pass[20];
   do{
    system("cls");
    printf("--------------------Welcome to the BUS RESERVATION SYSTEM--------------------\n");
    printf("::::Login Form::::\n");
      printf("---Enter the Name and the Password---\n");
      printf("\t\t\t\tENTER USERNAME : ");
      scanf("%s",name);
      printf("\n");
      printf("\t\t\t\tENTER PASSWORD : ");
      while(i<7){
        pass[i]=getch();
        printf("*");
        i++;
      }
      pass[i]='\0';
      i=0;
      if(strcmp(name,"cproject")==0&&strcmp(pass,"pass123")==0){
      printf("\n\t\tWELcome to the System..!!Login is Successfull.\n ");
      printf("\t\tPRESS ANY KEY TO CONTINUE..");
      getch();
      break;
      }
    
    else{
    printf(" \n\n\t\t  Sorry!!Login Unsuccesfull\n");
    a++;
    getch();
    }
}
while(a<=2);
if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for many times!!!");
	    getch();
        exit(0);
		}
		system("cls");
}



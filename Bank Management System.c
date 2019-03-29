/*
     Project Computer Programming II CS_KMUTNB
     Bank Management System [BMS]
     Developed By Panurut Chinakul CS1RB
     58-040626-2006-9
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>    //console input output เป็นชุดฟงก์ชนในการจัดการหน้าจอ
#include <windows.h>  //เป็น libraly เอาไว้ทำ Graphical User Interface (GUI) บน Microsoft Windows
#include <time.h>     //เวลา



COORD coord = {0, 0}; //ตำแหน่ง  x y

//Global Variable
int i,j,c=0;
int main_exit;
char ch,pass[10],password[10];//="kmutnb";
      char ch_acc,pass_acc[10],password_acc[10];//="test";
void menu();

//โครงสร้างข้อมูล วันที่
//structure date
struct date{
    int month,day,year;

    };

//struct ข้อมูลบัญชี
struct {

    char name[60];          //ชื่อ
    int acc_no,age;         //เลขบัญชี , อายุ
    char address[60];       //ที่อยู่
    char id_num[15];        //เลขบัตรประจำตัวประชาชน
    double phone;           //เบอร์โทรศัพท์
    char acc_type[10];      //ประเภทบัญชี
    float amt;              //จำนวนเงินฝากเปิดบัญชี
    struct date dob;        //วันเกิด
    struct date deposit;    //ฝาก
    struct date withdraw;   //ถอน

    }add,upd,check,rem,transaction;

//ฟังก์ชัน ย้ายตำแหน่ง X Y
//Fucntion Position
void gotoxy (int x, int y)
{
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//ฟังก์ชัน นาฬิกา
//Function Time
int t(void) //for time
{
    time_t t;
    time(&t);
    printf("Date and time : %s\n",ctime(&t));

    return 0 ;
}

//ฟังก์ชัน คำนวณดอกเบี้ย
//function interest
float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}

//ฟังก์ชัน แปลงค่าเงิน
//Function Currency Converter
float cur_con()
{
    int choice,choice_s;
    char bhti[32];
    float bhti2;
    //ค่าเงิน โดยประมาณ ณ 30 พฤษภาคม 2559
    const float bhtg = 53.01;
    const float bhtu = 35.82;
    const float bhte = 40.47;
    const float bhtj = 3.324;
    const float bhtk = 3.40;
    const float gbp = 0.05301;
    const float usd = 0.03582;
    const float eur = 0.04047;
    const float jpy = 0.3324;
    const float krw = 0.0340;

    convert:
    printf("\n\n\t\t<<<<< Currency Converter >>>>>\n\n");
    printf("\n\t1.Baht <> Dollar\n\n\t2.Baht <> Pound\n\n\t3.Baht <> Euro\n\n\t4.Baht <> Yen\n\n\t5.Baht <> Won\n\n");
    printf("\tWhat currency do you want to Exchange: ");
    scanf("%d",&choice);
    if(choice==1)
    {
         system("cls");
         printf("\n\n\t\t<<< BAHT & DOLLAR >>>\n\n");
         printf("\n\t\t1.Baht >> Dollar\n\n\t\t2.Dollar >> Baht\n\n");
         printf("\n\n\t What exchange do you want: ");
         scanf("%d",&choice_s);
         if(choice_s==1)
           {
               printf("\n\n\tPlease enter the amount: ");
               scanf("%f",&bhti2);
               printf("\n\n\tFor %.2f  BHT = %.2f  USD.\n",bhti2,bhti2*usd);
               getch();
               //system("cls");
               //goto convert;
               add_invalid:
               printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
               scanf("%d",&main_exit);
               system("cls");
               if(main_exit==1)
                  menu_user();
          else if(main_exit==0)
                  close();
          else
              {
                  printf("\nInvalid!\a");
                  goto add_invalid;
              }
           }
    else if(choice_s==2)
           {
                printf("\n\n\tPlease enter the amount: ");
                scanf("%f",&bhti2);
                printf("\n\n\tFor %.2f  USD = %.2f  BHT\t.\n",bhti2,bhti2*bhtu);
                getch();
                //system("cls");
                //goto convert;
                add_invalid0:
                printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
                scanf("%d",&main_exit);
                system("cls");
              if(main_exit==1)
                 menu_user();
         else if(main_exit==0)
                 close();
         else
             {
                 printf("\nInvalid!\a");
                 goto add_invalid0;
             }
           }
    }
    else if(choice==2)
           {
                 system("cls");
                 printf("\n\n\t\t<<< BAHT & POUND >>>\n\n");
                 printf("\n\t\t1.Baht >> Pound\n\n\t\t2.Pound >> Baht\n\n");
                 printf("\n\n\t What exchange do you want: ");
                 scanf("%d",&choice_s);
              if(choice_s==1)
                {
                     printf("\n\n\tPlease enter the amount: ");
                     scanf("%f",&bhti2);
                     printf("\n\n\tFor %.2f  BHT = %.2f  GBP.\n",bhti2,bhti2*gbp);
                     getch();
                     //system("cls");
                     //goto convert;
                     add_invalid1:
                     printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
                     scanf("%d",&main_exit);
                     system("cls");
                   if(main_exit==1)
                      menu_user();
              else if(main_exit==0)
                      close();
              else
                  {
                      printf("\nInvalid!\a");
                      goto add_invalid1;
                  }
                }
          else if(choice_s==2)
                 {
                      printf("\n\n\tPlease enter the amount: ");
                      scanf("%f",&bhti2);
                      printf("\n\n\tFor %.2f  GBP = %.2f  BHT\t.\n",bhti2,bhti2*bhtg);
                      getch();
                      //system("cls");
                      //goto convert;
                      add_invalid2:
                      printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
                      scanf("%d",&main_exit);
                      system("cls");
                   if(main_exit==1)
                      menu_user();
              else if(main_exit==0)
                      close();
              else
                  {
                      printf("\nInvalid!\a");
                      goto add_invalid2;
                  }
                 }
            }
     else if(choice==3)
            {
                 system("cls");
                 printf("\n\n\t\t<<< BAHT & EURO >>>\n\n");
                 printf("\n\t\t1.Baht >> Euro\n\n\t\t2.Euro >> Baht\n\n");
                 printf("\n\n\t What exchange do you want: ");
                 scanf("%d",&choice_s);
              if(choice_s==1)
                {
                    printf("\n\n\tPlease enter the amount: ");
                    scanf("%f",&bhti2);
                    printf("\n\n\tFor %.2f  BHT = %.2f  EUR.\n",bhti2,bhti2*eur);
                    getch();
                    //system("cls");
                    //goto convert;
                    add_invalid3:
                    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
                    scanf("%d",&main_exit);
                    system("cls");
                 if(main_exit==1)
                    menu_user();
            else if(main_exit==0)
                    close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid3;
        }
            }
            else if(choice_s==2)
            {
                printf("\n\n\tPlease enter the amount: ");
                scanf("%f",&bhti2);
                printf("\n\n\tFor %.2f  EUR = %.2f  BHT\t.\n",bhti2,bhti2*bhte);
                getch();
                //system("cls");
                //goto convert;
                add_invalid4:
                printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
                scanf("%d",&main_exit);
                system("cls");
    if (main_exit==1)
        menu_user();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid4;
        }
            }
    }
    else if(choice==4)
    {
         system("cls");
         printf("\n\n\t\t<<< BAHT & YEN >>>\n\n");
         printf("\n\t\t1.Baht >> YEN\n\n\t\t2.YEN >> Baht\n\n");
         printf("\n\n\t What exchange do you want: ");
         scanf("%d",&choice_s);
         if (choice_s==1)
            {
         printf("\n\n\tPlease enter the amount: ");
         scanf("%f",&bhti2);
         printf("\n\n\tFor %.2f  BHT = %.2f  JPY.\n",bhti2,bhti2*jpy);
         getch();
         //system("cls");
         //goto convert;
         add_invalid5:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu_user();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid5;
        }
            }
            else if(choice_s==2)
            {
                printf("\n\n\tPlease enter the amount: ");
         scanf("%f",&bhti2);
         printf("\n\n\tFor %.2f  JPY = %.2f  BHT\t.\n",bhti2,bhti2*bhtj);
         getch();
         //system("cls");
         //goto convert;
         add_invalid6:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu_user();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid6;
        }
            }
    }
    else if(choice==5)
    {
         system("cls");
         printf("\n\n\t\t<<< BAHT & WON >>>\n\n");
         printf("\n\t\t1.Baht >> Won\n\n\t\t2.Won >> Baht\n\n");
         printf("\n\n\t What exchange do you want: ");
         scanf("%d",&choice_s);
         if (choice_s==1)
            {
         printf("\n\n\tPlease enter the amount: ");
         scanf("%f",&bhti2);
         printf("\n\n\tFor %.2f  BHT = %.2f  KRW.\n",bhti2,bhti2*krw);
         getch();
         //system("cls");
         //goto convert;
         add_invalid7:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu_user();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid7;
        }
            }
            else if(choice_s==2)
            {
                printf("\n\n\tPlease enter the amount: ");
         scanf("%f",&bhti2);
         printf("\n\n\tFor %.2f  KRW = %.2f  BHT\t.\n",bhti2,bhti2*bhtk);
         getch();
         //system("cls");
         //goto convert;

            }
            add_invalid8:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu_user();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid8;
        }

    }
    else
    {
         try_con:
         printf("\n\t\tInvalid!");
         printf("\n\n\tEnter 1 to try again and 0 to Menu:");
                               scanf("%d",&main_exit);

                            if (main_exit==1)
                               {

                                   system("cls");
                                   goto convert;

                               }

                       else if (main_exit==0)
                               {
                                   system("cls");
                                   menu_user();
                               }
                       else
                               {
                                   printf("\nInvalid!");
                                   fordelay(1000000000);//delay
                                   goto try_con;
                               }
    }

}

//ฟังก์ชัน Loading Status (Loader)
//function fordelay
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

//ฟังก์ชัน สร้างบัญชี
//Menu >>> New_account
void new_acc()
{
    int choice;
    FILE *ptr;//ไฟล์เก็บขอมูล

    ptr=fopen("record.txt","a+");
    account_no:
    system("cls");
    printf("\n\n\n\t\t\t <<< ADD RECORD  >>> ");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);//รับค่าเข้าเก็บใน struct ของ ข้อมูลบัญชี
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);//เลขบัญชี
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.id_num,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)//เช็คเลขบัญชีซ้ำ
            {
                printf("Account no. already in use!");
                fordelay(1000000000);
                goto account_no;
            }
    }
    add.acc_no=check.acc_no;
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the identification card number:");
    scanf("%s",add.id_num);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit: $");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t1.Saving\n\t2.Current\n\t3.Fixed1(for 1 year)\n\t4.Fixed2(for 2 years)\n\t5.Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\nAccount created successfully!");

    //กรณี invalid
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

//ฟังก์ชัน สร้างบัญชี สำหรับ user
//Menu >>> New_account
void new_acc_user()
{
    int choice;
    FILE *ptr;//ไฟล์เก็บขอมูล

    ptr=fopen("record.txt","a+");
    account_no:
    system("cls");
    printf("\n\n\n\t\t\t <<< ADD RECORD  >>> ");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);//รับค่าเข้าเก็บใน struct ของ ข้อมูลบัญชี
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);//เลขบัญชี
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.id_num,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)//เช็คเลขบัญชีซ้ำ
            {
                printf("Account no. already in use!");
                fordelay(1000000000);
                goto account_no;
            }
    }
    add.acc_no=check.acc_no;
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the identification card number:");
    scanf("%s",add.id_num);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit: $");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t1.Saving\n\t2.Current\n\t3.Fixed1(for 1 year)\n\t4.Fixed2(for 2 years)\n\t5.Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\nAccount created successfully!");

    //กรณี invalid
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu_user();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

//ฟังก์ชัน ดูรายชื่อ
//Menu >>> View_List
void view_list()
{
    FILE *view;
    view=fopen("record.txt","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\tADDRESS\t\tPHONE\t\tDEPOSIT\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.id_num,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t%10s\t\t%.0lf\t\t$%.2f",add.acc_no,add.name,add.address,add.phone,add.amt);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");

        if (main_exit==1)
            menu_user();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

//ฟังก์ชัน แก้ไขข้อมูล
//Menu >>> Edit
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");//เปิดไฟล์ที่มีอยู่แล้ว
    newrec=fopen("new.txt","w");//เขียนทับเพิ่มเติมเพื่อแก้ไข้ข้อมูลบัญชี

    printf("\n\nEnter the account no. of the customer whose info you want to change: ");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.id_num,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n3.Account Type\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {
                    printf("Enter the new address:");
                    scanf("%s",upd.address);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    system("cls");
                    printf("\n\nChanges saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                    scanf("%lf",&upd.phone);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    system("cls");
                    printf("\n\nChanges saved!");
                }
            else if(choice==3)
                {
                    printf("\nType of account:\n\t1.#Saving\n\t2.#Current\n\t3.#Fixed1(for 1 year)\n\t4.#Fixed2(for 2 years)\n\t5.#Fixed3(for 3 years)\n\n");
                    printf("Enter the new Type of account:");
                    scanf("%s",upd.acc_type);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,upd.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    system("cls");
                    printf("\n\nChanges saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt","record.txt");


    if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }
}

//ฟังก์ชัน แก้ไขข้อมูล สำหรับ user
//Menu >>> Edit
void edit_user(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");//เปิดไฟล์ที่มีอยู่แล้ว
    newrec=fopen("new.txt","w");//เขียนทับเพิ่มเติมเพื่อแก้ไข้ข้อมูลบัญชี

    printf("\n\nEnter the account no. of the customer whose info you want to change: ");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.id_num,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n3.Account Type\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {
                    printf("Enter the new address:");
                    scanf("%s",upd.address);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    system("cls");
                    printf("\n\nChanges saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                    scanf("%lf",&upd.phone);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    system("cls");
                    printf("\n\nChanges saved!");
                }
            else if(choice==3)
                {
                    printf("\nType of account:\n\t1.#Saving\n\t2.#Current\n\t3.#Fixed1(for 1 year)\n\t4.#Fixed2(for 2 years)\n\t5.#Fixed3(for 3 years)\n\n");
                    printf("Enter the new Type of account:");
                    scanf("%s",upd.acc_type);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,upd.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    system("cls");
                    printf("\n\nChanges saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt","record.txt");


    if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu_user();
        else
            close();
        }
}

//ฟังก์ชัน การทำธุรกรรมการเงิน
//Menu >>> Transaction
void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

        printf("\n\n\t\tEnter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.id_num,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    menu();

                }
                printf("\n\n\tDo you want to\n\n\t1.Deposit\n\t2.Withdraw\n\t3.Transfer\n\nEnter your choice: ");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit: $");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else if(choice==2)
                {
                    printf("Enter the amount you want to withdraw: $");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nTransfer successfully!");
                }
                else if(choice==3)
                {
                   printf("Enter the amount you want to transfer: $");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
   }

}

//ฟังก์ชัน การทำธุรกรรมการเงิน สำหรับ user
//Menu >>> Transaction
void transact_user(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

        printf("\n\n\t\tEnter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.id_num,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    menu();

                }
                printf("\n\n\tDo you want to\n\n\t1.Deposit\n\t2.Withdraw\n\t3.Transfer\n\t4.Check balance of money\n\nEnter your choice: ");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit: $");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else if(choice==2)
                {
                    printf("Enter the amount you want to withdraw: $");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                }
                else if(choice==3)
                {
                   printf("Enter the amount you want to transfer: $");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nTransfer successfully!");
                }
                else if(choice==4)
                {
                    printf("\n\n\t\tYour balance is  $%.2f\n\n",add.amt);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu_user();
        else
            close();
   }

}

//ฟังก์ชัน ลบข้อมูลบัญชี
//Menu >>> Erase_account
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.id_num,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {
                test++;
                printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}

//ฟังก์ชัน ปิดบัญชี สำหรับ user
//Menu >>> Erase_account
void erase_user(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.id_num,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {
                test++;
                printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu_user();
        else
            close();
        }

}

//ฟังก์ชัน ตรวจสอบข้อมูล
//check Data
void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.txt","r");
    printf("\n\tDo you want to check by\n\n1.Account no\n\n2.Name\n\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.id_num,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nIdentification Number No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.id_num,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nIdentity card number  No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.id_num,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {
            printf("\nEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&main_exit);
        }
         if(main_exit==1)
           {
                system("cls");
                menu();
           }

        else
           {

             system("cls");
             close();

           }

}

//ฟังก์ชัน ปิดโปรแกรม
//function close program
void close()
{
    system("cls");
    printf("\n\n\n\n\n\n\      Bank Management System [BMS] developed by Panurut Chinakul CS1 RB\n\n\n");
    printf("\t\t\t58-040626-2006-9");
    getch();

    }

//ฟังก์ชัน เมนูผู้ดูแล
//Function Menu Admin
void menu(void)
{   int choice;
    system("cls");
    system("color 1F");
    printf("\n\n\t\t\t    <<<<< B M S >>>>>");
    printf("\n\n\t\t\tBANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Log out system\n\t\t8.Exit\n\n");
    gotoxy(16,19);
    t();
    printf("\n\t\tEnter your choice: ");
    scanf("%d",&choice);
    //t();


    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:main();
        break;
        case 8:close();
        break;
    }
    //t();

}

//ฟังก์ชัน เมนูผู้ใช้
//Function Menu User
void menu_user()
{   int choice;
    system("cls");
    system("color 9F");
    printf("\n\n\t\t\t    <<<<< B M S >>>>>");
    printf("\n\n\t\t\tBANKING SERVICES SYSTEM");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Open a bank account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Canceling an bank Account\n\t\t5.Currency Converter\n\t\t6.Log out system\n\t\t7.Exit\n\n");
    gotoxy(16,19);
    t();
    printf("\n\t\tEnter your choice: ");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc_user();
        break;
        case 2:edit_user();
        break;
        case 3:transact_user();
        break;
        case 4:erase_user();
        break;
        case 5:cur_con();
        break;
        case 6:main();
        break;
        case 7:close();
        break;
    }
    t();
}

//ฟังก์ชัน Reset รหัสผ่าน
char pass_sys()
{
        //int c=0;
        printf("\n\n\t\t\t  Set Password for Admin:");
        scanf("%s",password);
        printf("\n\n\t\t\t  Set Password for User:");
        scanf("%s",password_acc);
        //return password,password_acc;
        c++;
        main();



}

//MAIN <<< BMS >>>
int main()
{


      system("color 4F");
      //char ch,pass[10],password[10];//="kmutnb";
      //char ch_acc,pass_acc[10],password_acc[10];//="test";

      system("cls");

      //ตั้งรหัสผ่านเริ่มต้น
      if(c==0)
      {
          printf("\n\n\t\t\t  Set Password for Admin:");
          scanf("%s",password);
          printf("\n\n\t\t\t  Set Password for User:");
          scanf("%s",password_acc);
          c++;
      }


//ฟังก์ชัน หน้าหลักระบบรักษาความปลอดภัย
void sec_sys()
{


    char d[30]=" Security System Activated ";
//char ch,pass[10];
    int i=0,j;


    system("cls");
    gotoxy(10,4);
    for(j=0;j<15;j++)
       {
           Sleep(40);
           printf("*");
       }
    for(j=0;j<27;j++)
       {
           Sleep(40);
           printf("%c",d[j]);
       }
    for(j=0;j<15;j++)
       {
           Sleep(40);
           printf("*");

       }

    //int i=0;

    login_try0:

    //Security System Activated
    printf("\n\n\n\n\t\t      Which system do you want to access?\n\n\n\n");
    printf("\t\t\t1.Administrator\t\t2.User\n");
    printf("\n\n\t\t\t   3.Reset password system");
    printf("\n\n\n\t\t      Please Enter System do you want: ");
    scanf("%d",&main_exit);
            if (main_exit==1) //เข้าระบบรักษาความปลอดภัย Administrator
                    {
                        //char ch,pass[10]="kmutnb";
                        try_pass:
                        system("cls");
                        printf("\n\n\t\t\t<<< Authorized person only >>>\n");
                        printf("\n\n\n\tEnter the password to login:");
                        scanf("%s",pass);


                        //password protected for admin
                        if (strcmp(pass,password)==0)
                           {
                               printf("\n\n\n\n\n\t\tAccess Allowed!\n\n");
                               printf("\t\tLOADING");
                           for(i=0;i<=6;i++)
                              {
                                  fordelay(100000000);//loading Status
                                  printf(".");
                              }
                                  system("cls");
                                  menu();
                              }
                           else
                              {
                                  printf("\t\t\n\nAccess Denied!\a\a\a");
                                  login_try:
                                  printf("\nEnter 1 to try again and 0 to exit:");
                                  scanf("%d",&main_exit);
                              if (main_exit==1)
                                 {

                                     system("cls");
                                     //main();
                                     goto try_pass;
                                 }

                              else if (main_exit==0)
                                 {
                                     system("cls");
                                     close();
                                 }
                              else
                                 {
                                     printf("\nInvalid!");
                                     fordelay(1000000000);//delay
                                     goto login_try;
                                 }

                               }


                    }

            else if (main_exit==2)// เข้าระบบรักษาความปลอดภัย User
                    {

                        try_pass_acc:
                        system("cls");
                        printf("\n\n\n\t\t\t<<< Access with User >>>\n");
                        printf("\n\n\n\n\t\tEnter the password to login:");
                        scanf("%s",pass_acc);


                        //password protected for users
                        if (strcmp(pass_acc,password_acc)==0)
                           {
                               printf("\n\n\n\n\n\t\tAccess Allowed!\n\n");
                               printf("\t\tLOADING");
                            for(i=0;i<=6;i++)
                               {
                                   fordelay(100000000);//loading Status
                                   printf(".");
                               }
                               system("cls");
                               menu_user();
                           }
                        else
                           {
                               printf("\t\t\n\nAccess Denied!\a\a\a");
                               login_try1:
                               printf("\nEnter 1 to try again and 0 to exit:");
                               scanf("%d",&main_exit);

                            if (main_exit==1)
                               {

                                   system("cls");
                                   goto try_pass_acc;

                               }

                       else if (main_exit==0)
                               {
                                   getch();
                                   system("cls");
                                   close();
                               }
                       else
                               {
                                   printf("\nInvalid!");
                                   fordelay(1000000000);//delay
                                   goto login_try1;
                               }

                            }


                    }
                    else if(main_exit==3)//เข้าระบบการ  Reset รหัสผ่าน
                    {
                        system("cls");
                        pass_sys();
                    }
            else
               {

                               login_try3:
                               printf("\t\t\n\nData Invalid!\a\a\a");

                               printf("\nEnter 1 to try again and 0 to exit:");
                               scanf("%d",&main_exit);

                            if (main_exit==1)
                               {

                                   system("cls");
                                   goto login_try0;

                               }

                       else if (main_exit==0)
                               {
                                   system("cls");
                                   close();
                               }
                       else
                               {
                                   printf("\nInvalid!");
                                   fordelay(1000000000);//delay
                                   goto login_try3;
                               }


    }

  }
    sec_sys(); //เข้าระบบรักษาความปลอดภัย

    return 0;
    //จบโปรแกรม
}

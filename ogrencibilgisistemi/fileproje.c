#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *filePtr;


char name[25];
char surname[25];
char password[25];


struct Student
{
  int number;
  char name[25];
  char surname[25];
  char password[25];
  char department[25];
  char subjects[4][25];
  char failing_subjects[4][25];
  int scores[6][2];
  int semester;
  int akts;
  int staj;
} students[100];

struct Lecturer
{
  char name[25];
  char surname[25];
  char password[25];
  char subjects[3][25];
} lecturers[5];

struct Memur
{
  char name[25];
  char surname[25];
  char password[25]
}memur[10];



char departments[3][25]={"yazilim","ekonomi","edebiyat"};
char subjects[12][25]={"programlama","matematik","fizik","ingilizce","istatistik","muhasebe","iktisat","isletme","sosyoloji","tarih","felsefe","turkce"};

int endOrCont()
{
  int x;
  printf("Devam etmek istiyor musunuz?\n");
  printf("1. Evet\n");
  printf("2. Hayir ");
  scanf("%d",&x);
  if (x==1)
  { }
  
  else if (x==2)
  {
    return 0;
  }
}

int adminLogin()
{
char admin_name[25];
char admin_password[25];
char admnamef[25];
char admpassf[25];

printf("Enter admin name: ");
scanf("%s",admin_name);
printf("Enter admin password: ");
scanf("%s",admin_password);
filePtr = fopen("admin.txt","r+");
fscanf(filePtr,"%s\n%s",admnamef,admpassf);
fclose(filePtr);

if (strcmp(admin_name,admnamef)==0 && strcmp(admin_password,admpassf)==0)
  {
    printf("Admin successfully logged in.\n");
    filePtr = fopen("ogretim.txt","a+");
    printf("Enter Memur adi: ");
    scanf("%s",lecturers[0].name);
    fprintf(filePtr,"%s\n",lecturers[0].name);
    printf("Enter Memur soyadi: ");
    scanf("%s",lecturers[0].surname);
    fprintf(filePtr,"%s\n",lecturers[0].surname);
    printf("Enter Memur sifre: ");
    scanf("%s",lecturers[0].password);
    fprintf(filePtr,"%s\n\n\n\n\n",lecturers[0].password);

  for (int i = 1; i < 5; i++)
    {
      printf("Enter %d . Ogretim Uyesi name: ",i);
      scanf("%s",lecturers[i].name);
      fprintf(filePtr,"%s\n",lecturers[i].name);
      printf("Enter %d . Ogretim Uyesi surname: ",i);
      scanf("%s",lecturers[i].surname);
      fprintf(filePtr,"%s\n",lecturers[i].surname);
      printf("Enter %d . Ogretim Uyesi password: ",i);
      scanf("%s",lecturers[i].password);
      fprintf(filePtr,"%s\n\n\n\n\n",lecturers[i].password);
    }
    fclose(filePtr);
    return 0;
  }

else
  {
    printf("Cant login.\n");
    return 0;
  }
}

void memurEkleme()
{int x;
printf("Memur ismi giriniz: ");
scanf("%s",name);
printf("Memur soyadi giriniz: ");
scanf("%s",surname);
printf("Memur sifre giriniz: ");
scanf("%s",password);
filePtr = fopen("memur.txt","a+");
fprintf(filePtr,"%s\n%s\n%s\n\n",name,surname,password);
printf("Tekrar memur eklemek ister misiniz?");
printf("1. Evet\n");
printf("2. Hayir");
scanf("%d",&x);
if (x==1)
{
  fclose(filePtr);
  memurEkleme();
}
else if (x==2)
{
  fclose(filePtr);
}

fclose(filePtr);
}

void lecturerLogin()
{
int choice1=0,choice2=0,numara=0,a=0;  
filePtr = fopen("ogretim.txt","r+");
fscanf(filePtr,"%s\n%s\n%s\n\n\n\n\n",lecturers[0].name,lecturers[0].surname,lecturers[0].password);
for (int i = 1; i < 5; i++)
  {
    fscanf(filePtr,"%s\n%s\n%s\n%s\n%s\n%s\n\n",lecturers[i].name,lecturers[i].surname,lecturers[i].password,lecturers[i].subjects[0],lecturers[i].subjects[1],lecturers[i].subjects[2]);
  }
fclose(filePtr);
printf("Lutfen isminizi giriniz: ");
scanf("%s",name);
printf("Lutfen soyadinizi giriniz: ");
scanf("%s",surname);
printf("Lutfen sifrenizi giriniz.");
scanf("%s",password);

if ((strcmp(name,lecturers[0].name)==0 && strcmp(surname,lecturers[0].surname)==0) && strcmp(password,lecturers[0].password)==0 )
{
  printf("Ne yapmak istersiniz?\n");
  printf("1. Ogretim Uyesine Ders Atamak.\n");
  printf("2. Ogrenci Kayit Etmek.\n");
  scanf("%d",&choice1);

  if (choice1==1)
  {
    printf("Atayabileceginiz dersler:( ");
    for (int i = 0; i < 11; i++)
    {
      printf("%s , ",subjects[i]);
    }
    printf("turkce)\n");

    for (int i = 1; i <5 ; i++)
    {
      printf("Ders Atayacaginiz Ogretim Uyesi: %s %s\n",lecturers[i].name,lecturers[i].surname);
      for (int j = 0; j < 3; j++)
      {
        printf("Atanan %d. ders: ",j+1);
        scanf("%s",lecturers[i].subjects[j]);
      }
    }
    printf("Ders atama islemi sona erdi.\n");
    filePtr = fopen("ogretim.txt","w+");
    for (int i = 0; i <5; i++)
    {
        fprintf(filePtr,"%s\n%s\n%s\n%s\n%s\n%s\n\n",lecturers[i].name,lecturers[i].surname,lecturers[i].password,lecturers[i].subjects[0],lecturers[i].subjects[1],lecturers[i].subjects[2]);
    }
    fclose(filePtr);
  }

else  if (choice1==2)
  { filePtr = fopen("ogrenciler.txt","a+");
    for (int i = 0; i < 100; i++)
    {
      printf("Ogrencinin numarasini giriniz: ");
      scanf("%d",&students[i].number);
      printf("Ogrencinin ismini giriniz: ");
      scanf("%s",students[i].name);
      printf("Ogrencinin soyadini giriniz: ");
      scanf("%s",students[i].surname);
      printf("Ogrencinin sifresini giriniz: ");
      scanf("%s",students[i].password);
      printf("Ogrencinin bolumunu giriniz. (yazilim , ekonomi , edebiyat) : ");
      scanf("%s",students[i].department);
      if (strcmp("yazilim",students[i].department)==0)
      {
        printf("Ogrencinin alabilecegi dersler:(programlama , matematik , fizik , ingilizce)\n");
        for (int j = 0; j < 4; j++)
        {
          printf("Ogrencinin %d . donem dersini giriniz: ",j+1);
          scanf("%s",students[i].subjects[j]); 
        }
      }
      else if (strcmp("ekonomi",students[i].department)==0)
      {
        printf("Ogrencinin alabilecegi dersler:(istatistik , iktisat , muhasebe , isletme)\n");
        for (int j = 0; j < 4; j++)
        {
          printf("Ogrencinin %d . donem dersini giriniz: ",j+1);
          scanf("%s",students[i].subjects[j]);
        }
      }
      else if (strcmp("edebiyat",students[i].department)==0)
      {
        printf("Ogrencinin alabilecegi dersler:(sosyoloji , tarih , felsefe , turkce)\n");
        for (int j = 0; j < 4; j++)
        {
          printf("Ogrencinin %d . donem dersini giriniz: ",j+1);
          scanf("%s",students[i].subjects[j]);
        }
      }
      
      students[i].semester=1;
      fprintf(filePtr,"%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n%d\n\n\n\n",students[i].number,students[i].name,students[i].surname,students[i].password,students[i].department,students[i].subjects[0],students[i].subjects[1],students[i].subjects[2],students[i].subjects[3],students[i].semester);
      printf("Yeni bir ogrenci girmek ister misiniz?\n");
      printf("1. Evet\n");
      printf("2. Hayir\n");
      scanf("%d",&choice2);
      if (choice2==1)
      { }
      else if (choice2==2)
      {
        fclose(filePtr);
        break;
      }
    } 
  }
}

else if (strcmp(name,lecturers[0].name)!=0 || strcmp(surname,lecturers[0].surname)!=0 || strcmp(password,lecturers[0].password)!=0)
  {
    for (int i = 1; i < 5; i++)
    {
      if ((strcmp(name,lecturers[i].name)==0 && strcmp(surname,lecturers[i].surname)==0) && strcmp(password,lecturers[i].password)==0)
      {
        a=i;
        break;
      } 
    }

    if (a==0)
    {
      printf("Cant login.");
    }

  else if (a!=0)
    { 
      filePtr = fopen("ogrenciler.txt","r+");

      
      for (int i = 0; i < 100; i++)
      {
        if (fscanf(filePtr,"%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n",&students[i].number,students[i].name,students[i].surname,students[i].password,students[i].department,students[i].subjects[0],students[i].subjects[1],students[i].subjects[2],students[i].subjects[3]))
        {
          break;
        }
        
        //fscanf(filePtr,"%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n",&students[i].number,students[i].name,students[i].surname,students[i].password,students[i].department,students[i].subjects[0],students[i].subjects[1],students[i].subjects[2],students[i].subjects[3]);
      }
      fclose(filePtr);
      filePtr = fopen("ogrenciler.txt","r+");
      
      printf("Hosgeldiniz %s %s\n",lecturers[a].name,lecturers[a].surname);
      printf("Dersleriniz: %s , %s , %s\n",lecturers[a].subjects[0],lecturers[a].subjects[1],lecturers[a].subjects[2]);
      for (int i = 0; i < 100; i++)
      {
        for (int j = 0; j < 3; j++)
        {
          if (strcmp(lecturers[a].subjects[j],students[i].subjects[0])==0)
          {
            printf("1. yariyil %s dersinizin ogrencisi %s %s\n",lecturers[a].subjects[j],students[i].name,students[i].surname);
            printf("Vize notunu giriniz: ");
            scanf("%d",&students[i].scores[0][0]);
            printf("Final notunu giriniz: ");
            scanf("%d",&students[i].scores[0][1]);
            fprintf(filePtr,"%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n\n\n%d\n%d\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n",students[i].number,students[i].name,students[i].surname,students[i].password,students[i].department,students[i].subjects[0],students[i].subjects[1],students[i].subjects[2],students[i].subjects[3],students[i].scores[0][0],students[i].scores[0][1]);
          }
          
        }        
      }
          
fclose(filePtr);
filePtr = fopen("ogrenciler.txt","r+");

      for (int i = 0; i < 100; i++)
      {
        for (int j = 0; i < 3; j++)
        {
          if (strcmp(lecturers[a].subjects[j],students[i].subjects[1])==0)
          {
            printf("2. yariyil %s dersinizin ogrencisi %s %s\n",lecturers[a].subjects[j],students[i].name,students[i].surname);
            printf("Vize notunu giriniz: ");
            scanf("%d",&students[i].scores[1][0]);
            printf("Final notunu giriniz: ");
            scanf("%d",&students[i].scores[1][1]);
            fprintf(filePtr,"%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n\n\n\n\n%d\n%d\n\n\n\n\n\n\n\n\n\n\n\n\n",students[i].number,students[i].name,students[i].surname,students[i].password,students[i].department,students[i].subjects[0],students[i].subjects[1],students[i].subjects[2],students[i].subjects[3],students[i].scores[1][0],students[i].scores[1][1]);
          }
          
        }  
      }
fclose(filePtr);
filePtr = fopen("ogrenciler.txt","r+");
      for (int i = 0; i < 100; i++)
      {
        for (int j = 0; i < 3; j++)
        {
          if (strcmp(lecturers[a].subjects[j],students[i].subjects[2])==0)
          {
            printf("3. yariyil %s dersinizin ogrencisi %s %s\n",lecturers[a].subjects[j],students[i].name,students[i].surname);
            printf("Vize notunu giriniz: ");
            scanf("%d",&students[i].scores[2][0]);
            printf("Final notunu giriniz: ");
            scanf("%d",&students[i].scores[2][1]);
            fprintf(filePtr,"%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n\n\n\n\n\n\n%d\n%d\n\n\n\n\n\n\n\n\n\n\n",students[i].number,students[i].name,students[i].surname,students[i].password,students[i].department,students[i].subjects[0],students[i].subjects[1],students[i].subjects[2],students[i].subjects[3],students[i].scores[2][0],students[i].scores[2][1]);
          }
          
        }  
      }

fclose(filePtr);
filePtr = fopen("ogrenciler.txt","r+");
      for (int i = 0; i < 100; i++)
      {
        for (int j = 0; i < 3; j++)
        {
          if (strcmp(lecturers[a].subjects[j],students[i].subjects[3])==0)
          {
            printf("4. yariyil %s dersinizin ogrencisi %s %s\n",lecturers[a].subjects[j],students[i].name,students[i].surname);
            printf("Vize notunu giriniz: ");
            scanf("%d",&students[i].scores[3][0]);
            printf("Final notunu giriniz: ");
            scanf("%d",&students[i].scores[3][1]);
            fprintf(filePtr,"%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n\n\n\n\n\n\n\n\n%d\n%d\n\n\n\n\n\n\n\n\n",students[i].number,students[i].name,students[i].surname,students[i].password,students[i].department,students[i].subjects[0],students[i].subjects[1],students[i].subjects[2],students[i].subjects[3],students[i].scores[3][0],students[i].scores[3][1]);
          }
          
        }  
      }
fclose(filePtr);

    }
  }





}

int loginMenu()
{
int secim=0;
printf("OGRENCI BILGI SISTEMINE HOSGELDINIZ.\n");
printf("====================================\n\n\n");
printf("Giris yapmak istediginiz turu seciniz.\n");
printf("1. Yonetici girisi:\n");
printf("2. Akademisyen girisi:\n");
printf("3. Ogrenci girisi:\n");
printf("4. Memur ekleme");
scanf("%d",&secim);
if (secim==1)
  {
    adminLogin();
  }
else if (secim==2)
  {
    lecturerLogin();
  }
else if (secim==3)
  {

  }
  else if (secim==4)
  {
    memurEkleme();
  }
  
}

int main()
{

loginMenu();



    return 0;
}
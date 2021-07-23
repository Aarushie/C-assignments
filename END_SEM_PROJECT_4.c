#include<stdio.h>
#include<stdlib.h>
struct student
{
 int rollno;
 char name[30];
 float mark[10];
}stud;
void insert()
{
 FILE *fp;
 fp = fopen("Record", "a");
 printf("Enter the Roll no   :");
 scanf("%d", &stud.rollno);
 printf("Enter the Name      :");
 scanf("%s", stud.name);
 for(int i=0;i<10;i++)
 {printf("Enter the marks in sub %d     :\n",i+1);
 scanf("%f\n", &stud.mark[i]);}
 fwrite(&stud, sizeof(stud), 1, fp);
 fclose(fp);
}
void disp()
{
 FILE *fp1;
 fp1 = fopen("Record", "r");
 printf("\nRoll Number\tName\n");
 for(int i=0;i<10;i++)
 printf("Enter the marks in sub %d     :\n",i+1);
 while (fread(&stud, sizeof(stud), 1, fp1))
 {printf("  %d\t\t%s\t\n", stud.rollno, stud.name);
 for(int i=0;i<10;i++)
 printf("%f\n",stud.mark[i]);}
 fclose(fp1);
}
void deletefile()
{
 FILE *fpo;
 FILE *fpt;
 int r, s;
 printf("Enter the Roll no you want to delete :");
 scanf("%d", &r);
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&stud, sizeof(stud), 1, fpo))
  {
   s = stud.rollno;
   if (s != r)
    fwrite(&stud, sizeof(stud), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&stud, sizeof(stud), 1, fpt))
   fwrite(&stud, sizeof(stud), 1, fpo);
  printf("\nRECORD DELETED\n");
  fclose(fpo);
  fclose(fpt);

}
int main()
{
 int c;
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. DELETE");
  printf("\n\t4. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insert();
   break;
  case 2:
    disp();
   break;
  case 3:
   deletefile();
   break;
  case 4:
   exit(1);
   break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 4);
 return 0;
}

#include <stdio.h>
#include <string.h>

   struct Student 
   {
     char name[50];
      int id;
      float grade; };
int main(void)
{
    struct Student s1, s2;
      strcpy(s1.name, "hehe");
       s1.id =1001;
      s1.grade= 9.1f;
    strcpy(s2.name,"hihi");
    s2.id=1002;
    s2.grade=8.7f;
     printf("Student1- %s, ID: %d,Grade- %.1f\n",s1.name,s1.id, s1.grade);
      printf("Student2: %s, ID- %d,Grade: %.1f\n",s2.name, s2.id,s2.grade);
    return 0; }
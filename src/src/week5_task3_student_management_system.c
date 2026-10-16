
/* Name Tushar SohanLal
  ID: 251ADB110*/

#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100

typedef struct Student
 {
    char name[50];
    int id;
    float gpa; } 
    Student;

void read_line(char line[], int size){
    if(fgets(line, size, stdin) != NULL)
{  line[strcspn(line, "\n")] = '\0';
}   else{
   line[0] = '\0'; }
}

int load_students(Student arr[], int max) {
    FILE *fp =fopen("students.txt", "r");
    char line[200];
    int count =0;
    if (fp == NULL)
     {
        return 0; }
    while (count<max && fgets(line,sizeof(line),fp) != NULL)
     {
        Student s;
        if (sscanf(line, "%49[^,],%d,%f",s.name, &s.id, &s.gpa) ==3)
         {
            if(s.name[0] != '\0' &&
                 s.gpa >= 0.0f && s.gpa <= 4.0f) 
                 {
                   arr[count] =s;
                    count++; }}}
  fclose(fp);
       return count ; }

  int save_students(const Student arr[], int count) {
    FILE *fp = fopen("students.txt", "w");
    int i;
    if (fp == NULL)
     {
        return -1; }
    for (i =0;i<count;i++)
     {
        fprintf(fp,"%s,%d,%.2f\n", arr[i].name, arr[i].id, arr[i].gpa); }
    fclose(fp);
    return 0; }
 

    void add_student(Student arr[],int *count)
{
    char name[50];
    char input[100];
    int id;
    float gpa;
    char extra;
    if (*count >= MAX_STUDENTS)
     {
        printf("Cannot add more students (limit reached).\n");
        return;
    }
        printf("Enter name ");
          read_line(name,sizeof(name));
           printf("Enter ID ");
            read_line(input, sizeof(input));
           if (sscanf(input,"%d %c",&id,&extra) != 1) {
         printf("Invalid input. Student not added.\n");
         return;
    }
    printf("Enter GPA");
    read_line(input,sizeof(input));
    if (sscanf(input, "%f %c", &gpa, &extra) != 1 || name[0] == '\0' || strchr(name, ',') != NULL ||
        gpa < 0.0f || gpa > 4.0f)
         {
        printf("Invalid input. Student not added.\n");
        return; }
    strcpy(arr[*count].name, name);
    arr[*count].id=id;
    arr[*count].gpa=gpa;
    (*count)++;
    printf("Student added successfully!\n");
}
    void list_students(const Student arr[], int count) {
    int i;
    if (count ==0)
     {
        printf("No students found.\n");
        return;
    }

    printf("ID    Name                 GPA\n");
    for (i = 0; i < count; i++) 
    {
      printf("%-5d %-20s %.2f\n",
     arr[i].id, arr[i].name, arr[i].gpa);
    }}

   int main(void) {
    Student students[MAX_STUDENTS];
    char input[100];
    int count;
    int choice;
    count =load_students(students, MAX_STUDENTS);
    printf("Loaded %d student(s) from students.txt\n",count);
    while (1) {
        printf("\n=== Student Management System ===\n");
        printf("List students\n");
        printf("Add student\n");
        printf("Save and Exit\n");
        printf("Select an option");
        read_line(input, sizeof(input));
        if (sscanf(input, "%d", &choice) != 1)
        {
            break; }
          if (choice == 1) {
           list_students(students, count); } 
           else if (choice == 2)  {
            add_student(students, &count);} 
            else if (choice == 3) {
            break; } 
            else {
            printf("Invalid option.\n"); }
    }

    if(save_students(students,count) != 0) 
     {
        printf("Error saving data.\n");
          return 1; }
    printf("Data saved. Goodbye!\n");
    return 0; 

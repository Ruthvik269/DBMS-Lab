#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char sid[20];
    char name[30];
    char branch[20];
    int semester;
    char address[50];
}student;

const char *filename="student.txt";
void print_student(student s){
    printf("Student ID: %s\n", s.sid);
    printf("Name: %s\n", s.name);
    printf("Branch: %s\n", s.branch);
    printf("Semester: %d\n", s.semester);
    printf("Address: %s\n", s.address);
    printf("-------------------------\n");
}
void insert()
{
    student s;
    FILE *fp=fopen(filename,"a");
    if(!fp){
        printf("Unable to open file\n");
        return;
    }
    printf("Enter Student ID: ");
    scanf("%s", s.sid);                     
    printf("\nEnter Name: ");
    scanf(" %s", s.name);
    printf("Enter Branch: ");
    scanf(" %s", s.branch);
    printf("Enter Semester: ");
    scanf("%d", &s.semester);
    printf("Enter Address: ");
    scanf(" %s", s.address);
    fprintf(fp,"%s %s %s %d %s\n",s.sid,s.name,s.branch,s.semester,s.address);
    fclose(fp);
    printf("Student record inserted successfully.\n");
}

void printall(){
    student s;
    FILE *fp=fopen(filename,"r");
    while(fscanf(fp,"%s %s %s %d %s",s.sid,s.name,s.branch,&s.semester,s.address)!=EOF){
        print_student(s);
    }
fclose(fp);
}

void printcse(){
    student s;
    FILE *fp=fopen(filename,"r");
    while(fscanf(fp,"%s %s %s %d %s",s.sid,s.name,s.branch,&s.semester,s.address)!=EOF){
        
        if(strcmp(s.branch,"CSE")==0){
        print_student(s);
        }
    }
fclose(fp);
}

void printcsandku(){
    student s;
    FILE *fp=fopen(filename,"r");
    while(fscanf(fp,"%s %s %s %d %s",s.sid,s.name,s.branch,&s.semester,s.address)!=EOF){
        if(strcmp(s.branch,"CSE")==0 && strcmp(s.address,"Kuvempunagar")==0){
            print_student(s);
    }
}
fclose(fp);
}

int main(){
    int choice;
    while(1){

        printf("1. Insert Student Record\n");
        printf("2. Print All Student Records\n");
        printf("3. Print CSE Students\n");
        printf("4. Print CSE Students from Kuvempunagar\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                printall();
                break;
            case 3:
                printcse();
                break;
            case 4:
                printcsandku();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
    }
}
    return 0;
}

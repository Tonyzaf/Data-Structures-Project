#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct Student{
    char AM[50];
    char Name[50];
    char Surname[50];
    float Grade;
};

void SwapStudents(struct Student st1,struct Student st2){
    struct Student temp;
    temp = st1;
    st1 = st2;
    st2 = temp;
}

struct Student st[20];
int found = 0;

void GradeBookImport(){
    FILE * file;
    file = fopen( "Gradebook.txt" , "r");
    if (file == NULL){
        printf("Error In Reading Gradebook File");
    }
    else{
        for(int i=0;i<20;i++){
            fscanf(file,"%s  %s %s %f\n",&st[i].AM,&st[i].Name,&st[i].Surname,&st[i].Grade);
        }
    }
}

void SortStudents(){
    int i, j;
        for (i = 0; i < 20; i++)
            for (j = 0; j < 19 - i; j++)
                if (st[j].Grade > st[j+1].Grade){
                    struct Student temp;
                    temp = st[j];
                    st[j] = st[j+1];
                    st[j+1] = temp;
                }
}

void ShowGradeBook(){
        printf("The Full Gradebook Is:\n\n\n");
        for(int i=0;i<20;i++){
        printf("%s  %s %s %f\n",st[i].AM,st[i].Name,st[i].Surname,st[i].Grade);
    }
}

void SearchStudent(){
    printf("Please Enter The Desired Roll Number:\n");
    char RN[8];
    scanf("%s", RN);
    for (int i = 0; i < 20; i++){
        if(strcmp(RN,st[i].AM) == 0){
            printf("%s  %s %s %f\n",st[i].AM,st[i].Name,st[i].Surname,st[i].Grade);
            found = 1;
        }
    }
}

void ShowStudent(int i){
        printf("%s  %s %s %f\n",st[i].AM,st[i].Name,st[i].Surname,st[i].Grade);
}

void ModifyStudent(){
    printf("Please Enter The Desired Roll Number:\n");
    char RN[8];
    scanf("%s", RN);
    for (int i = 0; i < 20; i++){
        if(strcmp(RN,st[i].AM) == 0){
            printf("%s  %s %s %f\n",st[i].AM,st[i].Name,st[i].Surname,st[i].Grade);
            found == 1;
            printf("Please Select The Field You Want To Edit:\n1.Name\n2.Surname\n3.Grade\n");
            int option;
            scanf("%d", &option);
            if (option == 1){
                printf("Please Enter The New Name:\n");
                scanf("%s", st[i].Name);
                ShowStudent(i);
            }
            if (option == 2){
                printf("Please Enter The New Surname:\n");
                scanf("%s", st[i].Surname);
                ShowStudent(i);
            }
            if (option == 3){
                printf("Please Enter The New Grade:\n");
                scanf("%f", &st[i].Grade);
                ShowStudent(i);
            }
            else{
                printf("Warning!The Option Was Not Found.");
            }
        }
    }
}

void DeleteStudent(){
    printf("Please Enter The Desired Roll Number:\n");
    char RN[8];
    int found;
    scanf("%s", RN);
    for (int i = 0; i < 20; i++){
        if(strcmp(RN,st[i].AM) == 0){
            printf("%s  %s %s %f\n",st[i].AM,st[i].Name,st[i].Surname,st[i].Grade);
            found = 1;
            for(int j = i; j < 19; i++) st[i] = st[i + 1];
        }
    }
    ShowGradeBook();
}

void LaunchMenu(){
    printf("Please Select An Action: \n1.Show BST\n2.Search Student\n3.Modify Student\n4.DeleteStudent\n5.Exit\n");
    int choice;
    int opt;
    scanf("%d",&choice);
    if (choice == 1){
        printf("Please Choose Sorting Method:\n1.Minimum First\n2.Maximum First\n");
        ShowGradeBook();
        /*else if (opt == 2){
            printf("The Full Gradebook Is:\n\n\n");
            for(int i=19;i>0;i--){
            printf("%s  %s %s %f\n",st[i].AM,st[i].Name,st[i].Surname,st[i].Grade);
            }
        }*/
    }
    else if (choice == 2){
        SearchStudent();
    }
    else if (choice == 3){
        ModifyStudent();
    }
    else if (choice == 4){
        DeleteStudent();
    }
    else if (choice == 5) exit(1);
    else{
        printf("Warning!The Option Was Not Found.Please Try Again!\n");
        LaunchMenu();
    }
}

int main(){
    GradeBookImport();
    SortStudents();
    LaunchMenu();
}
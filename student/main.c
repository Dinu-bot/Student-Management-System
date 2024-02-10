#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include <stdbool.h>
#include "subjects3.c"

// Define maximum number of students
#define MAX_LENGTH 20

void addstudent();
void studentrecord();
void searchstudent();
void update();
void Delete();
void clearscreen();
void picture();
void Delete1();
void main_menu();
void user_pass_role();
void delete_user_pass_role();
void viewstudent();
void gpa();

struct student{
    char first_name[20];
    char middle_name[20];
    char last_name[20];
    char stu_no[20];
    char course_code[20];
    char pho_no[20];
    char dob[20];
    char e_mail[40];
};

struct user{
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char role[MAX_LENGTH];

};

// Function prototypes
bool loginUser(const char* username, const char* password, char* role);

void main() {
    int choice;
    struct student info;
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char role[MAX_LENGTH];

    printf("\n\t\t\t\t\x1b[32m===== STUDENT DATABASE MANAGEMENT SYSTEM =====\x1b[0m\n");
    printf("\n");
    picture();
    printf("\n\t\t\t\t\t\x1b[32mEnter Username: ");
    scanf("%s", username);
    printf("\n\t\t\t\t\t\x1b[32mEnter Password: ");
    printf("\x1b[0m");

    // Hide password input
    int i = 0;
    while (1) {
        char ch = getch();  // Get a character without echoing it
        if (ch == 13) {     // Enter key
            password[i] = '\0';
            break;
        } else if (ch == 8 && i > 0) {  // Backspace key
            i--;
            printf("\b \b");  // Move cursor back, erase character, move cursor back again
        } else if (i < sizeof(password) - 1) {
            password[i++] = ch;
            printf("*");
        }
    }

    if (loginUser(username, password, role)) {
        clearscreen();
        printf("\n\t\t\t\t\t\x1b[36mLogin successful!  Role: %s\x1b[0m\n", role);

        // Implementing menu options based on the user's role
        if (strcmp(role, "admin") == 0) {
            // Implementing admin menu options
            while(choice!=11){
             printf("\n\t\t\t\t\x1b[33m===== STUDENT DATABASE MANAGEMENT SYSTEM =====");
             printf("\n\n\n\t\t\t\t\t1. Add Student Record\n");
            printf("\t\t\t\t\t2. Student Records\n");
            printf("\t\t\t\t\t3. Search Student\n");
            printf("\t\t\t\t\t4. Update Student\n");
            printf("\t\t\t\t\t5. Delete Student\n");
            printf("\t\t\t\t\t6. Log in as a user\n");
            printf("\t\t\t\t\t7. Username and password to user\n");
            printf("\t\t\t\t\t8. Remove user\n");
            printf("\t\t\t\t\t9. User guide\n");
            printf("\t\t\t\t\t10.Contact developers\n");
            printf("\t\t\t\t\t11.Exit\n");
            printf("\t\t\t\t\t_________________________\n");
            printf("\n\t\t\t\t\tEnter the number: \x1b[0m");
            scanf("%d",&choice);
            clearscreen();

            switch (choice){
                case 1:
                    clearscreen();
                    addstudent();
                    clearscreen();
                    break;

                case 2:
                    studentrecord();
                    printf("\n\t\t\t\t\t\x1b[33mPress any key to exit\x1b[0m\n");
                    getch();
                    clearscreen();
                    break;

                case 3:
                    searchstudent();
                    printf("\n\t\t\t\t\x1b[33mPress any key to exit\x1b[0m\n");
                    getch();
                    clearscreen();
                    break;

                case 4:
                    update();
                    getch();
                    clearscreen();
                    break;

                case 5:
                    Delete();
                    printf("\n\t\t\t\t\x1b[33mPress any key to continue\x1b[0m\n");
                    getch();
                    clearscreen();
                    break;

                case 6:
                    clearscreen();
                    main();
                    break;

                case 7:
                    clearscreen();
                    user_pass_role();
                    getch();
                    clearscreen();
                    break;

                case 8:
                    clearscreen();
                    delete_user_pass_role();
                    getch();
                    clearscreen();
                    break;

                case 9:
                    clearscreen();
                    printf("\n\t\t\t\t\x1b[33mUser guide\x1b[0m\n");
                    printf("\n\t\t\t\t\t\t\x1b[33mPress any key to exit\x1b[0m\n");
                    getch();
                    clearscreen();
                    break;

                case 10:
                    clearscreen();
                    printf("\n\t\t\t\t\x1b[33mContact Developers\x1b[0m\n");
                    printf("\n\t\t\t\t\t\t\x1b[33mPress any key to exit\x1b[0m\n");
                    getch();
                    clearscreen();
                    break;

                case 11:
                    clearscreen();
                    picture();
                    printf("\n\t\t\t\t\x1b[33m       Thank you for using this software\x1b[0m\n");
                    printf("\t\t\t\t\t\x1b[33m     Press any key to exit\x1b[0m\n");
                    exit(0);
                    break;

                default:
                    printf("\n\t\t\t\x1b[31m Ooops! Enter a valid number!\x1b[0m");
                    break;
            }
        }
        } else if (strcmp(role, "user") == 0) {
            // Implementing user menu options
            while(choice!=5){
                printf("\n\t\t\t\t\x1b[33m===== STUDENT DATABASE MANAGEMENT SYSTEM =====\x1b[0m");
                printf("\n\n\t\t\t\t\t\x1b[33m1. View my details");
                printf("\n\n\t\t\t\t2. GPA Calculator");
                printf("\n\n\t\t\t\t3. User guide");
                printf("\n\t\t\t\t\t4. Contact developers");
                printf("\n\t\t\t\t\t5. Logout");
                printf("\n\t\t\t\t\t_________________________\n");
                printf("\n\t\t\t\t\tEnter the number: ");
                scanf("%d",&choice);
                printf("\x1b[0m");
                clearscreen();

                switch (choice){
                    case 1:
                        clearscreen();
                        viewstudent(username);
                        printf("\n\t\t\t\t\x1b[33mPress any key to exit\x1b[0m\n");
                        getch();
                        clearscreen();
                        break;

                    case 2:
                        clearscreen();
                        gpa();
                        gpaMenu();
                        printf("\n\t\t\t\t\x1b[33mPress any key to exit\x1b[0m\n");
                        getch();
                        clearscreen();
                        break;

                    case 3:
                        clearscreen();
                        printf("\n\t\t\t\t\t\t\x1b[33mUser guide\x1b[0m\n");
                        printf("\n\t\t\t\t\t\t\x1b[33mPress any key to exit\x1b[0m\n");
                        getch();
                        clearscreen();
                        break;


                    case 4:
                        clearscreen();
                        printf("\n\t\t\t\t\t\t\x1b[33mContact Developers\x1b[0m\n");
                        printf("\n\t\t\t\t\t\t\x1b[33mPress any key to exit\x1b[0m\n");
                        getch();
                        clearscreen();
                        break;

                    case 5:
                        clearscreen();
                        picture();
                        printf("\n\t\t\t\t\t\x1b[33mThank you for using this software\x1b[0m\n");
                        printf("\n\t\t\t\t\t\t\x1b[33mPress any key to exit\x1b[0m\n");
                        getch();
                        clearscreen();
                        main();
                        break;
                }
            }
        }
    } else {
        clearscreen();
        printf("\n\t\t\t\t\x1b[31mLogin failed! Check your username and password again\x1b[0m\n");
        main();

    }
}

bool loginUser(const char* username, const char* password, char* role) {
    FILE* file = fopen("user_credentials.txt", "r");
    if (file == NULL) {
        perror("\x1b[33mError opening file\x1b[0m");
        return false;  // Failed to open file
    }

    char storedUsername[MAX_LENGTH];
    char storedPassword[MAX_LENGTH];
    char storedRole[MAX_LENGTH];

    while (fscanf(file, "%s %s %s", storedUsername, storedPassword, storedRole) == 3) {
        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
            strcpy(role, storedRole);  // Set the user's role
            fclose(file);
            return true;  // Login successful
        }
    }

    fclose(file);
    return false;  // Login failed
}

void user_pass_role() {

    FILE *file;
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char role[MAX_LENGTH];

    // Open the file for writing in append mode (to avoid overwriting existing data)
    file = fopen("user_credentials.txt", "a");

    if (file == NULL) {
        printf("\x1b[31mError opening the file!\x1b[0m\n");
        main(); // Exit with an error code
    }

    // Prompt the user to enter the username, password, and role
    printf("\n\t\t\t\t\x1b[33mEnter username(username is Student No): ");
    scanf("%s", username);
    printf("\n\t\t\t\tEnter password: ");
    scanf("%s", password);
    printf("\x1b[0m");
    printf("\x1b[36m");
    printf("\n\n\t\t\t\tEnter the password recipient's role");
    printf("\x1b[0m");
    printf("\x1b[33m");
    printf("\n\t\t\t\tEnter role(admin or user): ");
    scanf("%s", role);
    printf("\x1b[0m");

    // Write the data to the file in the specified format
    fprintf(file, "%s\n%s\n%s\n\n", username, password, role);

    // Close the file
    fclose(file);

    printf("\n\t\t\t\x1b[33mUser credentials have been saved to user_credentials.txt\x1b[0m\n");

}

void delete_user_pass_role() {

    FILE *originalFile, *tempFile;
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char role[MAX_LENGTH];
    char line[150]; // Assuming a maximum line length of 150 characters

    char deleteUsername[50]; // The username to delete
    printf("\n\t\t\t\t\x1b[33mEnter username(username is Student No): ");
    scanf("%s", deleteUsername);

    originalFile = fopen("user_credentials.txt", "r");
    tempFile = fopen("temp1.txt", "w");

    if (originalFile == NULL || tempFile == NULL) {
        printf("\x1b[31mError opening files!\x1b[0m\n");
        main_menu(); // goto main menu
    }

    // Read and process each line from the original file
    while (fgets(line, sizeof(line), originalFile)) {
        sscanf(line, "%s %s %s", username, password, role);

        // Check if the username matches the one to be deleted
        if (strcmp(username, deleteUsername) != 0) {
            // Write the line to the temporary file
            fprintf(tempFile, "%s %s %s\n", username, password, role);
        }
    }

    // Close both files
    fclose(originalFile);
    fclose(tempFile);

    // Replace the original file with the temporary file
    if (remove("user_credentials.txt") != 0) {
        printf("Error deleting the original file!\n");
    }
    if (rename("temp1.txt", "user_credentials.txt") != 0) {
        printf("Error renaming the temporary file!\n");
    }

    printf("\n\t\t\t\x1b[33mUser credentials for '%s' have been deleted.\x1b[0m\n\n", deleteUsername);
}

void clearscreen(){
    system("cls");
}

void picture(){
     printf("\t\t\t\t\x1b[33m                  .~7YJ!^.                     \n");
     printf("\t\t\t\t              .:7JPGBBBBG5?!:                  \n");
     printf("\t\t\t\t          .^!J57GBBBBBBBBBBBPY?~:              \n");
     printf("\t\t\t\t      .:!?5GB#G7GBBBBBBBBBBBBBBGPY7~:          \n");
     printf("\t\t\t\t   :7J5GBBBBBBP!YPPPPPPPPPPPGBBBBBBBPYJ~       \n");
     printf("\t\t\t\t   .~7YPB####BY:5BBBBBBBBBBGGG####BG5J!:       \n");
     printf("\t\t\t\t        :!?5##5:YBBBBBBBBBBBBB#GY7^.           \n");
     printf("\t\t\t\t            J&5^5#BBBBBBBBBB##B:               \n");
     printf("\t\t\t\t            J#J~?55GB##BP5YY5PB:               \n");
     printf("\t\t\t\t           :BP~!~^^^!Y?~^^^^^^P5.              \n");
     printf("\t\t\t\t          .!YJ^~^^^^^^^^^^^^^^JJ~              \n");
     printf("\t\t\t\t          .~~~^~^^^^^^^^^^^^^~~~~              \n");
     printf("\t\t\t\t           ^!~~!~^^^^^^^^^^^~~~~.              \n");
    printf("\t\t\t\t            ..!7!^^^^^^^^^^~~:..               \n");
    printf("\t\t\t\t               .~!^^^^^^^^^~~:                  \n");
    printf("\t\t\t\t                 77~^:^^^^~?~                   \n");
    printf("\t\t\t\t                 :7?7~^^~7?!.                   \n");
    printf("\t\t\t\t              :?.  :~!!!!~.  :7.                \n");
    printf("\t\t\t\t    ^:.        ^!:   :^^:   :~.        .:.      \n");
    printf("\t\t\t\t  ~5BGPJ~.       ::.  J7  .:.       :!YGGP7.    \n");
    printf("\t\t\t\t ^BBBBBBBP?^       .:!P5~..      .~JGBBBBB#Y    \n");
    printf("\t\t\t\t 7#BBBBBBBBB5?~:             .:!JPBBBBBBBBBG:   \n");
    printf("\t\t\t\t YBBBBBBBBBBB#BGP5J?7!~!!7?Y5GBBBBBBBBBBBBBB^   \n");
    printf("\t\t\t\t 5BBBBBBBBBBBBBBBB####B#####BBBBBBBBBBBBBBBB!   \n");
    printf("\t\t\t\t 5BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGBBBBBBB#7   \x1b[0m\n");
}

void addstudent(){
    char another;
    FILE *fp;
    struct student info;
    do{
        clearscreen();
        printf("\t\t\t\t\x1b[33m=======Add Student info======\n\n\n");
        fp=fopen("student_info.txt","a");
        printf("\n\t\t\tEnter first name : ");
        scanf("%s",info.first_name);
        printf("\n\t\t\tEnter middle name : ");
        scanf("%s",info.middle_name);
        printf("\n\t\t\tEnter last name : ");
        scanf("%s",info.last_name);
        printf("\n\t\t\tEnter Student No(FORMAT: EC/2021/037) : ");
        scanf("%s",info.stu_no);
        printf("\n\t\t\tEnter Course Code : ");
        scanf("%s",info.course_code);
        printf("\n\t\t\tEnter phone number : ");
        scanf("%s",info.pho_no);
        printf("\n\t\t\tEnter birthday(FORMAT: YYYY/MM/DD): ");
        scanf("%s",info.dob);
        printf("\n\t\t\tEnter Email : ");
        scanf("%s",info.e_mail);
        printf("\n\t\t\t______________\n");

        if (fp==NULL){
            fprintf(stderr,"\t\t\t\x1b[31mCan't open file\x1b[0m\n");
        }else{
            printf("\t\t\t\x1b[33mRecord stored successfully\x1b[0m\n");
        }
        fwrite(&info,sizeof(struct student),1,fp);
        fclose(fp);
        printf("\x1b[33m");
        printf("\t\t\t\x1b[33mDo you want to add another record?(y/n) : ");
        scanf("%s",&another);
        printf("\x1b[0m");
    } while (another=='y'||another=='Y');
}

void studentrecord(){
    FILE *fp;
     struct student info;
     int num;
     char stu_no[20];
    fp=fopen("student_info.txt","r");

    printf("\n\t\t\t\t\t\x1b[33m======Student Records======\x1b[0m\n\n");

    if (fp==NULL){
        fprintf(stderr,"\t\t\t\t\x1b[31mCan't open file\x1b[0m\n");
    }else{
        printf("\t\t\t\t\x1b[33mRecords\x1b[0m\n");

        while(fread(&info,sizeof(struct student),1,fp)){
            printf("\x1b[33m");
            printf("\n\t\t\t\tFirst name          : %s",info.first_name);
            printf("\n\t\t\t\tMiddle name         : %s",info.middle_name);
            printf("\n\t\t\t\tLast name           : %s",info.last_name);
            printf("\n\t\t\t\tStudent no          : %s",info.stu_no);
            printf("\n\t\t\t\tCourse Code         : %s",info.course_code);
            printf("\n\t\t\t\tPhone number        : %s",info.pho_no);
            printf("\n\t\t\t\tDate of Birth       : %s",info.dob);
            printf("\n\t\t\t\tEmail Address       : %s",info.e_mail);
            printf("\n\t\t\t\t________________________________________\x1b[0m\n");
        }
    }
    fclose(fp);
}

void searchstudent(){
    FILE *fp;
     struct student info;
     int found=0;
     char stu_no[20];
    fp=fopen("student_info.txt","r");

     printf("\t\t\t\t\x1b[33m======Search Records======\n\n\n");
     printf("\t\t\tEnter Student No: ");
     scanf("%s", stu_no);
     // loop read the student_info file
      while(fread(&info,sizeof(struct student),1,fp)){
            if(strcmp(info.stu_no, stu_no) == 0){
                found=1;
                printf("\n\t\t\t\tFirst name          : %s",info.first_name);
                printf("\n\t\t\t\tMiddle name         : %s",info.middle_name);
                printf("\n\t\t\t\tLast name           : %s",info.last_name);
                printf("\n\t\t\t\tStudent no          : %s",info.stu_no);
                printf("\n\t\t\t\tCourse Code         : %s",info.course_code);
                printf("\n\t\t\t\tPhone number        : %s",info.pho_no);
                printf("\n\t\t\t\tDate of Birth       : %s",info.dob);
                printf("\n\t\t\t\tEmail Address       : %s",info.e_mail);
                printf("\n\t\t\t\t________________________________________\n");
            }
    }
            if(!found){
                printf("\n\t\t\tRecord not found\x1b[0m\n");
            }
    fclose(fp);
}

void viewstudent(const char *stu_no){
    FILE *fp;
     struct student info;
     char username[MAX_LENGTH];
     char password[MAX_LENGTH];
     char role[MAX_LENGTH];
     int found=0;
    fp=fopen("student_info.txt","r");

     printf("\t\t\t\t\x1b[33m======Search Records======\n\n\n");

     //This loop read the student_info file
      while(fread(&info,sizeof(struct student),1,fp)){
            if(strcmp(info.stu_no, stu_no) == 0){
                found=1;
                printf("\n\t\t\t\tFirst name          : %s",info.first_name);
                printf("\n\t\t\t\tMiddle name         : %s",info.middle_name);
                printf("\n\t\t\t\tLast name           : %s",info.last_name);
                printf("\n\t\t\t\tStudent no          : %s",info.stu_no);
                printf("\n\t\t\t\tCourse Code         : %s",info.course_code);
                printf("\n\t\t\t\tPhone number        : %s",info.pho_no);
                printf("\n\t\t\t\tDate of Birth       : %s",info.dob);
                printf("\n\t\t\t\tEmail Address       : %s",info.e_mail);
                printf("\n\t\t\t\t________________________________________\n");
            }
        }
            if(!found){
                printf("\n\t\t\tRecord not found\x1b[0m\n");
            }
    fclose(fp);
}

void Delete1(){
    char Back[20];
    printf("\t\t\t\t\x1b[31mThe entered Number doesn't exist!\x1b[0m\n\n");
    main_menu();
}

void Delete() {
    FILE *fp, *temp;
    struct student info;
    int found = 0;
    char stu_no[20];

    printf("\n\t\t\t\t\t\x1b[33mEnter Student No to delete: ");
    scanf("%s", stu_no);
    // Open the student_info file in read mode
    fp = fopen("student_info.txt", "r");

    if (fp == NULL) {
        printf("\n\t\t\t\x1b[31mError opening file for delete.\x1b[0m\n");
        return;
    }

    // Create a temporary file for writing
    temp = fopen("temp_student_info.txt", "w");

    if (temp == NULL) {
        printf("\n\t\t\t\x1b[31mError creating temporary file.\x1b[0m\n");
        fclose(fp);
        return;
    }

    // Loop through the records and copy to the temporary file, excluding the student to be deleted
    while (fread(&info, sizeof(struct student), 1, fp)) {
        if (strcmp(info.stu_no, stu_no) == 0) {
            found = 1;
            // Skip this record (i.e., do not copy it to the temporary file)
            continue;
        }
        // Copy the record to the temporary file
        fwrite(&info, sizeof(struct student), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    // Delete the original file and rename the temporary file to the original file
    remove("student_info.txt");
    rename("temp_student_info.txt", "student_info.txt");

        if (found) {
            printf("\n\t\t\t\t\tStudent data deleted successfully.\n");
            getch();
            clearscreen();
            do{
                main_menu();
            }while(found);
        } else {
            printf("\n\t\t\t\tRecord not found\n");
            printf("\n\t\t\tPress any to main menu\x1b[0m");
            getch();
            clearscreen();
            do{
                main_menu();
            }while(found);
        }
}

void main_menu(){
    int choice;
    while(choice!=11){
             printf("\n\t\t\t\t\x1b[33m===== STUDENT DATABASE MANAGEMENT SYSTEM =====");
             printf("\n\n\n\t\t\t\t\t1. Add Student Record\n");
            printf("\t\t\t\t\t2. Student Records\n");
            printf("\t\t\t\t\t3. Search Student\n");
            printf("\t\t\t\t\t4. Update Student\n");
            printf("\t\t\t\t\t5. Delete Student\n");
            printf("\t\t\t\t\t6. Log in as a user\n");
            printf("\t\t\t\t\t7. Username and password to user\n");
            printf("\t\t\t\t\t8. Remove user\n");
            printf("\t\t\t\t\t9. User guide\n");
            printf("\t\t\t\t\t10.Contact developers\n");
            printf("\t\t\t\t\t11.Exit\n");
            printf("\t\t\t\t\t_________________________\n");
            printf("\n\t\t\t\t\tEnter the number: \x1b[0m");
            scanf("%d",&choice);
            clearscreen();

            switch (choice){
                case 1:
                    clearscreen();
                    addstudent();
                    clearscreen();
                    break;

                case 2:
                    studentrecord();
                    printf("\n\t\t\t\t\t\x1b[33mPress any key to exit\x1b[0m\n");
                    getch();
                    clearscreen();
                    break;

                case 3:
                    searchstudent();
                    printf("\n\t\t\t\t\x1b[33mPress any key to exit\x1b[0m\n");
                    getch();
                    clearscreen();
                    break;

                case 4:
                    update();
                    getch();
                    clearscreen();
                    break;

                case 5:
                    Delete();
                    printf("\n\t\t\t\t\x1b[33mPress any key to continue\x1b[0m\n");
                    getch();
                    clearscreen();
                    break;

                case 6:
                    clearscreen();
                    main();
                    break;

                case 7:
                    clearscreen();
                    user_pass_role();
                    getch();
                    clearscreen();
                    break;

                case 8:
                    clearscreen();
                    delete_user_pass_role();
                    getch();
                    clearscreen();
                    break;

                case 9:
                    clearscreen();
                    printf("\n\t\t\t\t\x1b[33mUser guide\x1b[0m\n");
                    printf("\n\t\t\t\t\t\t\x1b[33mPress any key to exit\x1b[0m\n");
                    getch();
                    clearscreen();
                    break;

                case 10:
                    clearscreen();
                    printf("\n\t\t\t\t\x1b[33mContact Developers\x1b[0m\n");
                    printf("\n\t\t\t\t\t\t\x1b[33mPress any key to exit\x1b[0m\n");
                    getch();
                    clearscreen();
                    break;

                case 11:
                    clearscreen();
                    picture();
                    printf("\n\t\t\t\t\x1b[33m       Thank you for using this software\x1b[0m\n");
                    printf("\t\t\t\t\t\x1b[33m     Press any key to exit\x1b[0m\n");
                    exit(0);
                    break;

                default:
                    printf("\n\t\t\t\x1b[31m Ooops! Enter a valid number!\x1b[0m");
                    break;
            }
        }
}

// Function to update student information by student number
void update() {
    FILE *fp;
    struct student info;
    int found = 0;
    char stu_no[20];

    printf("\x1b[33m");
    printf("\n\t\t\tEnter your student no(Example:-EC/2021/037)  : ");
    scanf("%s", stu_no);
    // Open the student_info file in read-write mode
    fp = fopen("student_info.txt", "r+");

    if (fp == NULL) {
        printf("\n\t\t\t\x1b[31mError opening file for update.\x1b[0m\n");
        return;
    }

    // Calculate the size of struct student
    long studentSize = sizeof(struct student);

    // Loop through the records and update if the student number matches
    while (fread(&info, sizeof(struct student), 1, fp)) {
        if (strcmp(info.stu_no, stu_no) == 0) {
            found = 1;
            printf("\n\t\t\tEnter first name : ");
            scanf("%s",info.first_name);
            printf("\n\t\t\tEnter middle name : ");
            scanf("%s",info.middle_name);
            printf("\n\t\t\tEnter last name : ");
            scanf("%s",info.last_name);
            printf("\n\t\t\tEnter Student No(FORMAT: EC/2021/037) : ");
            scanf("%s",info.stu_no);
            printf("\n\t\t\tEnter Course Code : ");
            scanf("%s",info.course_code);
            printf("\n\t\t\tEnter phone number : ");
            scanf("%s",info.pho_no);
            printf("\n\t\t\tEnter birthday : ");
            scanf("%s",info.dob);
            printf("\n\t\t\tEnter Email : ");
            scanf("%s",info.e_mail);
            printf("\n\t\t\t______________\n");

            // Calculate the offset to move back to the beginning of the current record
            long offset = -studentSize;
            fseek(fp, offset, SEEK_CUR);

            // Write the updated information back to the file
            fwrite(&info, sizeof(struct student), 1, fp);

            printf("\n\t\t\tStudent information updated successfully.\n");
            break;
        }
    }
    printf("\x1b[0m");
    if (!found) {
        printf("\n\t\t\t\x1b[31mOoops!..The entered Student No doesn't exist\x1b[0m\n");
        printf("\n\t\t\t\x1b[33mPress any key to main menu");
    }
    fclose(fp);
}


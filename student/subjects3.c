#include <stdio.h>


// Create module structure

struct Module {

    char module_name[40];
    int credit_count;
    char grade;



};


 //Function to Display GPA menu.

 float gpaMenu() {

    int grade;
    float gradePoints;
    printf("\x1b[33m");
    printf("\n\t\t\t\t---Grade Menu---\n");
    printf("\n\t\t\t\tEnter  1 for grade 'A+' \n");
    printf("\n\t\t\t\tEnter  2 for grade 'A' \n");
    printf("\n\t\t\t\tEnter  3 for grade 'A-' \n");
    printf("\n\t\t\t\tEnter  4 for grade 'B+' \n");
    printf("\n\t\t\t\tEnter  5 for grade 'B' \n");
    printf("\n\t\t\t\tEnter  6 for grade 'B-' \n");
    printf("\n\t\t\t\tEnter  7 for grade 'C+' \n");
    printf("\n\t\t\t\tEnter  8 for grade 'C' \n");
    printf("\n\t\t\t\tEnter  9 for grade 'C-' \n");
    printf("\n\t\t\t\tEnter 10 for grade 'D+' \n");
    printf("\n\t\t\t\tEnter 11 for grade 'D' \n");
    printf("\n\t\t\t\tEnter 12 for grade 'F' \n");
    printf("\n\t\t\t\tEnter the number : ");
    scanf("%d",&grade);

switch(grade){

   case 1:
       gradePoints = 4.00;
       break;

   case 2:
       gradePoints = 4.00;
       break;

   case 3:
       gradePoints = 3.70;
       break;

   case 4:
       gradePoints = 3.30;
       break;

   case 5:
       gradePoints = 3.00;
       break;

   case 6:
       gradePoints = 2.70;
       break;

   case 7:
       gradePoints = 2.30;
       break;

   case 8:
       gradePoints = 2.00;
       break;

   case 9:
       gradePoints = 1.70;
       break;

   case 10:
       gradePoints = 1.30;
       break;

   case 11:
       gradePoints = 1.00;
       break;

   case 12:
       gradePoints = 0.00;
       break;

   default:
       gradePoints = 0.00;
       break;

}

   return gradePoints;
   printf("\x1b[0m");
}


void gpa() {

    int total_modules;
    int credit_count;
    float gradePoints;
    float totalCredits = 0.00;
    float totalPoints = 0.00;
    float points = 0.00;
    float GPA = 0.00;

    printf("\x1b[36m");
    printf("\n\t\t\t\t\tGPA CALCULATOR\n");
    printf("\x1b[0m");

    printf("\x1b[33m");
    //Get Total Subject Count as a user input.
    printf("\n\t\t\t\tEnter the total number of modules: ");
    scanf("%d", &total_modules);

    //Collecting subject details

    struct Module modules[total_modules];


    FILE *file = fopen("subject_info.txt", "w");

        if (file == NULL) {
            printf("\n\t\t\t\tFile not found.\n");
        }


    for (int i = 0; i < total_modules; i++) {

        printf("Use underscore for space (EXAMPLE: Computer_Science)");
        printf("\n\t\t\t\tEnter module name %d: ",i+1);
        scanf("%s", &modules[i].module_name);
        printf("\n\t\t\t\tEnter credit count: ");
        scanf("%d", &modules[i].credit_count);

        gradePoints = gpaMenu();

        points = (modules[i].credit_count * gradePoints);
        //printf("\n\t\t\t\tPoints: %f\n\n",points);

        totalPoints = totalPoints + points;
        totalCredits = totalCredits + modules[i].credit_count;

        //fprintf(file, "Module: %s, Credits: %d\n", modules[i].module_name, modules[i].credit_count);

    }


       GPA = (totalPoints/totalCredits);

       printf("\n\n\n\t\t\t\tThe GPA is %.2f" ,GPA);
       printf("\x1b[0m");

    fclose(file);
    getch();
}







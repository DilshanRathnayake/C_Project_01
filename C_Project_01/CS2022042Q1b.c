#include <string.h>

int numberOfSubjects,numberOfExams;
float totalPayment,discount;
char stdNumber[25],enrollment[25],studentRoll[25];



void inputValues();
void calculateValues();
void calculatePayment();
void outputValues();



int main(){


    inputValues();
    calculateValues();
    calculatePayment();
    outputValues();




    return 0;
}
void inputValues()
{
    printf("\nEnter the student number(101 - 999):");
    scanf("%s", &stdNumber);
    printf("\nEnter the number of subjects:");
    scanf("%d", &numberOfSubjects);
    printf("\nEnter the number of exams:");
    scanf("%d", &numberOfExams);
    printf("\nDo you pay full payment at the enrollment(yes/no):");
    scanf("%s",&enrollment);
}

void calculateValues()
{
    if(numberOfSubjects > 4){
        strcpy(studentRoll, "full-time");
        totalPayment = 8000 + numberOfExams*1500 + numberOfSubjects*15000;

    }else{
        strcpy(studentRoll, "part-time");
        totalPayment = 4000 + numberOfExams*1500 + numberOfSubjects*15000;

    }
}

void calculatePayment()
{
    if(strcmp(enrollment, "yes") == 0 || strcmp(enrollment, "Yes") == 0){
        if(numberOfSubjects > 4){
            discount = totalPayment*0.15;
        }else{
            discount = totalPayment*0.10;
        }
        totalPayment -= discount;
    }else{
        discount = 0;
    }
}

void outputValues()
{
    printf("\n------ Enrollment of Student ------");
    printf("\nStudent Number : %s",stdNumber);
    printf("\nNumber of Subjects : %d",numberOfSubjects);
    printf("\nNumber of Exams : %d",numberOfExams);
    printf("\nStudent Roll : %s", studentRoll);
    if(discount > 0){
        printf("\nDiscount value : %.2f", discount);
    }else{
        printf("\nNo Discount Value");
    }
    printf("\nTotal Student fees : %.2f", totalPayment);
}

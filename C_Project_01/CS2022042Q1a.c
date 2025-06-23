
#include <string.h>


void inputValues(char *stdNumber,int *numberOfSubjects,int *numberOfExams,char *enrollment);
void ifCalFull(int numberOfExams,int numberOfSubjects,float *totalPayment,char *studentRoll);
void elseCalFull(int numberOfExams,int numberOfSubjects,float *totalPayment,char *studentRoll);
void calculatePayment(int numberOfSubjects,char *enrollment,float *discount,float *totalPayment);
void outputValues(char *stdNumber,int numberOfSubjects,int numberOfExams,float totalPayment,float discount,char *studentRoll);


int main(){


    int numberOfSubjects,numberOfExams;
    float totalPayment = 0;
    float discount = 0;
    char stdNumber[25],enrollment[25],studentRoll[25];


    inputValues(stdNumber,&numberOfSubjects,&numberOfExams,enrollment);



    if(numberOfSubjects > 4){
        ifCalFull(numberOfExams,numberOfSubjects,&totalPayment,studentRoll);
    }else{
        elseCalFull(numberOfExams,numberOfSubjects,&totalPayment,studentRoll);
    }
    calculatePayment(numberOfSubjects,enrollment,&discount,&totalPayment);
    outputValues(stdNumber,numberOfSubjects,numberOfExams,totalPayment,discount,studentRoll);


    return 0;
}

void inputValues(char *stdNumber,int *numberOfSubjects,int *numberOfExams,char *enrollment)
{
    printf("\nEnter the student number(101 - 999):");
    scanf("%s", stdNumber);
    printf("\nEnter the number of subjects:");
    scanf("%d", numberOfSubjects);
    printf("\nEnter the number of exams:");
    scanf("%d", numberOfExams);
    printf("\nDo you pay full payment at the enrollment(yes/no):");
    scanf("%s", enrollment);
}

void ifCalFull(int numberOfExams,int numberOfSubjects,float *totalPayment,char *studentRoll)
{
    strcpy(studentRoll, "full-time");
    *totalPayment = 8000 + numberOfExams*1500 + numberOfSubjects*15000;
}
void elseCalFull(int numberOfExams,int numberOfSubjects,float *totalPayment,char *studentRoll)
{
    strcpy(studentRoll, "part-time");
    *totalPayment = 4000 + numberOfExams*1500 + numberOfSubjects*15000;
}

void calculatePayment(int numberOfSubjects,char *enrollment,float *discount,float *totalPayment)
{

    if(strcmp(enrollment, "yes") == 0 || strcmp(enrollment, "Yes") == 0){
        if(numberOfSubjects > 4){
            *discount = *totalPayment*0.15;
        }else{
            *discount = *totalPayment*0.10;
        }
        *totalPayment -= *discount;
    }else{
        *discount = 0;
    }



}
void outputValues(char *stdNumber,int numberOfSubjects,int numberOfExams,float totalPayment,float discount,char *studentRoll)
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


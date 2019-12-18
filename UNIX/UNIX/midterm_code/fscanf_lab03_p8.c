#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

//bubblesort Integer by DESC
void bubblesort_int(int arr[]){
    
    int temp = 0;
    for(int i = 0 ; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if (arr[j] < arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}

//bubblesort Float by DESC
void bubblesort_float(float arr[]){

    float temp = 0.0;
    for(int i = 0; i < 4 ; i++){
        for(int j = 0; j < 4; j++){
            if(arr[j]< arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
    
            }
        }
    }

}

int main(void){

    FILE *rfp, *wfp;
    char buf[BUFSIZ];

    rfp = fopen("3-8.dat","r");
    if(rfp == NULL){
        perror("3-8.dat");
        exit(1);
    }

    wfp = fopen("3-8.out","w");
    if(wfp == NULL){
        perror("3-8.out");
        exit(1);
    }

    int sum[5]; // sum per person
    float avg[5]; // average per person

    char name[10]; // name
    int kor,eng,math; // each score of subject
    
    int sum_kor=0, sum_eng=0, sum_math=0; // declaration for average of each subject

    fprintf(wfp,"<<<< result >>>>\n");

    for(int i = 0 ; i < 5; i++){

        fscanf(rfp,"%s %d %d %d",name,&kor,&eng,&math);

        sum[i] += kor+eng+math;
        avg[i] = (float)sum[i]/3.0;
    
        sum_kor += kor;
        sum_eng += eng;
        sum_math += math;

    }

    bubblesort_int(sum); // bubble sort
    bubblesort_float(avg); // bubble sort

    for(int i = 0; i < 5; i++){
        fprintf(wfp,"sum : %d, avg : %.2f\n",sum[i],avg[i]); // fprintf sum and average by DESC
    }

    fprintf(wfp,"\n<<<< average of subject >>>>\n");
    fprintf(wfp,"kor : %.2f, eng : %.2f, math : %.2f\n",(float)sum_kor/5.0, (float)sum_eng/5.0, (float)sum_math/5.0); // fprintf average of each subject

    fclose(rfp);
    fclose(wfp);

    return 0;
}

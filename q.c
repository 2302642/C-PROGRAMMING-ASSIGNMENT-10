/*!
@file       the name of source file is q.c
@author     Najih & DP login: n.hajasheikallaudin
@course     This source file meant for RSE course    
@section    which section of this course are you enrolled in RSE
@tutorial   Assignment 10
@date       file created on 12/11/2023
@brief      provide a brief explanation about what this source file does:
            
            This file is contains 9 function definitions to called by main in qdriver.
            Functions:
            - double* read_data(char const *file_name, int *ptr_cnt);                                   // reading data from file and store into a sting variable
            - double max(double const *begin, double const *end);                                       // finding the largest number stored in begin
            - double min(double const *begin, double const *end);                                       // finding the smallest number stored in begin
            - double average(double const *begin, double const *end);                                   // calculating the average of the values stored in begin
            - double variance(double const *begin, double const *end);                                  // finding the varience of elements stored in begin
            - double std_dev(double const *begin, double const *end);                                   // finding the standard deviation of values stored in begin
            - double median(double *base, int size);                                                    // finding the element in the center of the values stored in base after values stored in begin is sorted
            - void selection_sort(double *base, int size);                                              // sorting elements stored in base in assending order
            - void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grades);          // indentifying number of grades as alpha charcters in terms of percentage
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________*/

#include "q.h" // we're including q.h here because we want to apply the DRY principle [see specs for additional info]
#include <stdio.h>  // for file
#include <stdlib.h> // for exit
#include <math.h>   // pow

double* read_data(char const *file_name, int *ptr_cnt){                                                 // reading data from file and store into a sting variable
    FILE *input_file = fopen(file_name, "r");                                                           // opening file file_name for read
    if (input_file == NULL){ fprintf(stderr, "Unable to open file\n"); exit(EXIT_FAILURE);}             // checking if file exist if print error statement and exit the programe

    int num_grads = 0; double grades;
    while( fscanf(input_file,"%lf", &grades) != EOF){ num_grads++; }                                    // counting the number of doubles in the file till EOF
    *ptr_cnt = num_grads;

    double *resutls = (double *)malloc(num_grads * sizeof(double));
    if (resutls == NULL) { fclose(input_file); return NULL;}                                            // Unable to allocate memory

    fseek(input_file, 0, SEEK_SET);                                                                     // reseting file position to the start of the file

    int i = 0;
    while (fscanf(input_file, "%lf", &resutls[i]) == 1) { i++; }                                        // reading doubles fromt the file and store in allocated memory
    fclose(input_file);                                                                                 // closing flie input_file
    return resutls;                                                                                     // returning results

}
double max(double const *begin, double const *end){                                                     // finding the largest number stored in begin
    double max = *begin;                                                                                // setting the initial max value as the first element 
    for (const double *ptr = begin; ptr != end; ptr++){                                                 // identifying the largest number stored in begin
        if (*ptr > max) { max = *ptr; }
    }
    return max;                                                                                         // returning max
}
double min(double const *begin, double const *end){                                                     // finding the smallest number stored in begin
    double min = *begin;                                                                                // setting the initial min value as the first element
    for (const double *ptr = begin; ptr != end; ptr++){                                                 // identifying the smallest number stored in begin
        if (*ptr < min) { min = *ptr; }
    }
    return min;                                                                                         // returning min
}
double average(double const *begin, double const *end){                                                 // calculating the average of the values stored in begin

    int count=0;                                                                                        // setting the initial values for average calculation
    double sum = 0.00;                                      
    for (const double *ptr = begin; ptr != end; ptr++){
        sum += *ptr; count++;
    }
    return sum/count;                                                                                   // returning average of values stored in begin
}
double variance(double const *begin, double const *end){                                                // finding the varience of elements stored in begin
    
    double mean = average(begin, end),var = 0.00;                                                       // using function average to identify average of values stored in begin for variance calculation
    for (const double *ptr = begin; ptr != end; ptr++){
        var += pow((*ptr - mean),2);                                                                    // summing the total numarator value for variance calculation
    }
    return var/ ((end-begin) -1);                                                                       // returning variance of values stored in begin
}
double std_dev(double const *begin, double const *end){                                                 // finding the standard deviation of values stored in begin
    return sqrt(variance(begin, end));                                                                  // calculating standard deviation by square rooting the returned value from function variance;
}
double median(double *base, int size){                                                                  // finding the element in the center of the values stored in base after values stored in begin is sorted

    selection_sort(base, size);                                                                         // using function selection_sort to sort elements stored in base in assending order
    int mid = size/2;                                                                                   // identifying position of element stored in the center of base

    if(size%2 == 0){                                                                                    // if the total number of elements in base is a even number
        return (base[mid] + base[mid-1])/2;                                                             // find the average of the 2 elements at the center of base and return it
    }
    else{ return base[mid]; }                                                                           // else return the element in the center of base

}
void selection_sort(double *base, int size){                                                            // sorting elements stored in base in assending order

    for(int i = 0; i < size; i++){
        
        int temp_pos = i;
        for(int j = i+1; j < size; j++){
            if(base[j]< base[temp_pos]){ temp_pos = j; }                                                // checking value of elements if elemen at position i+1 is smaller then element at position at i store element at position i into temp
        }
        double temp = base[i];                                                                          // swaping between 2 positions; 
        base[i] = base[temp_pos];
        base[temp_pos] = temp;
    }
}
void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grades){                        // indentifying number of grades as alpha charcters in terms of percentage 
    
    int total_grades = 0; 
    while (begin < end) {
        int grades = *begin;                                                                            // Assuming values in the range [0, 100]

        if (grades >= 90)       { ltr_grades[A_GRADE]++; }                                              // storing letter grade into enum based on elements in begin
        else if (grades >= 80)  { ltr_grades[B_GRADE]++; }
        else if (grades >= 70)  { ltr_grades[C_GRADE]++; }
        else if (grades >= 60)  { ltr_grades[D_GRADE]++; }
        else                    { ltr_grades[F_GRADE]++; }
        
        total_grades++;
        begin++;                                                                                        // Move to the next grade stored in begin
    }

    for (int i = 0; i < TOT_GRADE; i++) {                                                               // calculate and store number of letter grade in the form of percentages
        ltr_grades[i] = (ltr_grades[i] * 100.0) / total_grades;
    }
}
/*
for (const double *ptr = begin; ptr != end; ptr++){         // ptr is contains the address of the first element in begin 
}                                                           // (end contains the size of string stored in begin and the size of data type of string )
                                                            // the for loop will iterate through ptr pointing to each address if elements stored in begin till reaching the last address  
*/

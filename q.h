/*!
@file       the name of source file is q.h
@author     Najih & DP login: n.hajasheikallaudin
@course     This source file meant for RSE course    
@section    which section of this course are you enrolled in RSE
@tutorial   Assignment 10
@date       file created on 12/11/2023
@brief      provide a brief explanation about what this source file does:
            
            This file is contains 9 function declaractions to called by main in qdriver.
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

#ifndef Q_H
#define Q_H

enum LetterGrade {                                                                                      // declaring enum to store number of letter grades in terms of percentage
    A_GRADE,
    B_GRADE,
    C_GRADE,
    D_GRADE,
    F_GRADE,
    TOT_GRADE                                                                                           // to store total number of letter grades
};

double* read_data(char const *file_name, int *ptr_cnt);                                                 // reading data from file and store into a sting variable

double max(double const *begin, double const *end);                                                     // finding the largest number stored in begin
double min(double const *begin, double const *end);                                                     // finding the smallest number stored in begin
double average(double const *begin, double const *end);                                                 // calculating the average of the values stored in begin

double variance(double const *begin, double const *end);                                                // finding the varience of elements stored in begin
double std_dev(double const *begin, double const *end);                                                 // finding the standard deviation of values stored in begin
double median(double *base, int size);                                                                  // finding the element in the center of the values stored in base after values stored in begin is sorted

void selection_sort(double *base, int size);                                                            // sorting elements stored in base in assending order
void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grades);                        // indentifying number of grades as alpha charcters in terms of percentage

#endif // #ifndef Q_H


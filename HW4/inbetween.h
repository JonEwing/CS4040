//******************************************************************* 
//                                                                    
//  Program:     inbetween.h                                            
//                                                                     
//  Author:      Jonathan Feige
//  Email:       jf786915@ohio.edu
//  ID:          P100790961
//                                                                    
//  Course:      CS4040
//                                                                    
//  Description: This is the header file for the inbetween 
//               code. It also includes a generate vector
//               and some timeing functions.        
//                                                                    
//  Date:        10/21/2018
//                                                                    
//*******************************************************************

#ifndef inbetween_h
#define inbetween_h

#include <vector>
#include <cstdlib>
#include <iostream>
#include <sys/time.h>
#include "student.h"

using namespace std;

//******************************************************************                                                                  
//  Function:   inbetweenGPA
//                                                                  
//  Purpose:    runs a quick select to get j through k elments   
//              based on gpa out of a list
//******************************************************************
vector <Student> inbetweenGPA( vector <Student> list, const size_t j, const size_t k, size_t &num_compares);


//******************************************************************                                                              
//  Function:   inbetweenAlpha
//                                                                  
//  Purpose:    runs a quick select to get j through k elments   
//              based on first name out of a list  
//******************************************************************
vector <Student> inbetweenAlpha(vector <Student> list,const size_t j, const size_t k, size_t &num_compares);


//******************************************************************                                                                  
//  Function:   timeval2sec
//                                                                  
//  Purpose:    takes a time t and turns it intoo seconed 
//******************************************************************
double timeval2sec(const timeval& T);


//******************************************************************                                                              
//  Function:   timeofday
//                                                                  
//  Purpose:    collects the current time of day for the
//              runtime analisis.
//******************************************************************
double timeofday();


//******************************************************************                                                                
//  Function:   generateStudents
//                                                                  
//  Purpose:    generates a random list of students to
//              help the program run.
//******************************************************************
vector<Student> generateStudents(size_t num);


//******************************************************************                                                               
// Function:   printvector
//                                                                  
// Purpose:    helps print a vector of students
//******************************************************************
void printvector(vector<Student> v);


//******************************************************************                                                               
// Function:   partition_gpa
//                                                                  
// Purpose:    Takes a pivot index and tries to find
//             the value in the kth spot based on GPA
//******************************************************************
int partition_gpa(vector<Student> &vec, int left, int right, size_t &num_compares);


//******************************************************************                                                               
// Function:   select_gpa
//                                                                  
// Purpose:    Quick select taylord to find the kth
//             element based on GPA
//******************************************************************
Student select_gpa(vector<Student> &vec, int left, int right, int k, size_t &num_compares);


//******************************************************************                                                               
// Function:   partition_name
//                                                                  
// Purpose:    Takes a pivot index and tries to find the
//             value in the kth spot based on first name
//******************************************************************
int partition_name(vector<Student> &vec, int left, int right, size_t &num_compares);


//******************************************************************                                                               
// Function:   select_name
//                                                                  
// Purpose:    Quick select taylord to find the kth
//             element based on first name
//******************************************************************
Student select_name(vector<Student> &vec, int left, int right, int k, size_t &num_compares);



#endif
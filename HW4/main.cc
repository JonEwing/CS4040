//******************************************************************* 
//                                                                    
//  Program:     main.cc                                            
//                                                                     
//  Author:      Jonathan Feige
//  Email:       jf786915@ohio.edu
//  ID:          P100790961
//                                                                    
//  Course:      CS4040
//                                                                    
//  Description: This program tests and runs the two inbetween 
//               functions inbetweenGPA and inbetweenAlpha        
//                                                                    
//  Date:        10/21/2018
//                                                                    
//*******************************************************************

#include <iostream>
#include <vector>
#include "inbetween.h"
#include "student.h"

using namespace std;

int main()
{
  vector<Student> Students;
  size_t num_compares=0;  //base values of compares

  const size_t NUM_STUDENTS=10000;  //Number of students generated

  Students = generateStudents(NUM_STUDENTS);

  // Is this in the right place for this statement?
  double start=timeofday();

  // Test first function.


  vector<Student> answer = inbetweenGPA(Students, 10, 20, num_compares);

  cout << "\n\ninbetweenGPA took " << timeofday() - start << " seconds" 
       << " on input of size " << NUM_STUDENTS << endl;

  cout << "inbetweenGPA took " << num_compares << " comparisons" 
       << " on input of size " << NUM_STUDENTS << endl;

  cout << "There are " << answer.size() << " students in the answer" << endl << endl;

  printvector(answer);

  num_compares=0; //resets number of compares
  start=timeofday();
  answer = inbetweenAlpha(Students, 1000, 2000, num_compares);

  cout << "inbetweenAlpha took " << timeofday() - start << " seconds" 
       << " on input of size " << NUM_STUDENTS << endl;

  cout << "inbetweenAlpha took " << num_compares << " comparisons" 
       << " on input of size " << NUM_STUDENTS << endl;

  cout << "There are " << answer.size() << " students in the answer" << endl;

  printvector(answer);

  return(EXIT_SUCCESS);
}

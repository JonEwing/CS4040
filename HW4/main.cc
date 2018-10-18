#include <iostream>
#include <vector>
#include "inbetween.h"
#include "student.h"

using namespace std;

int main()
{
  vector<Student> Students;
  size_t num_compares=0;

  const size_t NUM_STUDENTS=1000000;

  Students = generateStudents(NUM_STUDENTS);

  Student tmp;

  // Is this in the right place for this statement?
  double start=timeofday();

  // Test first function.

  quickSort(Students, 0, Students.size(),num_compares, 0);
  vector<Student> answer = inbetweenGPA(Students, 1, 10, num_compares);

  cout << "inbetweenGPA took " << timeofday() - start << " seconds" 
       << " on input of size " << NUM_STUDENTS << endl;

  cout << "inbetweenGPA took " << num_compares << " comparisons" 
       << " on input of size " << NUM_STUDENTS << endl;

  cout << "There are " << answer.size() << " students in the answer" << endl << endl;

  num_compares=0;
  start=timeofday();
  quickSort(Students, 0, Students.size(),num_compares, 1);
  answer = inbetweenAlpha(Students, 100000, 200000, num_compares);

  cout << "inbetweenAlpha took " << timeofday() - start << " seconds" 
       << " on input of size " << NUM_STUDENTS << endl;

  cout << "inbetweenAlpha took " << num_compares << " comparisons" 
       << " on input of size " << NUM_STUDENTS << endl;

  cout << "There are " << answer.size() << " students in the answer" << endl;

  return(EXIT_SUCCESS);
}

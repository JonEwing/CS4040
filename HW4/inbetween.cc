//******************************************************************* 
//                                                                    
//  Program:     inbetween.cc                                           
//                                                                     
//  Author:      Jonathan Feige
//  Email:       jf786915@ohio.edu
//  ID:          P100790961
//                                                                    
//  Course:      CS4040
//                                                                    
//  Description: Inbetween takes a vector and returns either
//               gpa between j,k or alphibetical between j,k.
//               It does this using a quick select algorithem.      
//                                                                    
//  Date:        10/21/2018
//                                                                    
//*******************************************************************

#include <vector>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <cmath>
#include <sys/time.h>
#include "inbetween.h"


      //******************************************************************
      //                                                                  
      //  Function:   inbetweenGPA
      //                                                                  
      //  Purpose:    runs a quick select to get j through k elments   
      //              based on gpa out of a list                                  
      //                                                                  
      //  Parameters: Vector of students
      //              lower bound j
      //              upper bound k
      //              number of compares for main
      //                                                                  
      // Member/Global Variables: none
      //
      // Pre Conditions: All variables have valed values
      //
      // Post Conditions: returns a vector of students whos gpa lies
      //                  between the jth and kth element
      //
      // Space Complexity: O(calls to select_gpa)
      //
      // Time Complexity:  O(k - j)
      //
      // Calls:       function select_gpa
      //                                                                  
      //******************************************************************


vector <Student> inbetweenGPA( vector <Student> list,const size_t j,const size_t k,size_t &num_compares)
{ 
  vector <Student> gpa; //temperary vector to return
  for(int i = j; i < k + 1; i++)
  {
    gpa.push_back(select_gpa(list,0, list.size()-1, i,num_compares));
  }
  return gpa;
}


//******************************************************************
      //                                                                  
      //  Function:   inbetweenAlpha
      //                                                                  
      //  Purpose:    runs a quick select to get j through k elments   
      //              based on first name out of a list                                  
      //                                                                  
      //  Parameters: Vector of students
      //              lower bound j
      //              upper bound k
      //              number of compares for main
      //                                                                  
      // Member/Global Variables: none
      //
      // Pre Conditions: All variables have valed values
      //
      // Post Conditions: returns a vector of students whos first name lies
      //                  between the jth and kth element
      //
      // Space Complexity: O(calls to select_name)
      //
      // Time Complexity:  O(k - j)
      //
      // Calls:       function select_gpa
      //                                                                  
      //******************************************************************


vector <Student> inbetweenAlpha(vector <Student> list,const size_t j,const size_t k,size_t &num_compares)
{
  vector <Student> name;  //temperary vector to return
  for(int i = j; i < k + 1; i++)
  {
    name.push_back(select_name(list,0, list.size()-1, i,num_compares));
  }
  return name;
}


//******************************************************************
      //                                                                  
      //  Function:   timeval2sec
      //                                                                  
      //  Purpose:    takes a time t and turns it intoo seconed                                               
      //                                                                  
      //  Parameters: time T
      //                                                                  
      // Member/Global Variables: none
      //
      // Pre Conditions: T must be a valid positive number
      //
      // Post Conditions: Returns a double that is T in seconeds
      //
      // Space Complexity: O(constant T)
      //
      // Time Complexity:  O(1)
      //
      // Calls:   none
      //                                                                  
      //******************************************************************


double timeval2sec(const timeval& T) {
  // Constant for time unit conversion
  const double USEC_TO_SEC = 1000000.0; //conversion calculator

  return ((double) T.tv_sec + (double) (T.tv_usec / USEC_TO_SEC));
}


      //******************************************************************
      //                                                                  
      //  Function:   timeofday
      //                                                                  
      //  Purpose:    collects the current time of day for the
      //              runtime analisis.                                               
      //                                                                  
      //  Parameters: none
      //                                                                  
      // Member/Global Variables: none
      //
      // Pre Conditions:    none
      //
      // Post Conditions:   none
      //
      // Space Complexity: O(1)
      //
      // Time Complexity:  O(1)
      //
      // Calls:   gettimeofday
      //                                                                  
      //******************************************************************


double timeofday() {
  timeval T;  //Time variable
  gettimeofday(&T, NULL);
  return (timeval2sec(T));
}


      //******************************************************************
      //                                                                  
      //  Function:   generateStudents
      //                                                                  
      //  Purpose:    generates a random list of students to
      //              help the program run.
      //                                                                                                                         
      //  Parameters: num amount of students generated
      //                                                                  
      // Member/Global Variables: none
      //
      // Pre Conditions:    num must be a positive / non-zero number
      //
      // Post Conditions:   returns a vector with num amount of
      //                    of random students in it.
      //
      // Space Complexity: O(Number of students requested)
      //
      // Time Complexity:  O(Number of students requested (n at most))
      //
      // Calls:   none
      //                                                                  
      //******************************************************************


vector<Student> generateStudents(size_t num)
{
  vector <Student> testing; //Temparary vector to hold generated students
  Student tmp;  //Temparary Student to hold generated students
  string str = "AAA"; //Temparary sting to hold name
  for (int i = 0; i<num; i++) {

    str[0] = rand() % 26 + 65;  //rand char
	  str[1] = rand() % 26 + 65;  //rand char
    str[1] = rand() % 26 + 65;  //rand char
    tmp.first_name = str; //rand char set to first name

    str[0] = rand() % 26 + 65;  //rand char
	  str[1] = rand() % 26 + 65;  //rand char
    str[2] = rand() % 26 + 65;  //rand char
    tmp.last_name = str;  //rand char set to last name

    str[0] = rand() % 26 + 65;  //rand char
	  str[1] = rand() % 26 + 65;  //rand char
    str[2] = rand() % 26 + 65;  //rand char
    tmp.major = str;  //rand char set to major

    std::string out_string;
    std::stringstream ss;
    ss << i;
    tmp.SSN = ss.str();//index set to SSN

    tmp.gpa = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/4));  //random float set to GPA (up to 10^-6)
    testing.push_back(tmp);
}
  return(testing);
}


      //******************************************************************
      //                                                                  
      // Function:   printvector
      //                                                                  
      // Purpose:    helps print a vector of students
      //                                                                                                                         
      // Parameters: Vector of students
      //                                                                  
      // Member/Global: Variables: none
      //
      // Pre Conditions:    none
      //
      // Post Conditions:   none
      //
      // Space Complexity: O(1)
      //
      // Time Complexity:  O(Number of students in vector (at most n))
      //
      // Calls:   none
      //                                                                  
      //******************************************************************

 void printvector(vector<Student> v)
{  
    for (int i=0;i<v.size();i++)
    {
      std::cout <<v[i].first_name<< " "<<v[i].last_name<< " "<<v[i].major<< " "<< v[i].gpa<<" "<<v[i].SSN<<"\n"; //Prints a student
    }
    std::cout<<endl;
}


      //******************************************************************
      //                                                                  
      // Function:   partition_gpa
      //                                                                  
      // Purpose:    Takes a pivot index and tries to find
      //             the value in the kth spot based on GPA
      //                                                                                                                         
      // Parameters: Vector of students
      //             left most number
      //             right most number
      //             number of compares
      //                                                                  
      // Member/Global: Variables: none
      //
      // Pre Conditions:    left < right
      //
      // Post Conditions:   gives a index to continue to find the kth element
      //
      // Space Complexity: O(the size of the vector)
      //
      // Time Complexity:  O(n)
      //
      // Calls:   std::swap
      //                                                                  
      //******************************************************************


int partition_gpa(vector<Student> &vec, int left, int right, size_t &num_compares)
{
    float pivot = vec[right].gpa;
    
    while ( left < right )
    {
        while ( vec[left].gpa < pivot )
        {
            num_compares++;
            left++;
        }
        while ( vec[right].gpa > pivot )
        {
            num_compares++;
            right--;
        }
        if ( vec[left].gpa == vec[right].gpa )
        {
            left++;
        }
        else if ( left < right ) {
            swap(vec[left], vec[right]);
        }
    }
    
    return right;
}


      //******************************************************************
      //                                                                  
      // Function:   select_gpa
      //                                                                  
      // Purpose:    Quick select taylord to find the kth
      //             element based on GPA
      //                                                                                                                         
      // Parameters: Vector of students
      //             left most number
      //             right most number
      //             the kth element
      //             number of compares
      //                                                                  
      // Member/Global: Variables: none
      //
      // Pre Conditions:    left < right
      //                    k => 0
      //                    vec not empty
      //
      // Post Conditions:   returns the kth student in vec
      //    
      // Space Complexity: O(the size of the vector)
      //
      // Time Complexity:  O(logn)
      //
      // Calls:   partition_gpa
      //                                                                  
      //******************************************************************


Student select_gpa(vector<Student> &vec, int left, int right, int k, size_t &num_compares)
{
    if ( left == right ) return vec[left];
    int j = partition_gpa(vec, left, right,num_compares);
    int length = j - left + 1;
    if ( length == k ) return vec[j];
    else if ( k < length ) return select_gpa(vec, left, j - 1, k, num_compares);
    else  return select_gpa(vec, j + 1, right, k - length, num_compares);
}


      //******************************************************************
      //                                                                  
      // Function:   partition_name
      //                                                                  
      // Purpose:    Takes a pivot index and tries to find the
      //             value in the kth spot based on first name
      //                                                                                                                         
      // Parameters: Vector of students
      //             left most number
      //             right most number
      //             number of compares
      //                                                                  
      // Member/Global: Variables: none
      //
      // Pre Conditions:    left < right
      //
      // Post Conditions:   gives a index to continue to find the kth element
      //
      // Space Complexity: O(the size of the vector)
      //
      // Time Complexity:  O(n)
      //
      // Calls:   std::swap
      //                                                                  
      //******************************************************************


int partition_name(vector<Student> &vec, int left, int right, size_t &num_compares)
{
    string pivot = vec[right].first_name;
    
    while ( left < right )
    {
        while ( vec[left].first_name < pivot )
        {
            num_compares++;
            left++;
        }
        while ( vec[right].first_name > pivot )
        {
            num_compares++;
            right--;
        }
        if ( vec[left].first_name == vec[right].first_name )
        {
            left++;
        }
        else if ( left < right ) {
            swap(vec[left], vec[right]);
        }
    }
    
    return right;
}


      //******************************************************************
      //                                                                  
      // Function:   select_name
      //                                                                  
      // Purpose:    Quick select taylord to find the kth
      //             element based on first name
      //                                                                                                                         
      // Parameters: Vector of students
      //             left most number
      //             right most number
      //             the kth element
      //             number of compares
      //                                                                  
      // Member/Global: Variables: none
      //
      // Pre Conditions:    left < right
      //                    k => 0
      //                    vec not empty
      //
      // Post Conditions:   returns the kth student in vec
      //
      // Space Complexity: O(the size of the vector)
      //
      // Time Complexity:  O(3n/4)
      //
      // Calls:   partition_name
      //                                                                  
      //******************************************************************


Student select_name(vector<Student> &vec, int left, int right, int k, size_t &num_compares)
{
    if ( left == right ) return vec[left];
    int j = partition_name(vec, left, right,num_compares);
    int length = j - left + 1;
    if ( length == k ) return vec[j];
    else if ( k < length ) return select_name(vec, left, j - 1, k, num_compares);
    else  return select_name(vec, j + 1, right, k - length, num_compares);
}
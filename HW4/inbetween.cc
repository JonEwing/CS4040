#include <vector>
#include <cstdlib>
#include <iostream>
#include <sys/time.h>
#include "inbetween.h"

vector <Student> inbetweenGPA( vector <Student> list,const size_t j,const size_t k,size_t &num_compares)
{ 
  vector <Student> return_list;
  int i = 0;
  int ammount = k - j + 1;
  for(int i = 0; i < ammount; i++)
  {
    return_list.push_back(list[j + i]);
    num_compares++;
  }
  return return_list;
}

vector <Student> inbetweenAlpha(vector <Student> list,const size_t j,const size_t k,size_t &num_compares)
{
  vector <Student> return_list;
  int i = 0;
  int ammount = k - j + 1;
  for(int i = 0; i < ammount; i++)
  {
    return_list.push_back(list[j + i]);
    num_compares++;
  }
  return return_list;
}

double timeval2sec(const timeval& T) {
  // Constant for time unit conversion
  const double USEC_TO_SEC = 1000000.0;

  return ((double) T.tv_sec + (double) (T.tv_usec / USEC_TO_SEC));
}

double timeofday() {
  timeval T;
  gettimeofday(&T, NULL);
  return (timeval2sec(T));
}

vector<Student> generateStudents(size_t num)
{
  vector <Student> testing;
  Student tmp;
  string str = "AAA";
  for (int i = 0; i<num; i++) {

  str[0] = rand() % 26 + 65;
	str[1] = rand() % 26 + 65;
  str[1] = rand() % 26 + 65;
  tmp.first_name = str;

  str[0] = rand() % 26 + 65;
	str[1] = rand() % 26 + 65;
  str[2] = rand() % 26 + 65;
  tmp.last_name = str;

  str[0] = rand() % 26 + 65;
	str[1] = rand() % 26 + 65;
  str[2] = rand() % 26 + 65;
  tmp.major = str;

  tmp.SSN = std::to_string(i);

  tmp.gpa = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/4));
  testing.push_back(tmp);
  }
  return(testing);
}






int partition_gpa (vector<Student> &vec, int low, int high,size_t &num_compares)
{
    float pivot = vec[high].gpa;    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (vec[j].gpa <= pivot)
        {
            i++;    // increment index of smaller element
            num_compares++;
            swap(vec,i,j);
        }
    }
    num_compares++;
    swap(vec, i + 1,high);
    return (i + 1);
}

int partition_name (vector<Student> &vec, int low, int high,size_t &num_compares)
{
string pivot = vec[high].first_name;    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (vec[j].first_name <= pivot)
        {
            i++;    // increment index of smaller element
            num_compares++;
            swap(vec,i,j);
        }
    }
    num_compares++;
    swap(vec, i + 1,high);
    return (i + 1);
}
 

void quickSort(vector<Student> &vec, int low, int high,size_t &num_compares, int choice)
{
    if (low < high)
    {
      int pi;
       if(choice == 0)
       {
          pi = partition_gpa(vec, low, high,num_compares);
       }
       else
       {
          pi = partition_name(vec, low, high,num_compares);
       }
 
        // Separately sort elements before
        // partition and after partition
        quickSort(vec, low, pi - 1,num_compares, choice);
        quickSort(vec, pi + 1, high,num_compares, choice);
    }
}

void swap(vector<Student>& vec, int x, int y) {
    Student temp = vec[x];
    vec[x] = vec[y];
    vec[y] = temp;

}
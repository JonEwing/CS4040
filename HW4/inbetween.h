#ifndef inbetween_h
#define inbetween_h

#include <vector>
#include <cstdlib>
#include <iostream>
#include <sys/time.h>
#include "student.h"

using namespace std;

vector <Student> inbetweenGPA( vector <Student> list,
const size_t j,
const size_t k,
size_t &num_compares);

vector <Student> inbetweenAlpha(vector <Student> list,
const size_t j,
const size_t k,
size_t &num_compares);

double timeval2sec(const timeval& T);

double timeofday();

vector<Student> generateStudents(size_t num);

void swap(vector<Student>& v, int x, int y);

void quickSort(vector<Student> &vec, int low, int high,size_t &num_compares, int choice);

int partition_gpa (vector<Student> &vec, int low, int high,size_t &num_compares);

int partition_name (vector<Student> &vec, int low, int high,size_t &num_compares);

#endif
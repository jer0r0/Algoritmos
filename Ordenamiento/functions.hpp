#ifndef __FUNCTIONS_HPP
#define __FUNCTIONS_HPP

#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <sys/time.h>
using namespace std;

double gettime();

void generate_vector(int size, vector<int>& v, minstd_rand0& rng);

void generate_ordered_vector(int size, vector<int>& v, minstd_rand0& rng, bool inv);

void generate_norepeat_vector(int size, vector<int>& v, minstd_rand0& rng);

void swap(int i, int j, vector<int>& v);

void print_vector(vector<int>& v);

#endif

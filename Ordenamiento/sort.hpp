#ifndef SORT_HPP
#define SORT_HPP

#include <vector>
#include <iostream>

void max_heapify(std::vector<int> &v,
		 unsigned i, unsigned size);
void heap_sort(std::vector<int> &v);

void merge(std::vector<int> &v, std::vector<int> &aux,
	   unsigned left, unsigned right);
void merge_sort(std::vector<int> &v, std::vector<int> &aux,
	       unsigned left, unsigned right);
void merge_sort(std::vector<int> &v);

unsigned partition(std::vector<int> &v,
		   unsigned left, unsigned right);
void quick_sort(std::vector<int> &v,
		unsigned left, unsigned right);
void quick_sort(std::vector<int> &v);

//**************************************************

void insertion_sort(std::vector<int> &v);
void selection_sort(std::vector<int> &v);
void bubble_sort(std::vector<int> &v);

#endif

#include <iostream>
#include "functions.hpp"
#include "sort.hpp"

int main() {
  int N = 100;
  unsigned sz = 1e3;
  unsigned seed = 123;
  minstd_rand0 rng(seed);

  double tot_time = 0;
  for(int n = 0; n < N; n++){
    std::vector<int> v;
    generate_vector(sz, v, rng);
    //print_vector(v);

    double t1 = gettime();
    bubble_sort(v);
    double t2 = gettime();

    tot_time += t2-t1;
    
    //print_vector(v);
  }

  std::cout << "time: " << tot_time/N << "s\n";
  
  return 0;
}

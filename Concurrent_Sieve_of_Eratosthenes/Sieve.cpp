#include <iostream>
#include <math.h>
#include <typeinfo>

#include "Index.hpp"

using namespace std;

void sieve_worker(Index* index, int base, int max) {
	for (int i = 2 * base; i <= max; i += base) {
		index->remove(i);
	}
}

void foo (void) {
	cout << "foo" << endl;
}

int main(int argc, char** argv) {
	int max = stoi(argv[1]);
	int base_limit = pow(max, 0.5);
	cout << max << endl;

	int nums[max - 1];
	for (int i = 0; i < max - 1; i++) {
		nums[i] = i + 2;
	}
  Index* sieve_data = new Index(nums, max - 2);

	thread sieve_workers[base_limit	+ 1];

	for (int i = 0; i < base_limit + 1; i++) {
		sieve_workers[i] = thread(sieve_worker, sieve_data, i + 2, max - 1);
	}

	for (thread &t : sieve_workers) {
		t.join();
	}

  cout << "  print index forwards:" << endl;
  sieve_data->printIndex('<');

  cout << endl;

  cout << "  print index backwards:" << endl;
  sieve_data->printIndex('>');

  delete(sieve_data);
}

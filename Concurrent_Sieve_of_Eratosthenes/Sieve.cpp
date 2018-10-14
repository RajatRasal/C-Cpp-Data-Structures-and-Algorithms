#include <iostream>
#include <math.h>
#include <thread>

#include "Index.hpp"

using namespace std;

void sieve_worker(Index* index, int base, int max) {
  cerr << "TODO: implement the sieve workers" << endl;
  exit(-1);
}

int main(int argc, char** argv) {
	int max = stoi(argv[1]);
	cout << max << endl;

	int nums[max - 2];

	for (int i = 0; i <= max - 2; i++) {
		nums[i] = i + 2;
	}

	cout << nums << endl;

  Index* sieve_data = new Index(nums, max - 2);

  // TODO: write code here...

  // When all sieve workers have terminated, print out the final state of the index.
  // All of the values that are left in the index must be prime numbers.
  cout << "  print index forwards:" << endl;
  sieve_data->printIndex('<');

  cout << endl;

  cout << "  print index backwards:" << endl;
  sieve_data->printIndex('>');

  delete(sieve_data);
}

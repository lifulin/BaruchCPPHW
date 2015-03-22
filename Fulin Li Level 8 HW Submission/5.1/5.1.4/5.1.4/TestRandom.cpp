// TestRandom.cpp
//
// Test program for random number.
//
// @author Fulin Li
// @version 1.0 12/21/14

#include <boost/random.hpp>
#include <ctime>
#include <map>
#include <iostream>

using namespace std;

void main()
{
	// Throwing dice.
	// Mersenne Twister.
	boost::random::mt19937 myRng;

	// Set the seed.
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));

	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> six(1, 6);

	map<int, long> statistics; // Structure to hold outcome + frequencies
	int outcome;    // Current outcome

	int n = 1000000;
	cout << "How many trials? " << n << endl << endl;

	for (int i = 0; i < n; i++)
	{
		outcome = six(myRng);
		statistics[outcome]++;
	}

	for (int i = 1; i <= 6; i++)
	{
		cout << "Trial " << i << " has " << (double)statistics[i] / (double)n * 100 << "% outcomes" << endl;
		cout << statistics[i] << endl;
	}
}

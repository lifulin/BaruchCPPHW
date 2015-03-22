// TestNormal.cpp
//
// First program test the Boost statistics library.
//
// Look at the Normal distribution because it is important.
// And gamma distribution
//
// 2008-6-27 DD initial code
// 2011-11-9 DD for QN course
// 2014-12-21 Replace with Exponential distribution and Poisson distribution
//
// (C) Datasim Education BV 2009-2011
//

#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/gamma.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	// Exponential distribution
	// Don't forget to tell compiler which namespace
	using namespace boost::math;

	double scaleParameter1 = 0.5;
	// Default type is 'double'
	exponential_distribution<> myExponential1(scaleParameter1);
	cout << "Mean:" << mean(myExponential1)
		<< ",standard deviation: "
		<< standard_deviation(myExponential1) << endl;
	
	// Distributional properties
	double x = 10.25;

	cout << "pdf: " << pdf(myExponential1, x) << endl;
	cout << "cdf: " << cdf(myExponential1, x) << endl;

	float scaleParameter2 = 0.5;
	// Choose another data type
	exponential_distribution<float> myExponential2(scaleParameter2);
	cout << "Mean: " << mean(myExponential2) << ", standard deviation: " 
		<< standard_deviation(myExponential2) << endl;
	cout << "pdf: " << pdf(myExponential2, x) << endl;
	cout << "cdf: " << cdf(myExponential2, x) << endl;

	// Choose precision
	cout.precision(10); // Number of values behind the comma

	// Other properties
	cout << "\n***exponential distribution: \n";
	cout << "mean: " << mean(myExponential1) << endl;
	cout << "variance: " << variance(myExponential1) << endl;
	cout << "median: " << median(myExponential1) << endl;
	cout << "mode: " << mode(myExponential1) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myExponential1) << endl;
	cout << "kurtosis: " << kurtosis(myExponential1) << endl;
	cout << "characteristic function: " << chf(myExponential1, x) << endl;
	cout << "hazard: " << hazard(myExponential1, x) << endl;

	// Poisson distribution
	double mean = 3.0;
	poisson_distribution<double> myPoisson(mean);
	
	double val = 13.0;
	cout << endl << "pdf: " << pdf(myPoisson, val) << endl;
	cout << "cdf: " << cdf(myPoisson, val) << endl;

	vector<double> pdfList;
	vector<double> cdfList;

	double start = 0.0;
	double end = 10.0;
	long N = 30;		// Number of subdivisions

	val = 0.0;
	double h = (end - start) / double(N);

	for (long j = 1; j <= N; ++j)
	{
		pdfList.push_back(pdf(myPoisson, val));
		cdfList.push_back(cdf(myPoisson, val));

		val += h;
	}

	for (long j = 0; j < pdfList.size(); ++j)
	{
		cout << pdfList[j] << ", ";

	}

	cout << "***" << endl;

	for (long j = 0; j < cdfList.size(); ++j)
	{
		cout << cdfList[j] << ", ";

	}

	return 0;
}
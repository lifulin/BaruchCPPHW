// EuropeanOption.cpp
//
// Header file for EuropeanOption class.
//
// @author Fulin Li
// @version 1.0 12/30/14

#include "EuropeanOption.hpp"
#include <boost/math/distributions/normal.hpp>
#include <cmath>
#include <iostream>

using namespace boost::math;
using namespace std;

double EuropeanOption::CallPrice() const
{ // Price of call

	return ::CallPrice(T, K, sig, r, U, b);
}

double EuropeanOption::PutPrice() const
{ // Price of put

	return ::PutPrice(T, K, sig, r, U, b);
}

double EuropeanOption::CallDelta() const
{ // Delta of call

	return ::CallDelta(T, K, sig, r, U, b);
}

double EuropeanOption::PutDelta() const
{ // Delta of put

	return ::PutDelta(T, K, sig, r, U, b);
}

double EuropeanOption::CallGamma() const
{ // Gamma of call

	return ::CallGamma(T, K, sig, r, U, b);
}

double EuropeanOption::PutGamma() const
{ // Gamma of put

	return ::PutGamma(T, K, sig, r, U, b);
}

double EuropeanOption::CallVega() const
{ // Vega of call

	return ::CallVega(T, K, sig, r, U, b);
}

double EuropeanOption::PutVega() const
{ // Vega of put

	return ::PutVega(T, K, sig, r, U, b);
}

double EuropeanOption::CallTheta() const
{ // Theta of call

	return ::CallTheta(T, K, sig, r, U, b);
}

double EuropeanOption::PutTheta() const
{ // Theta of put

	return ::PutTheta(T, K, sig, r, U, b);
}

void EuropeanOption::Init()
{ // Initialise all default values

	Option::Init();
	T = 0.25;
	K = 65;
	sig = 0.30;
	r = 0.08;
	U = 60;
	b = r;
}

void EuropeanOption::Copy(const EuropeanOption& source)
{ // Copy all values

	Option::Copy(source);
	T = source.T;
	K = source.K;
	sig = source.sig;
	r = source.r;
	U = source.U;
	b = source.b;
}

EuropeanOption::EuropeanOption() : Option()
{ // Default constructor

	Init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& source) : Option(source)
{ // Copy constructor

	Copy(source);
}

EuropeanOption::EuropeanOption(const OptionType& newOptionType) : Option(newOptionType)
{ // Constructor with option type
	
	Init();
}

EuropeanOption::EuropeanOption(const struct EuropeanOptionData& optionData) : Option()
{ // Constructor with option data

	Init();
	T = optionData.T;
	K = optionData.K;
	sig = optionData.sig;
	r = optionData.r;
	U = optionData.U;
	b = optionData.b;
}

EuropeanOption::~EuropeanOption()
{ // Destructor
}

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& source)
{ // Assignment operator

	Option::operator = (source);

	if (this == &source)
	{
		return *this;
	}

	Copy(source);

	return *this;
}

double EuropeanOption::CallToPut(double c) const
{ // Use put-call parity to calculate put price

	return c + K * exp(-r * T) - U;
}

double EuropeanOption::PutToCall(double p) const
{ // Use put-call parity to calculate call price

	return p + U - K * exp(-r * T);
}

double EuropeanOption::PriceWithS(double newU) const
{
	if (optionType == Call)
	{
		return ::CallPrice(T, K, sig, r, newU, b);
	}
	else
	{
		return ::PutPrice(T, K, sig, r, newU, b);
	}
}

double EuropeanOption::PriceWithT(double newT) const
{
	if (optionType == Call)
	{
		return ::CallPrice(newT, K, sig, r, U, b);
	}
	else
	{
		return ::PutPrice(newT, K, sig, r, U, b);
	}
}

double EuropeanOption::PriceWithSig(double newSig) const
{
	if (optionType == Call)
	{
		return ::CallPrice(T, K, newSig, r, U, b);
	}
	else
	{
		return ::PutPrice(T, K, newSig, r, U, b);
	}
}

double EuropeanOption::DeltaDiff(double U, double h) const
{
	return (PriceWithS(U + h) - PriceWithS(U - h)) / (2.0 * h);
}

double EuropeanOption::GammaDiff(double U, double h) const
{
	return (PriceWithS(U + h) - 2.0 * PriceWithS(U) + PriceWithS(U - h)) / (h * h);
}

// Global Functions
//vector<double> GenerateMeshArray(double begin, double end, int n)
//{
//	vector<double> vec;
//	double h = (end - begin) / (n - 1);
//	for (int i = 0; i < n; i++)
//	{
//		vec.push_back(begin + h * i);
//	}
//
//	return vec;
//}

Vector<double, long> GenerateMeshArray(double begin, double end, long n)
{
	Vector<double, long> vec(n, 0.0);
	double TMin = begin;
	vec[vec.MinIndex()] = TMin;
	double h = (end - begin) / (n - 1);
	for (long i = vec.MinIndex() + 1; i <= vec.MaxIndex(); i++)
	{
		vec[i] = vec[i - 1] + h;
	}

	return vec;
}

double CallPrice(double T, double K, double sig, double r, double U, double b)
{
	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	double d2 = d1 - tmp;
	normal_distribution<> normalDist(0, 1);

	return (U * exp((b - r) * T) * cdf(normalDist, d1)) - (K * exp(-r * T) * cdf(normalDist, d2));
}

double PutPrice(double T, double K, double sig, double r, double U, double b)
{
	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	double d2 = d1 - tmp;
	normal_distribution<> normalDist(0, 1);

	return (K * exp(-r * T) * cdf(normalDist, -d2)) - (U * exp((b - r) * T) * cdf(normalDist, -d1));
}

double CallDelta(double T, double K, double sig, double r, double U, double b)
{
	normal_distribution<> normalDist(0, 1);
	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	return exp((b - r) * T) * cdf(normalDist, d1);
}

double PutDelta(double T, double K, double sig, double r, double U, double b)
{
	return CallDelta(T, K, sig, r, U, b) - exp((b - r) * T);
}

double CallGamma(double T, double K, double sig, double r, double U, double b)
{
	normal_distribution<> normalDist(0, 1);
	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	return pdf(normalDist, d1) * exp((b - r) * T) / (U * sig * sqrt(T));
}

double PutGamma(double T, double K, double sig, double r, double U, double b)
{
	return CallGamma(T, K, sig, r, U, b);
}

double CallVega(double T, double K, double sig, double r, double U, double b)
{
	normal_distribution<> normalDist(0, 1);
	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	return U * sqrt(T) * exp((b - r) * T) * pdf(normalDist, d1);
}

double PutVega(double T, double K, double sig, double r, double U, double b)
{
	return CallVega(T, K, sig, r, U, b);
}

double CallTheta(double T, double K, double sig, double r, double U, double b)
{
	normal_distribution<> normalDist(0, 1);
	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	double d2 = d1 - tmp;
	return -U * sig * exp((b - r) * T) * pdf(normalDist, d1) / (2 * sqrt(T))
		- (b - r) * U * exp((b - r) * T) * cdf(normalDist, d1) - r * K * exp(-r * T) * cdf(normalDist, d2);
}

double PutTheta(double T, double K, double sig, double r, double U, double b)
{
	return CallTheta(T, K, sig, r, U, b) + r * K * exp(-r * T) + U * exp((b - r) * T) * (b - r);
}
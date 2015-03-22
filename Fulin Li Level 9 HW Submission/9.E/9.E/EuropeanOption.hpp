// EuropeanOption.hpp
//
// Header file for EuropeanOption class.
//
// @author Fulin Li
// @version 1.0 12/30/14

#ifndef EuropeanOption_HPP
#define EuropeanOption_HPP

#include "Option.hpp"
#include <string>
#include <vector>
#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
using namespace std;

class EuropeanOption : public Option
{
private:
	double CallPrice() const; // Price of call
	double PutPrice() const; // Price of put
	double CallDelta() const; // Delta of call
	double PutDelta() const; // Delta of put
	double CallGamma() const; // Gamma of call
	double PutGamma() const; // Gamma of put
	double CallVega() const; // Vega of call
	double PutVega() const; // Vega of put
	double CallTheta() const; // Theta of call
	double PutTheta() const; // Theta of put
	void Init(); // Initialise all default values
	void Copy(const EuropeanOption& source); // Copy all values

public:
	double T; // Expiry time
	double K; // Strike price
	double sig; // volatility
	double r; // Risk free interest rate
	double U; // Current price of the underlying asset
	double b; // Cost of carry
	
public:
	EuropeanOption(); // Default constructor
	EuropeanOption(const EuropeanOption& source); // Copy constructor
	EuropeanOption(const enum OptionType& newOptionType); // Constructor with option type
	EuropeanOption(const struct EuropeanOptionData& optionData); // Constructor with option data
	virtual ~EuropeanOption(); // Destructor

	// Member operator overloading
	EuropeanOption& operator = (const EuropeanOption& source);

	// Additional Functions that calculate option price and sensitivities
	double CallToPut(double c) const; // Use put-call parity to calculate put price
	double PutToCall(double p) const; // Use put-call parity to calculate call price
	double PriceWithS(double newU) const; // Use underlying price as argument
	double PriceWithT(double newT) const; // Use expiry time as argument
	double PriceWithSig(double newSig) const; // Use volatility as argument
	double DeltaDiff(double U, double h) const; // Use divided differences to calculate Delta
	double GammaDiff(double U, double h) const; // Use divided differences to calculate Gamma
};

struct EuropeanOptionData
{
	double T; // Expiry time
	double K; // Strike price
	double sig; // volatility
	double r; // Risk free interest rate
	double U; // Current price of the underlying asset
	double b; // Cost of carry
};

// Global Functions
//vector<double> GenerateMeshArray(double begin, double end, int n);
Vector<double, long> GenerateMeshArray(double begin, double end, long n);
double CallPrice(double T, double K, double sig, double r, double U, double b);
double PutPrice(double T, double K, double sig, double r, double U, double b);
double CallDelta(double T, double K, double sig, double r, double U, double b);
double PutDelta(double T, double K, double sig, double r, double U, double b);
double CallGamma(double T, double K, double sig, double r, double U, double b);
double PutGamma(double T, double K, double sig, double r, double U, double b);
double CallVega(double T, double K, double sig, double r, double U, double b);
double PutVega(double T, double K, double sig, double r, double U, double b);
double CallTheta(double T, double K, double sig, double r, double U, double b);
double PutTheta(double T, double K, double sig, double r, double U, double b);

#endif
// PerpetualAmericanOption.hpp
//
// Header file for PerpetualAmericanOption class.
//
// @author Fulin Li
// @version 1.0 12/30/14

#ifndef PerpetualAmericanOption_HPP
#define PerpetualAmericanOption_HPP

#include "Option.hpp"
#include <string>
#include <vector>
using namespace std;

class PerpetualAmericanOption : public Option
{
private:
	double CallPrice() const; // Price of call
	double PutPrice() const; // Price of put
	void Init(); // Initialise all default values
	void Copy(const PerpetualAmericanOption& source); // Copy all values

public:
	double K; // Strike price
	double sig; // volatility
	double r; // Risk free interest rate
	double U; // Current price of the underlying asset
	double b; // Cost of carry

public:
	PerpetualAmericanOption(); // Default constructor
	PerpetualAmericanOption(const PerpetualAmericanOption& source); // Copy constructor
	PerpetualAmericanOption(const enum OptionType& optionType); // Constructor with option type
	PerpetualAmericanOption(const struct PerpetualAmericanOptionData& optionData); // Constructor with option data
	virtual ~PerpetualAmericanOption(); // Destructor

	// Member operator overloading
	PerpetualAmericanOption& operator = (const PerpetualAmericanOption& source);

	// Functions that calculate option price and sensitivities
	double PriceWithS(double newU) const; // Using underlying price as argument
};

struct PerpetualAmericanOptionData
{
	double K; // Strike price
	double sig; // volatility
	double r; // Risk free interest rate
	double U; // Current price of the underlying asset
	double b; // Cost of carry
};

// Global Functions
vector<double> GenerateMeshArray(double begin, double end, int n);
double PerpetualCall(double K, double sig, double r, double U, double b);
double PerpetualPut(double K, double sig, double r, double U, double b);

#endif
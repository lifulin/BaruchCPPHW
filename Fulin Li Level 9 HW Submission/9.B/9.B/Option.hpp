// Option.hpp
//
// Base class for options.
//
// @author Fulin Li
// @version 1.0 12/30/14

#ifndef Option_HPP
#define Option_HPP

#include <iostream>
using namespace std;

class Option
{
private:
	virtual double CallPrice() const = 0; // Price of call
	virtual double PutPrice() const = 0; // Price of put
	virtual double CallDelta() const; // Delta of call
	virtual double PutDelta() const; // Delta of put
	virtual double CallGamma() const; // Gamma of call
	virtual double PutGamma() const; // Gamma of put
	virtual double CallVega() const; // Vega of call
	virtual double PutVega() const; // Vega of put
	virtual double CallTheta() const; // Theta of call
	virtual double PutTheta() const; // Theta of put

protected:
	virtual void Init(); // Initialise all default values
	virtual void Copy(const Option& source); // Copy all values

public:
	enum OptionType optionType; // Option type, call or put

public:
	Option(); // Default constructor
	Option(const Option& source); // Copy constructor
	Option(const enum OptionType& optionType); // Constructor with option type
	virtual ~Option(); // Destructor

	// Member operator overloading
	Option& operator = (const Option& source);

	// Functions that calculate option price and sensitivities
	double Price() const;
	double Delta() const;
	double Gamma() const;
	double Vega() const;
	double Theta() const;

	// Modifier functions
	void toggle(); // Change option type
};

enum OptionType
{
	Put,
	Call
};

#endif
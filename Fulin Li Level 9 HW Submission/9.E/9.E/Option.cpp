// Option.cpp
//
// Base class for options.
//
// @author Fulin Li
// @version 1.0 12/30/14

#include "Option.hpp"
#include "NoImplementationException.hpp"
#include <iostream>
using namespace std;

double Option::CallDelta() const
{ // Delta of call

	throw NoImplementationException("CallDelta()");
}

double Option::PutDelta() const
{ // Delta of put

	throw NoImplementationException("PutDelta()");
}

double Option::CallGamma() const
{ // Gamma of call

	throw NoImplementationException("CallGamma()");
}

double Option::PutGamma() const
{ // Gamma of put

	throw NoImplementationException("PutGamma()");
}

double Option::CallVega() const
{ // Vega of call

	throw NoImplementationException("CallVega()");
}

double Option::PutVega() const
{ // Vega of put

	throw NoImplementationException("PutVega()");
}

double Option::CallTheta() const
{ // Theta of call

	throw NoImplementationException("CallTheta()");
}

double Option::PutTheta() const
{ // Theta of put

	throw NoImplementationException("PutTheta()");
}

void Option::Init()
{ // Initialise all default values

	optionType = Call;
}

void Option::Copy(const Option& source)
{ // Copy all values

	optionType = source.optionType;
}

Option::Option()
{ // Default constructor

	Init();
}

Option::Option(const Option& source)
{ // Copy constructor

	Copy(source);
}

Option::Option(const enum OptionType& newOptionType)
{ // Constructor with option type

	Init();
	optionType = newOptionType;
}

Option::~Option()
{ // Destructor
}

// Member operator overloading
Option& Option::operator = (const Option& source)
{ // Assignment operator

	if (this == &source)
	{
		return *this;
	}

	Copy(source);

	return *this;
}

// Functions that calculate option prices and sensitivities
double Option::Price() const
{
	if (optionType == Call)
	{
		return CallPrice();
	}
	else
	{
		return PutPrice();
	}
}

double Option::Delta() const
{
	if (optionType == Call)
	{
		return CallDelta();
	}
	else
	{
		return PutDelta();
	}
}

double Option::Gamma() const
{
	if (optionType == Call)
	{
		return CallGamma();
	}
	else
	{
		return PutGamma();
	}
}

double Option::Vega() const
{
	if (optionType == Call)
	{
		return CallVega();
	}
	else
	{
		return PutVega();
	}
}

double Option::Theta() const
{
	if (optionType == Call)
	{
		return CallTheta();
	}
	else
	{
		return PutTheta();
	}
}

// Modifier functions
void Option::toggle()
{// Change option type

	optionType = ((optionType == Call) ? Put : Call);
}
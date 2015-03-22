// TestEuropeanOption.cpp
//
// Test program for the exact solutions of European options.
//
// @author Fulin Li
// @version 1.0 12/30/14

#include "Option.hpp"
#include "PerpetualAmericanOption.hpp"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*
Cost of carry factor b must be included in formulae depending on the
derivative type. These are used in the generalised Black-Scholes formula.
If r is the risk-free interest and q is the continuous dividend yield then
the cost-of-carry b per derivative type is:

a) Black-Scholes (1973) stock option model: b = r
b) b = r - q Merton (1973) stock option model with continuous dividend yield
c) b = 0 Black (1976) futures option model
d) b = r - rf Garman and Kohlhagen (1983) currency option model, where rf is the
'foreign' interest rate
*/

void main()
{
	ofstream fout("output.txt");

	//////////  Option prices  //////////
	double K, sig, r, U, b;
	cout << "K: "; cin >> K;
	cout << "sig: "; cin >> sig;
	cout << "r: "; cin >> r;
	cout << "S: "; cin >> U;
	cout << "b: "; cin >> b;
	
	vector<double> vecU = GenerateMeshArray(10, 50, 41);
	
	// B.b)
	// Use global functions.
	cout << "S = " << U << ", C = " << PerpetualCall(K, sig, r, U, b) << ", P = " << PerpetualPut(K, sig, r, U, b) << endl;
	fout << "S = " << U << ", C = " << PerpetualCall(K, sig, r, U, b) << ", P = " << PerpetualPut(K, sig, r, U, b) << endl;

	// Use instances of PerpetualAmericanOption class.
	PerpetualAmericanOptionData optionData;
	optionData.K = K;
	optionData.sig = sig;
	optionData.r = r;
	optionData.U = U;
	optionData.b = b;
	PerpetualAmericanOption perpetualOption(optionData);
	cout << "S = " << U << ", C = " << perpetualOption.Price() << endl;
	fout << "S = " << U << ", C = " << perpetualOption.Price() << endl;
	perpetualOption.toggle();
	cout << "S = " << U << ", P = " << perpetualOption.Price() << endl;
	fout << "S = " << U << ", P = " << perpetualOption.Price() << endl;
	perpetualOption.toggle();

	// B.c)
	// Compute prices for a range of underlying value
	vector<double> vecC1, vecP1;
	for (int j = 0; j < vecU.size(); j++)
	{
		vecC1.push_back(perpetualOption.PriceWithS(vecU[j]));
		perpetualOption.toggle();
		vecP1.push_back(perpetualOption.PriceWithS(vecU[j]));
		perpetualOption.toggle();
	}

	for (int j = 0; j < vecC1.size(); j++)
	{
		cout << "S = " << vecU[j] << ", C = " << vecC1[j] << ", P = " << vecP1[j] << endl;
		fout << "S = " << vecU[j] << ", C = " << vecC1[j] << ", P = " << vecP1[j] << endl;
	}

	fout << flush;
	fout.close();
}
// TestEuropeanOption.cpp
//
// Test program for the exact solutions of European options and print results in Excel.
//
// @author Fulin Li
// @version 1.0 01/02/15

#include "Option.hpp"
#include "EuropeanOption.hpp"
#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "UtilitiesDJD/ExcelDriver/ExcelMechanisms.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include "UtilitiesDJD/ExceptionClasses/DatasimException.hpp"
#include <cmath>
#include <list>
#include <string>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
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
	double begin = 10.0;
	double end = 50.0;
	int n = 41;

	// Store Batch 1 to Batch 4 data in a vector.
	typedef boost::tuple<double, double, double, double, double> TupleFive;
	vector<TupleFive> vecBatch;
	vecBatch.push_back(boost::make_tuple(0.25, 65, 0.30, 0.08, 60));
	vecBatch.push_back(boost::make_tuple(1.0, 100, 0.2, 0.0, 100));
	vecBatch.push_back(boost::make_tuple(1.0, 10, 0.50, 0.12, 5));
	vecBatch.push_back(boost::make_tuple(30.0, 100.0, 0.30, 0.08, 100.0));

	// Create abscissa S array.
	Vector<double, long> vecU(n, 0.0);
	vecU = GenerateMeshArray(begin, end, n);
	std::list<std::string> labels; // Names of each vector
	std::list<Vector<double, long> > functionResult; // The list of Y values

	//////////  Option prices (stock option, b = r by default)  //////////
	double T, K, sig, r, U, b;
	stringstream ss;
	string str;

	for (int i = 0; i < vecBatch.size(); i++)
	{
		// Add column name.
		ss << i + 1;
		ss >> str;
		labels.push_back("Batch " + str + " Call");
		labels.push_back("Batch " + str + " Put");
		ss.clear();

		T = vecBatch[i].get<0>();
		K = vecBatch[i].get<1>();
		sig = vecBatch[i].get<2>();
		r = vecBatch[i].get<3>();
		U = vecBatch[i].get<4>();
		b = r;

		// Use EuropeanOptionData.
		EuropeanOptionData optionData1;
		optionData1.T = T;
		optionData1.K = K;
		optionData1.sig = sig;
		optionData1.r = r;
		optionData1.U = U;
		optionData1.b = b;
		EuropeanOption option1(optionData1);

		// Store option prices in vectors.
		Vector<double, long> vecC(n, 0.0), vecP(n, 0.0);
		for (int j = 0; j < vecU.Size(); j++)
		{
			vecC[j] = option1.PriceWithS(vecU[j]);
			option1.toggle();
			vecP[j] = option1.PriceWithS(vecU[j]);
			option1.toggle();
		}

		functionResult.push_back(vecC);
		functionResult.push_back(vecP);
	}

	cout << "Data has been created" << endl;

	// Print the results in Excel.
	try
	{
		printInExcel(vecU, labels, functionResult,
			string("Graph in One"), string("Underlying Value"), string("Option Price"));
	}
	catch (DatasimException& e)
	{
		e.print();
	}
}
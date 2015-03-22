// TestEuropeanOption.cpp
//
// Test program for the exact solutions of European options and print results in Excel.
//
// @author Fulin Li
// @version 1.0 01/02/15

#ifndef max
#define max(a, b) (a > b) ? (a) : (b)
#endif

#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "UtilitiesDJD/ExcelDriver/ExcelMechanisms.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include "UtilitiesDJD/ExceptionClasses/DatasimException.hpp"
#include "FdmDirector.hpp"
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

enum OptionType
{
	Put,
	Call
};

namespace BS // Black Scholes
{
	double sig = 0.3;
	double K = 65.0;
	double T = 0.25;
	double r = 0.08;
	double D = 0.0;
	double Smax = 5.0 * K;
	enum OptionType Type = Call;

	double mySigma(double x, double t)
	{
		double sigmaS = sig * sig;
		return 0.5 * sigmaS * x * x;
	}

	double myMu(double x, double t)
	{
		return (r - D) * x;
	}

	double myB(double x, double t)
	{
		return -r;
	}

	double myF(double x, double t)
	{
		return 0.0;
	}

	double myBCL(double t)
	{
		if (Type == Call)
		{
			return 0.0;
		}
		else
		{
			return K * exp(-r * t);
		}
	}

	double myBCR(double t)
	{
		if (Type == Call)
		{
			return Smax;
		}
		else
		{
			return 0.0;
		}
	}

	double myIC(double x)
	{ // Payoff 

		if (Type == Call)
		{
			return max(x - K, 0.0);
		}
		else
		{
			return max(K - x, 0.0);
		}
	}
}

void main()
{
	// Store Batch 1 to Batch 4 data in a vector.
	typedef boost::tuple<double, double, double, double, double> TupleFive;
	vector<TupleFive> vecBatch;
	vecBatch.push_back(boost::make_tuple(0.25, 65, 0.30, 0.08, 0.0));
	vecBatch.push_back(boost::make_tuple(1.0, 100, 0.2, 0.0, 0.0));
	vecBatch.push_back(boost::make_tuple(1.0, 10, 0.50, 0.12, 0.0));
	vecBatch.push_back(boost::make_tuple(30.0, 100.0, 0.30, 0.08, 0.0));
	// Name of each column.
	stringstream ss;
	string str;
	// The list of option price vectors.
	
	using namespace ParabolicIBVP;

	// Assignment of functions
	sigma = BS::mySigma;
	mu = BS::myMu;
	b = BS::myB;
	f = BS::myF;
	BCL = BS::myBCL;
	BCR = BS::myBCR;
	IC = BS::myIC;
	
	//int J = 5.0 * BS::K;
	int J = 50;
	//int N = 100000; // k = O(h^2)
	int N = 5000;
	double Smax = 50;

	for (int i = 0; i < vecBatch.size(); i++)
	{
		cout << "Batch " << i + 1 << ", start FDM" << endl;
		ss << i + 1;
		ss >> str;
		ss.clear();
		std::list<std::string> labels;
		labels.push_back("Batch " + str + " Call");
		labels.push_back("Batch " + str + " Put");
		std::list<Vector<double, long > > functionResult;
		
		// Load parameter value of the batch.
		BS::T = vecBatch[i].get<0>();
		BS::K = vecBatch[i].get<1>();
		BS::sig = vecBatch[i].get<2>();
		BS::r = vecBatch[i].get<3>();
		BS::D = vecBatch[i].get<4>();
		//BS::Smax = 5 * BS::K;
		BS::Smax = Smax;
		BS::Type = Call;

		// Calculate call option price.
		FDMDirector fdirCall(BS::Smax, BS::T, J, N);
		fdirCall.doit();
		functionResult.push_back(fdirCall.current());
		
		// Calculate put option price.
		BS::Type = Put;
		FDMDirector fdirPut(BS::Smax, BS::T, J, N);
		fdirPut.doit();
		functionResult.push_back(fdirPut.current());
		
		// Print the results in Excel.
		try
		{
			printInExcel(fdirCall.xarr, labels, functionResult,
				string("Graph of Batch " + str), string("Underlying Value"), string("Option Price"));
		}
		catch (DatasimException& e)
		{
			e.print();
		}

		cout << "Batch " << i + 1 << ", finished" << endl;
	}
}

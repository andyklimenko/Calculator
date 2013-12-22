#include <iostream>
#include "BinaryOperation.h"
#include <math.h>
#include <string>
IBinaryOperation::IBinaryOperation(void)
{
}


IBinaryOperation::~IBinaryOperation(void)
{
}


Add::Add(void)
{
}


Add::~Add(void)
{
}

double Add::Calculate(double a, double b)
{
	return a+b;
}


Substract::Substract(void)
{
}


Substract::~Substract(void)
{
}

double Substract::Calculate(double a, double b)
{
	return a-b;
}
Mult::Mult(void)
{
}


Mult::~Mult(void)
{
}

double Mult::Calculate(double a, double b)
{
	return a*b;
}
Div::Div(void)
{
}


Div::~Div(void)
{
}

double Div::Calculate(double a, double b)
{
	if(b!=0)
	{
		return a/b;
	}
	else
	{
		return 0;
	}
}
Pow::Pow(void)
{
}


Pow::~Pow(void)
{
}

double Pow::powRecurs(double a, double b) // should be private member
// I don't know what i must do with it
{
	if(b==0) 
	{
		return 1;
	}
	else
	{
		return Pow::powRecurs(a,b-1)*a;
	}
}

double Pow::Calculate(double a, double b)
{
	if(b>=1)
	{
		return Pow::powRecurs(a,b);
	}
}


Sqrt::Sqrt(void)
{
}


Sqrt::~Sqrt(void)
{
}

double Pow::sqrtRecurs(double a, double degree, double xk, double accuracy)
{
	double xIncremented = 1.0 / degree * (((degree - 1) * xk) + (a / powRecurs(xk, degree - 1)));
    double res = xIncremented;
	if(fabs(xIncremented - xk) > accuracy)
	{
		res = sqrtRecurs(a, degree, xIncremented, accuracy);
    }
    return res;
}

double Sqrt::Calculate(double a, double b)
{
	if(b>=1)
	{
		double x0 = 1;
		double accuracy = 0.001;
		return sqrtRecurs(a, b, x0, accuracy);
	}
	return 0;
}

IBinaryOperation* createBinaryOperation(const std::string& op)
{
	IBinaryOperation* res = NULL;
	if (op == "+")
	{
		res = new Add();
	}
	else if (op == "-")
	{
		res = new Substract();	
	}
	else if (op == "*")
	{
		res = new Mult();	
	}
	else if (op == "/")
	{
		res = new Div();	
	}
	else if (op == "pow")
	{
		res = new Pow();	
	}
	else if (op == "sqrt")
	{
		res = new Sqrt();	
	}
	return res;
}

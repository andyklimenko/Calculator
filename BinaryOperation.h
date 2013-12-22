#pragma once
class IBinaryOperation
{
public:
	IBinaryOperation(void);
	virtual ~IBinaryOperation(void); // should be virtual

	virtual double Calculate(double a, double b) = 0;
};

class Add: public IBinaryOperation
{
public:
	Add();
	virtual ~Add();
	virtual double Calculate(double a, double b);
};

class Substract: public IBinaryOperation
{
public:
	Substract();
	virtual ~Substract();
	virtual double Calculate(double a, double b);
};

class Mult: public IBinaryOperation
{
public:
	Mult();
	virtual ~Mult();
	virtual double Calculate(double a, double b);
};

class Div: public IBinaryOperation
{
public:
	Div();
	virtual ~Div();
	virtual double Calculate(double a, double b);
};

class Pow: public IBinaryOperation
{
public:
	Pow();
	virtual ~Pow();
	virtual double Calculate(double a, double b);
	
protected:
	double powRecurs(double a, double b);
	double sqrtRecurs(double a, double degree, double xk, double accuracy);
};

class Sqrt: public Pow
{
public:
	Sqrt();
	virtual ~Sqrt();
	virtual double Calculate(double a, double b);
};


IBinaryOperation* createBinaryOperation(const std::string& op);

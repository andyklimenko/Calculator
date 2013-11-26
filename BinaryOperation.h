#pragma once
class IBinaryOperation
{
public:
	IBinaryOperation(void);
	~IBinaryOperation(void); // should be virtual

	virtual double Calculate(double a, double b) = 0;
};

class Add: public IBinaryOperation
{
public:
	Add();
	~Add();
	virtual double Calculate(double a, double b);
};

class Substract: public IBinaryOperation
{
public:
	Substract();
	~Substract();
	virtual double Calculate(double a, double b);
};

class Mult: public IBinaryOperation
{
public:
	Mult();
	~Mult();
	virtual double Calculate(double a, double b);
};

class Div: public IBinaryOperation
{
public:
	Div();
	~Div();
	virtual double Calculate(double a, double b);
};

class Pow: public IBinaryOperation
{
public:
	Pow();
	~Pow();
	virtual double Calculate(double a, double b);
};

class Sqrt: public IBinaryOperation
{
public:
	Sqrt();
	~Sqrt();
	virtual double Calculate(double a, double b);
};


IBinaryOperation* createBinaryOperation(std::string op);

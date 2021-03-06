// 12345.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <math.h>
#include <stdexcept>
#include <auto_ptr.h>
#include "BinaryOperation.h"

template<typename T>
T StringToNumber(const std::string& numberAsString)
{
	T valor;

	std::stringstream stream(numberAsString);
	stream >> valor;
	if (stream.fail())
	{
		throw std::runtime_error(numberAsString);
	}
	return valor;
}

void parse(std::string& str)
{
	std::auto_ptr<IBinaryOperation> op;
	std::string numStr1;	
	int lastPosNum1=0;
	std::string binOp;
	std::string sqrOp;
	for(size_t i=0; i<str.size(); ++i)
	{
		if(!isspace(str[i]))
		{
			if(str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/')
			{
				if (isdigit(str[i]) || str[i]=='.')
				{
					numStr1 += str[i];
					lastPosNum1 = i;
				}
				else if(str[i]!='(' && str[i]!=',')
				{
					binOp += str[i];	
				}
				
				else if(str[i]==',')
				{
					op.reset(createBinaryOperation(binOp));
					break;
				}
				else if(str[i]=='(')
				{
					
				}
			}
			else if (NULL == op.get())
			{
				binOp += str[i];
				op.reset(createBinaryOperation(binOp));
				break;
			}
			

		}
		//op = createBinaryOperation(sqrOp);
	}

	if (!op.get())
	{
		return;
	}

	double num1 = StringToNumber<double>(numStr1);
	std::string numStr2;	
	//int lastPosNum2=0;
	for(size_t j=lastPosNum1+1; j<str.size(); ++j)
	{
		if(str[j] != ' ' && str[j] != ')')
		{
			if (isdigit(str[j]) || str[j]=='.')
			{
				numStr2 += str[j];
			}
		}
		else if(!numStr2.empty())
		{
			break;
		}
	}

	double num2 = StringToNumber<double>(numStr2);
	double res = op->Calculate(num1, num2);

	std::cout << "Res : " << res << std::endl;
}

int main()
{
	std::string s = " sqrt( 9 , 4 )";
	std::cout << s << std::endl;
	parse(s);
	
	//return 0;
}


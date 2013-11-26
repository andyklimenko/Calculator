// 12345.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <math.h>
#include "BinaryOperation.h"

void parse(std::string& str)
{
	IBinaryOperation *op = NULL;
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
					op = createBinaryOperation(binOp);
					break;
				}
				else if(str[i]=='(')
				{
					
				}
			}
			else if (NULL == op)
			{
				binOp += str[i];
				op = createBinaryOperation(binOp);
				break;
			}
			

		}
	
		
				
		//op = createBinaryOperation(sqrOp);
	}

	if (!op)
	{
		return;
	}

	double num1 = atof(numStr1.c_str());
	std::string numStr2;	
	int lastPosNum2=0;
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

	double num2 = atof(numStr2.c_str());
	double res;
	
	res = op->Calculate(num1, num2);

	std::cout << "Res : " << res << std::endl;
	
}

int main()
{
	std::string s = " pow( 9 , 4 )";
	std::cout << s << std::endl;
	parse(std::string(s));
	
	//return 0;
}


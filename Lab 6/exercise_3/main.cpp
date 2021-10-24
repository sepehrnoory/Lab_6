#include <iostream>
#include <string>

int recFib(int i)
{
	if(i == 0)
	{
		return(0);
	}
	else if(i == 1)
	{
		return(1);
	}
	else if(i < 0)
	{
		throw(std::runtime_error("Invalid 'i' value, please try again\n"));
	}
	else
	{
		return(recFib(i-1) + recFib(i-2));
	}
}

bool isIncluded(int checkValue)
{
	int value = 0;
	int i = 0;
	bool verify = false;
	while(value < checkValue)
	{
		value = recFib(i);
		if(value == checkValue)
		{
			verify = true;
		}
		i++;
	}
	if(verify)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

int main(int argc, char* argv[])
{
	if(argc == 3)
	{
		std::string ith = "-i";
		std::string ver = "-v";
		if(argv[1] == ith)
		{
			int value = 0;
			value = std::stoi(argv[2]);
			int fibValue = recFib(value);
			std::cout << fibValue << '\n';
		}
		else if(argv[1] == ver)
		{
			int check = 0;
			check = std::stoi(argv[2]);
			bool verify = isIncluded(check);
			
			if(verify)
			{
				std::cout << check << " is in the sequence\n";
			}
			else
			{
				std::cout << check << " is not in the sequence\n";
			}
		}
	}
	else
	{
		std::cout << "Invalid number of arguments\n";
		std::cout << "\tPlease use -i or -v followed by an integer to run this program\n";
	}
	return(0);
}
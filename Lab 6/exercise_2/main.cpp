#include <iostream>

int recOutbreak(int days)
{
	if(days < 1)
	{
		throw(std::runtime_error("Invalid Day"));
	}
	else if(days == 1)
	{
		return(1);
	}
	else if(days == 2)
	{
		return(8);
	}
	else if(days == 3)
	{
		return(22);
	}
	else
	{
		return(recOutbreak(days-1) + recOutbreak(days-2) + recOutbreak(days-3));
	}
}

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		int userDay = 0;
		int sickCount = 0;
		std::cout << "OUTBREAK!\n";
		
		std::cout << "What day do you want a sick count for?: ";
		std::cin >> userDay;
		try
		{
			sickCount = recOutbreak(userDay);
			std::cout << "Total people with flu: " << sickCount << '\n';
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	else
	{
		std::cout << "Sorry, this program does not take any input files, please try again\n";
	}
	
	return(0);
}
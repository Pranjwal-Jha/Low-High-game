#include <iostream>
#include <random>
#include "random.h"
#include <string>
#include <cassert>
#include <limits>

void clearfunction()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}
int inputfunction(int i)
{
	int userinputforgame{};
tryagain2:
	std::cout << "Guess #" << i << ": ";
	std::cin >> userinputforgame;
	
	if (std::cin.fail())
	{
		std::cin.clear();
		clearfunction();
		goto tryagain2;

	}
	else
	{
		clearfunction();

	}
	return userinputforgame;
}

int main()
{
	std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is." << '\n';
	char userinput2{};
	do
	{
		std::uniform_int_distribution numbers{1, 100};
		int KJ{ numbers(random::mt) };

		for (int i{ 1 }; i <= 7; ++i)
		{
			int userinput{ inputfunction(i) };
			#ifdef JHA
			int userinput{};
			std::cout << "Guess #" << i << ": ";
			std::cin >> userinput;
			#endif

			if (userinput == KJ)
			{
				std::cout << "Correct! You win!" << '\n';
				goto end;
			}
			else if (userinput > KJ)
			{
				std::cout << "Your guess is too high." << '\n';
			}
			else
			{
				std::cout << "Your guess is too low." << '\n';
			}
		}

		std::cout << "Sorry, you lose. The correct number was " << KJ << '\n';
	end:
	askagain:

		std::cout << "Would you like to play again (y/n)? : ";
		std::cin >> userinput2;
		#ifdef logicgate
		#define logicgate
		std::cout << "your input is : " << userinput2 << '\n';
		#endif
		if (!(userinput2 == 'y' || userinput2 == 'n'))
			goto askagain;
	    if (userinput2 == 'n')
			break;
	}
	while (userinput2 == 'y');


	#ifdef fuckyou
	std::uniform_int_distribution numbers{1, 100};
	int KJ{ numbers(random::mt) };

	for (int i{ 1 }; i <= 7; ++i)
	{
		int userinput{};
		std::cout << "Guess #" << i << ": ";
		std::cin >> userinput;

		if (userinput == KJ)
		{
			std::cout << "Correct! You win!";
			goto end;
		}
		else if (userinput > KJ)
		{
			std::cout << "Your guess is too high." << '\n';
		}
		else
		{
			std::cout << "Your guess is too low." << '\n';
		}
	}

	std::cout << "Sorry, you lose. The correct number was " << KJ << '\n';
end:
	#endif

	std::cin.get();



}

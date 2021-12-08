#include "Utils.h"
#include <stdlib.h>
#include <time.h>
/*If seed is not given it will seed using time which is typically what you will want to use.*/
Utilities::RandomGenerator::RandomGenerator(unsigned int seed)
{
	srand(seed);
}
Utilities::RandomGenerator::RandomGenerator()
{
	srand(time(NULL));
}
/*Gets a random number thats 0 or 1*/
bool Utilities::RandomGenerator::coinflip()
{
	int random = rand() % 2;
	return random;
}
int Utilities::RandomGenerator::generateint(int range)
{
	int num = rand() % range;
	return num;
}
Utilities::RandomGenerator::~RandomGenerator()
{
}

int Utilities::getwidth()
{
	return 1200;
}

int Utilities::getheight()
{
	return 600;
}

int Utilities::getscreenwidth()
{
	return 900;
}

int Utilities::getscreenheight()
{
	return 600;
}

#pragma once
namespace Utilities {
	int getwidth();
	int getheight();
	class RandomGenerator {
	public:
		RandomGenerator(unsigned int seed);
		RandomGenerator();
		~RandomGenerator();
		bool coinflip();
		int generateint(int range);
	};
}

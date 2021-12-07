#pragma once
namespace Utilities {
	class RandomGenerator {
	public:
		RandomGenerator(unsigned int seed);
		RandomGenerator();
		~RandomGenerator();
		bool coinflip();
		int generateint(int range);
	};
}

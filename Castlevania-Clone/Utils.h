#pragma once
namespace Utilities {
	int getwidth();
	int getheight();
	int lvlwidth();
	int lvlheight();
	int getscreenwidth();
	int getscreenheight();
	class RandomGenerator {
	public:
		RandomGenerator(unsigned int seed);
		RandomGenerator();
		~RandomGenerator();
		bool coinflip();
		int generateint(int range);
	};
}

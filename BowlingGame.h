#pragma once
#include<vector>


class BowlingGame
{
public:
	void roll(int pins) 
	{
		rolls.emplace_back(pins);
	}
	int getScore() 
	{
		int score = 0;
		bool isSecondRollInFrame = false;
		int numberOfFrame = 1;
		for (auto roll = rolls.begin(); roll != rolls.end(); roll++)
		{			
			score += *roll;
			if(numberOfFrame < 10)
			{
				if(!isSecondRollInFrame)
				{
					if(*roll == 10)
					{
						if(std::next(roll) != rolls.end())
							score += *std::next(roll);
						if(std::next(roll, 2) < rolls.end())
							score += *std::next(roll, 2);
						isSecondRollInFrame = false;
						numberOfFrame++; 
					}
					else
						isSecondRollInFrame = true;
				}
				else 
				{
					if (*roll + *std::prev(roll) == 10)
					{
						if(std::next(roll) != rolls.end())
							score += *std::next(roll);
					}
					isSecondRollInFrame = false;
					numberOfFrame++;
				}
			}		
		} 
		return score;
	}
private:
	std::vector<int> rolls;
};

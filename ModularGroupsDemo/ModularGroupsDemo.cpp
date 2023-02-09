// ModularGroupsDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

typedef long long int llint;

llint ggd(llint l, llint r)
{
	if (l % r == 0)
		return r;

	if (l < r)
		return ggd(r % l, l);
	return ggd(l % r, r);
}

int main()
{
	for (llint i = 10ull; i < 20ull; i++)
	{
		std::cout << "Group mod " << i << std::endl;
		std::vector<llint> group;
		for (llint j = 1ull; j < i; j++)
		{
			if (ggd(i, j) == 1)
			{
				std::cout << j << std::endl;
				group.push_back(j);
			}
		}
		std::cout << "End of group mod " << i << std::endl << std::endl;
		for (int it = 0; it < group.size(); it++)
		{
			std::cout << "Subgroup starting with " << group[it] << std::endl;
			std::cout << group[it] << " ";
			llint result = (group[it] * group[it]) % i;
			int count = 1;
			while (result != 1ull)
			{
				std::cout << result << " ";
				result = (result * group[it]) % i;
				count++;
			}
			if (group[it] != 1)
			{
				std::cout << result << " ";
				count++;
			}
			std::cout << std::endl << "Number of elements in subgroup: " << count << std::endl;
		}
		std::cout << "A straight line y=1/3x in P19" << std::endl;
		std::vector<llint> group19;
		for (llint j = 1ull; j < 19; j++)
		{
			if (ggd(19, j) == 1)
			{
//				std::cout << j << std::endl;
				group19.push_back(j);
			}
		}
		for (llint x = 1; x < 19; x++)
		{
			llint y = x * 13 % 19;
			std::cout << "(" << x << "," << y << ")" << std::endl;
		}
	}
}


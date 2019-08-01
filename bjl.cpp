#include "stdafx.h"
#include <iostream>
#include <random>
#include <array>
#include <vector>
#include <map>

int main()
{
	const int n = 1024 * 1024 * 128;
	std::cout << "下注" << n << "次" << std::endl;

	std::random_device rd;
	std::mt19937 generator(rd());
//	std::default_random_engine generator;
	std::bernoulli_distribution distribution(0.507);

	std::vector<bool> vec(n, false);
	int count = 0;  // count number of trues
	for (int i = 0; i < n; ++i)
	{
		bool b = distribution(generator);
		vec[i] = b;
		if (b)
			++count;
	}

	std::cout << "庄: " << count << "	" << ((float)count / n) << std::endl;
	std::cout << "闲: " << n - count << "	" << ((float)(n - count) / n) << std::endl << std::endl;

	int over6Sum = 0;
	std::map<int, int> over6MapCount;
	std::vector<int> over6Index;
	for (int i = 0; i < n; ++i)
	{
		if (!vec[i])
			continue;

		int j = i;
		for (; j < n; j++)
			if (!vec[j])
				break;

		if (j - i >= 6)
		{
			over6Sum++;
			over6Index.push_back(i);
			over6MapCount[j - i] = over6MapCount[j - i] + 1;
//			std::cout << "从:" << i << "	连续:" << j - i << std::endl;
		}
		i = j;
	}

	std::cout << "连输6次以上总共:" << over6Sum << std::endl;
	for (auto p : over6MapCount)
		std::cout << "连输:" << p.first << "		共:" << p.second << std::endl;

	std::cout << std::endl;
	//std::map<int, int> indexMapCount;
	//for (int i = 0; i < over6Index.size() - 1; ++i)
	//{
	//	int distance = over6Index[i + 1] - over6Index[i];
	//	indexMapCount[distance] = indexMapCount[distance] + 1;
	//}
	//for (auto p : indexMapCount)
	//{
	//	std::cout << "间隔:" << p.first << "  	次数:" << p.second << std::endl;		
	//}

	int sum = 0;
	int sum70 = 0, sum71 = 0, sum72 = 0, sum73 = 0, sum74 = 0, sum20 = 0, sum30 = 0, sum40 = 0, sum50 = 0, sum60 = 0;
	//std::cout << "间隔72的6连庄" << std::endl;
	for (int i = 0; i < over6Index.size() - 1; ++i)
	{
		if (over6Index[i] % 72 == 0)
		{
			sum++;
			int distance = over6Index[i + 1] - over6Index[i];
			switch (distance)
			{
			case 20:sum20++; break;
			case 30:sum30++; break;
			case 40:sum40++; break;
			case 50:sum50++; break;
			case 60:sum60++; break;
			case 70:sum70++; break;
			case 71:sum71++; break;
			case 72:sum72++; break;
			case 73:sum73++; break;
			case 74:sum74++; break;
			default: break;
			}
		}
	}
	std::cout << "开头6连庄:" << sum << std::endl;
	std::cout << "开头6连庄，后20:" << sum20 << std::endl;
	std::cout << "开头6连庄，后30:" << sum30 << std::endl;
	std::cout << "开头6连庄，后40:" << sum40 << std::endl;
	std::cout << "开头6连庄，后50:" << sum50 << std::endl;
	std::cout << "开头6连庄，后60:" << sum60 << std::endl;
	std::cout << "开头6连庄，后70:" << sum70 << std::endl;
	std::cout << "开头6连庄，后71:" << sum71 << std::endl;
	std::cout << "开头6连庄，后72:" << sum72 << std::endl;
	std::cout << "开头6连庄，后73:" << sum73 << std::endl;
	std::cout << "开头6连庄，后74:" << sum74 << std::endl;

	std::cin >> sum;
	return 0;
}

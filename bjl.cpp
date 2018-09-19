#include "stdafx.h"
#include <iostream>
#include <random>
#include <array>
#include <vector>
#include <map>

int main()
{
	const int n = 1024 * 1024 * 1024;
	std::cout << "��ע" << n << "��" << std::endl;

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

	std::cout << "ׯ: " << count << "	" << ((float)count / n) << std::endl;
	std::cout << "��: " << n - count << "	" << ((float)(n - count) / n) << std::endl << std::endl;

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
//			std::cout << "��:" << i << "	����:" << j - i << std::endl;
		}
		i = j;
	}

	std::cout << "����6�������ܹ�:" << over6Sum << std::endl;
	for (auto p : over6MapCount)
		std::cout << "����:" << p.first << "		��:" << p.second << std::endl;

	std::cout << std::endl;
	//std::map<int, int> indexMapCount;
	//for (int i = 0; i < over6Index.size() - 1; ++i)
	//{
	//	int distance = over6Index[i + 1] - over6Index[i];
	//	indexMapCount[distance] = indexMapCount[distance] + 1;
	//}
	//for (auto p : indexMapCount)
	//{
	//	std::cout << "���:" << p.first << "  	����:" << p.second << std::endl;		
	//}

	int sum = 0;
	int sum2 = 0;
	int sum3 = 0;
	//std::cout << "���72��6��ׯ" << std::endl;
	for (int i = 0; i < over6Index.size() - 1; ++i)
	{
		if (over6Index[i] % 72 == 0)
			sum3++;

		int distance = over6Index[i + 1] - over6Index[i];
		if (distance == 72)
		{
			sum++;
			//std::cout << over6Index[i] << "  :" << over6Index[i + 1] << std::endl;
			if (over6Index[i] % 72 == 0)
			{
				sum2++;
				//std::cout << over6Index[i] << "  :" << over6Index[i + 1] << std::endl;
			}
		}
	}
	std::cout << "���72��6��ׯ����:" << sum << std::endl;
	std::cout << "��ͷ6��ׯ����������:" << sum2 << std::endl;
	std::cout << "��ͷ6��ׯ:" << sum3 << std::endl;

	std::cin >> sum;
	return 0;
}

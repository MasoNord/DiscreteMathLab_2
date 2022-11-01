#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

// ------------------ Second task ----------------- 

bool function(int x, int y);

// ------------------------------------------------

// ------------------ Second task -----------------

bool Injective(int x, int y);
bool Surjective(int x, int y);
bool Bijective(int x, int y);

// ------------------------------------------------

void OutputVector(std::vector<std::vector<int>> array);
void OutputSimpleVector(std::vector<int> array);

void First(std::vector<int> A, std::vector<int> B)
{
	std::vector<std::vector<int>> result;
	int SurCount = 0;
	int size_A = A.size();
	int size_B = B.size();
	int count = 0;
	std::vector<int> temp;
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 0; i < size_A; i++)
	{
		for (int j = 0; j < size_B; j++)
		{
			if((function(A[i], B[j]) == true))
			{
				temp.push_back(A[i]);
				temp.push_back(B[j]);
					
				result.push_back(temp);
				count++;
				temp.erase(temp.begin(), temp.end());
			}
		}
	}
	
	OutputVector(result);
	
	if (size_A < size_B)
	{
		if (count == A.size())
			std::cout << "f: A -> B true\n";
		else
			std::cout << "f: A -> B false\n";
	}
	else if(size_A > size_B)
	{
		for (int i = 0, j = 1; j < result.size(); j++)
		{
			if (result[i][1] == result[j][1])
				SurCount++;
		}

		if (count == A.size() && SurCount >= 1)
			std::cout << "\nf: A -> B true\n";
		else
			std::cout << "f: A -> B false\n";
	}

}

void Second(std::vector<int> A, std::vector<int> B)
{
	std::vector<std::vector<int>> result;
	int size_A = A.size();
	int size_B = B.size();
	int count = 0;
	int SurCount = 0;
	short answer = 0;
	std::vector<int> temp;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	std::cout << "Enter function (1, 2, 3): ";
	std::cin >> answer;
	switch (answer)
	{
	case 1: // Injective
		std::cout << "f(x) = 5x\n";
		
		for (int i = 0; i < size_A; i++)
		{
			for (int j = 0; j < size_B; j++)
			{
				if (Injective(A[i], B[j]) == true)
				{
					temp.push_back(A[i]);
					temp.push_back(B[j]);

					result.push_back(temp);
					count++;
					temp.erase(temp.begin(), temp.end());
				}
			}
		}
		if (count == A.size())
			std::cout << "f: A -> B is injective\n";
		else
			std::cout << "f: A -> B is not injective\n";
		
		OutputVector(result);
		
		result.clear();
		count = 0;
		break;
	case 2: // Surjective
		std::cout << "f(x) =  x * x - 1\n";
		for (int i = 0; i < size_A; i++)
		{
			for (int j = 0; j < size_B; j++)
			{
				if (Surjective(A[i], B[j]) == true)
				{
					temp.push_back(A[i]);
					temp.push_back(B[j]);

					count++;
					result.push_back(temp);
					temp.erase(temp.begin(), temp.end());
				}
			}
		}

		for (int i = 0, j = 1; j < result.size(); j++)
		{
			if (result[i][1] == result[j][1])
				SurCount++;
		}

		if (count == A.size() && SurCount >= 1)
			std::cout << "\nf: A -> B is Surjective\n";
		else
			std::cout << "f: A -> B is not Surjective\n";

		OutputVector(result);

		count = 0;
		result.clear();
		break;
	case 3: // Bijective
		std::cout << "f(x) = 2x - 3\n";

		for (int i = 0; i < size_A; i++)
		{
			for (int j = 0; j < size_B; j++)
			{
				if (Bijective(A[i], B[j]) == true)
				{
					temp.push_back(A[i]);
					temp.push_back(B[j]);

					result.push_back(temp);
					count++;
					temp.erase(temp.begin(), temp.end());
				}
			}
		}

		if (count == A.size() && count == B.size())
			std::cout << "f: A -> B is Bijective\n";
		else
			std::cout << "f: A -> B is not Bijective\n";

		OutputVector(result);

		count = 0;
		result.clear();
		break;
	default:

		break;
	}

}
// Start:
// First task
bool function(int x, int y)
{
	// f(x) = x * x;

	if ((x * x) == y )
		return true;
}
// The end

// Start:
// Second task
bool Injective(int x, int y)
{
	// f(x) = 5x
	if ((5 * x) == y)
		return true;
}

bool Surjective(int x, int y)
{
	// f(x) =  x * x + 1
	if (((x * x) + 1) == y)
		return true;
}

bool Bijective(int x, int y)
{
	// f(x) = 2x - 3
	if ((2 * x - 3) == y)
		return true;
}
// The end
void OutputVector(std::vector<std::vector<int>> array)
{
	std::cout << "{\n";
	for (int i = 0; i < array.size(); i++)
	{
		std::cout << "( ";
		for (int j = 0; j < array[i].size(); j++)
			std::cout << array[i][j] << " ";
		std::cout << ")\n";
	}
	std::cout << "}\n";
}

void OutputSimpleVector(std::vector<int> array)
{
	std::cout << "{ ";
	for (int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << "}\n";
}
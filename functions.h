#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <Windows.h>

// In 1,3,4 tasks I made 2 "copy", when A was bigger then B and reverse
// This was made by me for predicting exceptions, when our programm calls an unexistable element

// ---------------- Was created for output a values of arrays ---------------- //

void Out_Multiply_Vector(std::vector<std::vector<int>> out) 
{
	std::cout << "\n{\n";
	for (int i = 0; i < out.size(); i++)
	{
		std::cout << "( ";
		for (int j = 0; j < out[i].size(); j++)
			std::cout << out[i][j] << " ";
		std::cout << ")\n";
	}

	std::cout << "}\n";
} 
void Out_Vector(std::vector<int> a)
{
	std::cout << "{ ";
	for(int o = 0; o < a.size(); o++)
	{
		std::cout << a[o] << " ";
	}
	std::cout << "}\n";
}
// --------------------------------------------------------------------------- //

// -------------------- This function use for second task -------------------- //

void Subset(std::vector <int>& mainV, std::vector<std::vector<int>> &res,
	std::vector <int>& subset, int index)
{
	res.push_back(subset);
	
	for (int i = index; i < mainV.size(); i++)
	{
		subset.push_back(mainV[i]);

		Subset(mainV, res, subset, i + 1);

		subset.pop_back();
	}
}

// --------------------------------------------------------------------------- //

// -------------------- This function use for fourth task -------------------- //

std::vector<int> Union(std::vector<int> A, std::vector<int> B, int size_A, int size_B,
	std::vector <int> &result)
{
	int i = 0;
	
	if (size_A > size_B)
	{
		for (i = 0; i < size_B; i++)
		{
			if (std::count(B.begin(), B.end(), A[i]))
				result.push_back(A[i]);
			else
			{
				result.push_back(A[i]);
				result.push_back(B[i]);
			}
		}
		for (; i < size_A; i++)
			result.push_back(A[i]);
	}
	else if (size_A < size_B)
	{
		for (i = 0; i < size_A; i++)
		{
			if (std::count(A.begin(), A.end(), B[i]))
				result.push_back(A[i]);
			else
			{
				result.push_back(A[i]);
				result.push_back(B[i]);
			}
		}
		for (i; i < size_B; i++)
			result.push_back(B[i]);
	}
	
	else
		result = A;
	
	return result;
}
std::vector<int> Intersection(std::vector<int> A, std::vector<int> B, int size_A, int size_B,
	std::vector <int> &result)
{
	if (size_A > size_B)
	{
		for (int i = 0; i < size_B; i++)
			if (std::count(B.begin(), B.end(), A[i]))
				result.push_back(A[i]);
	}

	else if (size_A < size_B)
	{
		for (int i = 0; i < size_A; i++)
			if (std::count(A.begin(), A.end(), B[i]))
				result.push_back(B[i]);
	}

	else
		result = A;

	return result;
}

std::vector<int>Difference(std::vector<int> A, std::vector<int> B, int size_A,
	std::vector <int> &result)
{
	for (int i = 0; i < size_A; i++)
		if (!std::count(B.begin(), B.end(), A[i]))
				result.push_back(A[i]);

	return result;
}

std::vector<int> Disunction(std::vector<int> A, std::vector<int> B, int size_A, int size_B,
	std::vector <int> &result)
{	

	if (size_A > size_B)
	{
		for (int i = 0; i < size_B; i++)
		{
			if (!std::count(A.begin(), A.end(), B[i]))
			{
				result.push_back(B[i]);
			}
			if (!std::count(B.begin(), B.end(), A[i]))
			{
				result.push_back(A[i]);
			}
		}
		for (int i = 0; i < size_A; i++)
			if ((!std::count(result.begin(), result.end(), A[i])) && (!std::count(B.begin(), B.end(), A[i])))
				result.push_back(A[i]);
	}
	else
	{
		for (int i = 0; i < size_A; i++)
		{
			if (!std::count(A.begin(), A.end(), B[i]))
			{
				result.push_back(B[i]);
			}
			if (!std::count(B.begin(), B.end(), A[i]))
			{
				result.push_back(A[i]);
			}
		}
		for (int i = 0; i < size_B; i++)
			if ((!std::count(result.begin(), result.end(), B[i])) && (!std::count(A.begin(), A.end(), B[i])))
				result.push_back(B[i]);
	}

	return result;
}

std::vector<int> Complement(std::vector<int> A, std::vector<int> U, int size_A, int size_U,
	std::vector<int> &result)
{
	int i = 0;
	
	for (i; i < size_A; i++)
		if (!std::count(A.begin(), A.end(), U[i]))
			result.push_back(U[i]);
	
	for (i; i < size_U; i++)
		result.push_back(U[i]);

	return result;
}


// --------------------------------------------------------------------------- //

// First task
void First(std::vector<int> a, std::vector<int> b)
{
	bool pass = true;
	int size_a = a.size();
	int size_b = b.size();

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	if (size_a == size_b)
	{
		for (int i = 0; i < size_a; i++)
		{
			if (std::count(b.begin(), b.end(), a[i]) == false)
			{
				std::cout << "They are not equivalent!\n";
				pass = false;
				break;
			}
		}
		if (pass == true)
			std::cout << "They are equivalent!\n";
	}
	else
	{
		if (size_a > size_b)
		{
			for (int i = 0; i < size_b; i++)
			{
				if (!std::count(a.begin(), a.end(), b[i]))
				{
					pass = false;
					std::cout << "B is not subset of A!\n";
					break;
				}
			}
			if (pass != false)
				std::cout << "B is subset of A!\n";
		}
		else
		{
			
			for (int i = 0; i < size_a; i++)
			{
				if (!std::count(b.begin(), b.end(), a[i]))
				{
					pass = false;
					std::cout << "A is not subset of B! \n";
					break;
				}
			}
			if (pass != false)
				std::cout << "A is subset of B!\n";
		}
	}
} 

// Second task
void Second(std::vector<int> mainV)
{
	std::vector<int> subset;

	std::vector<std::vector<int>> res;

	int index = 0;

	Subset(mainV, res, subset, index);
	
	Out_Multiply_Vector(res);
}

// Third task
void Third(std::vector<int> A, std::vector<int> B)
{
	std::vector<std::vector<int>> res;
	std::vector <std::vector<int>> res1;
	std::vector<int> subset;
	
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
		{
			subset.push_back(A[i]);
			subset.push_back(B[j]);

			res.push_back(subset);
			subset.pop_back();
			subset.pop_back();
		}
	}

	std::cout << "A * B = ";

	Out_Multiply_Vector(res);
	std::cout << std::endl;
	

	for (int i = 0; i < B.size(); i++)
	{
		for (int j = 0; j < A.size(); j++)
		{
			subset.push_back(B[i]);
			subset.push_back(A[j]);

			res1.push_back(subset);
			subset.pop_back();
			subset.pop_back();
		}
	}

	std::cout << "\nB * A = ";

	Out_Multiply_Vector(res1);
}

// Fourth
void Fourth(std::vector<int> A, std::vector<int> B, std::vector<int> U)
{
	int size_A = A.size();
	int size_B = B.size();
	int size_U = U.size();
	int i;

	std::vector<int> UnionRes, IntersectionRes, DifferenceRes, DisunctionRes, ComplementRes;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(U.begin(), U.end());

	Union(A, B, size_A, size_B, UnionRes);
	Intersection(A, B, size_A, size_B, IntersectionRes);
	Difference(A, B, size_A, DifferenceRes);
	Disunction(A, B, size_A, size_B, DisunctionRes);
	Complement(A, U, size_A, size_U, ComplementRes);
	
	std::cout << "\nUnion of A and B = ";
	Out_Vector(UnionRes);
	std::cout << std::endl;

	std::cout << "Intersection of A and B = ";
	Out_Vector(IntersectionRes);
	std::cout << std::endl;

	std::cout << "Difference of A and B = ";
	Out_Vector(DifferenceRes);
	std::cout << std::endl;

	std::cout << "Disunction of A and B = ";
	Out_Vector(DisunctionRes);
	std::cout << std::endl;

	std::cout << "Complement of A = ";
	Out_Vector(ComplementRes);

}
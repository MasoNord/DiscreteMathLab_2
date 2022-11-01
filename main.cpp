#include "C:/Users/trotf/University/DiscreteMath/Lab_2/header/functions.h"

void GetValue(std::vector<int>& array);

void ReWrite(std::vector<int>& array, std::string info);

int main()
{
	system("color a");

	std::vector<int> B;
	std::vector<int> A;
	short answer = -1;

	
	while (answer != 0)
	{
		std::cout << "\t\tFirst task\n\t\tf(x) = x * x\n";
		std::cout << "\t\tSecond task\n\t\tf(x) = 5x (Injective)\n\t\tf(x) = x * x + 1 (Surjective)\n\t\tf(x) = 2x - 3 (Bijective)\n";
		
		std::cout << "---------------------------------------------\n";
		
		std::cout << "1) Insert elemts in A and B array \n2) First task\n3) Second taks\n4) Rewrite A and B arrays"
			<< "\n0) Exit";

		std::cout << "\n---------------------------------------------";
		
		std::cout << "\nYour choice: ";
		std::cin >> answer;

		switch (answer)
		{
		case 1:
			std::cout << "Enter value for A array: ";
			GetValue(A);

			std::cout << "Enter value for B array: ";
			GetValue(B);

			system("pause");
			system("cls");
			break;
		case 2:
			std::cout << "Array A: ";
			OutputSimpleVector(A);
			
			std::cout << "Array B: ";
			OutputSimpleVector(B);
			
			First(A, B);
			system("pause");
			system("cls");
			break;
		case 3:
			std::cout << "Array A: ";
			OutputSimpleVector(A);

			std::cout << "Array B: ";
			OutputSimpleVector(B);

			Second(A, B);
			system("pause");
			system("cls");
			break;
		case 4:
			ReWrite(A, "Insert new elemnts for A array: ");
			ReWrite(B, "Insert new elemnets for B array: ");
			
			system("pause");
			system("cls");
			break;
		case 0:
			break;
		default:
			std::cerr << "Incorrect value!\n";
			break;
		}
	}
	system("pause");
}

void ReWrite(std::vector<int>& array, std::string info)
{
	array.clear();
	std::cout << info;
	GetValue(array);
}

void GetValue(std::vector<int>& array)
{
	int c = 1;

	while (std::cin && c != -0)
	{
		std::cin >> c;

		if (c != -0)
		{
			array.push_back(c);
		}
	}
}
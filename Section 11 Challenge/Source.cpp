// Section 11
// Challenge

/*
	Recall the challenge for Sectoin 9 below.
	Your challenge for section 11 is to modularize your solution to the Section 9
	challenge by refactoring your solution so that it uses functions.

	You decide how to modularize the program.

	Here are a few hints:
		- Create functions for each major function
		- Keep the function small
		- Remember the Boss/Worker analogy
		- Keep the vector declaration in the main function and pass the vector object
		to any function that requires it

		DO NOT move the vector object outside of main and make it a global variable.

		- You can start by defining a function that displays the menu
		- You can then define a function that reads the selection from the user and then return it in uppercase
		- Create functions for each menu option
		- Create functions that display the list of numbers, calculates the mean and so forth

	Take it one function at a time and take your time.
	If you get frustrated, take a break -- this isn't as easy as it looks the first time you do it!

	Finally, don't forget to use funtion prototypes!
*/

#include <iostream>
#include <vector>

using namespace std;

void display_menu();
char user_selection();
void print_numbers(const vector <int> nums);
void add_numbers(vector <int> &nums);
void display_mean(const vector <int> nums);
void display_small_num(const vector <int> nums);
void display_large_num(const vector <int> nums);
void search_for_num(const vector <int> nums);
void clear_list(vector <int> &nums);

int main()
{
	char selection{};
	vector <int> nums{};

	do
	{
		display_menu();

		selection = user_selection();

		if (selection == 'P')
		{
			print_numbers(nums);
		}

		else if (selection == 'A')
		{
			add_numbers(nums);
		}

		else if (selection == 'M')
		{
			display_mean(nums);
		}

		else if (selection == 'S')
		{
			display_small_num(nums);
		}

		else if (selection == 'L')
		{
			display_large_num(nums);
		}

		else if (selection == 'J')
		{
			search_for_num(nums);
		}

		else if (selection == 'C')
		{
			clear_list(nums);
		}

		else if (selection == 'Q')
		{
			cout << endl;
			cout << "Goodbye" << endl;
		}

		else
		{
			cout << endl;
			cout << "Unknown selection, please try again" << endl << endl;
		}

	} while (selection != 'Q');

	return 0;
}

void display_menu()
{
	cout << "P - Print numbers" << endl;
	cout << "A - Add a number" << endl;
	cout << "M - Display a mean of numbers" << endl;
	cout << "S - Display the smallest number" << endl;
	cout << "L - Display the largest number" << endl;
	cout << "J - Search for number in the list and how man times it occurs" << endl;
	cout << "C - Clear out the list" << endl;
	cout << "Q - Quit" << endl << endl;

	cout << "Enter your choice: ";

}

char user_selection()
{
	char selection{};

	cin >> selection;

	selection = toupper(selection);
		
	return selection;
}

void print_numbers(const vector <int> nums)
{
	cout << endl;
	
	if (nums.size() == 0)
	{
		cout << "The list is empty" << endl;
	}

	else
	{
		for (auto i{ 0 }; i < nums.size(); ++i)
		{
			cout << nums.at(i);

			if (i < nums.size() - 1)
			{
				cout << ", ";
			}
		}

		cout << endl;
	}

	cout << endl;
}

void add_numbers(vector <int> &nums)
{
	int add_num{};

	cout << endl;

	cout << "Enter an integer to add to the list: ";
	cin >> add_num;

	nums.push_back(add_num);

	cout << endl;

	cout << add_num << " was added" << endl;

	cout << endl;
}

void display_mean(const vector <int> nums)
{
	double total_added{};
	double mean{};

	cout << endl;

	if (nums.size() == 0)
	{
		cout << "Unable to calculate the mean - no data" << endl;
	}

	else
	{
		for (int i{ 0 }; i < nums.size(); ++i)
		{
			total_added += nums.at(i);
		}

		mean = total_added / nums.size();

		cout << "The mean of the list of numbers is: " << mean << endl;
	}

	cout << endl;
}

void display_small_num(const vector <int> nums)
{
	int smallest_num{};

	cout << endl;

	if (nums.size() == 0)
	{
		cout << "Unable to determine the smallest number - list is empty" << endl << endl;
	}

	else
	{
		smallest_num = nums.at(0);

		for (int i{ 0 }; i < nums.size(); ++i)
		{
			if (nums.at(i) < smallest_num)
			{
				smallest_num = nums.at(i);
			}
		}

		cout << "The smallest number is " << smallest_num << endl << endl;
	}
}

void display_large_num(const vector <int> nums)
{
	int largest_num{};
	
	cout << endl;

	if (nums.size() == 0)
	{
		cout << "Unable to determine the largest number - list is empty" << endl << endl;
	}

	else
	{
		largest_num = nums.at(0);

		for (int i{ 0 }; i < nums.size(); ++i)
		{
			if (nums.at(i) > largest_num)
			{
				largest_num = nums.at(i);
			}
		}
		cout << "The largest number is " << largest_num << endl << endl;
	}
}

void search_for_num(const vector <int> nums)
{
	cout << endl;

	if (nums.size() == 0)
	{
		cout << "List is empty" << endl << endl;
	}

	else
	{
		int num{};
		int counter{};

		cout << "Enter a number you would like to search for ";

		cin >> num;

		cout << endl;

		for (int i{ 0 }; i < nums.size(); ++i)
		{
			if (num == nums.at(i))
			{
				counter++;
			}

			else
			{
				continue;
			}
		}

		if (counter > 0)
		{
			cout << "Number detected in list - it appeared " << counter << " times" << endl << endl;
		}

		else
		{
			cout << "Number is not in list - please try again" << endl << endl;
		}
	}
}

void clear_list(vector <int> &nums)
{
	cout << endl;

	nums.clear();

	cout << "List was cleared" << endl << endl;
}
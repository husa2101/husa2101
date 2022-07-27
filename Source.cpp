#include<iostream>
#include "linked_list.h"
#include<ctime>
#include <random>
#include "Source.h"

void print_list(const linked_list l);
linked_list merge( linked_list& l1, linked_list& l2);
bool listSort(const linked_list& l1);


int main() {

	
	linked_list list;
	linked_list list2;
	double tal = 0;
	double tal1 = 0;

	srand((unsigned)time(0));
	
	for (size_t i = 0; i < 50; ++i)
	{
		tal = tal + rand() % 4 + 0;
		list.push_back(tal);
		tal1 = tal1 + rand() % 4 + 0;
		list2.push_back(tal1);
	}

	double num = list.at(24);
	double num1 = list2.at(24);

	if (num > num1) {
		std::cout<< "the element of the first list: ("<< num<<") is bigger then list2: ("<< num1 << ") and vill be remowed" << std::endl;
		list.print();
		list.remove(24);
		
	}
	else if(num == num1)
	{
		std::cout << "if both is equal the the element of the first list vill be removed" << std::endl;
		list.remove(24);
	}
	else
	{
		std::cout << " the element: ("<< num1<<") of the second list is bigger the elment of the first list: ("<< num <<") and will be removed " << std::endl;
		list2.print();
		list2.remove(24);
	}
	


	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";

	 linked_list list3;
	 double int1 =list.size();
	 double int2 = list2.size();

	 if (int1 < int2)
	 {
		 list3 = list;
		 std::cout << "the smallest is the first list" << std::endl;
		 list3.print_reverse();
		 
	 }
	 else
	 {
		 list3 = list2;
		 std::cout << "the smallest is the second list "<< std::endl;
		 list3.print_reverse();	
		
	 }
		
	

	 std::cout << "\n";
	 std::cout << "\n";
	 std::cout << "\n";

	 if (int1 > int2)
	 {
		 for (size_t i = 0; i < 25; i++)
		 {
			list.pop_back();
			list.push_front(list.pop_back());
		 }
		 std::cout << " first list after removing every other element from the list that still has 50 elements :""\n";
		 print_list(list);
	 }
	 else
	 {
		 for (size_t i = 0; i < 25; i++)
		 {
			 list2.pop_back();
			 list2.push_front(list2.pop_back());
		 }
		 std::cout << "second list after removing every other element from the list that still has 50 elements :""\n";
		 print_list(list2);
	 }
	 std::cout << "\n";
	 std::cout << "\n";
	 std::cout << "\n";
	 std::cout << "\n";

	 std::cout << "marged two linked list""\n";


	 
	 linked_list temp;
	 temp = merge(list, list2);
	 temp.print();
	 
	 std::cout << "\n";
	 std::cout << "\n";

	 bool sort;
	 sort = listSort(temp);
	 if (sort == true)
	 {
		 std::cout << " the list is sorted""\n";
	 }
	 else
	 {
		std::cout << " the list is not sorted""\n";
	 }
	 
	system("pause>0"); // ro get rid of jonke code,
	return 0;

}



void print_list(const linked_list l) 
{
	l.print();

}

linked_list merge(linked_list& l1, linked_list& l2) {
	linked_list merge;


	while (!l1.is_empthy() && !l2.is_empthy()) 
	{

		if (l1.front() < l2.front()) 
		{

			merge.push_back(l1.front());
			l1.pop_front();
		}
		else 
		{
			merge.push_back(l2.front());
			l2.pop_front();
		}
	}

	while (!l1.is_empthy()) 
	{
		merge.push_back(l1.front());
		l1.pop_front();
	}

	while (!l2.is_empthy()) 
	{
		merge.push_back(l2.front());
		l2.pop_front();
	}

	return merge;
}


bool listSort(const linked_list& list)
{

	for (int i = 0; i < list.size(); i++)
	{
		size_t pos = 0;
	
		if (list.at(pos) <= list.at(pos + 1))
		{
			pos++;
		}
		else
		{
			return false;
		}
	}
	return true;
}
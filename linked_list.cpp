#include<iostream>
#include"linked_list.h"

// constructer to create a empty linkedlist
linked_list::linked_list() {
	head = nullptr;
	tail = nullptr;
}

linked_list::node::node(double value)
{
	this->value = value;
	this->Next = nullptr;
	this->Prev = nullptr;
}

// copy constructor används till at kopiera innehållet av en object till en redan existerade object. 
// tar in en linked list som argument och lägger den i src. 
linked_list::linked_list(const linked_list& src)
{
	head = nullptr;
	tail = nullptr;
	if (!src.is_empthy()) { // om vår objekt är inte tomt
		node* ptr;
		for (ptr = src.head; ptr != nullptr; ptr = ptr->Next) {
			this->push_back(ptr->value); // pusha till den nya objektet
		}

	}
	else {
		std::cerr << " This list is empty." << std::endl;
	}

}

// access to the forst element in the list
double linked_list::front() const
{
	if (is_empthy) 					
	{ 
		return -1;  
	}
	else 
	{
		return head->value;
	}
}

// access to the last element of the linked list
double linked_list::back() const
{
	if (tail == nullptr)
	{
		return NULL;
	}
	else 
	{
		return tail->value;
	}
}


// return a element at the specific position 
double linked_list::at(size_t pos) const
{
	node* temp;
	temp = head;

		for (size_t i = 0; i < pos; i++)
		{
				temp = temp->Next;
		}
		return temp->value;
}


// delating from specific pos
void linked_list::remove(size_t pos)
{

	size_t loc = 0;
	if (loc == pos)
	{
		pop_front();
	}
	else if (pos == size()) 
	{
		pop_back();
	}
	else if (pos < size()) 
	{
		
		node* temp = head;
		for (; pos != loc; temp = temp->Next)
		{

			loc++;
		}
		temp->Prev->Next = temp->Next;
		temp->Next->Prev = temp->Prev;
		delete temp;

	}
	else 
	{
		std::cerr << "The given postion is out of limit" << std::endl;
	}
}


// delating from head
double linked_list::pop_front()
{
	node* ptr = head;
	double value = ptr->value;
	//if kontroll ifall om vi når slutet av länkade listan
	if (head == tail) {
		head = nullptr;
		tail = nullptr;
		delete ptr;
	}
	else if(ptr != nullptr) {
		head = head->Next; // ta en steg framat till nasta element
		head->Prev = nullptr; // satt head Prev till nullptr;
		ptr->Next = nullptr; // sätt Next av försgående element till nullptr och bryta linken.
		delete ptr;
	}
	else
	{
		return NULL;
	}
	return value;
}


// delating from end
double linked_list::pop_back()
{

	node* temp = tail;
	double value = temp->value;
	
	if (head == temp) {
		head = nullptr;
		tail = nullptr;
		delete temp;
		
	}
	else {
		tail = tail->Prev; // ta en steg bakåt
		temp->Prev = nullptr;
		tail->Next = nullptr;
		delete temp;
	}
	return value;
}

void linked_list::print() const
{
	// syftet med denna traverser �r att kunna g� from pos 1,2,3, osv...och vi b�rjar fr�n head
	node* traverser = head;
	while (traverser != nullptr)
	{
		std::cout << traverser->value << " "; // efter det so vill jag g� till n�sta node
		traverser = traverser->Next;
	}

}

void linked_list::print_reverse() const
{
	// h�r vi b�rjar fr�n slutet av listan och g�r till n�sta n�sta vilket �r prev
	node* traverser = tail;
	while (traverser != nullptr)
	{
		std::cout << traverser->value <<" "; // efter det so vill jag g� till n�sta node
		traverser = traverser->Prev;
	}

}


// insert a value from end 
void linked_list::push_back(double value)
{

	node* temp = new node(value);

	if (!is_empthy()) 
	{
		temp->Next = nullptr;
		temp->Prev = tail;
		tail->Next = temp;
		tail = temp;
	}
	else
	{
		head = temp;
		tail = head;
		tail->Next = nullptr;
		tail->Prev = nullptr;
	}
}


// inserting value at the given pos
void linked_list::insert(double value, size_t pos)
{
	node* new_node = new node(value);
	node* temp = head;
	size_t loc = 0;
	if (pos > size()) {
		std::cout << "The given postions is out of limit???" << std::endl;
	}
	else if (loc == pos) {
		node* pt0 = head;
		new_node->Next = pt0;
		pt0->Prev = new_node;
		head = new_node;
	}
	else if (pos == size()) {
		node* pt2 = tail;
		new_node->Prev = pt2;
		pt2->Next = new_node;
		tail = new_node;
	}
	else {

		for (size_t i = 0; i < pos - 1; i++)
		{
			temp = temp->Next;// pekar på nästa node
		}
		new_node->value = value;
		new_node->Next = temp->Next;
		temp->Next->Prev = new_node;
		new_node->Prev = temp->Prev;
		temp->Next = new_node;
		new_node->Prev = temp;
	}
}


// inserting value from head
void linked_list::push_front(double value)
{	
	try {
		node* temp = new node(value);
		temp->value = value;

		if (head != nullptr)
		{

			temp->Prev = nullptr; // nya noden prev = nullptrptr
			temp->Next = head; // nya noden next pekar på nästa node
			head->Prev = temp; // och head prev pekar på den nya noden
			head = temp; // här säger vi att den nya noden är head nu
		}
		else
		{
			// skapar vi en ny node ifall head är tomt
			head = temp;
			tail = head;
			head->Prev = nullptr;
			tail->Next = nullptr;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}


// geting the size of a linked list
size_t linked_list::size() const
{
	node* pekare = head;
	size_t counter = 0;

	if (head != nullptr)
	{
		counter = 1;
		while (pekare->Next != nullptr)
		{
			pekare = pekare->Next;
			counter++;
		}
		return counter;
	}
	else
	{
		return counter;
	}
}

bool linked_list::is_empthy() const
{
	return head == nullptr && tail == nullptr;
}


// destructer FRIGÖR DET MINNE SOM ÄR ALLOKERAT EFTER EN EXICUTION
linked_list::~linked_list() 
{
	while (head != nullptr) {
		pop_front();
	}
}
// here we returna refrence& and we take right handside as const because we do not want to change it and do take it as refrence 
// beacuse we do not want to make a copy of it because it is unneccery copy
// this will have address of list3 which is the oject we want to dereference to
linked_list& linked_list::operator=(const linked_list& rhs)
{   
	// in here we compering list3 and list1 or 2;
	// if they are not equel then we will assign it othewise we just return the list3 == *this
	// if lhs = rhs - dont do anything

	if (this == &rhs) {
		return *this;
	}
		while (head != nullptr) {  // bort element fron listan
			this->pop_back();
		}
		// lägg till element till listan från andra listan
		node* temp;
		for (temp = rhs.head; temp != nullptr; temp = temp->Next) {
			this->push_back(temp->value);
		}
		return *this;
	
}

// slå ihop två list. 
linked_list& linked_list::operator+=(const linked_list& rhs)
{
	node* ptr = rhs.head;

	while (ptr != nullptr) 
	{

		this->push_back(ptr->value);
		ptr = ptr->Next;
	
	}
	return *this;
}


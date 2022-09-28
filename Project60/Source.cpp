#include <iostream>
using namespace std;


struct Element
{
	
	char data;
	
	Element* Next;
};

class List
{
	Element* Head;
	Element* Tail;
	int Count;

public:

	List();
	~List();
	void Add(char data);
	void Del();
	void DelAll();
	void DelLast();
	void Print();
	int GetCount();
	char GetValue(int number);
	void PutValue(char value, int number);
	void DelValue(int number);
	int SearchElement(char c);
};

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}
List::~List()
{
	DelAll();
}
int List::GetCount()
{
	return Count;
}
char List::GetValue(int number)
{
	Element* temp = Head;
	int i = 1;
	while (i < number) {
		temp = temp->Next;
		i++;
	}

	return temp->data;
}
void List::PutValue(char data, int number)
{

	if (number > GetCount() || number < 0) return;  // Checks if the number is correct for the list
	else if (number == GetCount())Add(number);		// If the number = Elements, will call a function Add.
	else {
		Element* put = new Element;    // Allocate memory for a new node
		Element* temp = Head;		//Creating temp
		put->data = data;				//Init new memory with data

		int i = 1;					//number of the list starting with 1

		while (i < number - 1)		//While i < number of node-1
		{
			temp = temp->Next;	// Move on to the next node
			i++;					//i++;
		}
		put->Next = temp->Next;			//When the node before number is found direct put pointer to next node
		temp->Next = put;				//Next nod is new node now.


		Count++;
	}
	
}

void List::DelValue(int number)
{
	if (Head == NULL || number > GetCount() || number < 0) return; // Checks if the number is correct for the list
	else if (number == 1) Del();						//If there is need to delete the first element, calls function Del.
	else if (number == GetCount()) DelLast();		// If there is need to delete the last element, calss function DelLast.
	else {
		Element* temp = Head;	//Creating temp
		int i = 1;
		while (i < number - 1)			//Stops right before the element that should be deleted.
		{
			temp = temp->Next;
			i++;
		}

		Element* temp2 = temp->Next;			//Creates a new pointer that will point at the element that goes after deleted element
		temp2 = temp2->Next;

		delete temp->Next;					//Deletes the respective node
		temp->Next = temp2;					//The pointer before deleted node points at the node that goes after deleted node now.
		Count--;
	}
}
int List::SearchElement(char c)
{
	Element* temp = Head;

	for (int i = 1; i < GetCount();i++)				//Cycle works as long as i < number of elements in the list.
	{
		if (c == temp->data)						//If user character matches with character in the list, returns index of the character.
			return i;
		
		temp = temp->Next;
	}

	return NULL;							//If the condition in the cycle didn't work, returns NULL.
}
void List::Add(char data) //!!
{
	Element* temp = new Element;


	temp->data = data;

	temp->Next = NULL;
	
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
		Count++;
	}
	
	else {
		Head = Tail = temp;
		Count++;
	}

}
void List::Del()
{
	Element* temp = Head;
	
	Head = Head->Next;
	Count--;
	delete temp;
}
void List::DelAll()
{
	Count = 0;
	while (Head != 0)
		Del();
}

void List::DelLast()
{
	if (Head == NULL || Head->Next == NULL)return; // Checks is there are still nodes to delete.

	Element* temp = Head;

	int i = 1;
	while (i < GetCount() - 1)  //Sets the pointer temp at the node that goes before Tail node.
	{
		temp = temp->Next;
		i++;
	}
	delete Tail;			//Deletes Tail
	Tail = temp;			//Tail is temp now.
	
	Tail->Next = NULL; 

	Count--;
}

void List::Print()
{
	
	Element* temp = Head;
	
	while (temp != 0)
	{
		
		cout << temp->data << " ";
		
		temp = temp->Next;
	}

	cout << "\n\n";
}


void main(){
	List lst;
	char s[] = "Hello, World !!!\n";
	cout << s << "\n\n";
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	lst.Print();
	lst.PutValue('W', 5);
	lst.Print();
	lst.DelValue(10);
	lst.Print();


	cout << lst.SearchElement('W');
}


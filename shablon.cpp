/*! \file main.cpp
Главный файл проекта
*/
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <time.h>


using namespace std;

/** 
Список
*/
class abstractList
{
public:
	virtual void InsertHead ()=0;
	virtual void GetValue (int n)=0;
	virtual int remove (int n)=0;
	virtual int add (int n)=0;
	virtual void printList()=0; 

};


template <class T> class list: public abstractList 
{
private:
	list<T>* next;
	T value;

public:
	list() {next=0;};
	void InsertHead () 
	{
		
		list *p = new list<T>; 
		T a;
		cin>>a;
		p->value = a;
		p->next=this->next;
		this->next = p;

	}
/** fn void GetValue (int n)
Получение элемента
*/
void GetValue (int n)
	{
		list<T> *p= this->next;
		for (int i = 1; i < n; i++)
		{
			p = p->next;
		}
		cout <<p->value <<endl;
	}

/** int remove (int n)
Удаление элемента
*/
int remove (int n)
	{
		if(n>1){
			list<T> *p = this->next;
			int i;
			for (i = 1; (i < (n-1)) && (p!=0); i++)
			{
				p = p->next;
			}
			if (p!=0)
			{
				list<T> *tmp = p->next;
				p->next = p->next->next;
				delete tmp;
				return 0;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			if (this->next!=0)
			{	
				list<T> *p = this->next;
				this->next=p->next->next;
				delete p;
				return 0;
			}
			else
			{
				return -1;
			}
		}
	}


int add (int n) 
	{
		list<T> *p = this->next;
		int i;
		if(n>1)
		{
			T data;
			cin>> data;
			for (i = 1; (i < (n-1)) && (p!=0); i++)
			{
				p = p->next;
			}
			if (p!=0)
			{
				list<T> *newP = new list<T>;
				newP->value = data;
				newP->next=p->next;
				p->next = newP;
				return 0;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			InsertHead();
			return 0;
			
		}
	}


/** fn void printList()
Функция вывода списка
*/
	void printList()
	{
		list<T> *p=this->next;
		while (p)
		{
			cout << p->value<< " ";
			p = p->next;
		}
		cout<<"\n";
	}

};


/** fn void testfunc(abstractList *pFirst)
Функция
*/
void testfunc(abstractList *pFirst)
{
	
	int n = 0;
	cin >> n;

	int data;
	int num;
	char op;
	for (int i = 0; i < n; i++)
	{	
		cin >> op;
		if(op=='a')
		{
			cin >> num;
			
			if(	pFirst->add(num)<0)
			{
				cout << "Oshibka dobavlenia! Neverniy nomer!";
			}
		}
		else
		if(op=='d')
		{
			cin >> num;
			if(	pFirst->remove(num)<0)
			{
				cout << "Neverniy nomer!";
			}
		}
		
		
	}

};

/** \fn void main()
Главная функция проекта
*/
int main()
{
	setlocale(LC_ALL, "rus");

	int couTest;
	cin >> couTest;
	abstractList *testList[10];
	char typeData;
	for (int index=0; index<couTest; index++){
		cin>>typeData;
		if (typeData=='i')
		{
			testList[index] = new list<int>; 
			testfunc(testList[index]);
		}
	else
		if (typeData=='s')
		{
			testList[index] = new list<string>; 
			testfunc(testList[index]);
		}
			else
		{
			cout<<"Error type!";
		}

	}
	for (int index=0; index<couTest; index++)
	{
		testList[index]->printList(); 

	}
    getchar();
	getchar();
	return 0;
};

#pragma once
#include <iostream>


template<typename T>
class List
{
public:
	List();
	~List();

	void clear();
	void push_back(T data);
	int Get_Size();
	void pop_front();
	void insert(T value, int index);
	void push_front(T data);

	/*void remuveAT(int index);*/
	void pop_back();

	T& operator[](const int index);

private:


	template<typename T>
	class Node
	{
	public:

		Node* pNext;
		Node* prev;
		T data;
		Node(T data = T())
		{
			this->data = data;
		}
	};

	Node<T>* header = nullptr;
	int Size;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	header = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
	header = nullptr;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = header;
	header->pNext->prev = header->prev;
	header->prev->pNext = header->pNext;
	header = header->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::insert(T value, int index)
{
	if (index == 0)
	{
		push_front(value);
	}
	else
	{
		Node<T>* previos = this->header;
		for (int i = 0; i < index - 1; i++)
		{
			previos = previos->pNext;
		}
		Node<T>* newNode = new Node<T>(value);
		newNode->prev = previos;
		newNode->pNext = previos->pNext;
		previos->pNext->prev = newNode;
		previos->pNext = newNode;

		Size++;
	}

}


template<typename T>
void List<T>::push_front(T data)
{
	Node<T>* newHead = new Node<T>(data);
	newHead->pNext = header;
	newHead->prev = header->prev;
	newHead->prev->pNext = newHead;
	header->prev = newHead;
	header = newHead;
	Size++;
}

template<typename T>
void List<T>::push_back(T data)
{
	if (header == nullptr)
	{
		header = new Node<T>(data);
		header->pNext = header;
		header->prev = header;
	}else
	{
		Node<T>* current = this->header;

		while (current->pNext != header)
		{
			current = current->pNext;
		}

		current->pNext = new Node<T>(data);
		current->pNext->prev = current;
		current->pNext->pNext = header;
		header->prev = current->pNext;
	}

	Size++;
}

template<typename T>
int List<T>::Get_Size()
{
	return Size;
}

template<typename T>
inline void List<T>::pop_back()
{
	Node<T>* temp = header->prev;
	temp->prev->pNext = header;
	header->prev = temp->prev;
	delete temp;
	Size--;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	Node<T>* current = this->header;
	int counter = 0;
	int half = (index + 1);
	if (half <= Size / 2)
	{
		do
		{
			if (counter == index)
				return current->data;
			current = current->pNext;
			counter++;

		} while (current != header);
	}
	else
	{
		counter = Size;
		do
		{
			if (counter == index)
				return current->data;
			current = current->prev;
			counter--;

		} while (current != header);
	}

}



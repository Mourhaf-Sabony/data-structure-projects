#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsDblLinkedList
{

protected:
	int _size = 0;
	
public:

	class Node {
	public:
		T value;
		Node* next;
		Node* prev;
	};

	Node* head = NULL;

	void PrintList() {
		Node* current = head;
		while (current != NULL)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << "\n";
	}

	Node * Find(T value) {
		Node* current = head;
		while (current != NULL)
		{
			if (current->value == value)
			{
				return current;
			}
			current = current->next;
		}
	}

	void InsertAtBeginning(T value){
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = head;
		newNode->prev = NULL;

		if (head != NULL)
			head->prev = newNode;

		head = newNode;
		_size++;
	}

	void InsertAfter(Node* prevNode, T value){
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = prevNode->next;
		newNode->prev = prevNode;
		prevNode->next = newNode;

		if (newNode->next != NULL)
			newNode->next->prev = newNode;

		_size++;
	}

	void InsertAtEnd(T value) {
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = NULL;
		if (head == NULL) {
			newNode->prev = NULL;
			head = newNode;
			_size++;
			return;
		}
		else
		{
			Node* current = head;
			while (current->next != NULL)
				current = current->next;

			current->next = newNode;
			newNode->prev = current;
		}

		_size++;
	}

	void DeleteNode(Node* Node) {
		if (head == NULL || Node == NULL)
			return;
		if (head == Node)
			head = Node->next;
		if (Node->next != NULL)
			Node->next->prev = Node->prev;
		if (Node->prev != NULL)
			Node->prev->next = Node->next;
		delete Node;
		_size--;

	}

	void DeleteFirstNode() {
		if (head == NULL)
			return;

		Node* temp = head;
		head = head->next;

		if (head != NULL)
		{
			head->prev = NULL;
		}
		delete temp;
		_size--;
	}
	
	void DeleteLastNode() {
		if (head == NULL)
		{
			return;
		}
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			_size--;
			return;
		}
		Node* current = head;
		while (current->next->next != NULL)
		{
			current = current->next;
		}
		Node* temp = current->next;
		current->next = NULL;
		delete temp;
		_size--;
	}

	int Size()
	{
		return _size;
	}
	
	bool IsEmpty()
	{
		return (_size == 0 ? true : false);
	}

	void Clear()
	{
		while (_size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		Node* current = head;
		Node* temp = NULL;
		while (current != NULL)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}
		if (temp != NULL) // if we have a single node in the list
		{
			head = temp->prev;
		}
	}

	Node* GetNode(int index)
	{
		int counter = 0;
		if (index > _size - 1 || index < 0)
			return NULL;


		Node* current = head;
		while (current != NULL)
		{
			if (counter == index)
				break;

			counter++;
			current = current->next;
		}
		return current;
	}

	T GetItem(int index)
	{
		Node* ItemNode = GetNode(index);

		return (ItemNode == NULL ? T() : ItemNode->value);
	}

	bool UpdateItem(int index, T value)
	{
		Node* ItemNode = GetNode(index);

		if (ItemNode != NULL)
		{
			ItemNode->value = value;
			return true;
		}
		else
			return false;

	}
};



#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsDblLinkedList
{

protected:


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

	Node* Find(T value) {
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

	void InsertAtBeginning(T value) {
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = head;
		newNode->prev = NULL;

		if (head != NULL)
			head->prev = newNode;

		head = newNode;
	
	}

	void InsertAfter(Node* prevNode, T value) {
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = prevNode->next;
		newNode->prev = prevNode;
		prevNode->next = newNode;

		if (newNode->next != NULL)
			newNode->next->prev = newNode;

	}

	void InsertAtEnd(T value) {
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = NULL;
		if (head == NULL) {
			newNode->prev = NULL;
			head = newNode;
			
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
		
	}
};
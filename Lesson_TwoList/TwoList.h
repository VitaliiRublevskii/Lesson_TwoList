#pragma once

#include <iostream>

using namespace std;

template<typename T> struct Node {
	T value;
	Node* next;
	Node* prev;
};

template<typename T> class TwoList
{
	Node<T>* root = nullptr;
public:


	TwoList() {}


	~TwoList() {
		clear();
	}

	bool empty() {
		return root == nullptr;
	}

	void clear() {
		while (!empty())
			DeleteFromHead();
	}

	void AddToHead(T _value) {
		// Создаём новый узел с переданным значением
		Node<T>* new_node = new Node<T>;
		new_node->value = _value;
		new_node->next = nullptr;
		new_node->prev = nullptr;
		if (empty()) {
			root = new_node;  // Если элементов нет – записываем новый узел как корень списка
		}
		else {
			root->prev = new_node; // Записываем в старый root ссылку на новый элемент
			new_node->next = root; // Записываем в новый елемент ссылку на старый root
			new_node->prev = nullptr; // в новом элементе ссылка на предыдущий пустая
			root = new_node; // в root записываем новый первый элемент
		}

	}

	void AddToTail(T _value) {
		// Создаём новый узел с переданным значением
		Node<T>* new_node = new Node<T>;
		new_node->value = _value;
		new_node->next = nullptr;
		new_node->prev = nullptr;

		// Проверяем спискок на отсутствие элементов
		if (empty()) {
			// Если элементов нет – записываем новый узел как корень списка
			root = new_node;
		}
		else
		{
			// Если элементы есть, ищем последний элемент
			Node<T>* last = root;
			while (last->next != nullptr)
				last = last->next;
			last->next = new_node;// Указываем новый узел как следующий элемент последнего узла
			new_node->prev = last;// в последний элемент записываем ссылку на last
		}
	}

	void print() {
		if (root == nullptr)
			cout << "List is empty!" << endl;
		else
		{
			Node<T>* current = root;
			while (current != nullptr)
			{
				cout << current->value << " ";
				current = current->next;
			}
			cout << endl;
		}
	}

	int DeleteFromHead() {
		T result = root->value;
		Node<T>* current = root;
		root = root->next;
		delete current;
		return result;
	}

	void DeleteFromTail() {
		Node<T>* last = root;
		
		while (last->next != nullptr)
			last = last->next;
		last->prev->next = nullptr;
		delete last;
	}

	TwoList operator+(TwoList& _root) {
		TwoList newList;
		Node<T>* source_current = root;
		
		while (source_current != nullptr)
		{
			newList.AddToTail(source_current->value);
			source_current = source_current->next;

		}
		source_current = _root.root;
		while (source_current != nullptr)
		{
			newList.AddToTail(source_current->value);
			source_current = source_current->next;
		}
		return newList;
	}

	TwoList& operator=(TwoList _list) {
		while (!empty())
			DeleteFromHead();
		Node<T>* source_current = _list.root;
		while (source_current != nullptr)
		{
			AddToTail(source_current->value);
			source_current = source_current->next;
		}
		return *this;
	}

	TwoList* operator+=(T value) {
		Node<T>* new_node = new Node<T>;
		new_node->value = value;
		new_node->next = nullptr;
		new_node->prev = nullptr;
		AddToTail(value);
		return this;
	}
	/*
	T operator[](int index) {
		Node<T>* new_node = new Node<T>;
		new_node->value = value;
		new_node->next = nullptr;
		new_node->prev = nullptr;

		Node<T>* last = root;

		int index = 0;
		while (last->next != nullptr) {
			last = last->next;
			if (index == value)
				new_node = last;
		}
		return new_node;
	}*/






/*
	void clone(OneList& _source) {
		Node<T>* source_current = _source.root;
		while (source_current != nullptr)
		{
			push_back(source_current->value);
			source_current = source_current->next;
		}
	}

	void remove(int _value) {
		while (root != nullptr && root->value == _value)
		{
			Node<T>* current = root;
			root = root->next;

			delete current;
		}

		Node<T>* previous = root;
		Node<T>* curent = root->next;
		while (curent != nullptr)
		{
			if (curent->value == _value) {
				previous->next = curent->next;
				delete curent;
				curent = curent->next;
			}
			else {
				previous = curent;
				curent = curent->next;
			}

		}
	}

	

	unsigned int get_length() {
		unsigned int length = 0;
		Node<T>* current = root;
		while (current != nullptr)
		{
			length++;
			current = current->next;
		}
		return length;
	}


	OneList operator+(OneList& _root) {
		Node<T>* source_current = _root.root;
		while (source_current != nullptr)
		{
			push_back(source_current->value);
			source_current = source_current->next;
		}
		return OneList();
	}

	OneList operator*(OneList& _root) {
		Node<T>* first = root;
		Node<T>* second = _root.root;
		while (first != nullptr) {
			if (first->value == second->value)
				first = first->next;
			else
				remove(first->value);
		}
		return OneList();
	};
	*/

};
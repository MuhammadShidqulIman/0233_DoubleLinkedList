// Doublelinklist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int noMhs;
    string name;
    Node* next;
    Node* prev;
};

Node* START = NULL;

void addNode() 
{
    Node* newNode = new Node(); // step 1: create a new node
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs;     // Assign value to the data field of the new node
    cout << "\nEnter the name of the student: ";
    cin >> newNode->name;   // Assign value to the data field of the new node


    // Insert the new node in the list
    if (START == NULL || newNode->noMhs <= START->noMhs)
    {

        if (START != NULL && newNode->noMhs == START->noMhs) 
        {
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
            return;
        }

        newNode->next = START;
        if (START != NULL)
        {
            START->prev = newNode;
        }
        newNode->prev = NULL;
        START = newNode;
    }
    else
    {
        Node *current = START;
        Node* previous = NULL;

        while (current != NULL && current->noMhs < newNode->noMhs)
        {
            previous = current;
            current = current->next;
        }

        newNode->next = current;
    }
}

#include <iostream>
#include <stdlib.h> // Required for malloc and free
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main() {
    Node* head = NULL; // Head of the linked list

    cout << "Enter numbers to insert into the linked list (enter -1 to stop):\n";

    while (true) {
        // Create a new node using malloc
        Node* ptr = (Node*)malloc(sizeof(Node));
        cin >> ptr->data;
        if (ptr->data == -1) {
            free(ptr); // free the unused node
            break;
        }
        ptr->next = NULL;
        ptr->prev = NULL;

        // Insert new node at the end of the list
        if (head == NULL) {
            head = ptr;
        } else {
            Node* curr = head;
            // Traverse to the last node
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = ptr;
            ptr->prev = curr;
        }
    }

    // Display the doubly linked list
    cout << "The doubly linked list is: ";
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data;
        if (curr->next != NULL)
            cout << ", ";
        curr = curr->next;
    }
    cout << endl;

  

    // Search for an element
    int search;
    cout << "Enter the number to search: ";
    cin >> search;
    curr = head;
    bool found = false;
    while (curr != NULL) {
        if (curr->data == search) {
            found = true;
            break;
        }
        curr = curr->next;
    }
    if (found)
        cout << "Value Found" << endl;
    else
        cout << "Not Found" << endl;

    // Deletion: Delete a node with a given value
    int del;
    cout << "Enter the number you want to delete: ";
    cin >> del;

    if (head == NULL) {
        cout << "List is Empty" << endl;
    }
    else if (head->data == del) {
        // Deleting the head node
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
    }
    else {
        // Deleting a non-head node
        curr = head;
        while (curr != NULL) {
            if (curr->data == del) {
                // Update the previous node's next pointer
                if (curr->prev != NULL)
                    curr->prev->next = curr->next;
                // Update the next node's prev pointer if it exists
                if (curr->next != NULL)
                    curr->next->prev = curr->prev;
                free(curr);
                break;
            }
            curr = curr->next;
        }
    }

    // Display the updated doubly linked list
    cout << "The updated doubly linked list is: ";
    curr = head;
    while (curr != NULL) {
        cout << curr->data;
        if (curr->next != NULL)
            cout << ", ";
        curr = curr->next;
    }
    cout << endl;

    Node * prev =NULL;
    curr=head;
    
    Node *next=NULL;
while(curr!=NULL){
    next=curr->next;
    curr->next=prev;
    curr->prev=next;
    prev=curr;
    curr=next;
}
head=prev;
cout << "The reversed doubly linked list is: ";
curr = head;
while (curr != NULL) {
    cout << curr->data;
    if (curr->next != NULL)
        cout << ", ";
    curr = curr->next;
}
cout << endl;

    return 0;
}

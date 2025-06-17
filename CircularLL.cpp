#include <iostream>
#include <stdlib.h> // Required for malloc
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL; // Head of the circular linked list

    cout << "Enter numbers to insert into the circular linked list (enter -1 to stop):\n";

    while (true) {
        Node* ptr = (Node*)malloc(sizeof(Node));
        cin >> ptr->data;

        if (ptr->data == -1) {
            free(ptr);
            break;
        }

        ptr->next = NULL;

        if (head == NULL) {  // First node
            head = ptr;
            head->next = head;  // Circular link
        } else {
            Node* curr = head;
            while (curr->next != head) { // Find last node
                curr = curr->next;
            }
            curr->next = ptr;
            ptr->next = head; // Maintain circular link
        }
    }

    // Display the circular linked list
    if (head != NULL) {
        cout << "The circular linked list is: ";
        Node* curr = head;
        do {
            cout << curr->data;
            if (curr->next != head) cout << ", ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }

    // Searching an element
    int search;
    cout << "Enter the number to search: ";
    cin >> search;
    Node* curr = head;
    bool found = false;

    if (head != NULL) {
        do {
            if (curr->data == search) {
                found = true;
                break;
            }
            curr = curr->next;
        } while (curr != head);
    }

    if (found) cout << "Value Found\n";
    else cout << "Not Found\n";

    // Deletion of a node
    int del;
    cout << "Enter the number to delete: ";
    cin >> del;

    if (head == NULL) {
        cout << "List is empty.\n";
    } else {
        Node *prev = NULL;
        curr = head;
        bool deleted = false;

        // Case 1: Deleting the head node
        if (head->data == del) {
            Node* last = head;
            while (last->next != head) { // Find last node
                last = last->next;
            }

            if (head->next == head) { // If it's the only node
                free(head);
                head = NULL;
            } else {
                last->next = head->next; // Link last node to second node
                Node* temp = head;
                head = head->next;
                free(temp);
            }
            deleted = true;
        } else {
            // Case 2: Deleting a non-head node
            do {
                prev = curr;
                curr = curr->next;

                if (curr->data == del) {
                    prev->next = curr->next;
                    free(curr);
                    deleted = true;
                    break;
                }
            } while (curr != head);
        }

        if (deleted)
            cout << "Node deleted successfully.\n";
        else
            cout << "Node not found.\n";
    }

    // Display the updated circular linked list
    if (head != NULL) {
        cout << "Updated circular linked list: ";
        curr = head;
        do {
            cout << curr->data;
            if (curr->next != head) cout << ", ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    } else {
        cout << "The list is now empty.\n";
    }

    return 0;
}

#include <iostream>
#include <stdlib.h> // Required for malloc
using namespace std;

struct Node {
    int data;
    Node* next;
   
};
Node* begin(int x,Node *head){
Node *n=(Node*)malloc(sizeof(Node));
n->data=x;
n->next=head;
head=n;
return n;
}
int main() {
    Node* head = NULL; // Head of the linked list
    

    cout << "Enter numbers to insert into the linked list (enter -1 to stop):\n";

    while (true) {
         // Exit condition

        // Create a new node using malloc
        Node* ptr = (Node*)malloc(sizeof(Node));
     

       cin>> ptr->data ;
       if(ptr->data==-1){
        break;
       }
        ptr->next = NULL;
       

        // If the list is empty, make ptr the first node
        if (head == NULL) {
            head = ptr;
        } else {
            Node* curr = head;

            // Traverse to the last node
            while (curr->next != NULL) {
                curr = curr->next;
                
            }

            // Insert new node at the end
            curr->next = ptr;
            
        }
    }

    // Display the linked list
    cout << "The linked list is: ";
    Node* curr = head;
    
    while (curr != NULL) {
        cout << curr->data;
        if (curr->next != NULL) cout << ", ";
        curr = curr->next;
    }
    
    cout << endl;
    int search;
    cout<<"Enter the number tosearch"<<" ";
    cin>>search;
     curr =head;
     bool found =false;
     while (curr!=NULL){
        if(curr->data==search){
            found=true; 
            break;
            
        }
        curr=curr->next;
     }
     if(found){
        cout<<"Value Found";
        cout<<endl;
     }
     else 
     cout<<"Not Found";
     cout<<endl;
     
     int del;
     cout<<"Enter the number you want to delete"<<" ";
     cin>>del;

     if(head==NULL){
        cout<<"list is empty";
     }
       else if(head->data==del){
            Node* temp=head;
            head=head->next;
            free(temp);
            
        }

            else{
             curr=head->next;
                Node *prev=head;
            
     
     while(curr!=NULL){
        if(curr->data==del){
            prev->next=curr->next;
            free(curr);
            break;
        }
        curr=curr->next;
        prev=curr;
     }
     cout << "The updated linked list is: ";
    Node* curr = head;
    
    while (curr != NULL) {
        cout << curr->data;
        if (curr->next != NULL) cout << ", ";
        curr = curr->next;
    }
        
    }
    cout<<endl;
     head =begin(8,head);
     cout << "The updated linked list is: ";
      curr = head;
     
     while (curr != NULL) {
         cout << curr->data;
         if (curr->next != NULL) cout << ", ";
         curr = curr->next;
     }
    return 0;
}

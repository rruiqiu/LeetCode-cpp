// C++ program for the above approach
#include <iostream>
using namespace std;

// Node class to represent
// a node of the linked list.
class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Linked list class to
// implement a linked list.
class Linkedlist {
    Node* head;

public:
    // Default constructor
    Linkedlist() { head = NULL; }
    Node *getHead(){
        return head;
    }
    void setHead(Node *ptr){
        head = ptr;
    }
    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(int);

    // Function to print the
    // linked list.
    void printList();

    // Function to delete the
    // node at given position
    void deleteNode(int);
};

// Function to delete the
// node at given position
void Linkedlist::deleteNode(int nodeOffset)
{
    Node *temp1 = head, *temp2 = NULL;
    int ListLen = 0;

    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }

    // Find length of the linked-list.
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }

    // Check if the position to be
    // deleted is less than the length
    // of the linked list.
    if (ListLen < nodeOffset) {
        cout << "Index out of range"
            << endl;
        return;
    }

    // Declare temp1
    temp1 = head;

    // Deleting the head.
    if (nodeOffset == 1) {

        // Update head
        head = head->next;
        delete temp1;
        return;
    }

    // Traverse the list to
    // find the node to be deleted.
    while (nodeOffset-- > 1) {

        // Update temp2
        temp2 = temp1;

        // Update temp1
        temp1 = temp1->next;
    }

    // Change the next pointer
    // of the previous node.
    temp2->next = temp1->next;

    // Delete the node
    delete temp1;
}

// Function to insert a new node.
void Linkedlist::insertNode(int data)
{
    // Create the new Node.
    Node* newNode = new Node(data);

    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse till end of list
    Node* temp = head;
    while (temp->next != NULL) {

        // Update temp
        temp = temp->next;
    }

    // Insert at the last.
    temp->next = newNode;
}

// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
    Node* temp = head;

    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    // Traverse the list.
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
class Solution {
public:
    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node *dummy, *temp;
        dummy = new Node();
        temp = dummy;
        while(list1 && list2){
            if(list1->data < list2->data){
                temp->next = list1;
                list1 = list1 ->next;
            }else{
                temp->next = list2;
                list2 = list2 ->next;
            }
            temp=temp->next;

        }
        if(list1){
            temp->next = list1;
        }else{
            temp->next = list2;
        }
        return dummy->next;
    }
    
    
    Node* reverseList(Node* head) {
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    
    Node* middleNode(Node* head) {
//        Node* current = head;
//        Node* middle = head;
//        int count = 0;
//        while(current!=NULL){
//            current = current->next;
//            count ++;
//        }
//        for(int i=0; i<count/2;i++){
//            middle = middle -> next;
//        }
//
//        return middle;
        //Linked List Cycle Theorem: When fast pointed reaches end then slow is going to be at middle.
        Node *slow = head, *fast = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    //Leetcode2 adding two numbers
    Node* addTwoNumbers_reversely(Node* l1, Node* l2) {
        Node *dummy, *temp;
        dummy = new Node();
        temp = dummy;
        Node *curr1 = l1, *curr2 = l2;
        int count=0;
        while (curr1!=NULL && curr2 !=NULL) {
            int data =0;
            data = curr1->data + curr2->data + count;
            count =0;
            if(data >= 10){
                data = data %10;
                count ++;
            }
            curr1 =curr1 ->next;
            curr2 =curr2 ->next;
            Node *newNode = new Node(data);
            temp->next=newNode;
            temp =temp ->next;
        }
        while(curr1 !=NULL){
            int data =0;
            data = curr1->data+count;
            count =0;
            if(data >= 10){
                data = data %10;
                count ++;
            }
            Node *newNode = new Node(data);
            temp->next=newNode;
            temp =temp ->next;
            curr1 = curr1->next;
        }
        while(curr2 !=NULL){
            int data =0;
            data = curr2->data+count;
            count =0;
            if(data >= 10){
                data = data %10;
                count ++;
            }
            Node *newNode = new Node(data);
            temp->next=newNode;
            temp =temp ->next;
            curr2 = curr2->next;
        }
        if(count!=0){
            Node *newNode = new Node(count);
            temp->next=newNode;
            temp = temp->next;
        }
        
        return dummy->next;
    }
};


// Driver Code
int main()
{
    Solution res;
    Linkedlist list;
    Linkedlist ans;
    Linkedlist result;
    // Inserting nodes
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);

    Linkedlist list2;

    // Inserting nodes
    list2.insertNode(1);
    list2.insertNode(3);
    list2.insertNode(4);
    list2.insertNode(5);
    Node* ptr1 = list.getHead();
    Node* ptr2 = list2.getHead();
    
    cout << "Elements of the list are: ";

    res.addTwoNumbers_reversely(ptr1,ptr2);
    result.setHead(res.mergeTwoLists(ptr1, ptr2));//ans linked to the head of the

    // Print the list
    result.printList();
    cout << endl;
    cout << endl<<"reversed list";
    result.setHead(res.reverseList(result.getHead()));
    result.printList();
    result.setHead(res.middleNode(result.getHead()));
    cout << endl;

    // Delete node at position 2.
    list.deleteNode(2);

    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;
    return 0;
}

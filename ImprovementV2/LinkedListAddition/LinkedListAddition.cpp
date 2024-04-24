// C++ Code to add two nodes by reversing the two lists
 
#include <iostream>
using namespace std;
 
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
};
 
Node* newNode(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
 
/* Function to insert a node at the
beginning of the Singly Linked List */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = newNode(new_data);
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
void printList(Node* n)
{
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
 
//----------------------------------------------------------------------------
 
Node* addTwoLists(Node* first, Node* second)
{
    int carry = 0;
    Node *head = NULL, *prev = NULL;
    Node* sum = NULL;
    // if any one of these is left we are still left with addition
    while (first != NULL || second != NULL || carry == 1)
    {
        int newVal = carry;
        if (first)
            newVal += first->data;
        if (second)
            newVal += second->data;
        // to be used in the next node calculation
        carry = newVal / 10;
        newVal = newVal % 10;
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = newVal;
        // appending in the beginning of the final ans list,
        // this way we do not have to reverse in the end
        newNode->next = sum;
        sum = newNode;
        // initialising nodes for next iteration
 
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
 
    return sum;
}
 
//----------------------------------------------------------------------------
 
// { Driver Code Starts.
 
int main()
{
    Node* first = NULL;
    Node* second = NULL;
 
    push(&first, 7);
    push(&first, 5);
    push(&first, 9);
    push(&first, 4);
    push(&first, 6);
 
    push(&second, 8);
    push(&second, 4);
 
    Node* ans = addTwoLists(first, second);
 
    cout << "Sum is : ";
    printList(ans);
 
    return 0;
}
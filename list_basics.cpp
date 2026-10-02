#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int v) {val=v;next=nullptr;}
    Node(int v, Node* nt) {val=v; next=nt;}
};

void displayList(Node *head){
    Node *curr = head;
    while(curr != nullptr){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << "\n";
}

// inserting in linkedlist
Node* insertAtEnd(Node *head, int value){
    Node *temp = new Node(value);

    if(head->next == nullptr){
        head->next = temp;
        return head;
    }

    Node *curr = head;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
} 

Node* insertAtHead(Node *head, int value){
    Node *newHead = new Node(value);
    newHead->next = head;
    return newHead; 
}

Node* insertAtPos(Node *head, int value, int pos){
    // if pos out of range then making no change to the list and returning the list.
    if(pos <= 0){
        return head;
    }

    if(pos == 1){
        head = insertAtHead(head, value);
        return head;
    }

    Node *curr = head;
    int currPos = 1;
    bool posFound = false;
    while(currPos < pos && curr->next != nullptr){
        curr = curr->next;
        currPos++;
    }

    if(curr->next != nullptr && currPos == pos){
        Node *currPosNodeCpy = new Node(curr->val);
        currPosNodeCpy->next = curr->next;
        curr->val = value;
        curr->next = currPosNodeCpy;
    }

    return head;
}

// deleting in linkedlist
Node* deleteAtEnd(Node *head){
    Node* curr = head;
    if(head->next == nullptr){
        head = nullptr;
        return head;
    }

    while(curr->next->next != nullptr) curr = curr->next;
    curr->next = nullptr;
    return head;
}

Node* deleteAtHead(Node *head){
    if(head->next == nullptr){
        head = nullptr;
        return head;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteAtPos(Node *head, int pos){
    if (pos<=0){
        return head;
    }
    
    if(pos == 1){
        head = deleteAtHead(head);
        return head;
    }

    Node *curr = head;
    int currPos = 1;

    while (currPos < pos-1 && curr->next != nullptr){
        curr = curr->next;
        currPos++;
    }

    if (curr->next != nullptr && currPos == pos-1){
        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
        return head;
    }
    return head;
}

// generate linkedlist from array
Node* generateFromVector(vector<int> array){
    if (array.size() == 0) {
        return nullptr;
    }

    Node* head = new Node(array[0]);
    Node* curr = head;
    for (int i = 1; i < array.size(); i++){
        Node* node = new Node(array[i]);
        curr->next = node;
        curr = curr->next;
    } 
    return head;
}

// reverse the linked list
Node* reverse(Node* head){
    if (head == nullptr || head->next == nullptr) return head;

    Node* temp = nullptr;
    Node* temp2 = nullptr;
    while(head != nullptr){
        temp2 = head->next;
        head->next = temp;
        temp = head;
        head= temp2;
    }
    head = temp;
    return head;
} 

// reverse the linkedlist from position left to position right
Node* reverseBetween(Node* head, int left, int right) {
    if (head == nullptr || left == right) {
        return head;
    }

    int currPos = 1;
    Node* curr = nullptr;              
    Node* newHead = head;              
    while (currPos != left) {
        curr = newHead;
        newHead = newHead->next;
        currPos++;
    }

    Node* newTail = newHead;           
    while (currPos != right) {
        newTail = newTail->next;
        currPos++;
    }

    Node* temp = newTail->next;        
    Node* temp2 = nullptr;
    while (currPos >= left) {          
        temp2 = newHead->next;
        newHead->next = temp;
        temp = newHead;
        newHead = temp2;
        currPos--;
    }

    if (curr == nullptr) {             
        head = newTail;
    } else {
        curr->next = newTail;
    }
    return head;
}


int main(){
    Node *tail = new Node(5);
    Node *third= new Node(12, tail);
    Node *second = new Node(15, third);
    Node *head = new Node(32, second);

    cout << "### Inserting into linkedlist ###" << endl;
    head = insertAtEnd(head, 87);
    displayList(head);
    head = insertAtHead(head, 1);
    displayList(head);
    head = insertAtPos(head, 2, 2);
    displayList(head);

    cout << "\n### Deleting from linkedlist ###" << endl;
    head = deleteAtEnd(head);
    displayList(head);
    head = deleteAtHead(head);
    displayList(head);
    head = deleteAtPos(head, 2);
    displayList(head);

    cout << "\n### New Linked list and reversing it###" << endl;
    head = generateFromVector({1,2,4,3,2,5,6});
    displayList(head);
    head = reverse(head);
    displayList(head);
    reverseBetween(head, 2,4);
    displayList(head);
    return 0;
}
#include <iostream>

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    Node* getHead(){
        return this->head;
    }
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }
    void insertInMiddle(int value, int position)
    {
        if (position <= 0)
        {
            std::cout << "Invalid Position" << std::endl;
            return;
        }
        if (head == nullptr)
        {
            insertAtBeginning(value);
        }
        if (position == 1)
        {
            insertAtBeginning(value);
        }
        Node *aux = head;
        Node *newNode = new Node;
        newNode->data = value;

        int i = 0;
        while (aux != nullptr && i < position - 2)
        {
            aux = aux->next;
            i++;
        }
        if (aux == nullptr)
        {
            std::cout << "Position out of bounds. Inserting at the end of the list." << std::endl;
            insertAtTail(value); // Insert at the end of the list if position is too large
            return;
        }
        newNode->next = aux->next;
        aux->next = newNode;
    }
    void insertAtTail(int value)
    {
        if (head == nullptr)
        {
            insertAtBeginning(value);
            return;
        }
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        Node *aux = head;

        while (aux->next != nullptr)
        {
            aux = aux->next;
        }
        aux->next = newNode;
    }
    void deleteNode(int position)
    {
        if (position <= 0)
        {
            std::cout << "Invalid Position" << std::endl;
            return;
        }
        if (head == nullptr)
        {
            std::cout << "List is empty";
            return;
        }
        if (position == 1)
        {
            delete head;
            head = head->next;
            return;
        }
        else
        {
            int j = 1;
            Node *temp = head;
            while (temp != nullptr && j < position - 1)
            {
                temp = temp->next;
            }
            if (temp == nullptr || temp->next == nullptr)
            {
                std::cout << "Ran out bounds" << std::endl;
                return;
            }
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }
    void reverseLinkedList()
    {
        if (head == nullptr)
        {
            std::cout << "Impossible to reverse an empty list" << std::endl;
            return;
        }
        if (head->next != nullptr)
        {
            Node *current, *prev, *aux=current->next;
            current = head;
            prev = nullptr;

            while (current != nullptr)
            {
                aux = current->next;  // address of the next node
                current->next = prev; // Here I make the link
                prev = current;
                current = aux;
            }
            head = prev;
        }
        else
        {
            return;
        }
    }
    void printList()
    {
        if (head == nullptr)
        {
            std::cout << "The list is empty" << std::endl;
            return;
        }
        Node *x = head;
        while (x != nullptr)
        {
            std::cout << x->data << " ";
            x = x->next;
        }
        std::cout << std::endl;
    }
    void printListByRecursion(Node* p){
        if(p==nullptr){
            std::cout<<std::endl;
            return;
        }
        std::cout<<p->data<<" ";
        printListByRecursion(p->next);
        
    }
    void printReverseOrderByRecursion(Node* p){
       
        if(p==nullptr){
            std::cout<<std::endl;
            return;
        }
        printReverseOrderByRecursion(p);
        std::cout<<p->data<<" ";

    }

};

int main()
{
    LinkedList* myList=new LinkedList();

    myList->insertAtTail(10);
    myList->insertAtTail(20);
    myList->insertAtTail(30);
    myList->insertAtTail(40);
    myList->insertInMiddle(35,5);
    myList->reverseLinkedList();
    myList->printListByRecursion(myList->getHead());
    

    return 0;
}
#include<iostream>


struct Node{
    int data;
    Node* next;
    Node* prev;
};

class List{

private:
    Node* head;

public:
    List(){
      head=nullptr;  
    }
    void insertAtHead(int value){
        Node* newNode=new Node;
        newNode->data=value;
        
        if(head==nullptr){
            newNode->prev=nullptr;
            newNode->next=nullptr;
            head=newNode;
        }
        else{
            newNode->prev=nullptr;
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }
    void insertAtTail(int value){
        Node* newNode=new Node;
        newNode->data=value;
        newNode->next=nullptr;
        if(head==nullptr){
            newNode->prev=nullptr;
            head=newNode;
        }
        else{ 
        Node*aux=head;
        while(aux->next!=nullptr){
            aux=aux->next;
        }
        newNode->prev=aux;
        aux->next=newNode;
        }
    }


    void print(){
        Node* aux=head;
        while(aux!=nullptr){
            std::cout<<aux->data<<" ";
            aux=aux->next;
        }
        std::cout<<std::endl;
    }
    void printReverse(){
        Node*aux=head;

        if(head==nullptr){
            throw std::empty("List is empty");
        }
        else{
            while(aux->next!=nullptr){
                aux=aux->next;
            }
            while(aux!=nullptr){
                std::cout<<aux->data<<" ";
                aux=aux->prev;
            }
            std::cout<<std::endl;
        }
    }

    void reverseLinkedList(){
        if(head==nullptr){
            throw std::empty("Linked List is empty");
        }
        
    Node *current,*prev,*nextElement;

    current=head;
    prev=nullptr;
     
    while(current!=nullptr){
        nextElement=current->next;
        current->next=prev;
        prev=nextElement;

    }



        
    }


    ~List(){
        Node* current=head;
        while(current!=nullptr){
            Node* nextNode = current->next;
            delete current;
            current=nextNode;
        }
    }

};


int main(){


    List myList;
    myList.insertAtHead(10);
    myList.insertAtTail(100);
    myList.insertAtTail(90);
    myList.insertAtTail(80);
    myList.insertAtTail(60);

    myList.reverseLinkedList();
    myList.print();







    return 0;
}
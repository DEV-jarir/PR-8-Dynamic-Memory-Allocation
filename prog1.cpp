#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist{
    public:
        Node* head;
        int size;

    Linkedlist()
    {
        this->head = NULL;
        this->size = 0 ;
    }

    void insertAtstart(int data)
    {
        Node* newNode = new Node(data);
        newNode->next = this->head;
        head = newNode;
        this->size++;
    }

    void insertAtend(int data)
    {
        Node* newNode = new Node(data);
        if(this->head == NULL)
        {
            this->head = newNode;
        }
        else
        {
            Node* ptr = this->head;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
        this->size++;
    }

    void search_opration(int element) {
        Node* ptr = head;
        int position = 1;

        while (ptr != NULL) {
            if (ptr->data == element) {
                cout << element << " Found at " << position <<" Position "<< "."<<endl;
                return;
            }
            ptr = ptr->next;
            position++;
        }

        cout << element << " Oooops ! Not Found "<<endl;
    }

    void delete_node(int index)
    {
        if(this->head == NULL)
        {
            cout<<"List is Empty!"<<endl;
            return;
        }
        if(index == 0)
        {
            this->head = this->head->next;
            cout<<"Deleted Successfully."<<endl;
        }
        else
        {
            Node* current = this->head;
            for(int i = 0; i < index - 1;i++)
            {
                current = current->next;
            }
            current->next = current->next->next;
            cout<<"Deleted Successfully."<<endl;
        } 
        this->size--;
    }

    void reversing_Linkedlist() {
        Node* previous = NULL;
        Node* current = this->head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        this->head = previous;
        cout << "List Reversed Successfully.\n";
    }

    void display()
    {
        if(this->head == NULL)
        {
            cout<<"List is Empty!"<<endl;
            return;
        }
        Node* ptr = this->head;
        cout<<"Linked List : ";
        while(ptr != NULL)
        {
            cout<<ptr->data<<" - ";
            ptr = ptr->next;
        }
        cout<<"0"<<endl;//NULL=0
    }
};

int main()
{
    Linkedlist list;
    int choice,element,index;

    do
    {
        cout<<endl<<"<----------------Dynamic Memory Allocation---------------->"<<endl;
        cout<<"Enter 1 for Insert at Start"<<endl;
        cout<<"Enter 2 for Insert at End"<<endl; 
        cout<<"Enter 3 Search Element"<<endl;
        cout<<"Enter 4 Reverse Linkedlist"<<endl;
        cout<<"Enter 5 Display list"<<endl;
        cout<<"Enter 6 Delete list"<<endl;
        cout<<"Enter 0 exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1 :
                cout<<"Enter Element : ";
                cin>>element;
                list.insertAtstart(element);
                break;
            case 2 :
                cout<<"Enter Element : ";
                cin>>element;
                list.insertAtend(element);
                break;
            case 3 :
                cout<<"Enter Element You want to Search : ";
                cin>>element;
                list.search_opration(element);
                break;
            case 4 :
                list.reversing_Linkedlist();
                list.display();
                break;
            case 5 :
                list.display();
                break;
            case 6 :
                cout<<"Enter Index Value for Delete : ";
                cin>>index;
                list.delete_node(index);
                list.display();
                break;
            case 0 :
                cout<<"Exiting..!!!"<<endl;
                break;
            default :
                cout<<"Invalid choice!"<<endl;
        }
    } while (choice != 0);

    return 0;

}
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class SLL
{
public:
    node *head;

    SLL()
    {
        head = NULL;
    }

    void insert(int val)
    {
        node *n = new node(val);

        if (head == NULL)
        {
            head = n;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
    }

    void lsearch(int val)
    {
        node *temp = head;
        int count = 1;
        while (temp->next != NULL)
        {
            if (temp->data == val)
            {
                cout << "element found at position " << count << endl;
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << "Node not found! " << endl;
    }

    void reverse(){
        node *prev,*next1,*curr=head;
        prev=next1=NULL;
        while (curr!=NULL)
        {
            next1=curr->next; //next1 points to next node of curr.
            curr->next=prev; //Reverses curr pointer to point to prev.
            //Move pointers one position ahead.
            prev=curr;
            curr=next1;
        }
        head=prev;
    }

    void sort()
    {
        node *first = head;
        node *second = NULL;

        while (first != NULL)
        {
            second = first->next;

            while (second != NULL)
            {
                if (first->data > second->data)
                {
                    int swap = first->data; //Will swap the first element with the second element if larger.
                    first->data = second->data;
                    second->data = swap;
                }
                second = second->next;
            }
            first = first->next;
        }
    }
    void merge(SLL s1)
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = s1.head;
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    SLL list1, list2, list3, list4, list5;

    int ch, value, search_val;

    do
    {
        cout <<"---------SLL MENU---------"<<endl;
        cout << "1. Insert "<<endl;
        cout << "2. Search "<<endl;
        cout << "3. Reverse "<<endl;
        cout << "4. Sort "<<endl;
        cout << "5. Merge "<<endl;
        cout << "6. Display "<<endl;
        cout << "7. Exit "<<endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the value to be inserted: ";
            cin >> value;
            list1.insert(value);
            break;

        case 2:
            cout << "Enter the value to be searched: ";
            cin >> search_val;
            list1.lsearch(search_val);
            break;

        case 3:
            list1.reverse();
            cout << "Linked List has been reversed" << endl;
            break;

        case 4:
            list1.sort();
            cout << "Linked List has been sorted" << endl;
            break;

        case 5:
            int size;
            cout<<"Enter the size of the second linked list :";cin>>size;
            cout << "Enter the values of the second linked list: " << endl;

            for (int i = 0; i < size; i++)
            {
                cin >> value;
                list2.insert(value);
            }

            list1.merge(list2);
            cout << "The two linked lists have been merged" << endl;
            break;

        case 6:
            list1.display();
            break;

        case 7:
            exit(0);

        default:
            cout << "Invalid choice" << endl;
        }
    } while (ch != 7);

    return 0;
}
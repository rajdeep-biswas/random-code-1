#include<iostream> //this has some issues i couldn't decipher
#include<conio.h>
#include<ducky.h>

using namespace std;

class NODE
{
public:
    int info;
    NODE *prev, *nxt;
    NODE()
    {
        info = 0;
        prev = nxt = NULL;
    }
};

class QUEUE
{
    NODE *front, *rear;
public:
    void insertRear()
    {
        NODE *ele = new NODE;
        if(ele == NULL)
        {
            cout<<"Memory Overflow"<<endl;
            return;
        }
    cout<<"Enter the element to insert: ";
    cin>>ele -> info;
    if(rear == NULL)
        front = ele;
    else
    {
        rear -> nxt = ele;
        ele -> prev = rear;
    }
    rear = ele;
    cout<<"Insert successful"<<endl;
    }

    void insertFront()
    {
        NODE *ele = new NODE;
        if(ele == NULL)
        {
            cout<<"Memory Overflow"<<endl;
            return;
        }
        cout<<"Enter the element to insert: ";
        cin>>ele -> info;
        if(rear == NULL)
            rear = ele;
        else
        {
            front -> prev = ele;
            ele -> nxt = front;
        }
        front = ele;
        cout<<"Insertion Successful"<<endl;
    }

    void deleteFront()
    {
        if(front == NULL)
        {
            cout<<"Queue Underflow"<<endl;
            return;
        }
        cout<<"The element deleted is "<<front -> info<<endl;
        NODE *cur = front;
        front = front -> nxt;
        if(front == NULL)
            rear = NULL;
        else
            front -> prev = NULL;
        delete cur;
    }

    void deleteRear()
    {
        if(rear == NULL)
        {
            cout<<"Queue Underflow"<<endl;
            return;
        }
        cout<<"The element deleted is "<<rear -> info<<endl;
        NODE *cur = rear;
        rear = rear -> prev;
        if(rear == NULL)
            front = NULL;
        else
            rear -> nxt = NULL;
        delete cur;
    }

    void displayFwd()
    {
        if(front == NULL)
        {
            cout<<"Nothing to display"<<endl;
            return;
        }
        NODE *cur = front;
        cout<<"Front -> ";
        while(cur != NULL)
        {
            cout<<cur -> info<<" --> ";
            cur = cur -> nxt;
        }
        cout<<"Rear"<<endl;
    }

    void displayRev()
    {
        if(rear == NULL)
        {
            cout<<"Nothing to display"<<endl;
            return;
        }
        NODE *cur = rear;
        cout<<" <-- Rear";
        while(cur != NULL)
        {
            cout<<cur -> info<<" <-- ";
            cur = cur -> prev;
        }
        cout<<"Front"<<endl;
    }
};

int main()
{
    QUEUE q;
    int ch;
    do
    {
        clrscr();
        cout<<"MENU"<<endl;
        cout<<"Enter 1 to Insert at Rear"<<endl;
        cout<<"Enter 2 to Insert at Front"<<endl;
        cout<<"Enter 3 to Delete at Front"<<endl;
        cout<<"Enter 4 to Delete at Rear"<<endl;
        cout<<"Enter 5 for Show Forward"<<endl;
        cout<<"Enter 6 for Show Backward"<<endl;
        cout<<"Enter 7 to Exit\n"<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1: q.insertRear();
                break;
            case 2: q.insertFront();
                break;
            case 3: q.deleteFront();
                break;
            case 4: q.deleteRear();
                break;
            case 5: q.displayFwd();
                break;
            case 6: q.displayRev();
                break;
            case 7: cout<<"Thanks";
                return 0;
        }
        getch();

    }while(ch != 7);

    return 0;
}


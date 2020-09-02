#include <iostream>
#include <windows.h>
#include <conio.h>

#define max 5

using namespace std;

class QUEUE
{
    int *Q, front, rear;
public:
    QUEUE()
    {
        Q = new int [max];
        front = rear = 0;
    }
    void ENQ();
    void DEQ();
    void DISPLAY();
};

void QUEUE :: ENQ()
{
    if(rear == max)
    {
        cout<<"Queue Overflow"<<endl;
        return;
    }
    cout<<"Enter the element to insert: ";
    cin>>Q[rear++];
    cout<<"Insertion successful"<<endl;
}

void QUEUE :: DEQ()
{
    if(front == rear)
    {
        cout<<"Queue Underflow"<<endl;
        return;
    }
    cout<<"The element deleted is "<<Q[front++]<<endl;
}

void QUEUE :: DISPLAY()
{
    if(front == rear)
    {
        cout<<"Nothing to display"<<endl;
        return;
    }
    cout<<"Front <-- ";
    for(int i=front; i<front+noele; i++) // note at second year: i guess it must have been "i < front + rear" (since "noele" hasn't even been declared)
        cout<<Q[i]<<" <-- ";
    cout<<"Rear"<<endl;
}

int main()
{
    QUEUE queue;
    int ch;
    do
    {
        system("cls");
        cout<<"Enter\n1. to Enqueue\n2. to Dequeue\n3. to Show All\n4. Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1: queue.ENQ();
                break;
            case 2: queue.DEQ();
                break;
            case 3: queue.DISPLAY();
                break;
            case 4: cout<<"Thanks!"<<endl;
                break;
            default: cout<<"Wrong Input"<<endl;
                break;
        }
        getch();
    }
    while(ch!=4);
    return 0;
}

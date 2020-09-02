#include <iostream>
#include <conio.h>
#include <windows.h>

#define max 5

using namespace std;

class QUEUE
{
    int *Q, front, rear, noele;
public:
    QUEUE()
    {
        Q = new int[max];
        front = rear = noele = 0;
    }
    void INSERT();
    void DLETE();
    void DISPLAY();
};

void QUEUE :: INSERT()
{
    if(noele == max)
    {
        cout<<"Queue Overflow"<<endl;
        return;
    }
    cout<<"Enter the element to insert: ";
    cin>>Q[rear];
    rear = (rear+1) % max;
    noele++;
    cout<<"Insertion Successful"<<endl;
}

void QUEUE :: DLETE()
{
    if(noele == 0)
    {
        cout<<"Queue Underflow"<<endl;
        return;
    }
    cout<<"The element deleted is "<<Q[front]<<endl;
    front = (front+1) % max;
    noele--;
}

void QUEUE :: DISPLAY()
{
    if(noele == 0)
    {
        cout<<"Nothing to display"<<endl;
        return;
    }
    cout<<"Front <-- ";
    for(int i=front; i<front+noele; i++)
        cout<<Q[i%max]<<" <-- ";
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
            case 1: queue.INSERT();
                break;
            case 2: queue.DLETE();
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

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

using namespace std;

class NODE
{
public:
    int info;
    NODE *nxt;
    NODE()
    {
        info = 0;
        nxt = NULL;
    }
};

class STACK
{
    NODE *top;
public:
    STACK()
    {
        top = NULL;
    }
    void PUSH();
    void POP();
    void DISPLAY();
};

void STACK :: PUSH()
{
    NODE *ele = new NODE;
    if(ele == NULL)
    {
        cout<<"Memory Overflow"<<endl;
        return;
    }
    cout<<"Enter the element to push: ";
    cin>>ele -> info;
    ele -> nxt = top;
    top = ele;
    cout<<"Push Successful"<<endl;
}

void STACK :: POP()
{
    if(top == NULL)
    {
        cout<<"Memory Underflow"<<endl;
        return;
    }
    cout<<"The element popped is "<<top -> info<<endl;
    NODE *cur = top;   // PREVENTS
    top = top -> nxt;  // MEMORY
    delete cur;       // LEAKING
}

void STACK :: DISPLAY()
{
    if(top == NULL)
    {
        cout<<"Nothing to Display"<<endl;
        return;
    }
    NODE *cur = top;
    cout<<"_Top_"<<endl;
    while(cur != NULL)
    {
        cout<<setw(3)<<cur -> info<<endl;
        cur = cur -> nxt;
    }
    cout<<"_Bottom_"<<endl;
}

int main()
{
    STACK thunder;
    int ch;
    do
    {
        system("cls");
        cout<<"Enter\n1. to Push\n2. to Pop\n3. to Show All\n4. Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1: thunder.PUSH();
                break;
            case 2: thunder.POP();
                break;
            case 3: thunder.DISPLAY();
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

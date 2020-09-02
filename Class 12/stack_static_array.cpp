#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

#define max 5

using namespace std;

class STACK
{
    int stk[max], top=0;
public:
    void PUSH();
    void POP();
    void DISPLAY();
};

void STACK :: PUSH()
{
    {
        if(top == max)
        {
            cout<<"Memory Overflow"<<endl;
            return;
        }
    }
    cout<<"Enter the element to push: ";
    cin>>stk[top++];
    cout<<"Push Successful"<<endl;
}

void STACK :: POP()
{
    if(top == 0)
    {
        cout<<"Memory Underflow"<<endl;
        return;
    }
    cout<<"The element popped is "<<stk[--top]<<endl;
}

void STACK :: DISPLAY()
{
    if(top == 0)
    {
        cout<<"Nothing to Display"<<endl;
        return;
    }
    cout<<"_Top_"<<endl;
    for(int i=top-1; i>=0; i--)
        cout<<setw(3)<<stk[i]<<endl;
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

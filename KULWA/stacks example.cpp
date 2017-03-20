#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;



void push(int);

void pop();
void clr();
bool isEmpty();
bool isFull();
const int maxx = 10;
int stacks[maxx];
int top=0;
void show ();




int main ()
{
int temp;



    int pil;
    int nilai;

    do
    {
        system ("cls");



        cout<<"1. Push "<<endl;
        cout<<"2. Pop "<<endl;
        cout<<"3. Clear "<<endl;
        cout<<"4. Show Stacks "<<endl;
        cout<<"5. Exit "<<endl;

        cout<<"Masukan Pilihan : ";
        cin>>pil;
        cout<<endl<<endl;


        switch(pil)
        {


        case 1 :
              if (!isFull())
            {

                cout<<"Masukan Nilai : ";
                cin>>nilai;



                push (nilai);
                break;


            }
            else
            {
                cout<<"The STACKS is Full "<<endl;
                getch();




            }

        case 2 :
            if (!isEmpty())
            {

                pop();
            }

            else
            {
               cout<<"The STACKS is Empty "<<endl;
            }
            break;

        case 3 :
            clr();
            break;

        case 4 :
            show();
            break;

        }


    }
    while (pil!=5);


}

void push (int value)
{
stacks[top]=value;
top++;

}

void pop ()
{

stacks[top-1]= NULL ;
top--;

}

void clr ()
{
    for(int a = 0 ; a<maxx; a++)
    {
        stacks[a]=NULL;
    }
top=0;

}
void show ()
{
    system("cls");
    for (int a = 0 ; a <top ; a++)
    {
        cout<<stacks[a]<<" ";
    }

    getch();

}

bool isEmpty()
{
    if (top==0)
        return true;

    else
        return false;
}

bool isFull()
{
    if (top==maxx)
        return true;

    else
        return false;
}

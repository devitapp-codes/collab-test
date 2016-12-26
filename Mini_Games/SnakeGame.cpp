//STILL NOTHING..

// clearsreen is annoying..

// Edit Sesukamu ..

#include <iostream>
#include <conio.h>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
using namespace std;


const int panjang =20;
const int lebar =20;


class snake {


public :
    char snake ;
    int x;
    int y;


}s;
int foodx;
int foody;
char food;
bool gameover;
char key;


void draw ();
void setup();
void input();
void logic ();
void menu ();
bool maps (int a, int b);
void play();
bool snakepos(int a,int b);




int main () {
    srand(time(0));


    setup();
    //menu();
play();



}

void setup() {

gameover=true;

    s.snake='^';
    food = 'o';
    s.y=panjang/2;
    s.x=lebar/2;
    foody = rand()%panjang;
    foodx = rand()%lebar;

    if (foody<2 )foody+2;
    if (foodx<2)foodx+2;

}


void play()
{
    while (gameover)
    {
        draw();
        input();
        logic();

    }


}

void draw () {
    system ("cls");


    for (int a=1; a<=panjang; a++) {
        for (int b=1; b<=lebar; b++) {
            if (maps(a,b)  )
                cout<<"#";

            else if (snakepos(a,b))
                cout<<s.snake;


            else if (a==foody && b==foodx)
                cout<<food;






            else cout<<" ";

        }
        cout<<endl;

    }
cout<<"W A S D To Move ";


}



void logic()
{

    if (key==72 || key=='w'){
            s.y--;

        }
            else if (key==80 || key=='s'){
                s.y++;

            }

            else if (key==75 || key=='a')
            {

                s.x--;
            }

            else if (key==76 || key=='d')
            {
                s.x++;
            }

            else if (key==27)
            {
                gameover=false;
            }





}

void input()
{
    bool input=true;

    while (input)
    {

        if (kbhit())
        {
            key=getch();
            input=false;




        }



    }

}


bool maps (int a,int b) {
    if (a==1 || b==1 || a==panjang || b==lebar)
        return true;

    else return false;

}

bool snakepos (int a, int b) {



    if (a==s.y &&  b ==s.x)
        return true;

    else return false;
}

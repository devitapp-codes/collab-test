//Flikering Screen Is Fix....

//gotoxy its really helpfull..

//kurang ekornya aja,, masih binggung wwkwkk,,,

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


class Food
{

public :

  char bigfood='O';
  char food='o';

  int x;
  int y;


};

class Snake {


public :
    char snake ;
    int x;
    int y;


};

bool gameover;
char key;
double speed;
int score;
char tail;
int tails[100];
int jumlahtails;
Snake snake;
Food food;



void draw ();
void setup();
void input();
void logic ();
void gotoxy(int x, int y);
void menu ();
void maps ();
void play();
bool snakepos(int a,int b);




int main () {
    srand(time(0));


    setup();
    //menu();
play();



}

void setup() {

maps();
gameover=true;
speed=100;
jumlahtails=0;
score=0;
    snake.snake='^';

    snake.y=panjang/2;
    snake.x=lebar/2;
    food.x = rand()%panjang-1;
    food.y = rand()%lebar-1;

    if (food.x<2 )food.x+=2;
    if (food.y<2)food.y+=2;

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



//system("cls");


             gotoxy(snake.x,snake.y);

                cout<<snake.snake;


            gotoxy(food.x,food.y);
            if(rand()%10==5)
                cout<<food.bigfood;
            else cout<<food.food;






gotoxy(panjang+2 , 0);
cout<<"SCORE : "<<score;
gotoxy(panjang+5 , 10);
cout<<" W A S D To Move";

}



void logic()
{

    if (key==72 || key=='w'){
            gotoxy(snake.x,snake.y);
            cout<<" ";
            snake.y--;
            snake.snake='^';

        }
            else if (key==80 || key=='s'){
 gotoxy(snake.x,snake.y);
            cout<<" ";
                snake.y++;
                snake.snake ='v';


            }

            else if (key==75 || key=='a')
            {gotoxy(snake.x,snake.y);
            cout<<" ";

                snake.x--;
                snake.snake='<';
            }

            else if (key==76 || key=='d')
            {gotoxy(snake.x,snake.y);
            cout<<" ";
                snake.x++;
                snake.snake='>';
            }

            else if (key==27)
            {
                gameover=false;
            }


    if (snake.x == food.x && snake.y == food.y)
    {
        jumlahtails++;
        food.x=rand()%lebar-1;;
        food.y=rand()%panjang-1;;

        if (food.y<2 )food.y+=2;
    if (food.x<2)food.x+=2;
        score+=10;

        speed-=1;
    }


if (snake.x==lebar-1)
snake.x=1;

if (snake.y==panjang-1)
snake.y=1;
if (snake.x==0)
snake.x=lebar-2;

if(snake.y==0)
snake.y=panjang-2;





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

        Sleep(speed);
        input=false;



    }

}


void maps () {

for (int a=0;a<panjang;a++){

    for (int b=0;b<lebar;b++)
    {



    if (a==0|| b==0 || a==panjang-1 || b==lebar-1)
        cout<<"#";
        else cout<<" ";

}cout<<endl;
}
cout<<endl<<endl;

}
bool snakepos (int a, int b) {



    if (a==snake.y &&  b ==snake.x)
        return true;

    else return false;
}


void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

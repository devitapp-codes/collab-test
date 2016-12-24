
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;
bool gameover;
time_t currentTime;
struct tm *localTime;
int benar;
int countdown;
int salah;
char ketik[100][64];
int data=0;
int kata=1;
int colour[16];
int warnahuruf[20][20];
int bestscore[5];
struct {
    string name;
    double nilai;
} person[100];

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
char teks [25][64] = {"ketika ","kamu ","setiap ","aku ","jangan ","kelas ","bagi ","sedap ",
                      "makan ","siang ","dari ","tadi ","kamu ","cantik ","sekali ","diam ","tanpa ",
                      "kata ","selalu ","pada ","terima ","dewa ","nanda ","keren ","sekali "
                     };
int random[15];
void sorting ();
void randomarray();
void draw ();
void input(int );
//void setup();
void logic();
void submitscore(double s);
//void ketik ();
int main  () {






    srand(time(0));
    int pil;
    do {
        countdown=15;

        for (int a=0; a<=15; a++) {
            for(int b=0; b<=15; b++) {
                warnahuruf[a][b]=7;
            }
        }
        system("cls");

        cout<<"Welcome To Type Fast Mini Game Created By @Dewa"<<endl;
        cout<<"================================================="<<endl;
        cout<<"1. Play Game "<<endl;
        cout<<"2. See High Score "<<endl;
        cout<<"3. How To Play "<<endl;
        cout<<"4. Update News "<<endl;
        cout<<"5. Quit "<<endl;

        cout<<"Masukan Pilihan : ";
        cin>>pil;
        switch (pil) {

          case 4 : system("cls");
          cout<<"New Feature "<<endl;
          cout<<"- Timeout Added"<<endl;
          cout<<"- Menggunakan spasi setelah kata di ketik "<<endl;
          cout<<"- Setiap huruf highlighted jika huruf yang anda masukan benar"<<endl;


          getch();
          break;

        case 2 :

            if (data==0) {
                system("cls");
                cout<<"There's No Data! "<<endl;
                getch();
            }

            else {
                if (data>1) sorting();


                system("cls");
                int b=1;
                for (int a=data-1; a>=0; a--) {
                    cout<<b<<".\t";
                    cout<<"Name\t: "<<person[a].name<<endl;
                    cout<<"\tSCORE\t: "<<person[a].nilai<<endl<<endl<<endl;;
                    b++;
                }
                getch();
            }
            break;

        case 3 :
            system("cls");
            cout<<"How to play : \nKetik kalimat per kata yang tetera pada layar, lalu tekan spasi ";
            cout<<"\njika teks berubah menjadi hijau berarti teks yang anda masukan benar ";
            cout<<"\ndan merah jika salah, jika waktu habis maka game selesai";

            getch();
            break;


        case 1 :



            system ("cls");
            benar=0;
            salah=0;

            randomarray();




            logic();
            system("cls");


            cout<<"Teks Yang Benar Diketik : "<<benar<<endl;
            cout<<"Teks Yang Salah Diketik : "<<salah<<endl;


if (countdown==0)countdown++;


            float score = (benar*countdown*100)/15-(salah*2);
            cout<<"SCORE :  "<<score<<endl<<endl;

            cout<<"1. Submit Score"<<endl;
            cout<<"2. Back To Menu "<<endl;
            cout<<"Masukan Pilihan : ";
            cin>>pil;

            if (pil==1) {
                submitscore(score);
            }

        }

    } while(pil!=5);


}

void randomarray() {
    for (int a=0; a<=15; a++) {
        random[a]=rand()%25;
    }
}









void draw () {


    system("cls");


    for (int a=1; a<=15; a++) {
        for (int b = 0; b<strlen(teks[random[a]]); b++) {

            SetConsoleTextAttribute(hConsole, warnahuruf[a][b] );
            cout<<teks[random[a]][b];



        }
        //cout<<" ";


        if(a==8)cout<<endl;
    }
    SetConsoleTextAttribute(hConsole, 7 );

    cout<<endl<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Type : "<<ketik[kata]<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\t\t"<<"\t| Timeout "<<countdown<<" |"<<endl;


}

void logic () {
int a=1;
    bool selesai;
    bool gameover=true;

string hasil;
    while(gameover) {
        selesai=true;
int b=0;
        while(selesai) {

                if (countdown==0){selesai=false;
                gameover=false;}
if (a==15)gameover=false;


            draw();
            input(a);



       if (ketik[kata][b]=='\0'){
            b--;

        }


            if (ketik[kata][b] == teks [random[a]][b]) {

            warnahuruf[a][b]=15;
        }


hasil=ketik[kata];
if (ketik[kata][b]==' ' ||ketik[kata][b]=='\n' )selesai=false;

        b++;

            }
            if (hasil==teks[random[a]]) {
                for(int b=strlen(teks[random[a]]); b>=0; b--)
                    warnahuruf[a][b]=10;


                benar++;
        }
        else {
        for(int b=strlen(teks[random[a]]); b>=0; b--)
                    warnahuruf[a][b]=12;
                    salah++;
        }



        a++;
        kata++;


    }
}



void input (int a) {

    bool keluar=true;

    time( &currentTime );
    localTime = localtime( &currentTime );

    int out    = localTime->tm_sec;
    int len=strlen(ketik[kata]);

    while (keluar) {

        time( &currentTime );
        localTime = localtime( &currentTime );

        int out2    = localTime->tm_sec;


        if (kbhit())

        {
            char  key = getch();
            if (key=='\b') {
                ketik[kata][len-1]='\0';
                warnahuruf[a][len-1]=7;
                keluar=false;

            }

            else {
                ketik[kata][len]=key;

                keluar=false;
            }
        }


        if (out!=out2) {
            keluar=false;

            countdown--;
        }
    }





}



void submitscore(double s) {
    system("cls");
    cout<<"YOUR SCORE = "<<s<<endl;
    cout<<"Enter Name : ";
    cin>>person[data].name;
    person[data].nilai=s;
    data++;

}
void sorting () {
    int temp;
    string tempnama;
    int maks;
    int u=data-1;
    for (int a=0; a<data-1; a++) {
        maks=0;
        for (int b=1; b<=u; b++) {
            if (person[b].nilai>person[maks].nilai) {
                maks =b;
            }
        }
        temp = person[u].nilai;
        tempnama = person[u].name;
        person[u].nilai = person[maks].nilai;
        person[u].name = person[maks].name;

        person[maks].nilai= temp;
        person[maks].name=tempnama;
        u--;

    }

}


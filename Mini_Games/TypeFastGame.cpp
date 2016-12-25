//Berkedip-kedip ketika di clearscreen, Kalo Ada Punya Solusi  yang lain selain clearscreen,
//bisa Di bantu,, di fungsi Void Draw
//this code is bad programming technique, masih asal-asalan..
//yang mau edit monggo...

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;
bool gameover;
time_t currentTime;
struct tm *localTime;
int data=0;
int benar;
int countdown;
int salah;
char ketik[64][64];
int   mulai;
int kata;
int colour[16];
int warnahuruf[100][100];
int bestscore[5];
struct {
    string name;
    double nilai;
} person[100];

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


char teks [35][64] = {"ketika","kamu","setiap","aku","jangan","kelas","bagi","sedap",
                      "makan","siang","dari","tadi","kamu","cantik","sekali","diam","tanpa",
                      "kata","selalu","pada","terima","dewa","nanda","keren","sekali"
                      ,"main","kemari","sayang","libur","berenang","tetapi","wabrazyah",
                      "makan","omteloletom","uvuvwevwev"
                     };
int random[100];
void sorting ();
void randomarray();
void draw ();
void win();
void input();
void resetketik();
void menu();
void highscore ();

void howtoplay();
void done();
//void clearbox();
void setup();
void updatenews();
void logic();
void play();
void submitscore(double s);
//void ketik ();

int main  () {

    srand(time(0));
    int pil;
    do {



            setup();


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

        case 4 :
            updatenews();
            break;

        case 2 :
            highscore();

            break;

        case 3 :
           howtoplay();
            break;


        case 1 :
           play();
           done();


           }


    } while(pil!=5);


}


void setup()
{

    resetketik();
    kata=1;
    countdown=30;

        for (int a=0; a<=100; a++) {
            for(int b=0; b<=100; b++) {
                warnahuruf[a][b]=7;
            }
        }
        system("cls");



}

void randomarray()
{


    for (int a=0; a<=100; a++) {
        random[a]=rand()%35;
    }
}









void draw () {

    system("cls");


    for (int a=1; a<=30; a++) {
        for (int b = 0; b<strlen(teks[random[a]]); b++) {

            SetConsoleTextAttribute(hConsole, warnahuruf[a][b] );
            cout<<teks[random[a]][b];



        }
        cout<<" ";


        if(a%8==0)cout<<endl;
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

            if (countdown==0) {
                selesai=false;
                gameover=false;
            }
            if (a==30 ) {
                win();
                gameover=false;
            }


            draw();

            time( &currentTime );
            localTime = localtime( &currentTime );

            int    out    = localTime->tm_sec;

            input();
            if (ketik[kata][b]==27) {
                selesai=false;
                gameover=false;
            }

            if (mulai!=out) {
                countdown-- ;
                mulai++;
                if (mulai>59)mulai=0;
            }



            if (ketik[kata][b]=='\0' &&ketik[kata][b-1]=='\0' && b!=0) {
                b--;
                warnahuruf[a][b]=7;

            }
            if (ketik[kata][b]=='\0') {
                b--;

            }


            if (ketik[kata][b] == teks [random[a]][b]) {

                warnahuruf[a][b]=15;
            }


            if (ketik[kata][b]==' ' || ketik[kata][b]==13) {
                selesai=false;

            }


else {
            hasil=ketik[kata];

            b++;

        }

        }
        if (hasil==teks[random[a]]) {
            for(int b=strlen(teks[random[a]]); b>=0; b--)
                warnahuruf[a][b]=10;


            benar++;
        } else {
            for(int b=strlen(teks[random[a]]); b>=0; b--)
                warnahuruf[a][b]=12;
            salah++;
        }



        a++;
        kata++;


    }
}



void input () {

    bool keluar=true;

    time( &currentTime );
    localTime = localtime( &currentTime );

    int    out    = localTime->tm_sec;
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

                keluar=false;

            }

            else {
                ketik[kata][len]=key;

                keluar=false;
            }
        }


        if (out!=out2) {
            keluar=false;


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


void sorting ()
{

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

void win ()
{


    if (benar==30) {
            system("cls");
        cout<<"Congratulatiaon...! Your'e The Fastest Type In The World "<<endl;

    }

}


void resetketik()
{

for (int a=1;a<=64;a++){
    for (int b=0;b<64;b++){
        ketik[a][b]='\0';

    }
}

}

void updatenews()
{
    system("cls");
            cout<<"New Update"<<endl<<endl;
            cout<<"Fix some bugs : "<<endl;
            cout<<"- Fix Time calculation "<<endl;
            cout<<"- Warna huruf kembali ke default jika dibackspace"<<endl;
            cout<<"- Fix Countdown time"<<endl;


            cout<<endl;
            cout<<"New Feature : "<<endl;
            cout<<"- Timeout Added"<<endl;
            cout<<"- Menggunakan spasi setelah kata di ketik "<<endl;
            cout<<"- Setiap huruf highlighted jika huruf yang anda masukan benar"<<endl;


            getch();
}

void highscore()
{
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
}

void howtoplay()
{
     system("cls");
            cout<<"How To Play : ";
            cout<<"- Ketik kalimat pada layar "<<endl;
            cout<<"- Jika kata yang anda masukan benar maka kata berwana hijau, Merah jika salah "<<endl;
            cout<<"- Setiap huruf akan highlightd jika huruf yang anda masukan benar "<<endl;
            cout<<"- Waktu hanya diberikan 30 detik untuk mengetik semua kata"<<endl;

            getch();
}

void play ()
{

        randomarray();

time( &currentTime );
            localTime = localtime( &currentTime );

            mulai   = localTime->tm_sec;



            system ("cls");
            benar=0;
            salah=0;






            logic();

    if (countdown==0){
            system("cls"); cout<<"TIMEOUT!!"<<endl;
    getch();
    countdown++;

    }
}
void done()
{
    int pil;
    system("cls");


            cout<<"Teks Yang Benar Diketik : "<<benar<<endl;
            cout<<"Teks Yang Salah Diketik : "<<salah<<endl;



            float score = (benar*countdown*100)/30-(salah*salah);
            cout<<"SCORE :  "<<score<<endl<<endl;

            cout<<"1. Submit Score"<<endl;
            cout<<"2. Back To Menu "<<endl;
            cout<<"Masukan Pilihan : ";
            cin>>pil;

            if (pil==1) {
                submitscore(score);

            }

}

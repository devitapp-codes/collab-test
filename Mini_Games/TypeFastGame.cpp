//dewdewadaewadwaewdewadewadewadewa
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;
int benar;
int salah;
int data=0;
int colour[16];
int bestscore[5];
    struct {
    string name;
    double nilai;
    }person[100];

 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
string teks [25] = {"ketika","kamu","setiap","aku","jangan","kelas","bagi","sedap",
"makan","siang","dari","tadi","kamu","cantik","sekali","diam","tanpa",
"kata","selalu","pada","terima","dewa","nanda","keren","sekali"};
int random[15];
void sorting ();
void randomarray();
void teksgenerate ();
void submitscore(double s);
void ketik ();
int main  () {
time_t currentTime;
  struct tm *localTime;




srand(time(0));
int pil;
do{
    for (int a=0;a<=15;a++){
            colour[a]=7;

    }
    system("cls");

    cout<<"Welcome To Type Fast Mini Game Created By @Dewa"<<endl;
    cout<<"================================================="<<endl;
    cout<<"1. Play Game "<<endl;
    cout<<"2. See High Score "<<endl;
    cout<<"3. How To Play "<<endl;
    cout<<"4. Quit "<<endl;

    cout<<"Masukan Pilihan : ";
    cin>>pil;
switch (pil){
case 2 :

    if (data==0){system("cls"); cout<<"There's No Data! "<<endl;
    getch(); }

else {
       if (data>1) sorting();


system("cls");
int b=1;
    for (int a=data-1;a>=0;a--){
        cout<<b<<".\t";
        cout<<"Name\t: "<<person[a].name<<endl;
        cout<<"\tSCORE\t: "<<person[a].nilai<<endl<<endl<<endl;;
        b++;
    }
getch();
}
    break;

case 3 : system("cls");
cout<<"Ketik kalimat per kata yang tetera pada layar, lalu tekan enter ";
cout<<"\njika teks berubah menjadi hijau berarti teks yang anda masukan benar ";
cout<<"\ndan merah jika salah";

    getch();
    break;


case 1 :

  time( &currentTime );
  localTime = localtime( &currentTime );

  int sec    = localTime->tm_sec;

system ("cls");
benar=0;
salah=0;

randomarray();

teksgenerate();
cout<<endl;

ketik();

cout<<"Teks Yang Benar Diketik : "<<benar<<endl;
cout<<"Teks Yang Salah Diketik : "<<salah<<endl;
time( &currentTime );
  localTime = localtime( &currentTime );

  int sec2    = localTime->tm_sec;
int jarak=0;
while (sec!=sec2){
sec++;
jarak++;
if (sec>59)sec=1;
}

cout<<"Anda Mengetik Dalam Waktu : "<<jarak<<" Detik"<<endl<<endl;
int sanksi;
if (jarak<=10)jarak=0;
else
sanksi=(jarak-10)*2;

float score = (benar*100)/15-(sanksi);
cout<<"SCORE :  "<<score<<endl<<endl;

cout<<"1. Submit Score"<<endl;
cout<<"2. Back To Menu "<<endl;
cout<<"Masukan Pilihan : ";
cin>>pil;

if (pil==1){
    submitscore(score);
}

}

}while(pil!=4);


}

void randomarray(){
    for (int a=0;a<=15;a++){
        random[a]=rand()%25;
    }
}


void teksgenerate (){






for (int a=1;a<=15;a++){

SetConsoleTextAttribute(hConsole, colour[a] );
cout<<teks [random[a]]<<" ";
if(a==8)cout<<endl;
}

}

void ketik () {



string ketik;

for (int a=1;a<=15;a++){
        system ("cls");
        teksgenerate();
SetConsoleTextAttribute(hConsole, 7 );
        cout<<"\n____________________________________________"<<endl;
        cout<<endl;


cin>>ketik;

if (getchar()!=32 ||getchar()!=' ')system ("cls");

if (ketik==teks [random[a]]){
benar++; colour[a]=10;}
else {salah++; colour[a]=12;}
}
}

void submitscore(double s){
system("cls");
cout<<"YOUR SCORE = "<<s<<endl;
cout<<"Enter Name : ";cin>>person[data].name;
person[data].nilai=s;
data++;

}
void sorting (){
int temp;
string tempnama;
  int maks; int u=data-1;
for (int a=0;a<data-1;a++){
    maks=0;
    for (int b=1;b<=u;b++){
        if (person[b].nilai>person[maks].nilai)
        {
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



//Games? :)  /19-09-18/
//MathewsMonoo
#include <iostream>
#include <time.h>
#include <ctype.h>
//#include <stdio.h>

using namespace std;

//prototypes:
void game1(void);
void game2(void);
void clearscreen(void);


int main(void){

char mainmenu = 0;
int choosegame = 0;

beginning:
cout << "\n\t__________________________________" << endl;
cout << "\t Welcome to simple games v0.1!!..." << endl;
cout << "\t Please select your game.........:" << endl;
cout << "\t <1> for GUESS MY NUMBER!........:" << endl;
cout << "\t <2> for GUESS MY CARD!..........:" << endl;
cout << "\t OR <0> to EXIT..................:" << endl;
cout << "\t__________________________________\t" << endl;
cin >> choosegame ; cin.ignore('80','\n');

switch (choosegame){
    case (0): goto finish; break;
    case (1): game1();  break;
    case (2): game2();  break;
    default : break;
}

cout << "\n\t Return to MAIN MENU?...:\n";
cout << "\n\t <Y/y>  -  YES............:\n";
cout << "\n\t <N/n>  -  NO..............\n";
cin >> mainmenu; cin.ignore('80','\n');
mainmenu = toupper(mainmenu);

if (mainmenu == 'Y'){
    clearscreen();
    goto beginning;
    }

finish:
clearscreen();
cout << "\n\t[ENTER] to finish.......:\n\t"; cin.get();
return 0;
}

void game1(void){
char level;
int maxnum = 0;
int generated = 0;
int guess = 0;
int again = 0;
int tries = 0;
gamestart:
cout << "\n\n\t    Guess my number!     " << endl;
cout << "\t Press [E/e] for  EASY   ; " << endl;
cout << "\t Press [M/m] for  MEDIUM ; " << endl;
cout << "\t Press [H/h] for  HARD   ; " << endl;
cin >> level; cin.ignore('80','\n');
level = toupper(level);

switch(level){
    case ('E'): maxnum = 10;  break;
    case ('M'): maxnum = 50;  break;
    case ('H'): maxnum = 100; break;
    default : clearscreen(); goto gamestart;
}
// Generating random number between 1 and 10/50/100
srand (time(NULL));
generated = rand() % maxnum + 1;

while (guess != generated){
    tries++;
    cout << "\t Guess my number (between 1 and " << maxnum << " )...:" << endl;
    insertguess:
    cin >> guess;cin.ignore('80','\n');
    if (cin.fail()){
        cout << "\t Please insert a INT number between 1 and " << maxnum <<" ...:" << endl;
        goto insertguess;
    }

    if (generated > guess)
        cout << "\tMy number is higher than " << guess << "  ." << endl;
    else if(generated < guess)
        cout << "\tMy number is lower than " << guess << "  ." << endl;
}
cout << "\n\t Congratulations !!! [ " << generated << " ] was my number!" << endl;
cout << "\tAnd it only took you [ " << tries << " ] tries! Good Job!     " << endl;
cout << "\n\t Press <1> to play again....:";
cout << "\n\t Or    <2> to leave............:";
cin >> again;cin.ignore('80','\n');
clearscreen();
if (again == 1)
    goto gamestart;
return;
}

void game2(void){
    cout << "\t             Guess my CARD!                 " << endl;
    cout << "\t____________________________________________" << endl;
    cout << "\t         You'll be guessing my              " << endl;
    cout << "\t     CARD      and it's     SUIT             " << endl;
    cout << "\t((A to King)(Hearts, Spades, Clubs, Diamonds)" << endl;


return;
}

void clearscreen(void){
    for (int i = 0; i < 60; i++)
        cout << endl;
cout << "___________________________________________________________________________________________________" << endl;
return;
}

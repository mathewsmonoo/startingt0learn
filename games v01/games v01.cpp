//Games v0.2 :)  /19-09-18/,20/09/18
//MathewsMonoo
#include <iostream>
#include <time.h>
#include <ctype.h>

using namespace std;

//prototypes:
void game1(void);
void game2(void);
void clearscreen(void);


int main(void){

char mainmenu = 0;
int choosegame = 0;

beginning:
cout << "\n\t __________________________________" << endl;
cout << "\t ....Welcome to games v0.2!!!!......" << endl;
cout << "\t Please select your game...........:" << endl;
cout << "\t <1> for 'GUESS MY NUMBER!'........:" << endl;
cout << "\t <2> for 'GUESS MY CARD!'..........:" << endl;
cout << "\t OR <0> to EXIT....................:" << endl;
cout << "\t ___________________________________\t" << endl;
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
char again;
char level;
int maxnum = 0;
int guessnum = 0;
int generatednum = 0;
int tries = 0;
clearscreen();
gamestart:
cout << "\n\t-----Guess my number!------" << endl;
cout << "\t Press [E/e] for  EASY   ; " << endl;
cout << "\t Press [M/m] for  MEDIUM ; " << endl;
cout << "\t Press [H/h] for  HARD   ; " << endl;
cin >> level; cin.ignore('80','\n');
level = toupper(level);
switch(level){
    case ('E'): maxnum = 10;  break;
    case ('M'): maxnum = 100;  break;
    case ('H'): maxnum = 1000; break;
    default : clearscreen(); goto gamestart;
}
// Generating random number between 1 and 10/50/100
srand (time(NULL));
generatednum = rand() % maxnum + 1;

while (guessnum != generatednum){
    tries++;
    cout << "\t guessnum my number (between 1 and " << maxnum << " )...:";
    cin >> guessnum;cin.ignore('80','\n');
    if (generatednum > guessnum)
        cout << "\tMy number is higher than " << guessnum << "  ." << endl;
    else if(generatednum < guessnum)
        cout << "\tMy number is lower than " << guessnum << "  ." << endl;
    }
cout << "\n\t Congratulations !!! [ " << generatednum << " ] was my number!" << endl;
cout << "\tAnd it only took you [ " << tries << " ] tries! Good Job!     " << endl;
cout << "\n\t Press <Y/y> to play again....:";
cout << "\n\t Or    <N/n> to leave............:";
cin >> again;cin.ignore('80','\n');
clearscreen();
if (again == 'y' || again == 'Y')
    goto gamestart;
return;
}

void game2(void){
string pcard[14]{"A","2","3","4","5","7","8","9","10","Q","J","K"};
string card = "";
string suit = "";
string gencard = "";
string gensuit = "";
int rndmgen = 0 ;
int tries2 = 0;
char again2 = 0;
string strsuit = "";
startgame2:
clearscreen();
cout << "\t----------------------------------------------------" << endl;
cout << "\t------------------GUESS MY CARD!--------------------" << endl;
cout << "\t----------------------------------------------------" << endl;
cout << "\t--In this game, you will guess : -------------------" << endl;
cout << "\t--My  (CARD) (from A to K) -------------------------" << endl;
cout << "\t--The card's SUIT (HEARTS, SPADES, CLUBS, DIAMONDS)-" << endl;
cout << "\t----------------------------------------------------" << endl;
cout << "\t----------------------------------------------------" << endl;
//Generating random card and suit
srand (time(NULL));
rndmgen = rand() % 12 + 1;
gencard = pcard[rndmgen - 1]; // -1 because the array starts @ x[0]
rndmgen = rand() % 4 + 1;
switch(rndmgen){
    case(1):gensuit = "HEARTS"; break;
    case(2):gensuit = "SPADES"; break;
    case(3):gensuit = "CLUBS"; break;
    case(4):gensuit = "DIAMONDS"; break;
    default:gensuit = "";
}

while(card != gencard || suit != gensuit){
    tries2++;
    cout << "\n\t  Insert CARD(A,2,3,4,5,6,7,8,9,Q,J,K)..::";
    cin >> card;   cin.ignore('80','\n');
    cout << "\n\t  Insert SUIT.............................";
    cout << "\n\t  (H for Hearts, S for Spades  )..........";
    cout << "\n\t  (C for Clubs , D for Diamonds)........::";
    cin >> suit;   cin.ignore('80','\n');
    //Converting user input to uppercase
    if (card == "a" || card == "q" || card == "j" || card == "k"){
        if(card == "a")
            card = "A";
            else if (card == "q")
                card = "Q";
                else if (card == "j")
                    card = "J";
                    else
                        card = "K";
    }
    //Converting user input to full-named suits
    if (suit == "H" || suit == "h" || suit == "S" || suit == "s" || suit == "C" || suit == "c" || suit == "D" || suit == "d"){
        if (suit == "H" || suit == "h")
            suit = "HEARTS";
            else if (suit == "S" || suit == "s")
                suit = "SPADES";
                else if (suit == "C" || suit == "c")
                    suit = "CLUBS";
                    else
                        suit = "DIAMONDS";
    }

    if(card == gencard && suit != gensuit)
        cout << "\n\tThe card [" << card << "] is RIGHT, but the SUIT [" << suit << "] is WRONG." << endl;
    if(card != gencard && suit == gensuit)
        cout << "\n\tThe card [" << card << "] is WRONG, but the SUIT [" << suit << "] is RIGHT." << endl;
    if(card != gencard && suit != gensuit)
        cout << "\n\tBoth CARD [" << card << "] and SUIT [" << suit << "] are WRONG." << endl;
}
cout << "________________________________________" << endl;
cout << "\n\n\tCONGRATULATIONS!         " << endl;
cout << "\tThe CARD [" << gencard << "] " << endl;
cout << "\tAND SUIT [" << gensuit << "] " << endl;
cout << "\tARE CORRECT!!                " << endl;
cout << "\tand it only took you         " << endl;
cout << "\t         [" << tries2 <<  "] tries!\n" << endl;
cout << "________________________________________" << endl;
tries2 = 0;
cout << "\n\t Press <Y/y> to play again.......:";
cout << "\n\t Or    <N/n> to leave............:";
cin >> again2;  cin.ignore('80','\n');
if (again2 == 'y' || again2 == 'Y')
    goto startgame2;
clearscreen();
return;
}

void clearscreen(void){
    for (int i = 0; i < 60; i++)
        cout << endl;
cout << "___________________________________________________________________________________________________" << endl;
return;
}

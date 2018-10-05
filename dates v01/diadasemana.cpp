//Aprendendo manipulacao de dia/semana/mes/ano
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct DIA{
  int   d_dia;
  char  d_nomedia[14];
  int   d_mes;
  char  d_nomemes[4];
  int   d_ano;
  bool  d_bissexto;
};

const char *NOMEMES[13]={"JAN","FEV","MAR","MAI","ABR","JUN","JUL","AGO","SET",
                         "OUT","NOV","DEZ"};
const char *NOMEDIA[8]={"SEGUNDA-FEIRA","TERCA-FEIRA","QUARTA-FEIRA",
                          "QUINTA-FEIRA","SEXTA-FEIRA","SABADO","DOMINGO"};
int QUANTDIAS[12]={31,28,31,30,31,30,31,31,30,31,30,31};

//prototipos
void inserirdata(DIA *ip1);
int diadasemana(int,int,int);
bool verificabissexto(int);
void mostrabissexto(DIA *bp1);
void mostradata(DIA *mp1);

int main(void){
  DIA *p1 = new DIA;
  inserirdata(p1);
  mostradata(p1);
  
cin.get();
return 0;
}

void inserirdata(DIA *ip1){
inicioinserirdata:
  int idia;
  bool vidia = 0;
  int imes;
  bool vimes = 0;
  int iano;
  bool viano = 0;
  bool vbissexto;
  int dsemana;
  cout <<"\n\t<DIA>...........:";
  cin >> idia; cin.ignore('80','\n');
  cout <<"\n\t<MES>...........:";
  cin >> imes; cin.ignore('80','\n');
  cout <<"\n\t<ANO>...........:";
  cin >> iano; cin.ignore('80','\n');

  vbissexto = verificabissexto(iano);

  if(idia >= 1 && idia <=31)
    vidia = 1;
  if(imes >= 1 && imes <=12)
    vimes = 1;
  if(iano >= 0000)
    viano = 1;


  if(imes == 2){
    if(vbissexto == 1 && idia > 29){
      cout << "FEV DESTE ANO SOMENTE ATE DIA 29!\n";
      goto inicioinserirdata;
    }
    else if(vbissexto == 0 && idia > 28){
     cout << "FEV DESTE ANO SOMENTE ATE DIA 28!\n";
     goto inicioinserirdata;
    }
  }

  if (vidia && vimes && viano){
    ip1->d_ano = iano;
    ip1->d_bissexto = vbissexto;
    ip1->d_dia = idia;
    ip1->d_mes = imes;
    strcpy(ip1->d_nomemes,NOMEMES[imes-1]);
    dsemana = diadasemana(idia,imes,iano);
    strcpy(ip1->d_nomedia, NOMEDIA[dsemana-1]);
  }
  else{
    cout << "FAVOR INSERIR DATA CORRETA....\n";
    goto inicioinserirdata;
  }
  return;
}

int diadasemana(int d,int m, int a){
  static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
  a -= m < 3;
  return ( a + a/4 - a/100 + a/400 + t[m-1] + d) % 7;
}

bool verificabissexto(int a){
  bool ehbissexto;
  if ((a%4)!=0)
    ehbissexto = 0;
  else if ((a%100)!=0)
    ehbissexto = 1;
  else if ((a%400)!=0)
    ehbissexto = 0;
  else
    ehbissexto = 1;
return ehbissexto;
}

void mostrabissexto(DIA *bp1){
  if (bp1->d_bissexto != 0)
    cout << "\nO ano [" << bp1->d_ano << "] E BISSEXTO...\n";
  else
    cout << "\nO ano [" << bp1->d_ano << "] NAO E BISSEXTO...\n";
  return;
}

void mostradata(DIA *mp1){
 cout << "\n\t O dia \t     " << mp1->d_dia << "-" << mp1->d_nomemes << "-" << mp1->d_ano;
 cout << ",\n\t equivale a  [" << mp1->d_nomedia << "]";
 if (mp1->d_bissexto != 0)
  cout << ",\n\t de um ano   [BISSEXTO]...\n";
else
  cout << ",\n\t de um ano   [NAO-BISSEXTO]...\n";

return;
}

//MATHEWS MONOO - 04.10.2018
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <iomanip>
#include <algorithm>    // random_shuffle
#include <vector>
using namespace std;

//global variables
struct CARTA{
  char nome[7];
  char naipe[8];
  int numero;
};

//prototypes
void limpartela(int);
void criarbaralho(CARTA *baralho);
void mostrarbaralho(CARTA *mostra);
void associarnaipes(CARTA *pnaipe);
void invertebaralho(CARTA *inverte);
void embaralhabaralho(CARTA *embaralha);
void deletarbaralho(CARTA *deleta, CARTA *deleta2);
void tirarmao(CARTA *bar1,CARTA *mao1,int *ptamanhomao, CARTA *apagador1);
void mostrarmao(CARTA *mao1,int *ptamanhomao);

//main
int main(void){
  CARTA *baralho1{nullptr};
  baralho1 = new CARTA[52];
  CARTA *mao1{nullptr};
  mao1 = new CARTA[52];
  CARTA apagador;
  CARTA *papagador = new CARTA[1];
     strcpy(papagador->naipe,"\0");
     strcpy(papagador->nome,"\0");
     papagador->numero = 0;

  int tamanhomao;
  int *ptamanhomao{nullptr};
  ptamanhomao = &tamanhomao;
  int escolha;
criarbaralho(baralho1);
menu:
  cout << "------------------------------------------------" << endl;
  cout << "..........|         MENU          |............:" << endl;
  cout << "------------------------------------------------" << endl;
  cout << "(1) - MOSTRAR BARALHO..........................:" << endl;
  cout << "(2) - INVERTER BARALHO.........................:" << endl;
  cout << "(3) - EMBARALHAR...............................:" << endl;
  cout << "(4) - RESTAURAR BARALHO;.......................:" << endl;
  cout << "(5) - TIRAR UMA MAO (n CARTAS).................:" << endl;
  cout << "(6) - MOSTRAR SUA MAO..........................:" << endl;
  cout << "(0) - DELETAR BARALHO E SAIR...................:" << endl;
  cout << "------------------------------------------------" << endl;
  if(!(cin >> escolha)){
    cout << "\n\nOPCAO DEVE SER UM NUMERO!    ENCERRANDO..." << endl;
    goto fimprograma;
  }
  else
    cin.ignore('80','\n');
  switch (escolha){
    case 1:  mostrarbaralho(baralho1);             goto menu; break;
    case 2:  invertebaralho(baralho1);             goto menu; break;
    case 3:  embaralhabaralho(baralho1);           goto menu; break;
    case 4:  criarbaralho(baralho1);               goto menu; break;
    case 5:  tirarmao(baralho1,mao1,ptamanhomao,papagador);  goto menu; break;
    case 6:  mostrarmao(mao1,ptamanhomao);         goto menu; break;
    case 0:  deletarbaralho(baralho1,mao1);             goto fimprograma; break;
    default: cout << "\n\tOPCAO INVALIDA...." << endl; goto menu; break;
  }

fimprograma:
  cout << "------------------------------------------------" << endl;
  cout << "...........|         FIM          |............:" << endl;
  cout << "------------------------------------------------" << endl;
  cin.get();
  return 0;
}

//sub-rotinas:
void criarbaralho(CARTA *baralho){
  CARTA *phelper{nullptr};
  phelper = baralho;
  for (int i = 0; i <= 52-1; i++){
    if (i <= 3){
        strcpy(phelper[i].nome,"AS");
        phelper[i].numero = 1;}
    else if (i <= 7){
            strcpy(phelper[i].nome,"DOIS");
            phelper[i].numero = 2;}
        else if (i <= 11){
                strcpy(phelper[i].nome,"TRES");
                phelper[i].numero = 3;}
                else if (i <= 15){
                        strcpy(phelper[i].nome,"QUATRO");
                        phelper[i].numero = 4;}
                        else if (i <=19){
                            strcpy(phelper[i].nome,"CINCO");
                            phelper[i].numero = 5;}
                            else if (i <= 23){
                                strcpy(phelper[i].nome,"SEIS");
                                phelper[i].numero = 6;}
                                else if (i <= 27){
                                    strcpy(phelper[i].nome,"SETE");
                                    phelper[i].numero = 7;}
                                    else if (i <= 31){
                                        strcpy(phelper[i].nome,"OITO");
                                        phelper[i].numero = 8;}
                                        else if (i <= 35){
                                            strcpy(phelper[i].nome,"NOVE");
                                            phelper[i].numero = 9;}
                                            else if (i <= 39){
                                                strcpy(phelper[i].nome,"DEZ");
                                                phelper[i].numero = 10;}
                                                else if (i <= 43){
                                                    strcpy(phelper[i].nome,"VALETE");
                                                    phelper[i].numero = 11;}
                                                    else if (i <= 47){
                                                        strcpy(phelper[i].nome,"DAMA");
                                                        phelper[i].numero = 12;}
                                                        else if (i <= 51){
                                                            strcpy(phelper[i].nome,"REI");
                                                            phelper[i].numero = 13;}
  }
  associarnaipes(phelper);
limpartela(3);
return;
}

void mostrarbaralho(CARTA *mostra){

    for (int i = 0; i <= 52-1; i++){
        cout << " CARTA " << setw(3) << i+1 << ":" << setw(9) << mostra[i].nome;
        cout << " \tNAIPE :\t  " << setw(7) << mostra[i].naipe << endl;
    }
cout << "\n\n<ENTER> para continuar...." << endl; cin.get();
return;
}

void associarnaipes(CARTA *pnaipe){
    int i = 0;
    for (i = 0 ; i <= 51; i+=4){
        strcpy(pnaipe[i].naipe, "COPAS");
        strcpy(pnaipe[i+1].naipe, "ESPADAS");
        strcpy(pnaipe[i+2].naipe, "OUROS");
        strcpy(pnaipe[i+3].naipe, "PAUS");
    }
    return;
}

void invertebaralho(CARTA *inverte){
for(int i = 0; i <= 50; i++)
    for (int j = i+1 ; j <= 51; j++ )
    swap(inverte[i],inverte[j]);
limpartela(1);
return;
}

void embaralhabaralho(CARTA *embaralha){
vector<CARTA> vcarta;
srand(time(NULL));
int myrand = rand()% 128 + 1;
  for(int i =0; i <=51; i++)
    vcarta.push_back(embaralha[i]);
  for(int x =0; x <= myrand; x++)
    random_shuffle(vcarta.begin(),vcarta.end());
  for(int j =0; j <=51; j++)
    embaralha[j] = vcarta.at(j);
vcarta.erase(vcarta.begin(),vcarta.end());
limpartela(2);
return;
}

void limpartela(int n){
char condicao[12];
switch(n){
    case 1 : strcpy(condicao,"INVERTIDO");    break;
    case 2 : strcpy(condicao,"EMBARALHADO");  break;
    case 3 : strcpy(condicao,"ORGANIZADO");   break;
    case 4 : strcpy(condicao,"DELETADO");     break;
    case 5 : strcpy(condicao,"TIRADA");       break;
    default : strcpy(condicao,"VOCE_ERROU");  break;
    }
if (n <= 4) {
    for (int i = 0; i <= 28; i++)
        cout << endl;
cout << "\tBaralho " << condicao << " com sucesso!" << endl;
 }
else{
    for (int i = 0; i <= 28; i++)
        cout << endl;
cout << "\tMAO" << condicao << " com sucesso!" << endl;
}
}

void deletarbaralho(CARTA *deleta, CARTA *deleta2){
    delete[]deleta;
    delete[]deleta2;
    limpartela(4);
return;
}

void tirarmao(CARTA *bar1,CARTA *mao1,int *ptamanhomao, CARTA *apagador1){
    cout << "\nNumero de CARTAS  na  MAO....:" << endl;
    cin >> *ptamanhomao; cin.ignore('80','\n');
    for(int i = 0; i <= *ptamanhomao-1; i++){
        mao1[i] = bar1[i];
        bar1[i] = apagador1[i];
    }
    limpartela(5);
    return;
}

void mostrarmao(CARTA *mao1,int *ptamanhomao){
    for (int i = 0; i <= *ptamanhomao-1; i++){
        cout << " CARTA " << setw(3) << i+1 << ":" << setw(9) << mao1[i].nome;
        cout << " \tNAIPE :\t  " << setw(7) << mao1[i].naipe << endl;
    }
    cout << "\n\n<ENTER> para continuar...." << endl; cin.get();
    return;
}

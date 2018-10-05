#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <cstring>

using namespace std;
#include <iostream>
#include <vector>


/*
int main()
{
	std::vector <something> v {};
	//say you want 5 something objects in the vector
	for (auto i = 0; i < 5; ++i)
    {
        std::cout << "enter int \n"; int x{}; std::cin >> x;
        std::cout << "enter double \n"; double y{}; std::cin >> y;
        std::cout << "enter char \n"; char c{}; std::cin >> c;
        v.emplace_back((something(x, y, c)));
    }
	for (const auto& elem : v)
    {
        std::cout << elem.m_x << " " << elem.m_y << " " << elem.m_c << "\n";
    }
}*/

//global vars
string suits[]{"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};
string faces[]{"ACE","2","3","4","5","6","7","8","9","10","JACK","QUEEN","KING"};
int fvalues[]{1,2,3,4,5,6,7,8,9,10,11,12,13};

struct CARD{
  char face[7];
  char suit[9];
  int  fvalue;
  CARD(const char f_a, const char s_u, const int v_a)
      : face(f_a), suit(s_u), fvalue(v_a){}
};

//prototypes
void createdeck(vector<CARD> *cdeck);

//main
int main(void){
vector<CARD> *deck = new vector<CARD>;
createdeck(deck);
program_end:
  cout << "\n------------------------------------------------" << endl;
  cout << "...........|         END          |............:" << endl;
  cout << "------------------------------------------------" << endl;  cin.get();
  return 0;
}

void createdeck(vector<CARD> *deck){
	for (auto i = 0; i <= 52-1 ; ++i)
    {
        char f_a{}; strcpy(f_a)
        char s_u{}; cin >> s_u;
        int v_a{}; cin >> v_a;
        *deck.emplace_back((CARD(f_a, s_u, v_a)));

    }

return;
}

/*
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
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  int qtdNaipes = 4;
  int qtdCartas = 13;
  int qtdBaralhos = 2;

  const int qtdParticipantes = 4;
  const int qtdCartasPorParticipante = 11;

  string baralho[qtdBaralhos][qtdNaipes * qtdCartas];
  string mao[qtdParticipantes][qtdCartasPorParticipante];

  srand(time(0));

  for (int i = 0; i < qtdBaralhos; i++)
  {
    int qtdColumn = 0;
    for (int j = 0; j < qtdNaipes; j++)
    {
      for (int k = 0; k < qtdCartas; k++)
      {
        stringstream resultLine;
        resultLine << j + 1 << std::setfill('0') << std::setw(2) << k + 1
                   << i + 1 << endl;

        cout << resultLine.str();
        baralho[i][qtdColumn] = resultLine.str();
        qtdColumn++;
      }
    }
  }

  for (int p = 0; p < qtdParticipantes; p++)
  {
    for (int c = 0; c < qtdCartasPorParticipante; c++)
    {
      int baralhoIndex = rand() % qtdBaralhos;
      int cartaIndex = rand() % (qtdNaipes * qtdCartas);

      while (baralho[baralhoIndex][cartaIndex] == "")
      {
        baralhoIndex = rand() % qtdBaralhos;
        cartaIndex = rand() % (qtdNaipes * qtdCartas);
      }

      mao[p][c] = baralho[baralhoIndex][cartaIndex];
      baralho[baralhoIndex][cartaIndex] = "";
    }
  }

  for (int p = 0; p < qtdParticipantes; p++)
  {
    cout << "Mão do Participante " << p + 1 << ":" << endl
         << endl;

    for (int c = 0; c < qtdCartasPorParticipante; c++)
    {
      cout << mao[p][c] << endl;
    }
    cout << endl;
  }
}

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <time.h>
using namespace std;

int elogiosOuReclamacoes()
{
    system("clear");

    ifstream sugestaoOuReclamacaoIn;
    string exibirSugestaoOuReclamacao;

    system("clear");
    cout << endl
         << endl
         << "****************************************" << endl
         << "*  Esses s�o os elogios e reclama��es  *" << endl
         << "*      realizadas pelos clientes       *" << endl
         << "****************************************" << endl
         << endl;
    sugestaoOuReclamacaoIn.open("sugestaoOuReclamacao.txt");

    if (sugestaoOuReclamacaoIn.is_open())
    {
        while (getline(sugestaoOuReclamacaoIn, exibirSugestaoOuReclamacao))
        {
            cout << exibirSugestaoOuReclamacao << endl;
        }
        sugestaoOuReclamacaoIn.close();
        cout << endl
             << endl;
        system("pause");
    }
    else
    {
        cout << "N�o foi possivel abrir o arquivo" << endl;
    }
    return 0;
}
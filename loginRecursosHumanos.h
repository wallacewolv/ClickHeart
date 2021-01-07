#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <time.h>
using namespace std;

int loginRecursosHumanos()
{
    system("clear");
    cin.ignore();
    cout << "--------------------------------------" << endl
         << "|                                    |" << endl
         << "|             CLICK HEART            |" << endl
         << "|      CLINICA PARAISO UNIDADE I     |" << endl
         << "|                                    |" << endl
         << "--------------------------------------" << endl
         << "**************************************" << endl
         << "*       Login Recursos Humanos       *" << endl
         << "**************************************" << endl
         << endl;

    //*********************************************************************************************************//
    // Entrando no laço While (Login Recursos Humanos), se for digitado de forma errada,
    // retorna para o começo do laço;
    string loginRecursosHumanos;
    cout << "Login RH: ";
    cin >> loginRecursosHumanos;
    int loginTentativaAdmA = 0; // Variavel para definar as tentativas de Login RecursosHumanos
    int loginTentativaAdmB = 3; // Variavel para mostrar as tentativas restantes
    while (loginRecursosHumanos != "Rhumano")
    {
        system("clear");
        loginTentativaAdmA = loginTentativaAdmA + 1;
        if (loginTentativaAdmA == 3)
        { // Laço para limitar à 3 tentativas o erro de login RecursosHumanos
            abort();
        }
        cout << endl
             << endl
             << "Login errado" << endl
             << endl
             << "Digite seu login novamente" << endl
             << endl
             << "Numero de tentativas restantes " << loginTentativaAdmB - loginTentativaAdmA << endl
             << endl;
        system("pause");
        system("clear");
        cout << "--------------------------------------" << endl
             << "|                                    |" << endl
             << "|             CLICK HEART            |" << endl
             << "|      CLINICA PARAISO UNIDADE I     |" << endl
             << "|                                    |" << endl
             << "--------------------------------------" << endl
             << "**************************************" << endl
             << "*       Login Recursos Humanos       *" << endl
             << "**************************************" << endl
             << endl
             << "Login RH: ";
        cin >> loginRecursosHumanos;
        break;
    }

    double senhaRecursosHumanos;
    cout << endl
         << "Insira sua senha" << endl
         << endl
         << "Senha: ";
    cin >> senhaRecursosHumanos;
    int senhaTentativaAdmA = 0; // Variavel para definar as tentativas de Senha RecursosHumanos
    int senhaTentativaAdmB = 3; // Variavel para mostrar as tentativas restantes
    //*********************************************************************************************************//
    // Entrando no laço While (Senha Recursos Humanos), se for digitado de forma errada,
    // retorna para o começo do laço;

    while (senhaRecursosHumanos != 4567)
    {
        system("clear");
        cin.ignore();
        senhaTentativaAdmA = senhaTentativaAdmA + 1;
        if (senhaTentativaAdmA == 3)
        { // Laço para limitar à 3 tentativas o erro de senha Recursos Humanos
            abort();
        }
        cout << endl
             << endl
             << "Senha errada" << endl
             << endl
             << "Digite sua senha novamente" << endl
             << endl
             << "Numero de tentativas restantes " << senhaTentativaAdmB - senhaTentativaAdmA << endl
             << endl;
        system("pause");
        system("clear");
        cout << "--------------------------------------" << endl
             << "|                                    |" << endl
             << "|             CLICK HEART            |" << endl
             << "|      CLINICA PARAISO UNIDADE I     |" << endl
             << "|                                    |" << endl
             << "--------------------------------------" << endl
             << "**************************************" << endl
             << "*       Login Recursos Humanos       *" << endl
             << "**************************************" << endl
             << endl
             << "Login RH: " << loginRecursosHumanos << endl
             << endl
             << "Senha: ";
        cin >> senhaRecursosHumanos;
        break;
    }

    cout << endl
         << "Acesso aprovado" << endl
         << endl;
    system("pause");
    return 0;
}
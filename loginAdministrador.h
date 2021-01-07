#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <time.h>
using namespace std;

int loginAdministrador()
{
    system("clear");
    cin.ignore();
    cout << "------------------------------------" << endl
         << "|                                  |" << endl
         << "|            CLICK HEART           |" << endl
         << "|          CLINICA PARAISO         |" << endl
         << "|                                  |" << endl
         << "------------------------------------" << endl
         << "************************************" << endl
         << "*       Login Administrativo       *" << endl
         << "************************************" << endl
         << endl;

    //*********************************************************************************************************//
    // Entrando no laço While (Login Administrativo), se for digitado de forma errada,
    // retorna para o começo do laço;
    string loginAdministrativo;
    cout << "Login Administrativo: ";
    cin >> loginAdministrativo;
    int loginTentativaAdmA = 0; // Variavel para definar as tentativas de Login Administrativo
    int loginTentativaAdmB = 3; // Variavel para mostrar as tentativas restantes
    while (loginAdministrativo != "Adm")
    {
        system("clear");
        loginTentativaAdmA = loginTentativaAdmA + 1;
        if (loginTentativaAdmA == 3)
        { // Laço para limitar à 3 tentativas o erro de login Administrativo
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
        cout << "------------------------------------" << endl
             << "|                                  |" << endl
             << "|            CLICK HEART           |" << endl
             << "|          CLINICA PARAISO         |" << endl
             << "|                                  |" << endl
             << "------------------------------------" << endl
             << "************************************" << endl
             << "*       Login Administrativo       *" << endl
             << "************************************" << endl
             << endl
             << "Login Administrativo: ";
        cin >> loginAdministrativo;
        break;
    }

    double senhaAdministrativa;
    cout << endl
         << "Insira sua senha" << endl
         << endl
         << "Senha: ";
    cin >> senhaAdministrativa;
    int senhaTentativaAdmA = 0; // Variavel para definar as tentativas de Senha Administrativa
    int senhaTentativaAdmB = 3; // Variavel para mostrar as tentativas restantes
    //*********************************************************************************************************//
    // Entrando no laço While (Senha Administrativa), se for digitado de forma errada,
    // retorna para o começo do laço;

    while (senhaAdministrativa != 9876)
    {
        system("clear");
        cin.ignore();
        senhaTentativaAdmA = senhaTentativaAdmA + 1;
        if (senhaTentativaAdmA == 3)
        { // Laço para limitar à 3 tentativas o erro de senha administrativa
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
        cout << "------------------------------------" << endl
             << "|                                  |" << endl
             << "|            CLICK HEART           |" << endl
             << "|     CLINICA PARAISO UNIDADE I    |" << endl
             << "|                                  |" << endl
             << "------------------------------------" << endl
             << "************************************" << endl
             << "*       Login Administrativo       *" << endl
             << "************************************" << endl
             << endl
             << "Login Administrativo: " << loginAdministrativo << endl
             << endl
             << "Senha: ";
        cin >> senhaAdministrativa;
        break;
    }

    cout << endl
         << "Acesso aprovado" << endl
         << endl;
    system("pause");
    return 0;
}
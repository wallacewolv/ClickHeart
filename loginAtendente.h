#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <time.h>
using namespace std;

int loginAtendente()
{
    system("clear");
    cin.ignore();
    cout << "----------------------------------" << endl
         << "|                                |" << endl
         << "|           CLICK HEART          |" << endl
         << "|         CLINICA PARAISO        |" << endl
         << "|                                |" << endl
         << "----------------------------------" << endl
         << "**********************************" << endl
         << "*       Login do Atendente       *" << endl
         << "**********************************" << endl
         << endl;

    //*********************************************************************************************************//
    // Entrando no laço While (Login), se for digitado de forma errada,
    // retorna para o começo do laço;
    string login;
    cout << "Login Atendente: ";
    cin >> login;
    int loginTentativaA = 0; // Variavel para definar as tentativas de Login
    int loginTentativaB = 3; // Variavel para mostrar as tentativas restantes
    while (login != "Clinica")
    {
        system("clear");
        loginTentativaA = loginTentativaA + 1;
        if (loginTentativaA == 3)
        { // Laço para limitar a 3 tentativas o erro de login
            abort();
        }
        cout << endl
             << endl
             << "Login errado" << endl
             << endl
             << "Digite seu login novamente" << endl
             << endl
             << "Número de tentativas restantes " << loginTentativaB - loginTentativaA << endl
             << endl;
        system("pause");
        system("clear");
        cout << "----------------------------------" << endl
             << "|                                |" << endl
             << "|           CLICK HEART          |" << endl
             << "|         CLINICA PARAISO        |" << endl
             << "|                                |" << endl
             << "----------------------------------" << endl
             << "**********************************" << endl
             << "*       Login do Atendente       *" << endl
             << "**********************************" << endl
             << endl
             << "Login Atendente: ";
        cin >> login;
        break;
    }

    double senha;
    cout << endl
         << "Insira sua senha" << endl
         << endl
         << "Senha: ";
    cin >> senha;
    int senhaTentativaA = 0; // Variavel para definar as tentativas de Senha
    int senhaTentativaB = 3; // Variavel para mostrar as tentativas restantes
    //*********************************************************************************************************//
    // Entrando no laço While (Senha), se for digitado de forma errada,
    // retorna para o começo do laço;

    while (senha != 1234)
    {
        system("clear");
        cin.ignore();
        senhaTentativaA = senhaTentativaA + 1;
        if (senhaTentativaA == 3)
        { // Laço para limitar a 3 tentativas o erro de senha
            abort();
        }
        cout << endl
             << endl
             << "Senha errada" << endl
             << endl
             << "Digite sua senha novamente" << endl
             << endl
             << "Número de tentativas restantes " << senhaTentativaB - senhaTentativaA << endl
             << endl;
        system("pause");
        system("clear");
        cout << "----------------------------------" << endl
             << "|                                |" << endl
             << "|           CLICK HEART          |" << endl
             << "|         CLINICA PARAISO        |" << endl
             << "|                                |" << endl
             << "----------------------------------" << endl
             << "**********************************" << endl
             << "*       Login do Atendente       *" << endl
             << "**********************************" << endl
             << endl
             << "Login Atendente: " << login << endl
             << endl
             << "Senha: ";
        cin >> senha;
        break;
    }

    cout << endl
         << "Acesso aprovado" << endl
         << endl;
    system("pause");
    return 0;
}
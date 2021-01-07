#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <time.h>
using namespace std;

int backupSistema()
{
    system("clear");
    cin.ignore();
    string opcoesBackup = "";

    while (opcoesBackup != "0")
    {
        // Opções de operação
        system("clear");
        int opcoesBackup;
        cout << "*************************************************" << endl
             << "*                                               *" << endl
             << "*  Os Backups são gerados de forma automática,  *" << endl
             << "*     de acordo com os prazos estipulados.      *" << endl
             << "*                                               *" << endl
             << "*      Caso queira faze-lo de forma manual,     *" << endl
             << "*  escolha qual das operações deseja realizar:  *" << endl
             << "*                                               *" << endl
             << "*************************************************" << endl
             << endl
             << "1 - Backup Diario" << endl
             << "2 - Backup Semanal" << endl
             << "3 - Backup Mensal" << endl
             << "0 - Sair" << endl
             << endl
             << "Digite o numero correspondente a operacao: ";
        cin >> opcoesBackup;
        if (opcoesBackup == 0)
        {   
            system("clear");
            cout << endl
                 << "Saindo do Backup" << endl
                 << endl;
            system("Pause");
            system("clear");
            break;
        }

        system("clear");
        bool backup = ""; // Definindo a variavel cadastro como booleam e atribuido valor NAO.
                          // Quando ela for alterada para SIM, sairÃ¡ do laÃ§o while (opcaoBackup).
        while (true)
        {
            string backup;
            cout << endl
                 << endl
                 << "Gostaria de fazer o Backup SIM(S) ou NÃO(N) ?  ";
            cin >> backup;

            system("clear");
            // Cadastro nÃ£o estÃ¡ Ok;
            if ((backup == "S") || (backup == "s"))
            {
                cin.ignore();
                cout << endl
                     << endl
                     << "Por favor aguarde o backup ser concluido" << endl
                     << endl
                     << "Essa operacao pode levar alguns minutos" << endl
                     << endl
                     << endl;
                fflush(stdin);
                unsigned short contadorNum;
                unsigned short contadorPorcent = 0;
                unsigned short i = 0;
                // int x= 0;
                while (contadorPorcent < 100)
                {
                    while (contadorNum += 400)
                        printf("\r%1d");
                    printf("[");
                    contadorPorcent += 10;
                    for (i = 0; i < contadorPorcent / 2; i++)
                        printf("%c", 35);
                    printf("]");
                    printf("%d%%", contadorPorcent);
                }

                cin.ignore();
                cout << endl
                     << endl
                     << "Backup concluido" << endl
                     << endl;
                system("pause");
                system("clear");
                break;
            }
            else
            {
                break;
            }
        }
        continue;
    }
    return 0;
}
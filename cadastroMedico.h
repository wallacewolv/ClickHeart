#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <time.h>
using namespace std;

// Contador pra Id de M�dicos
int idMedico()
{
    static int idM = 1;
    return idM++;
}

int cadastroMedico()
{
    system("clear");
    int opcoesMedico;

    // Struct para consulta e Backup
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);

    while (opcoesMedico != 3)
    {
        system("clear");
        cout << endl
             << endl
             << "*********************************" << endl
             << "*      Cadastro de M�dico       *" << endl
             << "*     --------------------      *" << endl
             << "*    Escolha uma das op��es     *" << endl
             << "*********************************" << endl
             << " ------------------------------- " << endl
             << "|  1 - Incluir dados do M�dico  |" << endl
             << "|-------------------------------|" << endl
             << "|  2 - Listar dados do M�dico   |" << endl
             << "|-------------------------------|" << endl
             << "|  3 - Sair                     |" << endl
             << " ------------------------------- " << endl
             << "   Digite a sua op��o: ";
        cin >> opcoesMedico;

        //*********************************************************************************************//
        // Switch para as op��es de cadastro do m�dico
        switch (opcoesMedico)
        {
        // Cadastro de m�dico
        case 1:
        {
            system("clear");
            string cadastro;
            // Quando a variavel cadastro for alterada para SIM, saira do la�o while (Cadastro).
            while ((cadastro != "S") || (cadastro != "s"))
            {
                cout << "*******************************" << endl
                     << "*   Incluir Dados do M�dico   *" << endl
                     << "*******************************" << endl
                     << endl;

                // Struct para captura de dados do cadastro;
                struct structMedico
                {
                    string nome;
                    string rg;
                    string cpf;
                    string crm;
                    string especialidade;
                    string nascimento;
                    string endereco;
                    string complemento;
                    string cep;
                    string bairro;
                };

                struct structMedico med;

                cin.ignore();
                cout << "Digite o Nome: ";
                getline(cin, med.nome);

                cout << endl
                     << "Digite o RG (com pontos): ";
                getline(cin, med.rg);

                cout << endl
                     << "Digite o CPF (com pontos): ";
                getline(cin, med.cpf);

                cout << endl
                     << "Digite o CRM (com pontos): ";
                getline(cin, med.crm);
                
                cout << endl
                     << "Digite a especialidade: ";
                getline(cin, med.crm);

                cout << endl
                     << "Digite a data de Nascimento (com barras '/'): ";
                getline(cin, med.nascimento);

                cout << endl
                     << "Digite o Endere�o: ";
                getline(cin, med.endereco);

                cout << endl
                     << "Digite o Complemento: ";
                getline(cin, med.complemento);

                cout << endl
                     << "Digite o CEP (com pontos): ";
                getline(cin, med.cep);

                cout << endl
                     << "Digite o Bairro: ";
                getline(cin, med.bairro);

                ofstream arquivoMedicoOut;
                auto idValor = idMedico(); //idValor recebe valor de idMedico pra inserir no registro

                arquivoMedicoOut.open("cadastroMedico.txt", ios::app);

                arquivoMedicoOut << "ID: "
                                 << "\t"
                                 << "\t" << idValor << endl
                                 << "NOME: "
                                 << "\t"
                                 << "\t" << med.nome << endl
                                 << "RG: "
                                 << "\t"
                                 << "\t" << med.rg << endl
                                 << "CPF: "
                                 << "\t"
                                 << "\t" << med.cpf << endl
                                 << "CRM: "
                                 << "\t"
                                 << "\t" << med.crm << endl
                                 << "Especialidade: "
                                 << "\t"
                                 << "\t" << med.crm << endl
                                 << "Nascimento: "
                                 << "\t" << med.nascimento << endl
                                 << "Endere�o: "
                                 << "\t" << med.endereco << endl
                                 << "complemento: "
                                 << "\t" << med.complemento << endl
                                 << "CEP: "
                                 << "\t"
                                 << "\t" << med.cep << endl
                                 << "Bairro: "
                                 << "\t" << med.bairro << " , SP" << endl
                                 << "------------------------------------------" << endl;

                arquivoMedicoOut.close();
                system("clear");
                cout << endl
                     << endl
                     << endl
                     << "Salvando cadastro...   ...   ...   ..." << endl
                     << endl
                     << endl;
                system("pause");
                system("clear");

                ifstream arquivoMedicoIn;
                string exibirArquivoMedico;

                cout << endl
                     << endl
                     << "************************************" << endl
                     << "*        Confirmar Cadastro        *" << endl
                     << "************************************" << endl
                     << endl;

                arquivoMedicoIn.open("cadastroMedico.txt");

                if (arquivoMedicoIn.is_open())
                {
                    while (getline(arquivoMedicoIn, exibirArquivoMedico))
                    {
                        cout << exibirArquivoMedico << endl;
                    }
                    arquivoMedicoIn.close();
                }
                else
                {
                    cout << "N�o foi possivel abrir o arquivo" << endl;
                }

                cout << endl
                     << endl
                     << "Dados est�o certos SIM(s) ou N�O(n)?  ";
                cin >> cadastro;

                system("clear");
                // Cadastro n�o est�o Ok;
                if ((cadastro == "N") || (cadastro == "n"))
                {
                    remove("cadastroMedico.txt");
                    cout << endl
                         << endl
                         << "Por favor" << endl
                         << endl
                         << "Refa�a o cadastro" << endl
                         << endl;
                    system("pause");
                    system("clear");
                    continue;
                }
                else // Cadastro Ok
                {
                    arquivoMedicoIn.open("cadastroMedico.txt");
                    ofstream arquivoMedicoBackupOut;
                    arquivoMedicoBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/cadastroMedico.txt", ios::app);

                    if (arquivoMedicoIn.is_open())
                    {
                        while (getline(arquivoMedicoIn, exibirArquivoMedico))
                        {
                            arquivoMedicoBackupOut << exibirArquivoMedico << endl;
                        }
                        arquivoMedicoIn.close();
                        // Fun��o para abrir e salvar os dados no backup automatico
                        arquivoMedicoBackupOut.close();
                        arquivoMedicoBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/cadastroMedico.txt", ios::app);
                        arquivoMedicoBackupOut << "Backup  acima, referente ao dia "
                                               << data_hora_atual->tm_mday << "/"          // Dia do backup
                                               << data_hora_atual->tm_mon + 1 << "/"       // M�s do backup
                                               << data_hora_atual->tm_year + 1900 << " - " // Ano do backup
                                               << data_hora_atual->tm_hour << ":"          // Hora do backup
                                               << data_hora_atual->tm_min << ":"           // Minuto do backup
                                               << data_hora_atual->tm_sec << endl          // Segundos do backup
                                               << "-------------------------------------------------------------------------------------------" << endl
                                               << endl;
                        arquivoMedicoBackupOut.close();
                    }
                    cout << endl
                         << "Cadastro realizado com sucesso" << endl
                         << endl
                         << "Bem vindo(a) Dr(a) " << med.nome << endl;
                    cin.ignore();
                    cout << endl
                         << endl;
                    system("pause");
                }
                break;
            }
            continue;
        }
        //*****************************************************************************************//
        // Listar medico
        case 2:
        {
            system("clear");
            cin.ignore();
            cout << "************************************************" << endl
                 << "*   Esses s�o os dados que foram encontrados   *" << endl
                 << "************************************************" << endl
                 << endl;

            ifstream arquivoMedicoIn; // arquivoMedicoIn = I de In, entrada;
            string linha;             // pra armazenamento do conteudo salvo no arquivo .txt

            arquivoMedicoIn.open("cadastroMedico.txt");
            //usando um if pra ter certeza que o arquivo esta aberto
            //metodo .is_open() verifica se ele abriu.
            if (arquivoMedicoIn.is_open())
            {
                // Laço while usando metodo geline pra leitura de aqruivo
                // usando as variaveis arquivoMedicoIn de saida e linha pra armazenar o conteudo
                while (getline(arquivoMedicoIn, linha))
                {
                    cout << linha << endl;
                }
                arquivoMedicoIn.close();
            }
            else
            {
                cout << "N�o foi possivel abrir o arquivo" << endl;
            }

            cout << endl
                 << endl;
            system("pause");
            continue;
        }
        //*****************************************************************************************//
        // Op��o Sair
        case 3:
        {
            system("clear");
            cin.ignore();
            cout << endl
                 << endl
                 << "Saindo das op��es de cadastro" << endl
                 << endl
                 << endl;
            system("pause");
            system("clear");
            break;
        }
        //*****************************************************************************************//
        // Op��o inexistente
        default:
        {
            cout << endl
                 << "O valor digitado n�o corresponde a nenhuma das op��es!" << endl
                 << endl;
            system("pause");
            break;
        }
        }
    }
    return 0;
}
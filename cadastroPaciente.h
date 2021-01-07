#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <time.h>
using namespace std;

// Contador pra Id de Pacientes
int idPaciente()
{
    static int idP = 1;
    return idP++;
}

int cadastroPaciente()
{
    system("clear");
    int opcoesPaciente;
    
    // Struct para consulta e Backup
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);

    while (opcoesPaciente != 3)
    {
        system("clear");
        cout << endl
             << endl
             << "**********************************" << endl
             << "*     Cadastro de Paciente       *" << endl
             << "*    ----------------------      *" << endl
             << "*    Escolha uma das op��es      *" << endl
             << "**********************************" << endl
             << " -------------------------------- " << endl
             << "|  1 - Incluir dados do Paciente |" << endl
             << "|--------------------------------|" << endl
             << "|  2 - Listar dados do Paciente  |" << endl
             << "|--------------------------------|" << endl
             << "|  3 - Sair                      |" << endl
             << " -------------------------------- " << endl
             << "   Digite a sua op��o: ";
        cin >> opcoesPaciente;

        //*********************************************************************************************//
        // Switch para as op��es de cadastro do Paciente
        switch (opcoesPaciente)
        {
        // Cadastro de Paciente
        case 1:
        {
            system("clear");
            string cadastro;
            // Quando a variavel cadastro for alterada para SIM, saira do la�o while (Cadastro).
            while ((cadastro != "S") || (cadastro != "s"))
            {
                cout << "*********************************" << endl
                     << "*   Incluir Dados do Paciente   *" << endl
                     << "*********************************" << endl
                     << endl;
                //*********************************************************************************//
                // Struct para captura de dados do cadastro;
                struct structPaciente
                {
                    string nome;
                    string rg;
                    string cpf;
                    string nascimento;
                    string endereco;
                    string complemento;
                    string cep;
                    string bairro;
                };

                struct structPaciente pac;

                cin.ignore();
                cout << "Digite o Nome: ";
                getline(cin, pac.nome);

                cout << endl
                     <<  "Digite o RG (com pontos): ";
                getline(cin, pac.rg);

                cout << endl
                     << "Digite o CPF (com pontos): ";
                getline(cin, pac.cpf);

                cout << endl
                     << "Digite a data de Nascimento (com barras '/'): ";
                getline(cin, pac.nascimento);

                cout << endl
                     << "Digite o Endere�o: ";
                getline(cin, pac.endereco);

                cout << endl
                     << "Digite o Complemento: ";
                getline(cin, pac.complemento);

                cout << endl
                     << "Digite o CEP (com pontos): ";
                getline(cin, pac.cep);

                cout << endl
                     << "Digite o Bairro: ";
                getline(cin, pac.bairro);

                ofstream arquivoPacienteOut;
                auto idValor = idPaciente(); //idValor recebe valor de idPaciente pra inserir no registro

                arquivoPacienteOut.open("cadastroPaciente.txt", ios::app);

                arquivoPacienteOut << "ID: "
                                   << "\t"
                                   << "\t" << idValor << endl
                                   << "NOME: "
                                   << "\t"
                                   << "\t" << pac.nome << endl
                                   << "RG: "
                                   << "\t"
                                   << "\t" << pac.rg << endl
                                   << "CPF: "
                                   << "\t"
                                   << "\t" << pac.cpf << endl
                                   << "Nascimento: "
                                   << "\t" << pac.nascimento << endl
                                   << "Endere�o: "
                                   << "\t" << pac.endereco << endl
                                   << "Complemento: "
                                   << "\t" << pac.complemento << endl
                                   << "CEP: "
                                   << "\t"
                                   << "\t" << pac.cep << endl
                                   << "Bairro: "
                                   << "\t" << pac.bairro << " , SP" << endl
                                   << "------------------------------------------" << endl;

                arquivoPacienteOut.close();
                system("clear");
                cout << endl
                     << endl
                     << endl
                     << "Salvando cadastro...   ...   ...   ..." << endl
                     << endl
                     << endl;
                system("pause");
                system("clear");

                ifstream arquivoPacienteIn;
                string exibirArquivoPaciente;

                cout << endl
                     << endl
                     << "************************************" << endl
                     << "*        Confirmar Cadastro        *" << endl
                     << "************************************" << endl
                     << endl;

                arquivoPacienteIn.open("cadastroPaciente.txt");

                if (arquivoPacienteIn.is_open())
                {
                    while (getline(arquivoPacienteIn, exibirArquivoPaciente))
                    {
                        cout << exibirArquivoPaciente << endl;
                    }
                    arquivoPacienteIn.close();
                }
                else
                {
                    cout << "N�o foi possivel abrir o arquivo" << endl;
                }
                cout << endl
                     << endl
                     << "Dados est�o certos SIM(S) ou NAO(N) ?  ";
                cin >> cadastro;

                system("clear");
                // Cadastro n�o est� Ok;
                if ((cadastro == "N") || (cadastro == "n"))
                {
                    remove("cadastroPaciente.txt");
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
                else // Cadastro Ok;
                {
                    arquivoPacienteIn.open("cadastroPaciente.txt");
                    ofstream arquivoPacienteBackupOut;
                    arquivoPacienteBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/cadastroPaciente.txt", ios::app);

                    if (arquivoPacienteIn.is_open())
                    {
                        while (getline(arquivoPacienteIn, exibirArquivoPaciente))
                        {
                            arquivoPacienteBackupOut << exibirArquivoPaciente << endl;
                        }
                        arquivoPacienteIn.close();
                        // Fun��o para abrir e salvar os dados no backup automatico
                        arquivoPacienteBackupOut.close();
                        arquivoPacienteBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/cadastroPaciente.txt", ios::app);
                        arquivoPacienteBackupOut << "Backup  acima, referente ao dia "
                                                 << data_hora_atual->tm_mday << "/"          // Dia do backup
                                                 << data_hora_atual->tm_mon + 1 << "/"       // M�s do backup
                                                 << data_hora_atual->tm_year + 1900 << " - " // Ano do backup
                                                 << data_hora_atual->tm_hour << ":"          // Hora do backup
                                                 << data_hora_atual->tm_min << ":"           // Minuto do backup
                                                 << data_hora_atual->tm_sec << endl          // Segundos do backup
                                                 << "-------------------------------------------------------------------------------------------" << endl
                                                 << endl;
                        arquivoPacienteBackupOut.close();
                    }
                    cout << endl
                         << "Cadastro realizado com sucesso" << endl
                         << endl;
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
        // Listar Paciente
        case 2:
        {
            system("clear");
            cin.ignore();
            cout << "************************************************" << endl
                 << "*   Esses s�o os dados que foram encontrados   *" << endl
                 << "************************************************" << endl
                 << endl;

            ifstream arquivoPacienteIn; // arquivoPacienteIn = I de In, entrada;
            string linha;               // pra armazenamento do conteudo salvo no arquivo .txt

            arquivoPacienteIn.open("cadastroPaciente.txt");
            //usando um if pra ter certeza que o arquivo esta aberto
            //metodo .is_open() verifica se ele abriu.
            if (arquivoPacienteIn.is_open())
            {
                // La�o while usando metodo geline pra leitura de aqruivo
                // usando as variaveis arquivoPacienteIn de saida e linha pra exibir o conteudo
                while (getline(arquivoPacienteIn, linha))
                {
                    cout << linha << endl;
                }
                arquivoPacienteIn.close();
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
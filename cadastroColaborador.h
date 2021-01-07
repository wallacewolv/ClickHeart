#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <time.h>
using namespace std;

// Contador pra Id de Colaboradores
int idColaborador()
{
    static int idC = 1;
    return idC++;
}

int cadastroColaborador()
{
    system("clear");
    cin.ignore();
    int opcoesColaborador;

    // Struct para consulta e Backup
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);

    while (opcoesColaborador != 3)
    {
        system("clear");
        cout << endl
             << endl
             << "**************************************" << endl
             << "*       Cadastro de Colaborador      *" << endl
             << "*      -------------------------     *" << endl
             << "*       Escolha uma das op��es       *" << endl
             << "**************************************" << endl
             << " ------------------------------------ " << endl
             << "|  1 - Incluir dados do Colaborador  |" << endl
             << "|------------------------------------|" << endl
             << "|  2 - Listar dados do Colaborador   |" << endl
             << "|------------------------------------|" << endl
             << "|  3 - Sair                          |" << endl
             << " ------------------------------------ " << endl
             << "   Digite a sua op��o: ";
        cin >> opcoesColaborador;

        //*********************************************************************************************//
        // Switch para as op��es de cadastro do colaborador
        switch (opcoesColaborador)
        {
        case 1:
        {
            system("clear");
            string cadastro = "";
            // Quando a variavel cadastro for alterada para SIM, saira do la�o while (Cadastro).
            while (cadastro != "SIM")
            {
                cout << "************************************" << endl
                     << "*   Incluir Dados do Colaborador   *" << endl
                     << "************************************" << endl
                     << endl;

                // Struct para captura de dados do cadastro;
                struct structColaborador
                {
                    string nome;
                    string rg;
                    string cpf;
                    string pis;
                    string nascimento;
                    string endereco;
                    string complemento;
                    string cep;
                    string bairro;
                };

                struct structColaborador colab;

                cin.ignore();
                cout << "Digite o Nome: ";
                getline(cin, colab.nome);

                cout << endl
                     << "Digite o RG (com pontos): ";
                getline(cin, colab.rg);

                cout << endl
                     << "Digite o CPF (com pontos): ";
                getline(cin, colab.cpf);

                cout << endl
                     << "Digite o PIS (com pontos): ";
                getline(cin, colab.pis);

                cout << endl
                     << "Digite a data de Nascimento (com barras '/'): ";
                getline(cin, colab.nascimento);

                cout << endl
                     << "Digite o Endere�o: ";
                getline(cin, colab.endereco);

                cout << endl
                     << "Digite o Complemento: ";
                getline(cin, colab.complemento);

                cout << endl
                     << "Digite o CEP (com pontos): ";
                getline(cin, colab.cep);

                cout << endl
                     << "Digite o Bairro: ";
                getline(cin, colab.bairro);

                ofstream arquivoColaboradorOut;
                auto idValor = idColaborador(); //idValor recebe valor de idColaborador pra inserir no registro

                arquivoColaboradorOut.open("cadastroColaborador.txt", ios::app);

                arquivoColaboradorOut << "ID: "
                                      << "\t"
                                      << "\t" << idValor << endl
                                      << "NOME: "
                                      << "\t"
                                      << "\t" << colab.nome << endl
                                      << "RG: "
                                      << "\t"
                                      << "\t" << colab.rg << endl
                                      << "CPF: "
                                      << "\t"
                                      << "\t" << colab.cpf << endl
                                      << "PIS: "
                                      << "\t"
                                      << "\t" << colab.pis << endl
                                      << "Nascimento: "
                                      << "\t" << colab.nascimento << endl
                                      << "Endere�o: "
                                      << "\t" << colab.endereco << endl
                                      << "Complemento: "
                                      << "\t" << colab.complemento << endl
                                      << "CEP: "
                                      << "\t"
                                      << "\t" << colab.cep << endl
                                      << "Bairro: "
                                      << "\t" << colab.bairro << " , SP" << endl
                                      << "------------------------------------------" << endl;
                arquivoColaboradorOut.close();
                system("clear");
                cout << endl
                     << endl
                     << endl
                     << "Salvando cadastro...   ...   ...   ..." << endl
                     << endl
                     << endl;
                system("pause");
                system("clear");

                ifstream arquivoColaboradorIn;
                string exibirArquivoColaborador;

                system("clear");
                cout << endl
                     << endl
                     << "************************************" << endl
                     << "*        Confirmar Cadastro        *" << endl
                     << "************************************" << endl
                     << endl
                     << endl;

                arquivoColaboradorIn.open("cadastroColaborador.txt");

                if (arquivoColaboradorIn.is_open())
                {
                    while (getline(arquivoColaboradorIn, exibirArquivoColaborador))
                    {
                        cout << exibirArquivoColaborador << endl;
                    }
                    arquivoColaboradorIn.close();
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
                // Cadastro n�o est� Ok;
                if ((cadastro == "N") || (cadastro == "n"))
                {
                    remove("cadastroColaborador.txt");
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
                    arquivoColaboradorIn.open("cadastroColaborador.txt");
                    ofstream arquivoColaboradorBackupOut;
                    arquivoColaboradorBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/cadastroColaborador.txt", ios::app);

                    if (arquivoColaboradorIn.is_open())
                    {
                        while (getline(arquivoColaboradorIn, exibirArquivoColaborador))
                        {
                            arquivoColaboradorBackupOut << exibirArquivoColaborador << endl;
                        }
                        arquivoColaboradorIn.close();
                        // Fun��o para abrir e salvar os dados no backup automatico
                        arquivoColaboradorBackupOut.close();
                        arquivoColaboradorBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/cadastroColaborador.txt", ios::app);
                        arquivoColaboradorBackupOut << "Backup  acima, referente ao dia "
                                                    << data_hora_atual->tm_mday << "/"          // Dia do backup
                                                    << data_hora_atual->tm_mon + 1 << "/"       // M�s do backup
                                                    << data_hora_atual->tm_year + 1900 << " - " // Ano do backup
                                                    << data_hora_atual->tm_hour << ":"          // Hora do backup
                                                    << data_hora_atual->tm_min << ":"           // Minuto do backup
                                                    << data_hora_atual->tm_sec << endl          // Segundos do backup
                                                    << "-------------------------------------------------------------------------------------------" << endl
                                                    << endl;
                        arquivoColaboradorBackupOut.close();
                    }
                    cout << endl
                         << "Cadastro realizado com sucesso" << endl
                         << endl
                         << "Bem vindo colaborador(a) " << colab.nome << endl;
                    cin.ignore();
                    cout << endl
                         << endl;
                    system("pause");
                    system("clear");
                }
                break;
            }
            continue;
        }
        //*****************************************************************************************//
        // Listar Colaborador
        case 2:
        {
            system("clear");
            cin.ignore();
            cout << "************************************************" << endl
                 << "*   Esses s�o os dados que foram encontrados   *" << endl
                 << "************************************************" << endl
                 << endl;

            ifstream arquivoColaboradorIn; // arquivoColaboradorIn = I de In, entrada;
            string linha;                  // pra armazenamento do conteudo salvo no arquivo .txt

            arquivoColaboradorIn.open("cadastroColaborador.txt");
            //usando um if pra ter certeza que o arquivo esta aberto
            //metodo .is_open() verifica se ele abriu.
            if (arquivoColaboradorIn.is_open())
            {
                // La�o while usando metodo geline pra leitura de aqruivo
                // usando as variaveis arquivoColaboradorIn de saida e linha pra armazenar o conteudo
                while (getline(arquivoColaboradorIn, linha))
                {
                    cout << linha << endl;
                }
                arquivoColaboradorIn.close();
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
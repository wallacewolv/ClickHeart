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
             << "*       Escolha uma das opções       *" << endl
             << "**************************************" << endl
             << " ------------------------------------ " << endl
             << "|  1 - Incluir dados do Colaborador  |" << endl
             << "|------------------------------------|" << endl
             << "|  2 - Listar dados do Colaborador   |" << endl
             << "|------------------------------------|" << endl
             << "|  3 - Sair                          |" << endl
             << " ------------------------------------ " << endl
             << "   Digite a sua opção: ";
        cin >> opcoesColaborador;

        //*********************************************************************************************//
        // Switch para as opções de cadastro do colaborador
        switch (opcoesColaborador)
        {
        case 1:
        {
            system("clear");
            string cadastro = "";
            // Quando a variavel cadastro for alterada para SIM, saira do laço while (Cadastro).
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
                     << "Digite o Endereço: ";
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
                                      << "Endereço: "
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
                    cout << "Não foi possivel abrir o arquivo" << endl;
                }

                cout << endl
                     << endl
                     << "Dados estão certos SIM(s) ou NÃO(n)?  ";
                cin >> cadastro;

                system("clear");
                // Cadastro não está Ok;
                if ((cadastro == "N") || (cadastro == "n"))
                {
                    remove("cadastroColaborador.txt");
                    cout << endl
                         << endl
                         << "Por favor" << endl
                         << endl
                         << "Refaça o cadastro" << endl
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
                        // Função para abrir e salvar os dados no backup automatico
                        arquivoColaboradorBackupOut.close();
                        arquivoColaboradorBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/cadastroColaborador.txt", ios::app);
                        arquivoColaboradorBackupOut << "Backup  acima, referente ao dia "
                                                    << data_hora_atual->tm_mday << "/"          // Dia do backup
                                                    << data_hora_atual->tm_mon + 1 << "/"       // Mês do backup
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
                 << "*   Esses são os dados que foram encontrados   *" << endl
                 << "************************************************" << endl
                 << endl;

            ifstream arquivoColaboradorIn; // arquivoColaboradorIn = I de In, entrada;
            string linha;                  // pra armazenamento do conteudo salvo no arquivo .txt

            arquivoColaboradorIn.open("cadastroColaborador.txt");
            //usando um if pra ter certeza que o arquivo esta aberto
            //metodo .is_open() verifica se ele abriu.
            if (arquivoColaboradorIn.is_open())
            {
                // Laço while usando metodo geline pra leitura de aqruivo
                // usando as variaveis arquivoColaboradorIn de saida e linha pra armazenar o conteudo
                while (getline(arquivoColaboradorIn, linha))
                {
                    cout << linha << endl;
                }
                arquivoColaboradorIn.close();
            }
            else
            {
                cout << "Não foi possivel abrir o arquivo" << endl;
            }

            cout << endl
                 << endl;
            system("pause");
            continue;
        }
        //*****************************************************************************************//
        // Opção Sair
        case 3:
        {
            system("clear");
            cin.ignore();
            cout << endl
                 << endl
                 << "Saindo das opções de cadastro" << endl
                 << endl
                 << endl;
            system("pause");
            system("clear");
            break;
        }
        //*****************************************************************************************//
        // Opção inexistente
        default:
        {
            cout << endl
                 << "O valor digitado não corresponde a nenhuma das opções!" << endl
                 << endl;
            system("pause");
            break;
        }
        }
    }

    return 0;
}
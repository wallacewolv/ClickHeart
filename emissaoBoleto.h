#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <time.h>
using namespace std;

int emissaoBoleto()
{
    system("clear");
    string confirmacaoBoleto;

    // Struct para consulta e Backup
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);

    while ((confirmacaoBoleto != "S") || (confirmacaoBoleto != "s"))
    {
        cout << endl
             << endl
             << "*******************************************" << endl
             << "*   Digite os dados para gerar o boleto   *" << endl
             << "*******************************************" << endl
             << endl;

        struct structBoletoPaciente
        {
            string nome;
            string cpf;
            string endereco;
            string complemento;
            string cep;
            string bairro;
            int convenio;
        };

        struct structBoletoPaciente boletoPaci;
        
        cin.ignore();
        cout << "Digite o nome: ";
        getline(cin, boletoPaci.nome);

        cout << endl
             << "Digite o CPF (com pontos): ";
        getline(cin, boletoPaci.cpf);

        cout << endl
             << "Digite o Endereco: ";
        getline(cin, boletoPaci.endereco);

        cout << endl
             << "Digite o Complemento: ";
        getline(cin, boletoPaci.complemento);

        cout << endl
             << "Digite o CEP (com pontos): ";
        getline(cin, boletoPaci.cep);

        cout << endl
             << "Digite o Bairro: ";
        getline(cin, boletoPaci.bairro);
        cout << endl
             << endl
             << "*****************************" << endl
             << "*  Escolha uma das op��es   *" << endl
             << "*****************************" << endl
             << " --------------------------- " << endl
             << "|  1 - Conv�nio Amil        |" << endl
             << "|---------------------------|" << endl
             << "|  2 - Conv�nio Sulamerica  |" << endl
             << "|---------------------------|" << endl
             << "|  3 - Conv�nio Unimed      |" << endl
             << "|---------------------------|" << endl
             << "|  4 - Sem Conv�nio         |" << endl
             << " --------------------------- " << endl
             << "   Digite a sua op��o: ";
        cin >> boletoPaci.convenio;

        //*********************************************************************************************//
        // Switch para op��es de conv�nio
        switch (boletoPaci.convenio)
        {
        // Conv�nio Amil
        case 1:
        {
            system("clear");
            cin.ignore();
            //Gerando arquivo do boleto exten��o .TXT
            ofstream arquivoBoletoOut;

            arquivoBoletoOut.open("boleto.txt", ios::trunc); // ios::trunc grava por cima do arquivo anterior

            arquivoBoletoOut << "-----------------------------------------------------------------------------------------" << endl
                             << "|                                                                                       |" << endl
                             << endl
                             << "   SR(a) " << boletoPaci.nome << "\t\t\t"
                             << "CPF: " << boletoPaci.cpf << endl
                             << "   Endereco: " << boletoPaci.endereco << "\t\t" << boletoPaci.complemento << endl
                             << "   CEP: " << boletoPaci.cep << "\t\t\t"
                             << "Bairro: " << boletoPaci.bairro << ", SP" << endl
                             << endl
                             << endl
                             << "   Conv�nio: "
                             << "\t"
                             << "Amil"
                             << "\t\t\t"
                             << "Valor R$ 80,00 " << endl
                             << endl
                             << "|-------|------|----|----------|----------------|--------|----------------|-------------|" << endl
                             << "| BANCO   PIM    11    INSTIT       R$ 80,00                  UNIVERSIDADE PAULISTA     |" << endl
                             << "|-------|------|----|----------|----------------|--------|----------------|-------------|" << endl
                             << "| 2323     41     9     7776      1000990001      44444      2311110001      1222000001 |" << endl
                             << "-----------------------------------------------------------------------------------------" << endl;

            arquivoBoletoOut.close();
            system("clear");
            cout << endl
                 << endl
                 << endl
                 << "Gerando boleto...   ...   ...   ..." << endl
                 << endl
                 << endl;
            system("pause");
            system("clear");

            // Fun��o leitura, pra exibir na tela o boleto gerado
            ifstream arquivoBoletoIn;
            string exibirBoleto;

            system("clear");
            cout << endl
                 << endl
                 << "                         **********************************                             " << endl
                 << "                         *        Confirmar Boleto        *                             " << endl
                 << "                         **********************************                             " << endl
                 << endl;

            arquivoBoletoIn.open("boleto.txt");
            //usando um if pra ter certeza que o arquivo esta aberto
            //metodo .is_open() verifica se ele abriu.
            if (arquivoBoletoIn.is_open())
            {
                // La�o while usando metodo geline pra leitura de aqruivo
                // usando as variaveis arquivoBoletoIn de saida e exibirBoleto pra exibiro conteudo
                while (getline(arquivoBoletoIn, exibirBoleto))
                {
                    cout << exibirBoleto << endl;
                }
                arquivoBoletoIn.close();
            }
            else
            {
                cout << "N�o foi possivel abrir o arquivo" << endl;
            }

            break;
        }

        //**********************************************************************************************************************//
        // Conv�nio Sulamerica
        case 2:
        {
            system("clear");
            cin.ignore();
            //Gerando arquivo do boleto exten��o .TXT
            ofstream arquivoBoletoOut;

            arquivoBoletoOut.open("boleto.txt", ios::trunc); // ios::trunc grava por cima do arquivo anterior

            arquivoBoletoOut << "-----------------------------------------------------------------------------------------" << endl
                             << "|                                                                                       |" << endl
                             << endl
                             << "   SR(a) " << boletoPaci.nome << "\t\t\t"
                             << "CPF: " << boletoPaci.cpf << endl
                             << "   Endereco: " << boletoPaci.endereco << "\t\t" << boletoPaci.complemento << endl
                             << "   CEP: " << boletoPaci.cep << "\t\t\t"
                             << "Bairro: " << boletoPaci.bairro << ", SP" << endl
                             << endl
                             << endl
                             << "   Conv�nio: "
                             << "\t"
                             << "Sulamerica"
                             << "\t\t\t"
                             << "Valor R$ 70,00 " << endl
                             << endl
                             << "|-------|------|----|----------|----------------|--------|----------------|-------------|" << endl
                             << "| BANCO   PIM    11    INSTIT       R$ 70,00                  UNIVERSIDADE PAULISTA     |" << endl
                             << "|-------|------|----|----------|----------------|--------|----------------|-------------|" << endl
                             << "| 2323     41     9     7776      1000990001      44444      2311110001      1222000001 |" << endl
                             << "-----------------------------------------------------------------------------------------" << endl;

            arquivoBoletoOut.close();
            system("clear");
            cout << endl
                 << endl
                 << endl
                 << "Gerando boleto...   ...   ...   ..." << endl
                 << endl
                 << endl;
            system("pause");
            system("clear");

            // Fun��o leitura, pra exibir na tela o boleto gerado
            ifstream arquivoBoletoIn;
            string exibirBoleto;

            system("clear");
            cout << endl
                 << endl
                 << "                         **********************************                             " << endl
                 << "                         *        Confirmar Boleto        *                             " << endl
                 << "                         **********************************                             " << endl
                 << endl;

            arquivoBoletoIn.open("boleto.txt");
            //usando um if pra ter certeza que o arquivo esta aberto
            //metodo .is_open() verifica se ele abriu.
            if (arquivoBoletoIn.is_open())
            {
                // La�o while usando metodo geline pra leitura de aqruivo
                // usando as variaveis arquivoBoletoIn de saida e exibirBoleto pra exibiro conteudo
                while (getline(arquivoBoletoIn, exibirBoleto))
                {
                    cout << exibirBoleto << endl;
                }
                arquivoBoletoIn.close();
            }
            else
            {
                cout << "N�o foi possivel abrir o arquivo" << endl;
            }
            break;
        }

        //**********************************************************************************************************************//
        // Conv�nio Unimed
        case 3:
        {
            system("clear");
            cin.ignore();
            //Gerando arquivo do boleto exten��o .TXT
            ofstream arquivoBoletoOut;

            arquivoBoletoOut.open("boleto.txt", ios::trunc); // ios::trunc grava por cima do arquivo anterior

            arquivoBoletoOut << "-----------------------------------------------------------------------------------------" << endl
                             << "|                                                                                       |" << endl
                             << endl
                             << "   SR(a) " << boletoPaci.nome << "\t\t\t"
                             << "CPF: " << boletoPaci.cpf << endl
                             << "   Endereco: " << boletoPaci.endereco << "\t\t" << boletoPaci.complemento << endl
                             << "   CEP: " << boletoPaci.cep << "\t\t\t"
                             << "Bairro: " << boletoPaci.bairro << ", SP" << endl
                             << endl
                             << endl
                             << "   Conv�nio: "
                             << "\t"
                             << "Unimed"
                             << "\t\t\t"
                             << "Valor R$ 60,00 " << endl
                             << endl
                             << "|-------|------|----|----------|----------------|--------|----------------|-------------|" << endl
                             << "| BANCO   PIM    11    INSTIT       R$ 60,00                  UNIVERSIDADE PAULISTA     |" << endl
                             << "|-------|------|----|----------|----------------|--------|----------------|-------------|" << endl
                             << "| 2323     41     9     7776      1000990001      44444      2311110001      1222000001 |" << endl
                             << "-----------------------------------------------------------------------------------------" << endl;

            arquivoBoletoOut.close();
            system("clear");
            cout << endl
                 << endl
                 << endl
                 << "Gerando boleto...   ...   ...   ..." << endl
                 << endl
                 << endl;
            system("pause");
            system("clear");

            // Fun��o leitura, pra exibir na tela o boleto gerado
            ifstream arquivoBoletoIn;
            string exibirBoleto;

            system("clear");
            cout << endl
                 << endl
                 << "                         **********************************                             " << endl
                 << "                         *        Confirmar Boleto        *                             " << endl
                 << "                         **********************************                             " << endl
                 << endl;

            arquivoBoletoIn.open("boleto.txt");
            //usando um if pra ter certeza que o arquivo esta aberto
            //metodo .is_open() verifica se ele abriu.
            if (arquivoBoletoIn.is_open())
            {
                // La�o while usando metodo geline pra leitura de aqruivo
                // usando as variaveis arquivoBoletoIn de saida e exibirBoleto pra exibiro conteudo
                while (getline(arquivoBoletoIn, exibirBoleto))
                {
                    cout << exibirBoleto << endl;
                }
                arquivoBoletoIn.close();
            }
            else
            {
                cout << "N�o foi possivel abrir o arquivo" << endl;
            }
            break;
        }

        //**********************************************************************************************************************//
        // Sem conv�nio
        case 4:
        {
            system("clear");
            cin.ignore();
            //Gerando arquivo do boleto exten��o .TXT
            ofstream arquivoBoletoOut;

            arquivoBoletoOut.open("boleto.txt", ios::trunc); // ios::trunc grava por cima do arquivo anterior

            arquivoBoletoOut << "-----------------------------------------------------------------------------------------" << endl
                             << "|                                                                                       |" << endl
                             << endl
                             << "   SR(a) " << boletoPaci.nome << "\t\t\t"
                             << "CPF: " << boletoPaci.cpf << endl
                             << "   Endereco: " << boletoPaci.endereco << "\t\t" << boletoPaci.complemento << endl
                             << "   CEP: " << boletoPaci.cep << "\t\t\t"
                             << "Bairro: " << boletoPaci.bairro << ", SP" << endl
                             << endl
                             << endl
                             << "   Conv�nio: "
                             << "\t"
                             << "Sem conv�nio"
                             << "\t\t\t"
                             << "Valor R$ 130,00 " << endl
                             << endl
                             << "|-------|------|----|----------|----------------|--------|----------------|-------------|" << endl
                             << "| BANCO   PIM    11    INSTIT      R$ 130,00                  UNIVERSIDADE PAULISTA     |" << endl
                             << "|-------|------|----|----------|----------------|--------|----------------|-------------|" << endl
                             << "| 2323     41     9     7776      1000990001      44444      2311110001      1222000001 |" << endl
                             << "-----------------------------------------------------------------------------------------" << endl;

            arquivoBoletoOut.close();
            system("clear");
            cout << endl
                 << endl
                 << endl
                 << "Gerando boleto...   ...   ...   ..." << endl
                 << endl
                 << endl;
            system("pause");
            system("clear");

            // Fun��o leitura, pra exibir na tela o boleto gerado
            ifstream arquivoBoletoIn;
            string exibirBoleto;

            system("clear");
            cout << endl
                 << endl
                 << "                         **********************************                             " << endl
                 << "                         *        Confirmar Boleto        *                             " << endl
                 << "                         **********************************                             " << endl
                 << endl;

            arquivoBoletoIn.open("boleto.txt");
            //usando um if pra ter certeza que o arquivo esta aberto
            //metodo .is_open() verifica se ele abriu.
            if (arquivoBoletoIn.is_open())
            {
                // La�o while usando metodo geline pra leitura de aqruivo
                // usando as variaveis arquivoBoletoIn de saida e exibirBoleto pra exibiro conteudo
                while (getline(arquivoBoletoIn, exibirBoleto))
                {
                    cout << exibirBoleto << endl;
                }
                arquivoBoletoIn.close();
            }
            else
            {
                cout << "N�o foi possivel abrir o arquivo" << endl;
            }
            break;
        }
        //**********************************************************************************************************************//
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
        cout << endl
             << endl
             << "Dados est�o certos SIM(S) ou NAO(N) ?  ";
        cin >> confirmacaoBoleto;

        system("clear");
        ifstream arquivoBoletoIn;
        string exibirBoleto;
        // Cadastro não está Ok;
        if ((confirmacaoBoleto == "N") || (confirmacaoBoleto == "n"))
        {
            remove("boleto.txt");
            cout << endl
                 << endl
                 << "Por favor" << endl
                 << endl
                 << "Digite novamente os dados" << endl
                 << endl;
            cin.ignore();
            system("pause");
            system("clear");
            continue;
        }
        else
        {
            arquivoBoletoIn.open("boleto.txt");
            ofstream arquivoBoletoBackupOut;
            arquivoBoletoBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/boleto.txt", ios::app);

            if (arquivoBoletoIn.is_open())
            {
                while (getline(arquivoBoletoIn, exibirBoleto))
                {
                    arquivoBoletoBackupOut << exibirBoleto << endl;
                }
                arquivoBoletoIn.close();
                // Fun��o para abrir e salvar os dados no backup automatico
                arquivoBoletoBackupOut.close();
                arquivoBoletoBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/boleto.txt", ios::app);
                arquivoBoletoBackupOut << "Backup  acima, referente ao dia "
                                       << data_hora_atual->tm_mday << "/"          // Dia do backup
                                       << data_hora_atual->tm_mon + 1 << "/"       // M�s do backup
                                       << data_hora_atual->tm_year + 1900 << " - " // Ano do backup
                                       << data_hora_atual->tm_hour << ":"          // Hora do backup
                                       << data_hora_atual->tm_min << ":"           // Minuto do backup
                                       << data_hora_atual->tm_sec << endl          // Segundos do backup
                                       << "-------------------------------------------------------------------------------------------" << endl
                                       << endl;
                arquivoBoletoBackupOut.close();
            }
            cout << endl
                 << endl
                 << "   Boleto emitido com sucesso!   " << endl
                 << endl;
            system("pause");
            system("clear");
            break;
        }
    }
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <time.h>
using namespace std;

int relatorioDeAtendimento()
{
    system("clear");
    cin.ignore();
    int escolhaDaUnidade = 0;
    int sair = 0;

    // Struct para armazenar o horario para backup
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);

    while (sair != 4)
    {
        system("clear");
        cout << endl
             << endl
             << "  Escolha uma das opÁıes  " << endl
             << " ------------------------ " << endl
             << "|    1 - Unidade I       |" << endl
             << "|------------------------|" << endl
             << "|    2 - Unidade II      |" << endl
             << "|------------------------|" << endl
             << "|    3 - Unidade III     |" << endl
             << "|------------------------|" << endl
             << "|    4 - Sair            |" << endl
             << " ------------------------ " << endl
             << "   Digite a sua opÁ„o: ";
        cin >> sair;

        //*********************************************************************************************//
        // Switch para opÁıes de convÍnio
        switch (sair)
        {
        // Unidade I
        case 1:
        {
            system("clear");
            string confirmacaoRelatorio;
            while ((confirmacaoRelatorio != "S") || (confirmacaoRelatorio != "s"))
            {
                system("clear");
                cin.ignore();
                cout << endl
                     << endl
                     << "**********************************************" << endl
                     << "*   Digite os dados para gerar o relatÛrio   *" << endl
                     << "**********************************************" << endl
                     << endl;

                ofstream arquivoRelatorioOut;

                arquivoRelatorioOut.open("relatorioDeAtendimentoUnidadeParaisoI.txt", ios::trunc); // ios::trunc grava por cima do arquivo anterior

                arquivoRelatorioOut << " ------------------------------------------ " << endl
                                    << "|                                          |" << endl
                                    << "|          RELAT”RIO ATENDIMENTO           |" << endl
                                    << "|                                          |" << endl
                                    << "|        CLINICAS PARAISO UNIDADE I        |" << endl
                                    << "|                                          |" << endl
                                    << " ------------------------------------------ " << endl
                                    << " __________________________________________ " << endl
                                    << "|------------------------------------------|" << endl
                                    << "|  M…TRICAS - CHAVE - ATENDIMENTOS         |" << endl
                                    << "|__________________________________________|" << endl
                                    << "|------------------------------------------|" << endl
                                    << "|  ATENDIMENTOS GERAIS        450 PESSOAS  |" << endl
                                    << "|------------------------------------------|" << endl
                                    << "|  ATENDIMENTOS CARDIOLOGIA   123 PESSOAS  |" << endl
                                    << "|------------------------------------------|" << endl
                                    << "|  ATENDIMENTOS DIAGNOSTICO   187 PESSOAS  |" << endl
                                    << "|------------------------------------------|" << endl
                                    << "|  ATENDIMENTOS ORTOPEDIA     113 PESSOAS  |" << endl
                                    << "|------------------------------------------|" << endl
                                    << "|  ATENDIMENTOS TRAUMOLOGIA    27 PESSOAS  |" << endl
                                    << " ------------------------------------------ " << endl;

                arquivoRelatorioOut.close();

                system("clear");
                cout << endl
                     << endl
                     << endl
                     << "Gerando relatÛrio...   ...   ...   ..." << endl
                     << endl
                     << endl;
                system("pause");
                system("clear");

                ifstream arquivoRelatorioIn;
                string exibirRelatorio;

                system("clear");
                cout << "  ***********************************  " << endl
                     << "  *       Confirmar Relatorio       *  " << endl
                     << "  ***********************************  " << endl
                     << endl
                     << endl;

                arquivoRelatorioIn.open("relatorioDeAtendimentoUnidadeParaisoI.txt");

                if (arquivoRelatorioIn.is_open())
                {
                    while (getline(arquivoRelatorioIn, exibirRelatorio))
                    {
                        cout << exibirRelatorio << endl;
                    }
                    arquivoRelatorioIn.close();
                }
                else
                {
                    cout << "N„o foi possivel abrir o arquivo" << endl;
                }

                cout << endl
                     << endl
                     << "Dados est„o certos SIM(S) ou NAO(N) ?  ";
                cin >> confirmacaoRelatorio;

                system("clear");
                // Cadastro n√£o est√° Ok;
                if ((confirmacaoRelatorio == "N") || (confirmacaoRelatorio == "n"))
                {
                    remove("relatorioDeAtendimentoUnidadeParaisoI.txt");
                    cout << endl
                         << endl
                         << "Por favor" << endl
                         << endl
                         << "Digite novamente os dados" << endl
                         << endl;
                    system("clear");
                }
                else
                {
                    arquivoRelatorioIn.open("relatorioDeAtendimentoUnidadeParaisoI.txt");
                    ofstream arquivoRelatorioBackupOut;
                    arquivoRelatorioBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/relatorioDeAtendimentoUnidadeParaisoI.txt", ios::app);

                    if (arquivoRelatorioIn.is_open())
                    {
                        while (getline(arquivoRelatorioIn, exibirRelatorio))
                        {
                            arquivoRelatorioBackupOut << exibirRelatorio << endl;
                        }
                        arquivoRelatorioIn.close();
                        // FunÁ„o para abrir e salvar os dados no backup automatico
                        arquivoRelatorioBackupOut.close();
                        arquivoRelatorioBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/relatorioDeAtendimentoUnidadeParaisoI.txt", ios::app);
                        arquivoRelatorioBackupOut << "Backup  acima, referente ao dia "
                                                  << data_hora_atual->tm_mday << "/"          // Dia do backup
                                                  << data_hora_atual->tm_mon + 1 << "/"       // MÍs do backup
                                                  << data_hora_atual->tm_year + 1900 << " - " // Ano do backup
                                                  << data_hora_atual->tm_hour << ":"          // Hora do backup
                                                  << data_hora_atual->tm_min << ":"           // Minuto do backup
                                                  << data_hora_atual->tm_sec << endl
                                                  << "-------------------------------------------------------------------------------------------" << endl
                                                  << endl;
                        arquivoRelatorioBackupOut.close();
                    }
                    cout << endl
                         << endl
                         << "   RelatÛrio emitido com sucesso!   " << endl
                         << endl;
                    system("pause");
                    system("clear");
                    break;
                }
            }
            continue;
        }
        //**********************************************************************************************************************//
        // Unidade II
        case 2:
        {
            system("clear");
            string confirmacaoRelatorio;
            while ((confirmacaoRelatorio != "S") || (confirmacaoRelatorio != "s"))
            {
                system("clear");
                cin.ignore();
                cout << endl
                     << endl
                     << "**********************************************" << endl
                     << "*   Digite os dados para gerar o relatÛrio   *" << endl
                     << "**********************************************" << endl
                     << endl;

                ofstream arquivoRelatorioOut;

                arquivoRelatorioOut.open("relatorioDeAtendimentoUnidadeParaisoII.txt", ios::trunc); // ios::trunc grava por cima do arquivo anterior

                arquivoRelatorioOut << " ------------------------------------------- " << endl
                                    << "|                                           |" << endl
                                    << "|          RELAT”RIO ATENDIMENTO            |" << endl
                                    << "|                                           |" << endl
                                    << "|       CLINICAS PARAISO UNIDADE II         |" << endl
                                    << "|                                           |" << endl
                                    << " ------------------------------------------- " << endl
                                    << " ___________________________________________ " << endl
                                    << "|-------------------------------------------|" << endl
                                    << "|  M…TRICAS - CHAVE - ATENDIMENTOS          |" << endl
                                    << "|___________________________________________|" << endl
                                    << "|-------------------------------------------|" << endl
                                    << "|  ATENDIMENTOS GERAIS         387 PESSOAS  |" << endl
                                    << "|-------------------------------------------|" << endl
                                    << "|  ATENDIMENTOS INFECTOLOGIA    94 PESSOAS  |" << endl
                                    << "|-------------------------------------------|" << endl
                                    << "|  ATENDIMENTOS OFTALMOLOGIA    89 PESSOAS  |" << endl
                                    << "|-------------------------------------------|" << endl
                                    << "|  ATENDIMENTOS RADIOLOGIA     127 PESSOAS  |" << endl
                                    << "|-------------------------------------------|" << endl
                                    << "|  ATENDIMENTOS UROLOGIA        68 PESSOAS  |" << endl
                                    << " ------------------------------------------- " << endl;

                arquivoRelatorioOut.close();

                system("clear");
                cout << endl
                     << endl
                     << endl
                     << "Gerando relatÛrio...   ...   ...   ..." << endl
                     << endl
                     << endl;
                system("pause");
                system("clear");

                ifstream arquivoRelatorioIn;
                string exibirRelatorio;

                system("clear");
                cout << "   ***********************************  " << endl
                     << "   *       Confirmar Relatorio       *  " << endl
                     << "   ***********************************  " << endl
                     << endl
                     << endl;

                arquivoRelatorioIn.open("relatorioDeAtendimentoUnidadeParaisoII.txt");

                if (arquivoRelatorioIn.is_open())
                {
                    while (getline(arquivoRelatorioIn, exibirRelatorio))
                    {
                        cout << exibirRelatorio << endl;
                    }
                    arquivoRelatorioIn.close();
                }
                else
                {
                    cout << "N„o foi possivel abrir o arquivo" << endl;
                }

                cout << endl
                     << endl
                     << "Dados est„o certos SIM(S) ou NAO(N) ?  ";
                cin >> confirmacaoRelatorio;

                system("clear");
                // Cadastro n√£o est√° Ok;
                if ((confirmacaoRelatorio == "N") || (confirmacaoRelatorio == "n"))
                {
                    remove("relatorioDeAtendimentoUnidadeParaisoII.txt");
                    cout << endl
                         << endl
                         << "Por favor" << endl
                         << endl
                         << "Digite novamente os dados" << endl
                         << endl;
                    system("clear");
                }
                else
                {
                    arquivoRelatorioIn.open("relatorioDeAtendimentoUnidadeParaisoII.txt");
                    ofstream arquivoRelatorioBackupOut;
                    arquivoRelatorioBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/relatorioDeAtendimentoUnidadeParaisoII.txt", ios::app);

                    if (arquivoRelatorioIn.is_open())
                    {
                        while (getline(arquivoRelatorioIn, exibirRelatorio))
                        {
                            arquivoRelatorioBackupOut << exibirRelatorio << endl;
                        }
                        arquivoRelatorioIn.close();
                        // FunÁ„o para abrir e salvar os dados no backup automatico
                        arquivoRelatorioBackupOut.close();
                        arquivoRelatorioBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/relatorioDeAtendimentoUnidadeParaisoII.txt", ios::app);
                        arquivoRelatorioBackupOut << "Backup  acima, referente ao dia "
                                                  << data_hora_atual->tm_mday << "/"          // Dia do backup
                                                  << data_hora_atual->tm_mon + 1 << "/"       // MÍs do backup
                                                  << data_hora_atual->tm_year + 1900 << " - " // Ano do backup
                                                  << data_hora_atual->tm_hour << ":"          // Hora do backup
                                                  << data_hora_atual->tm_min << ":"           // Minuto do backup
                                                  << data_hora_atual->tm_sec << endl
                                                  << "-------------------------------------------------------------------------------------------" << endl
                                                  << endl;
                        arquivoRelatorioBackupOut.close();
                    }
                    cout << endl
                         << endl
                         << "   RelatÛrio emitido com sucesso!   " << endl
                         << endl;
                    system("pause");
                    system("clear");
                    break;
                }
            }
            continue;
        }
        //**********************************************************************************************************************//
        // Unidade III
        case 3:
        {
            system("clear");
            string confirmacaoRelatorio;
            while ((confirmacaoRelatorio != "S") || (confirmacaoRelatorio != "s"))
            {
                system("clear");
                cin.ignore();
                cout << endl
                     << endl
                     << "**********************************************" << endl
                     << "*   Digite os dados para gerar o relatÛrio   *" << endl
                     << "**********************************************" << endl
                     << endl;

                ofstream arquivoRelatorioOut;

                arquivoRelatorioOut.open("relatorioDeAtendimentoUnidadeParaisoIII.txt", ios::trunc); // ios::trunc grava por cima do arquivo anterior

                arquivoRelatorioOut << " -------------------------------------------- " << endl
                                    << "|                                            |" << endl
                                    << "|          RELAT”RIO ATENDIMENTO             |" << endl
                                    << "|                                            |" << endl
                                    << "|        CLINICAS PARAISO UNIDADE I          |" << endl
                                    << "|                                            |" << endl
                                    << " -------------------------------------------- " << endl
                                    << " ____________________________________________ " << endl
                                    << "|--------------------------------------------|" << endl
                                    << "|  M…TRICAS - CHAVE - ATENDIMENTOS           |" << endl
                                    << "|____________________________________________|" << endl
                                    << "|--------------------------------------------|" << endl
                                    << "|  ATENDIMENTOS GERAIS        502 PESSOAS    |" << endl
                                    << "|--------------------------------------------|" << endl
                                    << "|  ATENDIMENTOS GERIATRIA      85 PESSOAS    |" << endl
                                    << "|--------------------------------------------|" << endl
                                    << "|  ATENDIMENTOS GINECOLOGIA   136 PESSOAS    |" << endl
                                    << "|--------------------------------------------|" << endl
                                    << "|  ATENDIMENTOS OBSTRETICIA    77 PESSOAS    |" << endl
                                    << "|--------------------------------------------|" << endl
                                    << "|  ATENDIMENTOS PEDIATRIA     204 PESSOAS    |" << endl
                                    << " -------------------------------------------- " << endl;

                arquivoRelatorioOut.close();

                system("clear");
                cout << endl
                     << endl
                     << endl
                     << "Gerando relatÛrio...   ...   ...   ..." << endl
                     << endl
                     << endl;
                system("pause");
                system("clear");

                ifstream arquivoRelatorioIn;
                string exibirRelatorio;

                system("clear");
                cout << "  ***********************************  " << endl
                     << "  *       Confirmar Relatorio       *  " << endl
                     << "  ***********************************  " << endl
                     << endl
                     << endl;

                arquivoRelatorioIn.open("relatorioDeAtendimentoUnidadeParaisoIII.txt");

                if (arquivoRelatorioIn.is_open())
                {
                    while (getline(arquivoRelatorioIn, exibirRelatorio))
                    {
                        cout << exibirRelatorio << endl;
                    }
                    arquivoRelatorioIn.close();
                }
                else
                {
                    cout << "N„o foi possivel abrir o arquivo" << endl;
                }

                cout << endl
                     << endl
                     << "Dados est„o certos SIM(S) ou NAO(N) ?  ";
                cin >> confirmacaoRelatorio;

                system("clear");
                // Cadastro n√£o est√° Ok;
                if ((confirmacaoRelatorio == "N") || (confirmacaoRelatorio == "n"))
                {
                    remove("relatorioDeAtendimentoUnidadeParaisoIII.txt");
                    cout << endl
                         << endl
                         << "Por favor" << endl
                         << endl
                         << "Digite novamente os dados" << endl
                         << endl;
                    system("clear");
                }
                else
                {
                    arquivoRelatorioIn.open("relatorioDeAtendimentoUnidadeParaisoIII.txt");
                    ofstream arquivoRelatorioBackupOut;
                    arquivoRelatorioBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/relatorioDeAtendimentoUnidadeParaisoIII.txt", ios::app);

                    if (arquivoRelatorioIn.is_open())
                    {
                        while (getline(arquivoRelatorioIn, exibirRelatorio))
                        {
                            arquivoRelatorioBackupOut << exibirRelatorio << endl;
                        }
                        arquivoRelatorioIn.close();
                        // FunÁ„o para abrir e salvar os dados no backup automatico
                        arquivoRelatorioBackupOut.close();
                        arquivoRelatorioBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/relatorioDeAtendimentoUnidadeParaisoIII.txt", ios::app);
                        arquivoRelatorioBackupOut << "Backup  acima, referente ao dia "
                                                  << data_hora_atual->tm_mday << "/"          // Dia do backup
                                                  << data_hora_atual->tm_mon + 1 << "/"       // MÍs do backup
                                                  << data_hora_atual->tm_year + 1900 << " - " // Ano do backup
                                                  << data_hora_atual->tm_hour << ":"          // Hora do backup
                                                  << data_hora_atual->tm_min << ":"           // Minuto do backup
                                                  << data_hora_atual->tm_sec << endl
                                                  << "-------------------------------------------------------------------------------------------" << endl
                                                  << endl;
                        arquivoRelatorioBackupOut.close();
                    }
                    cout << endl
                         << endl
                         << "   RelatÛrio emitido com sucesso!   " << endl
                         << endl;
                    system("pause");
                    system("clear");
                    break;
                }
            }
            continue;
        }

        case 4:
        {
            break;
        }
        //**********************************************************************************************************************//
        // OpÁ„o inexistente
        default:
        {
            cout << endl
                 << "O valor digitado n„o corresponde a nenhuma das opÁıes!" << endl
                 << endl;
            system("pause");
            continue;
        }
        }
        sair = 4;
        // OpÁ„o 0 para sair do laÁo
        if (sair == 4)
        {
            system("clear");
            cin.ignore();
            cout << endl
                 << endl
                 << "Saindo das opÁıes" << endl
                 << endl;
            cout << system("pause");
            break;
        }
    }
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <time.h>
using namespace std;

int relatorioMensal()
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

    struct relatorioMensal
    {
        double receitas;
        double despesasOperacionais;
        double lucrosOperacionais;
        double depreciacao;
        double juros;
        double lucroLiquido;
        double impostos;
        double lucroPosImpostos;
    };

    while (sair != 4)
    {
        system("clear");
        cout << endl
             << endl
             << "  Escolha uma das op��es  " << endl
             << " ------------------------ " << endl
             << "|    1 - Unidade I       |" << endl
             << "|------------------------|" << endl
             << "|    2 - Unidade II      |" << endl
             << "|------------------------|" << endl
             << "|    3 - Unidade III     |" << endl
             << "|------------------------|" << endl
             << "|    4 - Sair            |" << endl
             << " ------------------------ " << endl
             << "   Digite a sua op��o: ";
        cin >> sair;

        //*********************************************************************************************//
        // Switch para op��es de conv�nio
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
                     << "*   Digite os dados para gerar o relat�rio   *" << endl
                     << "**********************************************" << endl
                     << endl;

                relatorioMensal unidadeI;
                fflush(stdin);
                cout << "Digite a receita do m�s: ";
                cin >> unidadeI.receitas;

                cout << endl
                     << endl
                     << "Digite as despesas do m�s: ";
                cin >> unidadeI.despesasOperacionais;

                cout << endl
                     << endl
                     << "Digite os juros recolhidos no m�s: ";
                cin >> unidadeI.juros;

                cout << endl
                     << endl
                     << "Digite o valor dos impostos do m�s passado: ";
                cin >> unidadeI.impostos;

                // Calculos para achar os valores do relat�rio
                unidadeI.impostos = unidadeI.impostos / 4;
                unidadeI.lucroLiquido = unidadeI.receitas - (unidadeI.impostos - unidadeI.despesasOperacionais);
                unidadeI.lucrosOperacionais = unidadeI.lucroLiquido - unidadeI.despesasOperacionais;
                unidadeI.depreciacao = unidadeI.receitas - (unidadeI.lucroLiquido - unidadeI.impostos);
                unidadeI.lucroPosImpostos = unidadeI.lucroLiquido - unidadeI.impostos;

                ofstream arquivoRelatorioOut;

                arquivoRelatorioOut.open("relatorioMensalUnidadeParaisoI.txt", ios::trunc); // ios::trunc grava por cima do arquivo anterior

                arquivoRelatorioOut << " ----------------------------------------------------------------------------------------- " << endl
                                    << "|                                                                                         |" << endl
                                    << "|                             RELAT�RIO FINANCEIRO MENSAL                                 |" << endl
                                    << "|                                                                                         |" << endl
                                    << "|                             CLINICAS PARAISO UNIDADE I                                  |" << endl
                                    << "|                                                                                         |" << endl
                                    << " ----------------------------------------------------------------------------------------- " << endl
                                    << "___________________________________________________________________________________________" << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "  M�TRICAS - CHAVE                                                                         " << endl
                                    << "___________________________________________________________________________________________" << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "                                                   _____                                   " << endl
                                    << "  RECEITAS           R$ " << unidadeI.receitas << ",00             _____/                  " << endl
                                    << "                                       _____/                                              " << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "                                                   _____                                   " << endl
                                    << "  LUCRO LIQUIDO      R$ " << unidadeI.lucroLiquido << ",00             _____/              " << endl
                                    << "                                       _____/                                              " << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "                                                                                           " << endl
                                    << "  JUROS              R$ " << unidadeI.juros << ",00         -----*-----*-----              " << endl
                                    << "                                                                                           " << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "                                                                                           " << endl
                                    << "  DEPRECIA��O        R$ " << unidadeI.depreciacao << ",00         -----*-----*-----        " << endl
                                    << "                                                                                           " << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "                                                   _____                                   " << endl
                                    << "  LUCRO OPERACIONAL  R$ " << unidadeI.lucrosOperacionais << ",00             _____/        " << endl
                                    << "                                       _____/                                              " << endl
                                    << "___________________________________________________________________________________________" << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "  RESUMO DE TODAS AS M�TRICAS M�S                                                     " << endl
                                    << "___________________________________________________________________________________________" << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "  RECEITAS                         R$ " << unidadeI.receitas << ",00                 " << endl
                                    << "  DESPESAS OPERACIONAIS            R$ " << unidadeI.despesasOperacionais << ",00     " << endl
                                    << "  LUCRO OPERACIONAL                R$ " << unidadeI.lucrosOperacionais << ",00       " << endl
                                    << "  DEPRECIA��O                      R$ " << unidadeI.depreciacao << ",00              " << endl
                                    << "  JUROS                            R$ " << unidadeI.juros << ",00                    " << endl
                                    << "  LUCRO LIQUIDO                    R$ " << unidadeI.lucroLiquido << ",00             " << endl
                                    << "  IMPOSTOS                         R$ " << unidadeI.impostos << ",00                 " << endl
                                    << "  LUCROS AP�S DEDU��O DE IMPOSTOS  R$ " << unidadeI.lucroPosImpostos << ",00         " << endl
                                    << "-------------------------------------------------------------------------------------------" << endl;

                arquivoRelatorioOut.close();

                system("clear");
                cout << endl
                     << endl
                     << endl
                     << "Gerando relat�rio...   ...   ...   ..." << endl
                     << endl
                     << endl;
                system("pause");
                system("clear");

                ifstream arquivoRelatorioIn;
                string exibirRelatorio;

                system("clear");
                cout << "                         ***********************************                               " << endl
                     << "                         *       Confirmar Relatorio       *                               " << endl
                     << "                         ***********************************                               " << endl
                     << endl
                     << endl;

                arquivoRelatorioIn.open("relatorioMensalUnidadeParaisoI.txt");

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
                    cout << "N�o foi possivel abrir o arquivo" << endl;
                }

                cout << endl
                     << endl
                     << "Dados est�o certos SIM(S) ou NAO(N) ?  ";
                cin >> confirmacaoRelatorio;

                system("clear");
                // Cadastro não está Ok;
                if ((confirmacaoRelatorio == "N") || (confirmacaoRelatorio == "n"))
                {
                    remove("relatorioMensalUnidadeParaisoI.txt");
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
                    arquivoRelatorioIn.open("relatorioMensalUnidadeParaisoI.txt");
                    ofstream arquivoRelatorioBackupOut;
                    arquivoRelatorioBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/relatorioMensalUnidadeParaisoI.txt", ios::app);

                    if (arquivoRelatorioIn.is_open())
                    {
                        while (getline(arquivoRelatorioIn, exibirRelatorio))
                        {
                            arquivoRelatorioBackupOut << exibirRelatorio << endl;
                        }
                        arquivoRelatorioIn.close();
                        // Fun��o para abrir e salvar os dados no backup automatico
                        arquivoRelatorioBackupOut.close();
                        arquivoRelatorioBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/relatorioMensalUnidadeParaisoI.txt", ios::app);
                        arquivoRelatorioBackupOut << "Backup  acima, referente ao dia "
                                                  << data_hora_atual->tm_mday << "/"          // Dia do backup
                                                  << data_hora_atual->tm_mon + 1 << "/"       // M�s do backup
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
                         << "   Relat�rio emitido com sucesso!   " << endl
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
                     << "*   Digite os dados para gerar o relat�rio   *" << endl
                     << "**********************************************" << endl
                     << endl;

                relatorioMensal unidadeII;
                fflush(stdin);
                cout << "Digite a receita do m�s: ";
                cin >> unidadeII.receitas;

                cout << endl
                     << endl
                     << "Digite as despesas do m�s: ";
                cin >> unidadeII.despesasOperacionais;

                cout << endl
                     << endl
                     << "Digite os juros recolhidos no m�s: ";
                cin >> unidadeII.juros;

                cout << endl
                     << endl
                     << "Digite o valor dos impostos do m�s passado: ";
                cin >> unidadeII.impostos;

                // Calculos para achar os valores do relat�rio
                unidadeII.impostos = unidadeII.impostos / 4;
                unidadeII.lucroLiquido = unidadeII.receitas - (unidadeII.impostos - unidadeII.despesasOperacionais);
                unidadeII.lucrosOperacionais = unidadeII.lucroLiquido - unidadeII.despesasOperacionais;
                unidadeII.depreciacao = unidadeII.receitas - (unidadeII.lucroLiquido - unidadeII.impostos);
                unidadeII.lucroPosImpostos = unidadeII.lucroLiquido - unidadeII.impostos;

                ofstream arquivoRelatorioOut;

                arquivoRelatorioOut.open("relatorioMensalUnidadeParaisoII.txt", ios::trunc); // ios::trunc grava por cima do arquivo anterior

                arquivoRelatorioOut << " ----------------------------------------------------------------------------------------- " << endl
                                    << "|                                                                                         |" << endl
                                    << "|                            RELAT�RIO FINANCEIRO MENSAL                                 |" << endl
                                    << "|                                                                                         |" << endl
                                    << "|                            CLINICAS PARAISO UNIDADE II                                  |" << endl
                                    << "|                                                                                         |" << endl
                                    << " ----------------------------------------------------------------------------------------- " << endl
                                    << "___________________________________________________________________________________________" << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "  M�TRICAS - CHAVE                                                                         " << endl
                                    << "___________________________________________________________________________________________" << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "                                                   _____                                   " << endl
                                    << "  RECEITAS           R$ " << unidadeII.receitas << ",00             _____/                  " << endl
                                    << "                                       _____/                                              " << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "                                                   _____                                   " << endl
                                    << "  LUCRO LIQUIDO      R$ " << unidadeII.lucroLiquido << ",00             _____/              " << endl
                                    << "                                       _____/                                              " << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "                                                                                           " << endl
                                    << "  JUROS              R$ " << unidadeII.juros << ",00         -----*-----*-----              " << endl
                                    << "                                                                                           " << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "                                                                                           " << endl
                                    << "  DEPRECIA��O        R$ " << unidadeII.depreciacao << ",00         -----*-----*-----        " << endl
                                    << "                                                                                           " << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "                                                   _____                                   " << endl
                                    << "  LUCRO OPERACIONAL  R$ " << unidadeII.lucrosOperacionais << ",00             _____/        " << endl
                                    << "                                       _____/                                              " << endl
                                    << "___________________________________________________________________________________________" << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "  RESUMO DE TODAS AS M�TRICAS M�S                                                     " << endl
                                    << "___________________________________________________________________________________________" << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "  RECEITAS                         R$ " << unidadeII.receitas << ",00                 " << endl
                                    << "  DESPESAS OPERACIONAIS            R$ " << unidadeII.despesasOperacionais << ",00     " << endl
                                    << "  LUCRO OPERACIONAL                R$ " << unidadeII.lucrosOperacionais << ",00       " << endl
                                    << "  DEPRECIA��O                      R$ " << unidadeII.depreciacao << ",00              " << endl
                                    << "  JUROS                            R$ " << unidadeII.juros << ",00                    " << endl
                                    << "  LUCRO LIQUIDO                    R$ " << unidadeII.lucroLiquido << ",00             " << endl
                                    << "  IMPOSTOS                         R$ " << unidadeII.impostos << ",00                 " << endl
                                    << "  LUCROS AP�S DEDU��O DE IMPOSTOS  R$ " << unidadeII.lucroPosImpostos << ",00         " << endl
                                    << "-------------------------------------------------------------------------------------------" << endl;

                arquivoRelatorioOut.close();

                system("clear");
                cout << endl
                     << endl
                     << endl
                     << "Gerando relat�rio...   ...   ...   ..." << endl
                     << endl
                     << endl;
                system("pause");
                system("clear");

                ifstream arquivoRelatorioIn;
                string exibirRelatorio;

                system("clear");
                cout << "                         ***********************************                               " << endl
                     << "                         *       Confirmar Relatorio       *                               " << endl
                     << "                         ***********************************                               " << endl
                     << endl
                     << endl;

                arquivoRelatorioIn.open("relatorioMensalUnidadeParaisoII.txt");

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
                    cout << "N�o foi possivel abrir o arquivo" << endl;
                }

                cout << endl
                     << endl
                     << "Dados est�o certos SIM(S) ou NAO(N) ?  ";
                cin >> confirmacaoRelatorio;

                system("clear");
                // Cadastro não está Ok;
                if ((confirmacaoRelatorio == "N") || (confirmacaoRelatorio == "n"))
                {
                    remove("relatorioMensalUnidadeParaisoII.txt");
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
                    arquivoRelatorioIn.open("relatorioMensalUnidadeParaisoII.txt");
                    ofstream arquivoRelatorioBackupOut;
                    arquivoRelatorioBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/relatorioMensalUnidadeParaisoII.txt", ios::app);

                    if (arquivoRelatorioIn.is_open())
                    {
                        while (getline(arquivoRelatorioIn, exibirRelatorio))
                        {
                            arquivoRelatorioBackupOut << exibirRelatorio << endl;
                        }
                        arquivoRelatorioIn.close();
                        // Fun��o para abrir e salvar os dados no backup automatico
                        arquivoRelatorioBackupOut.close();
                        arquivoRelatorioBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/relatorioMensalUnidadeParaisoII.txt", ios::app);
                        arquivoRelatorioBackupOut << "Backup  acima, referente ao dia "
                                                  << data_hora_atual->tm_mday << "/"          // Dia do backup
                                                  << data_hora_atual->tm_mon + 1 << "/"       // M�s do backup
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
                         << "   Relat�rio emitido com sucesso!   " << endl
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
                     << "*   Digite os dados para gerar o relat�rio   *" << endl
                     << "**********************************************" << endl
                     << endl;

                relatorioMensal unidadeIII;
                fflush(stdin);
                cout << "Digite a receita do m�s: ";
                cin >> unidadeIII.receitas;

                cout << endl
                     << endl
                     << "Digite as despesas do m�s: ";
                cin >> unidadeIII.despesasOperacionais;

                cout << endl
                     << endl
                     << "Digite os juros recolhidos no m�s: ";
                cin >> unidadeIII.juros;

                cout << endl
                     << endl
                     << "Digite o valor dos impostos do m�s passado: ";
                cin >> unidadeIII.impostos;

                // Calculos para achar os valores do relat�rio
                unidadeIII.impostos = unidadeIII.impostos / 4;
                unidadeIII.lucroLiquido = unidadeIII.receitas - (unidadeIII.impostos - unidadeIII.despesasOperacionais);
                unidadeIII.lucrosOperacionais = unidadeIII.lucroLiquido - unidadeIII.despesasOperacionais;
                unidadeIII.depreciacao = unidadeIII.receitas - (unidadeIII.lucroLiquido - unidadeIII.impostos);
                unidadeIII.lucroPosImpostos = unidadeIII.lucroLiquido - unidadeIII.impostos;

                ofstream arquivoRelatorioOut;

                arquivoRelatorioOut.open("relatorioMensalUnidadeParaisoIII.txt", ios::trunc); // ios::trunc grava por cima do arquivo anterior

                arquivoRelatorioOut << " ----------------------------------------------------------------------------------------- " << endl
                                    << "|                                                                                         |" << endl
                                    << "|                            RELAT�RIO FINANCEIRO MENSAL                                 |" << endl
                                    << "|                                                                                         |" << endl
                                    << "|                            CLINICAS PARAISO UNIDADE III                                 |" << endl
                                    << "|                                                                                         |" << endl
                                    << " ----------------------------------------------------------------------------------------- " << endl
                                    << "___________________________________________________________________________________________" << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "  M�TRICAS - CHAVE                                                                         " << endl
                                    << "___________________________________________________________________________________________" << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "                                                   _____                                   " << endl
                                    << "  RECEITAS           R$ " << unidadeIII.receitas << ",00             _____/                  " << endl
                                    << "                                       _____/                                              " << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "                                                   _____                                   " << endl
                                    << "  LUCRO LIQUIDO      R$ " << unidadeIII.lucroLiquido << ",00             _____/              " << endl
                                    << "                                       _____/                                              " << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "                                                                                           " << endl
                                    << "  JUROS              R$ " << unidadeIII.juros << ",00         -----*-----*-----              " << endl
                                    << "                                                                                           " << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "                                                                                           " << endl
                                    << "  DEPRECIA��O        R$ " << unidadeIII.depreciacao << ",00         -----*-----*-----        " << endl
                                    << "                                                                                           " << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "                                                   _____                                   " << endl
                                    << "  LUCRO OPERACIONAL  R$ " << unidadeIII.lucrosOperacionais << ",00             _____/        " << endl
                                    << "                                       _____/                                              " << endl
                                    << "___________________________________________________________________________________________" << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "  RESUMO DE TODAS AS M�TRICAS M�S                                                     " << endl
                                    << "___________________________________________________________________________________________" << endl
                                    << "-------------------------------------------------------------------------------------------" << endl
                                    << "  RECEITAS                         R$ " << unidadeIII.receitas << ",00                 " << endl
                                    << "  DESPESAS OPERACIONAIS            R$ " << unidadeIII.despesasOperacionais << ",00     " << endl
                                    << "  LUCRO OPERACIONAL                R$ " << unidadeIII.lucrosOperacionais << ",00       " << endl
                                    << "  DEPRECIA��O                      R$ " << unidadeIII.depreciacao << ",00              " << endl
                                    << "  JUROS                            R$ " << unidadeIII.juros << ",00                    " << endl
                                    << "  LUCRO LIQUIDO                    R$ " << unidadeIII.lucroLiquido << ",00             " << endl
                                    << "  IMPOSTOS                         R$ " << unidadeIII.impostos << ",00                 " << endl
                                    << "  LUCROS AP�S DEDU��O DE IMPOSTOS  R$ " << unidadeIII.lucroPosImpostos << ",00         " << endl
                                    << "-------------------------------------------------------------------------------------------" << endl;

                arquivoRelatorioOut.close();

                system("clear");
                cout << endl
                     << endl
                     << endl
                     << "Gerando relat�rio...   ...   ...   ..." << endl
                     << endl
                     << endl;
                system("pause");
                system("clear");

                ifstream arquivoRelatorioIn;
                string exibirRelatorio;

                system("clear");
                cout << "                         ***********************************                               " << endl
                     << "                         *       Confirmar Relatorio       *                               " << endl
                     << "                         ***********************************                               " << endl
                     << endl
                     << endl;

                arquivoRelatorioIn.open("relatorioMensalUnidadeParaisoIII.txt");

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
                    cout << "N�o foi possivel abrir o arquivo" << endl;
                }

                cout << endl
                     << endl
                     << "Dados est�o certos SIM(S) ou NAO(N) ?  ";
                cin >> confirmacaoRelatorio;

                system("clear");
                // Cadastro não está Ok;
                if ((confirmacaoRelatorio == "N") || (confirmacaoRelatorio == "n"))
                {
                    remove("relatorioMensalUnidadeParaisoIII.txt");
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
                    arquivoRelatorioIn.open("relatorioMensalUnidadeParaisoIII.txt");
                    ofstream arquivoRelatorioBackupOut;
                    arquivoRelatorioBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/relatorioMensalUnidadeParaisoIII.txt", ios::app);

                    if (arquivoRelatorioIn.is_open())
                    {
                        while (getline(arquivoRelatorioIn, exibirRelatorio))
                        {
                            arquivoRelatorioBackupOut << exibirRelatorio << endl;
                        }
                        arquivoRelatorioIn.close();
                        // Fun��o para abrir e salvar os dados no backup automatico
                        arquivoRelatorioBackupOut.close();
                        arquivoRelatorioBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/relatorioMensalUnidadeParaisoIII.txt", ios::app);
                        arquivoRelatorioBackupOut << "Backup  acima, referente ao dia "
                                                  << data_hora_atual->tm_mday << "/"          // Dia do backup
                                                  << data_hora_atual->tm_mon + 1 << "/"       // M�s do backup
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
                         << "   Relat�rio emitido com sucesso!   " << endl
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
        // Op��o inexistente
        default:
        {
            cout << endl
                 << "O valor digitado n�o corresponde a nenhuma das op��es!" << endl
                 << endl;
            system("pause");
            continue;
        }
        }
        sair = 4;
        // Op��o 0 para sair do la�o
        if (sair == 4)
        {
            system("clear");
            cin.ignore();
            cout << endl
                 << endl
                 << "Saindo das op��es" << endl
                 << endl;
            cout << system("pause");
            break;
        }
    }
    return 0;
}
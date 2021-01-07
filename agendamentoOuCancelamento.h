#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <time.h>
using namespace std;

int agendamentoOuCancelamento()
{
    system("clear");
    int sair = 0;

    // Struct para consulta e Backup
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);

    while (sair != 3)
    {
        system("clear");
        cout << endl
             << endl
             << "****************************" << endl
             << "*  Escolha uma das opções  *" << endl
             << "****************************" << endl
             << " ------------------------- " << endl
             << "|  1 - Agendar Consulta   |" << endl
             << "|-------------------------|" << endl
             << "|  2 - Cancelar Consulta  |" << endl
             << "|-------------------------|" << endl
             << "|  3 - Sair               |" << endl
             << " ------------------------- " << endl
             << "   Digite a sua opção: ";
        cin >> sair;

        // Switch para opções
        switch (sair)
        {
        // Agendar
        case 1:
        {
            system("clear");
            string confirmacaoAgendamento;
            while ((confirmacaoAgendamento != "S") || (confirmacaoAgendamento != "s"))
            {
                int numeroDoutor;
                string nomeDoutor;
                string escolhaUnidade;
                string especialidade;
                string enderecoClinica;
                fflush(stdin);
                system("clear");
                cout << endl
                     << endl
                     << " ------------------------------------------------------------------------------------------------------------------- " << endl
                     << "|                                    ESSAS SÃO AS OPÇÕES DISPONIVEIS POR UNIDADE                                    |" << endl
                     << "|-------------------------------------------------------------------------------------------------------------------|" << endl
                     << "|              UNIDADE I              |              UNIDADE II               |             UNIDADE III             |" << endl
                     << "|-------------------------------------|---------------------------------------|-------------------------------------|" << endl
                     << "| 1 - Dr(a) Edgar D.    (Cardiologia) | 5 - Dr(a) Wallace W.  (Infectologia) | 9  - Dr(a) Miriã A.    (Geriatria)   |" << endl
                     << "| 2 - Dr(a) Jade P.     (Diagnostico) | 6 - Dr(a) Paulo J.    (Oftalmologia) | 10 - Dr(a) Roberto P.  (Ginecologia) |" << endl
                     << "| 3 - Dr(a) Raphael M.  (Ortopedia)   | 7 - Dr(a) Tatiana E.  (Radiologia)   | 11 - Dr(a) Luza S.     (Obstetricia) |" << endl
                     << "| 4 - Dr(a) Jessica S.  (Traumologia) | 8 - Dr(a) Auzio V.    (Urologia)     | 12 - Dr(a) Raquel S.   (Pediatra)    |" << endl
                     << " ------------------------------------------------------------------------------------------------------------------- " << endl
                     << endl
                     << "  Digite o numero do Dr(a): ";
                cin >> numeroDoutor;

                // A partir do nome do doutor determinar as variaveis escolhaUnidade e espescialidade
                switch (numeroDoutor)
                {
                case 1:
                {
                    nomeDoutor = "Edgar D.";
                    escolhaUnidade = "Unidade I";
                    enderecoClinica = "Rua Domingos de Moraes, n° 111";
                    especialidade = "Cardiologia";
                    break;
                }
                case 2:
                {
                    nomeDoutor = "Jade P.";
                    escolhaUnidade = "Unidade I";
                    enderecoClinica = "Rua Domingos de Moraes, n° 111";
                    especialidade = "Diagnostico";
                    break;
                }
                case 3:
                {
                    nomeDoutor = "Raphael M.";
                    escolhaUnidade = "Unidade I";
                    enderecoClinica = "Rua Domingos de Moraes, n° 111";
                    especialidade = "Ortopedia";
                    break;
                }
                case 4:
                {
                    nomeDoutor = "Jessica S.";
                    escolhaUnidade = "Unidade I";
                    enderecoClinica = "Rua Domingos de Moraes, n° 111";
                    especialidade = "Traumologia";
                    break;
                }
                case 5:
                {
                    nomeDoutor = "Wallace W.";
                    escolhaUnidade = "Unidade II";
                    enderecoClinica = "Rua Azevedo Macedo, n° 222";
                    especialidade = "Infectologia";
                    break;
                }
                case 6:
                {
                    nomeDoutor = "Paulo J.";
                    escolhaUnidade = "Unidade II";
                    enderecoClinica = "Rua Azevedo Macedo, n° 222";
                    especialidade = "Oftalmologia";
                    break;
                }
                case 7:
                {
                    nomeDoutor = "Tatiana E.";
                    escolhaUnidade = "Unidade II";
                    enderecoClinica = "Rua Azevedo Macedo, n° 222";
                    especialidade = "Radiologia";
                    break;
                }
                case 8:
                {
                    nomeDoutor = "Auzio V.";
                    escolhaUnidade = "Unidade II";
                    enderecoClinica = "Rua Artur Sabóia, n° 333";
                    especialidade = "Urologia";
                    break;
                }
                case 9:
                {
                    nomeDoutor = "Miriã A.";
                    escolhaUnidade = "Unidade III";
                    enderecoClinica = "Rua Artur Sabóia, n° 333";
                    especialidade = "Geriatria";
                    break;
                }
                case 10:
                {
                    nomeDoutor = "Roberto P.";
                    escolhaUnidade = "Unidade III";
                    enderecoClinica = "Rua Artur Sabóia, n° 333";
                    especialidade = "Ginecologia";
                    break;
                }
                case 11:
                {
                    nomeDoutor = "Luza S.";
                    escolhaUnidade = "Unidade III";
                    enderecoClinica = "Rua Artur Sabóia, n° 333";
                    especialidade = "Obstetricia";
                    break;
                }
                case 12:
                {
                    nomeDoutor = "Raquel S.";
                    escolhaUnidade = "Unidade III";
                    enderecoClinica = "Rua Artur Sabóia, n° 333";
                    especialidade = "Pediatria";
                    break;
                }
                default:
                {
                    cout << endl
                         << "O valor digitado não corresponde a nenhuma das opções!" << endl
                         << endl;
                    system("pause");
                    continue;
                }
                }
                string cadastro;
                struct structPacienteAgendar
                {
                    string nome;
                    string rg;
                    string cpf;
                };

                system("clear");
                cout << "**********************************" << endl
                     << "*  Informe os dados do paciente  *" << endl
                     << "**********************************" << endl
                     << endl
                     << endl;

                structPacienteAgendar pacAgendar;

                cin.ignore();
                cout << endl
                     << "  Digite o Nome: ";
                getline(cin, pacAgendar.nome);

                cout << endl
                     << "  Digite o RG (com pontos): ";
                getline(cin, pacAgendar.rg);

                cout << endl
                     << "  Digite o CPF (com pontos): ";
                getline(cin, pacAgendar.cpf);

                ofstream arquivoAgendamentoOut;

                arquivoAgendamentoOut.open("agendamentoPaciente.txt", ios::trunc); // ios::trunc grava por cima do arquivo anterior

                arquivoAgendamentoOut << "----------------------------------------------------------------------------------" << endl
                                      << "                                 CLINICAS PARAISO " << endl
                                      << "                                   " << escolhaUnidade << endl
                                      << "----------------------------------------------------------------------------------" << endl
                                      << "                               Agendamento de Consulta         " << endl
                                      << endl
                                      << " O(A) paciente: " << pacAgendar.nome << endl
                                      << endl
                                      << " Rg: " << pacAgendar.rg << " e CPF: " << pacAgendar.cpf << endl
                                      << endl
                                      << endl
                                      << " Atendimento será na Clinica Paraiso " << escolhaUnidade << " " << enderecoClinica << endl
                                      << endl
                                      << " Consulta marcada com o(a) Dr(a) " << nomeDoutor << " no consultorio de " << especialidade << endl
                                      << endl
                                      << " Dia da consulta:  "
                                      << data_hora_atual->tm_mday + 7 << "/"      // Dia do backup
                                      << data_hora_atual->tm_mon + 1 << "/"       // Mês do backup
                                      << data_hora_atual->tm_year + 1900 << " - " // Ano do backup
                                      << "14:00 hrs" << endl
                                      << "----------------------------------------------------------------------------------" << endl;

                arquivoAgendamentoOut.close();
                system("clear");
                cout << endl
                     << endl
                     << endl
                     << "Gerando Consulta...   ...   ...   ..." << endl
                     << endl
                     << endl;
                system("pause");
                system("clear");

                ifstream arquivoAgendamentoIn;
                string exibirAgendamento;

                system("clear");
                cout << "                         *************************************               " << endl
                     << "                         *       Confirmar Agendamento       *               " << endl
                     << "                         *************************************               " << endl
                     << endl
                     << endl;

                arquivoAgendamentoIn.open("agendamentoPaciente.txt");

                if (arquivoAgendamentoIn.is_open())
                {
                    while (getline(arquivoAgendamentoIn, exibirAgendamento))
                    {
                        cout << exibirAgendamento << endl;
                    }
                    arquivoAgendamentoIn.close();
                }
                else
                {
                    cout << "Não foi possivel abrir o arquivo" << endl;
                }

                cout << endl
                     << endl
                     << "Dados estão certos SIM(S) ou NÃO(N) ?  ";
                cin >> confirmacaoAgendamento;

                system("clear");

                if ((confirmacaoAgendamento == "N") || (confirmacaoAgendamento == "n"))
                {
                    remove("agendamentoPaciente.txt");
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
                    arquivoAgendamentoIn.open("agendamentoPaciente.txt");
                    ofstream arquivoAgendamentoBackupOut;
                    arquivoAgendamentoBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/agendamentoPaciente.txt", ios::app);

                    if (arquivoAgendamentoIn.is_open())
                    {
                        while (getline(arquivoAgendamentoIn, exibirAgendamento))
                        {
                            arquivoAgendamentoBackupOut << exibirAgendamento << endl;
                        }
                        arquivoAgendamentoIn.close();
                        // Função para abrir e salvar os dados no backup automatico
                        arquivoAgendamentoBackupOut.close();
                        arquivoAgendamentoBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/agendamentoPaciente.txt", ios::app);
                        arquivoAgendamentoBackupOut << "Backup  acima, referente ao dia "
                                                    << data_hora_atual->tm_mday << "/"          // Dia do backup
                                                    << data_hora_atual->tm_mon + 1 << "/"       // Mês do backup
                                                    << data_hora_atual->tm_year + 1900 << " - " // Ano do backup
                                                    << data_hora_atual->tm_hour << ":"          // Hora do backup
                                                    << data_hora_atual->tm_min << ":"           // Minuto do backup
                                                    << data_hora_atual->tm_sec << endl          // Segundos do backup
                                                    << "-------------------------------------------------------------------------------------------" << endl
                                                    << endl;
                        arquivoAgendamentoBackupOut.close();
                    }
                    cout << endl
                         << endl
                         << "   Relatório emitido com sucesso!   " << endl
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
            string confirmacaoCancelamento;
            ifstream arquivoCancelamentoIn;
            string exibirCancelamento;

            system("clear");
            cout << "                        **************************************               " << endl
                 << "                        *       Confirmar Cancelamento       *               " << endl
                 << "                        **************************************               " << endl
                 << endl
                 << endl;

            arquivoCancelamentoIn.open("agendamentoPaciente.txt");

            if (arquivoCancelamentoIn.is_open())
            {
                while (getline(arquivoCancelamentoIn, exibirCancelamento))
                {
                    cout << exibirCancelamento << endl;
                }
                arquivoCancelamentoIn.close();
            }
            else
            {
                cout << "Não foi possivel abrir o arquivo" << endl;
            }

            cout << endl
                 << endl
                 << "Dados estão certos SIM(S) ou NAO(N) ?  ";
            cin >> confirmacaoCancelamento;

            system("clear");
            // Cadastro nÃ£o estÃ¡ Ok;
            if ((confirmacaoCancelamento == "S") || (confirmacaoCancelamento == "s"))
            {
                remove("agendamentoPaciente.txt");
                cout << endl
                     << endl
                     << "Por favor" << endl
                     << endl
                     << "Digite novamente os dados" << endl
                     << endl;
                system("clear");
            }

            continue;
        }
        //**********************************************************************************************************************//
        case 3:
        {
            break;
        }
        //**********************************************************************************************************************//
        // Opção inexistente
        default:
        {
            cout << endl
                 << "O valor digitado não corresponde a nenhuma das opções!" << endl
                 << endl;
            system("pause");
            continue;
        }
        }
        sair = 3;
        // Opção 0 para sair do laço
        if (sair == 3)
        {
            system("clear");
            cin.ignore();
            cout << endl
                 << endl
                 << "Saindo das opções" << endl
                 << endl;
            cout << system("pause");
            break;
        }
    }
    return 0;
}
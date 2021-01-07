#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <time.h>
using namespace std;

// Chamada dos cabeçalhos header´s
#include "loginAtendente.h"
#include "loginAdministrador.h"
#include "loginRecursosHumanos.h"
#include "areaDoPaciente.h"
#include "cadastroPaciente.h"
#include "cadastroMedico.h"
#include "cadastroColaborador.h"
#include "emissaoBoleto.h"
#include "relatorioFaturamentoSemanal.h"
#include "relatorioFaturamentoMensal.h"
#include "backupSistema.h"
#include "agendamentoOuCancelamento.h"
#include "elogiosOuReclamacoes.h"
#include "relatorioDeAtendimento.h"

// Inicio do Programa
int main()
{
    system("clear");
    setlocale(LC_ALL, "Portuguese");
    int loginSoftware = 0;
    while (loginSoftware != 6)
    {
        system("clear"); // limpa o terminal;
        cout << " ****************************************** " << endl
             << "|                                          |" << endl
             << "|   ************************************   |" << endl
             << "|   |                                  |   |" << endl
             << "|   |            CLICK HEART           |   |" << endl
             << "|   |         CLINICAS PARAISO         |   |" << endl
             << "|   |                                  |   |" << endl
             << "|   ************************************   |" << endl
             << "|                                          |" << endl
             << " ****************************************** " << endl
             << endl
             << "          ****  Bem vindo  ****" << endl
             << endl
             << "          Escolha uma das opções" << endl
             << "     -------------------------------- " << endl
             << "    |  1 - Area do Administrador     |" << endl
             << "    |--------------------------------|" << endl
             << "    |  2 - Area do Atendente         |" << endl
             << "    |--------------------------------|" << endl
             << "    |  3 - Area do Recursos Humanos  |" << endl
             << "    |--------------------------------|" << endl
             << "    |  4 - Area do Paciente          |" << endl
             << "    |--------------------------------|" << endl
             << "    |  5 - Ajuda                     |" << endl
             << "    |--------------------------------|" << endl
             << "    |  6 - Sair                      |" << endl
             << "     -------------------------------- " << endl
             << "       Digite a sua opção: ";
        cin >> loginSoftware;

        // Area do Administrador
        if (loginSoftware == 1)
        {
            system("clear");
            // Arquivo loginAdministrador.h
            loginAdministrador();
            //*********************************************************************************************************//
            // Opções de operação do Administrador
            string opcoesSoftware;

            while (opcoesSoftware != "5")
            {
                system("clear");
                int opcao;
                cout << "************************************************" << endl
                     << "*            Área do Administrador             *" << endl
                     << "*           -----------------------            *" << endl
                     << "*  Escolha qual das operações deseja realizar  *" << endl
                     << "************************************************" << endl
                     << endl
                     << "    ---------------------------------------- " << endl
                     << "   |  1 - Relatório de Atendimento          |" << endl
                     << "   |----------------------------------------|" << endl
                     << "   |  2 - Relatorio de Faturamento Semanal  |" << endl
                     << "   |----------------------------------------|" << endl
                     << "   |  3 - Relatorio de Faturamento Mensal   |" << endl
                     << "   |----------------------------------------|" << endl
                     << "   |  4 - Backup do Sistema                 |" << endl
                     << "   |----------------------------------------|" << endl
                     << "   |  5 - Sair                              |" << endl
                     << "    ---------------------------------------- " << endl
                     << endl
                     << "   Digite o número correspondente a operação: ";
                cin >> opcao;

                //**************************************//
                // Switch para as opções do colaborador
                switch (opcao)
                {
                // Relatorio de Atendimento
                case 1:
                {
                    // Arquivo relatorioDeAtendimento.h
                    relatorioDeAtendimento();
                    continue;
                }
                //*********************************//
                // Relatorio de faturamento diário
                case 2:
                {
                    // Arquivo relatorioFaturamentoSemanal.h
                    relatorioSemanal();
                    continue;
                }
                //*********************************//
                // Relatorio de faturamento mensal
                case 3:
                {
                    // Arquivo relatorioFaturamentoMensal.h
                    relatorioMensal();
                    continue;
                }
                //*********************************//
                // Backup do Sistema
                case 4:
                {
                    // Arquivo backupSistema.h
                    backupSistema();
                    continue;
                }
                // Saindo do Sistema
                case 5:
                {
                    break;
                }
                //*************************************************************************************************//
                // Opção inexistente
                default:
                {
                    cout << "O valor digitado não corresponde a nenhuma das opções!" << endl
                         << endl;
                }
                } // Fim do Switch

                // Opção 0 para sair do laço
                if (opcao == 5)
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
        }
        // Area do Atendente
        if (loginSoftware == 2)
        {
            system("clear");

            // Arquivo loginAtendente.h
            loginAtendente();

            //*********************************************************************************************************//
            // Opções de operação do Atendente
            string opcoesSoftware;

            while (opcoesSoftware != "5")
            {
                system("clear");
                int opcao;
                cout << "************************************************" << endl
                     << "*              Área do Atendente               *" << endl
                     << "*             -------------------              *" << endl
                     << "*  Escolha qual das operações deseja realizar  *" << endl
                     << "************************************************" << endl
                     << endl
                     << " ---------------------------------------------- " << endl
                     << "|  1 - Cadastro de Paciente                    |" << endl
                     << "|----------------------------------------------|" << endl
                     << "|  2 - Agendamento e Cancelamento de Consulta  |" << endl
                     << "|----------------------------------------------|" << endl
                     << "|  3 - Emissão de Boleto                       |" << endl
                     << "|----------------------------------------------|" << endl
                     << "|  4 - Backup do Sistema                       |" << endl
                     << "|----------------------------------------------|" << endl
                     << "|  5 - Sair                                    |" << endl
                     << " ---------------------------------------------- " << endl
                     << endl
                     << "   Digite o número correspondente a operação: ";
                cin >> opcao;

                //**************************************//
                // Switch para as opções do colaborador
                switch (opcao)
                {
                // Cadastro de Paciente
                case 1:
                {
                    // Arquivo cadastroPaciente.h
                    cadastroPaciente();
                    continue;
                }
                // Agendamento ou cancelamento
                case 2:
                {
                    // Arquivo cadastroPaciente.h
                    agendamentoOuCancelamento();
                    continue;
                }
                //*********************************//
                // Emissão de Boleto
                case 3:
                {
                    // Arquivo emissaoBoleto.h
                    emissaoBoleto();
                    continue;
                }
                //*********************************//
                // Backup do Sistema
                case 4:
                {
                    // Arquivo backupSistema.h
                    backupSistema();
                    continue;
                }
                //*********************************//
                // Sair do Sistema
                case 5:
                {
                    break;
                }
                //*************************************************************************************************//
                // Opção inexistente
                default:
                {
                    cout << "O valor digitado não corresponde a nenhuma das opções!" << endl
                         << endl;
                    continue;
                }
                } // Fim do Switch

                // Opção 0 para sair do laço
                if (opcao == 5)
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
        }
        // Area do Recursos Humanos
        if (loginSoftware == 3)
        {
            system("clear");

            // Arquivo loginRecursosHumanos.h
            loginRecursosHumanos();

            //*********************************************************************************************************//
            // Opções de operação para o Recursos Humanos
            string opcoesSoftware;

            while (opcoesSoftware != "5")
            {
                system("clear");
                int opcao;
                cout << "************************************************" << endl
                     << "*           Área do Recursos Humanos           *" << endl
                     << "*          --------------------------          *" << endl
                     << "*  Escolha qual das operações deseja realizar  *" << endl
                     << "************************************************" << endl
                     << endl
                     << "     ---------------------------------------- " << endl
                     << "    |  1 - Cadastro de Colaborador           |" << endl
                     << "    |----------------------------------------|" << endl
                     << "    |  2 - Cadastro de Médico                |" << endl
                     << "    |----------------------------------------|" << endl
                     << "    |  3 - Consultar Elogios ou Reclamações  |" << endl
                     << "    |----------------------------------------|" << endl
                     << "    |  4 - Backup do Sistema                 |" << endl
                     << "    |----------------------------------------|" << endl
                     << "    |  5 - Sair                              |" << endl
                     << "     ---------------------------------------- " << endl
                     << endl
                     << "     Digite o número correspondente a operação: ";
                cin >> opcao;

                //**************************************//
                // Switch para as opções do colaborador
                switch (opcao)
                {
                // Cadastro de Colaborador
                case 1:
                {
                    // Arquivo cadastroColaborador.h
                    cadastroColaborador();
                    continue;
                }
                //*********************************//
                // Cadastro de Médico
                case 2:
                {
                    //Arquivo cadastroMedico.h
                    cadastroMedico();
                    continue;
                }
                //*********************************//
                // Consultar Elogios ou Reclamações
                case 3:
                {
                    // Arquivo elogiosOuReclamacoes.h
                    elogiosOuReclamacoes();
                    continue;
                }
                //*********************************//
                // Backup do Sistema
                case 4:
                {
                    // Arquivo backupSistema.h
                    backupSistema();
                    continue;
                }
                //*********************************//
                // Sair do Sistema
                case 5:
                {
                    break;
                }
                //*************************************************************************************************//
                // Opção inexistente
                default:
                {
                    cout << endl
                         << "O valor digitado não corresponde a nenhuma das opções!" << endl
                         << endl
                         << system("pause") << endl;
                }
                } // Fim do Switch
                // Opção 0 para sair do laço
                if (opcao == 5)
                {
                    system("clear");
                    cin.ignore();
                    cout << endl
                         << endl
                         << "Saindo das opções" << endl
                         << endl
                         << system("pause");
                    break;
                }
            }
        }
        // Area do Paciente
        if (loginSoftware == 4)
        {
            // Arquivo areaDoPaciente.h
            areaDoPaciente();
        }
        // Ajuda
        if (loginSoftware == 5)
        {
            system("clear");
            cout << endl
                 << endl
                 << "***************************************************" << endl
                 << "*                                                 *" << endl
                 << "*  Para qualquer duvida vejo o manual de usuario  *" << endl
                 << "*      ou entre em contato com nossa equipe       *" << endl
                 << "*     através do e-mail: equipepim@gmail.com      *" << endl
                 << "*                                                 *" << endl
                 << "***************************************************" << endl
                 << endl
                 << endl
                 << system("pause");
        }
        // Sair da aplicação
        if (loginSoftware == 6)
        {
            system("clear");
            cout << endl
                 << endl
                 << "Saindo da aplicação" << endl
                 << endl
                 << system("pause");
        }
    }
    //**********************************************************************************************************************//
    // Créditos
    system("clear");
    cin.ignore();
    cout << endl
         << "*******************************************" << endl
         << "*                                         *" << endl
         << "*  OBRIGADO POR USAR OS NOSSOS SERVIÇOS!  *" << endl
         << "*                                         *" << endl
         << "*        ***** EQUIPE PIM *****           *" << endl
         << "*                                         *" << endl
         << "*         Wallace W. Oliveira             *" << endl
         << "*         Raphael M. da Silva             *" << endl
         << "*           Jade P. de Lima               *" << endl
         << "*          Miriã A. da Silva              *" << endl
         << "*        Tatiana E. de Freitas            *" << endl
         << "*                                         *" << endl
         << "*      TODOS OS DIREITOS RESERVADOS       *" << endl
         << "*                                         *" << endl
         << "*******************************************" << endl
         << endl
         << endl
         << system("pause");
    system("clear");

    return 0;
}
// Final do programa
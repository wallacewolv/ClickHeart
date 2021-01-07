#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <time.h>
using namespace std;

// Chamada dos cabe�alhos header�s
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
             << "          Escolha uma das op��es" << endl
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
             << "       Digite a sua op��o: ";
        cin >> loginSoftware;

        // Area do Administrador
        if (loginSoftware == 1)
        {
            system("clear");
            // Arquivo loginAdministrador.h
            loginAdministrador();
            //*********************************************************************************************************//
            // Op��es de opera��o do Administrador
            string opcoesSoftware;

            while (opcoesSoftware != "5")
            {
                system("clear");
                int opcao;
                cout << "************************************************" << endl
                     << "*            �rea do Administrador             *" << endl
                     << "*           -----------------------            *" << endl
                     << "*  Escolha qual das opera��es deseja realizar  *" << endl
                     << "************************************************" << endl
                     << endl
                     << "    ---------------------------------------- " << endl
                     << "   |  1 - Relat�rio de Atendimento          |" << endl
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
                     << "   Digite o n�mero correspondente a opera��o: ";
                cin >> opcao;

                //**************************************//
                // Switch para as op��es do colaborador
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
                // Relatorio de faturamento di�rio
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
                // Op��o inexistente
                default:
                {
                    cout << "O valor digitado n�o corresponde a nenhuma das op��es!" << endl
                         << endl;
                }
                } // Fim do Switch

                // Op��o 0 para sair do la�o
                if (opcao == 5)
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
        }
        // Area do Atendente
        if (loginSoftware == 2)
        {
            system("clear");

            // Arquivo loginAtendente.h
            loginAtendente();

            //*********************************************************************************************************//
            // Op��es de opera��o do Atendente
            string opcoesSoftware;

            while (opcoesSoftware != "5")
            {
                system("clear");
                int opcao;
                cout << "************************************************" << endl
                     << "*              �rea do Atendente               *" << endl
                     << "*             -------------------              *" << endl
                     << "*  Escolha qual das opera��es deseja realizar  *" << endl
                     << "************************************************" << endl
                     << endl
                     << " ---------------------------------------------- " << endl
                     << "|  1 - Cadastro de Paciente                    |" << endl
                     << "|----------------------------------------------|" << endl
                     << "|  2 - Agendamento e Cancelamento de Consulta  |" << endl
                     << "|----------------------------------------------|" << endl
                     << "|  3 - Emiss�o de Boleto                       |" << endl
                     << "|----------------------------------------------|" << endl
                     << "|  4 - Backup do Sistema                       |" << endl
                     << "|----------------------------------------------|" << endl
                     << "|  5 - Sair                                    |" << endl
                     << " ---------------------------------------------- " << endl
                     << endl
                     << "   Digite o n�mero correspondente a opera��o: ";
                cin >> opcao;

                //**************************************//
                // Switch para as op��es do colaborador
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
                // Emiss�o de Boleto
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
                // Op��o inexistente
                default:
                {
                    cout << "O valor digitado n�o corresponde a nenhuma das op��es!" << endl
                         << endl;
                    continue;
                }
                } // Fim do Switch

                // Op��o 0 para sair do la�o
                if (opcao == 5)
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
        }
        // Area do Recursos Humanos
        if (loginSoftware == 3)
        {
            system("clear");

            // Arquivo loginRecursosHumanos.h
            loginRecursosHumanos();

            //*********************************************************************************************************//
            // Op��es de opera��o para o Recursos Humanos
            string opcoesSoftware;

            while (opcoesSoftware != "5")
            {
                system("clear");
                int opcao;
                cout << "************************************************" << endl
                     << "*           �rea do Recursos Humanos           *" << endl
                     << "*          --------------------------          *" << endl
                     << "*  Escolha qual das opera��es deseja realizar  *" << endl
                     << "************************************************" << endl
                     << endl
                     << "     ---------------------------------------- " << endl
                     << "    |  1 - Cadastro de Colaborador           |" << endl
                     << "    |----------------------------------------|" << endl
                     << "    |  2 - Cadastro de M�dico                |" << endl
                     << "    |----------------------------------------|" << endl
                     << "    |  3 - Consultar Elogios ou Reclama��es  |" << endl
                     << "    |----------------------------------------|" << endl
                     << "    |  4 - Backup do Sistema                 |" << endl
                     << "    |----------------------------------------|" << endl
                     << "    |  5 - Sair                              |" << endl
                     << "     ---------------------------------------- " << endl
                     << endl
                     << "     Digite o n�mero correspondente a opera��o: ";
                cin >> opcao;

                //**************************************//
                // Switch para as op��es do colaborador
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
                // Cadastro de M�dico
                case 2:
                {
                    //Arquivo cadastroMedico.h
                    cadastroMedico();
                    continue;
                }
                //*********************************//
                // Consultar Elogios ou Reclama��es
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
                // Op��o inexistente
                default:
                {
                    cout << endl
                         << "O valor digitado n�o corresponde a nenhuma das op��es!" << endl
                         << endl
                         << system("pause") << endl;
                }
                } // Fim do Switch
                // Op��o 0 para sair do la�o
                if (opcao == 5)
                {
                    system("clear");
                    cin.ignore();
                    cout << endl
                         << endl
                         << "Saindo das op��es" << endl
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
                 << "*     atrav�s do e-mail: equipepim@gmail.com      *" << endl
                 << "*                                                 *" << endl
                 << "***************************************************" << endl
                 << endl
                 << endl
                 << system("pause");
        }
        // Sair da aplica��o
        if (loginSoftware == 6)
        {
            system("clear");
            cout << endl
                 << endl
                 << "Saindo da aplica��o" << endl
                 << endl
                 << system("pause");
        }
    }
    //**********************************************************************************************************************//
    // Cr�ditos
    system("clear");
    cin.ignore();
    cout << endl
         << "*******************************************" << endl
         << "*                                         *" << endl
         << "*  OBRIGADO POR USAR OS NOSSOS SERVI�OS!  *" << endl
         << "*                                         *" << endl
         << "*        ***** EQUIPE PIM *****           *" << endl
         << "*                                         *" << endl
         << "*         Wallace W. Oliveira             *" << endl
         << "*         Raphael M. da Silva             *" << endl
         << "*           Jade P. de Lima               *" << endl
         << "*          Miri� A. da Silva              *" << endl
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
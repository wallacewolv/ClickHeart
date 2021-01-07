#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <time.h>
using namespace std;

int areaDoPaciente()
{
    system("clear");
    // Struct para consulta e Backup
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);
    cin.ignore();
    string areaPaciente;
    while ((areaPaciente != "S") || (areaPaciente != "s"))
    {
        cout << "**********************************************" << endl
             << "*        Deixe sua opni�o ou sugest�o,       *" << endl
             << "*  para que possamos sempre trazer o melhor  *" << endl
             << "*     a voc� e todos os nossos clientes!     *" << endl
             << "**********************************************" << endl
             << endl
             << endl;

        // Struct para captura de dados do cadastro;
        struct infoReclamacao
        {
            string nome;
            string sugestaoOuReclamacao;
        };

        struct infoReclamacao infoRecla;

        cout << "Digite o nome: ";
        // cin.ignore();
        getline(cin, infoRecla.nome);

        cout << endl
             << "Digite sua sugest�o ou reclama��o" << endl
             << "(Essas informa��es sao an�nimas) " << endl
             << endl;
        getline(cin, infoRecla.sugestaoOuReclamacao);

        //Gerando arquivo do sugestaoOureclamacao exten��o .TXT
        ofstream sugestaoOuReclamacaoOut;

        sugestaoOuReclamacaoOut.open("sugestaoOuReclamacao.txt", ios::app); // ios::trunc grava por cima do arquivo anterior

        sugestaoOuReclamacaoOut << endl
                                << infoRecla.nome << endl
                                << endl
                                << infoRecla.sugestaoOuReclamacao << endl
                                << endl
                                << "Dia do registro :  "
                                << data_hora_atual->tm_mday << "/"          // Dia do backup
                                << data_hora_atual->tm_mon + 1 << "/"       // M�s do backup
                                << data_hora_atual->tm_year + 1900 << " - " // Ano do backup
                                << data_hora_atual->tm_hour << ":"          // Hora do backup
                                << data_hora_atual->tm_min << ":"           // Minuto do backup
                                << data_hora_atual->tm_sec << endl
                                << "----------------------------------------------------------" << endl;

        sugestaoOuReclamacaoOut.close();
        system("clear");

        ifstream sugestaoOuReclamacaoIn;
        string exibirSugestaoOuReclamacao;

        system("clear");
        cout << endl
             << endl
             << "*********************************" << endl
             << "*     Confirmar informa��es     *" << endl
             << "*********************************" << endl
             << endl;

        sugestaoOuReclamacaoIn.open("sugestaoOuReclamacao.txt");

        if (sugestaoOuReclamacaoIn.is_open())
        {
            while (getline(sugestaoOuReclamacaoIn, exibirSugestaoOuReclamacao))
            {
                cout << exibirSugestaoOuReclamacao << endl;
            }
            sugestaoOuReclamacaoIn.close();
        }
        else
        {
            cout << "N�o foi possivel abrir o arquivo" << endl;
        }
        cout << "Informa��es est�o certas, SIM(S) ou N�O(N) ?  ";
        cin >> areaPaciente;

        system("clear");
        // Cadastro não está Ok;
        if ((areaPaciente == "N") || (areaPaciente == "n"))
        {
            remove("sugestaoOuReclamacao.txt");
            cout << endl
                 << endl
                 << "Por favor" << endl
                 << endl
                 << "Refa�a o preenchimento das informa��es" << endl
                 << endl
                 << system("pause");
            cin.ignore();
            cout << endl;
            system("clear");
            continue;
        }
        else // Se estiver tdu ok ele fara o backup da mensagem
        {
            sugestaoOuReclamacaoIn.open("sugestaoOuReclamacao.txt");
            ofstream sugestaoOuReclamacaoBackupOut;
            sugestaoOuReclamacaoBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/sugestaoOuReclamacao.txt", ios::app);

            if (sugestaoOuReclamacaoIn.is_open())
            {
                while (getline(sugestaoOuReclamacaoIn, exibirSugestaoOuReclamacao))
                {
                    sugestaoOuReclamacaoBackupOut << exibirSugestaoOuReclamacao << endl;
                }
                sugestaoOuReclamacaoIn.close();
                // Fun��o para abrir e salvar os dados no backup automatico
                sugestaoOuReclamacaoBackupOut.close();
                sugestaoOuReclamacaoBackupOut.open("C:/Users/Wallace/Desktop/ClickHeart/backups/sugestaoOuReclamacao.txt", ios::app);
                sugestaoOuReclamacaoBackupOut << "Backup  acima, referente ao dia "
                                              << data_hora_atual->tm_mday << "/"          // Dia do backup
                                              << data_hora_atual->tm_mon + 1 << "/"       // M�s do backup
                                              << data_hora_atual->tm_year + 1900 << " - " // Ano do backup
                                              << data_hora_atual->tm_hour << ":"          // Hora do backup
                                              << data_hora_atual->tm_min << ":"           // Minuto do backup
                                              << data_hora_atual->tm_sec << endl          // Segundos do backup
                                              << "-------------------------------------------------------------------------------------------" << endl
                                              << endl;
                sugestaoOuReclamacaoBackupOut.close();
            }
            break;
        }
    }
    // Cadastro Ok;
    cout << endl
         << "***********************************************" << endl
         << "*            Informa��es enviadas!            *" << endl
         << "*                                             *" << endl
         << "*    Agradecemos a dedica�ao do seu tempo,    *" << endl
         << "*  sempre estamos abertos a novas sugest�es.  *" << endl
         << "*                                             *" << endl
         << "*       ****   Clinicas Paraiso   ****        *" << endl
         << "*         Sua sa�de em primeiro lugar         *" << endl
         << "*                                             *" << endl
         << "***********************************************" << endl
         << endl
         << system("pause");
    cin.ignore();
    system("clear");
    return 0;
}
/**
 * @file main.cpp
 *
 * @brief Função principal que executa o programa Concordo.
 */

#include "Sistema.h"

#include <iostream>
#include <sstream>

/**
 * @brief Função principal que inicia o programa Concordo.
 *
 * @param argc O número de argumentos de linha de comando.
 * @param argv Um array de strings contendo os argumentos de linha de comando.
 *
 * @return O código de saída do programa.
 */
int main(int argc, char *argv[])
{
    Sistema sistema;
    int continuar = 1;

    cout << "ABRINDO CONCORDO..." << endl;

    do
    {
        string linha;
        getline(cin, linha);

        /* Manipulação da linha */
        istringstream iss(linha);
        string comando, param1, param2, param3;
        getline(iss, comando, ' ');
        getline(iss, param1, ' ');
        getline(iss, param2, '\n');
        if (param2[0] == '"')
        {
            param2.erase(0, 1);
            param2.pop_back();
        }
        else
        {
            istringstream iss2(param2);
            getline(iss2, param2, ' ');
            getline(iss2, param3, '\n');
        }


        /* Menu de comandos*/

        if (comando == "quit")
        {
            cout << "Saindo do Concordo" << endl;
            sistema.disconnect();
            return 0;
        }
        else if (comando == "create-user")
        {
            sistema.adicionarUsuario(param1, param2, param3);
        }
        else if (comando == "login")
        {
            sistema.login(param1, param2);
        }
        else if (comando == "disconnect")
        {
            sistema.disconnect();
        }
        else if (comando == "create-server")
        {
            sistema.criarServidor(param1);
        }
        else if (comando == "set-server-desc")
        {
            sistema.modificarDescricaoDeServidor(param1, param2);
        }
        else if (comando == "set-server-invite-code")
        {
            sistema.modificarCodigoServidor(param1, param2);
        }
        else if (comando == "list-servers")
        {
            sistema.listarServidores();
        }
        else if (comando == "remove-server")
        {
            sistema.removerServidor(param1);
        }
        else if (comando == "enter-server")
        {
            sistema.entrarEmServidor(param1, param2);
        }
        else if (comando == "leave-server")
        {
            sistema.sairDoServidor();
        }
        else if (comando == "list-participants")
        {
            sistema.listarParticipantesDoServidor();
        }
        else
        {
            cout << "Comando invalido" << endl;
        }
    } while (continuar);
}
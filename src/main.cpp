#include "Sistema.h"

#include <iostream>
#include <sstream>

int main(int argc, char *argv[])
{
    Sistema sistema;
    int continuar = 1;

    cout << "ABRINDO CONCORDO..." << endl;

    do
    {
        string linha;

        getline(cin, linha);
        istringstream iss(linha);
        string comando, param1, param2, param3;

        if (getline(iss, comando, ' '))
        {
            if (getline(iss, param1, ' '))
            {
                if (getline(iss, param2, ' '))
                {
                    getline(iss, param3, '\n');
                }
            }
        }

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
        } else {
            cout << "Comando invalido" << endl;
        }
    } while (continuar);
}
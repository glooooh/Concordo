/**
 * @file main.cpp
 *
 * @brief Função principal que executa o programa Concordo.
 */

#include "Sistema.h"

#include <iostream>
#include <sstream>

/**
 * @brief Processa uma linha de entrada e separa os tokens em comando e parâmetros.
 * 
 * @details Esta função recebe uma linha de entrada e realiza a separação dos tokens por espaços.
 * Caso um token esteja entre aspas, ele é tratado como um único parâmetro, mesmo se contiver espaços.
 * Os tokens separados são armazenados nas variáveis de referência comando, param1, param2 e param3.
 * 
 * @param linha A linha de entrada a ser processada.
 * @param comando Variável de referência para armazenar o comando.
 * @param param1 Variável de referência para armazenar o primeiro parâmetro.
 * @param param2 Variável de referência para armazenar o segundo parâmetro.
 * @param param3 Variável de referência para armazenar o terceiro parâmetro.
*/
void processarLinha(const string &linha, string &comando, string &param1, string &param2, string &param3)
{
    istringstream iss(linha);
    vector<string> tokens;
    string token;

    /* Separa a linha por espaços. */
    while (iss >> token)
    {
        if (token.front() == '"' && token.back() != '"')
        {
            string param;
            while (iss >> token && token.back() != '"')
            {
                param += token + " ";
            }
            param += token;
            param.pop_back();
            tokens.push_back(param);
        }
        else
        {
            tokens.push_back(token);
        }
    }

    /* Manipulação das variáveis usadas no código: */
    if (tokens.size() >= 1)
        comando = tokens[0];
    if (tokens.size() >= 2)
        param1 = tokens[1];
    if (tokens.size() >= 3)
        param2 = tokens[2];
    if (tokens.size() >= 4)
    {
        param3 = tokens[3];
        for (size_t i = 4; i < tokens.size(); i++)
            param3 += ' ' + tokens[i];
    }
}

/**
 * @brief Essa função executa um comando no sistema Concordo. Ela recebe o comando
 * e seus parâmetros, e realiza a operação correspondente no sistema.
 *
 * @param sistema Referência para o objeto Sistema.
 * @param comando O comando a ser executado.
 * @param param1 O primeiro parâmetro do comando.
 * @param param2 O segundo parâmetro do comando.
 * @param param3 O terceiro parâmetro do comando.
 *
 * @return Retorna 0 se o comando "quit" foi executado, caso contrário retorna 1.
 */

int executarComando(Sistema &sistema, const string &comando, const string &param1, const string &param2, const string &param3)
{
    /* Menu de comandos*/
    if (comando == "quit")
    {
        cout << "Saindo do Concordo" << endl;
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

    return 1;
}

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
        /* Armazena entrada do usuário. */
        string linha;
        string comando, param1, param2, param3;
        getline(cin, linha);

        /* Manipulação da linha */
        processarLinha(linha, comando, param1, param2, param3);

        /* Chama função que executa o comando do usuário. */
        continuar = executarComando(sistema, comando, param1, param2, param3);

    } while (continuar);
}
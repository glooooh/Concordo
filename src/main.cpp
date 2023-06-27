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
        tokens.push_back(token);
    }

    /* Manipulação das variáveis usadas no código: */
    if (tokens.size() >= 1)
        comando = tokens[0];
    if (tokens.size() >= 2)
        param1 = tokens[1];
    if (tokens.size() >= 3)
    {
        param2 = tokens[2];
        for (size_t i = 3; i < tokens.size() && param2.front() == '"'; i++)
        {
            param2 += ' ' + tokens[i];
            tokens[i] = "";
        }
    }
    if (tokens.size() >= 4)
    {
        param3 = tokens[3];
        for (size_t i = 4; i < tokens.size() && param2.front() != '"'; i++)
            param3 += ' ' + tokens[i];
    }

    /* Retirar as aspas (se houver) do param2. */
    if (param2.front() == '"') {
        param2.erase(0, 1);
        param2.pop_back();
    }
}

bool verificarArgumentos(const string &param1, const string &param2, const string &param3, int argc)
{
    switch (argc)
    {
    /* Caso a função precise de 0 parâmetros. */
    case 0:
        if (param1 != "" || param2 != "" || param3 != "")
            return false;
        return true;
        break;
    /* Caso a função precise de 1 parâmetro. */
    case 1:
        if ((param2 != "" || param3 != "") || param1 == "")
            return false;
        return true;
        break;
    /* Caso a função precise de 2 parâmetros. */
    case 2:
        if (param3 != "" || (param1 == "" || param2 == ""))
            return false;
        return true;
        break;
    /* Caso a função precise de 3 parâmetros. */
    case 3:
        if (param1 == "" || param2 == "" || param3 == "")
            return false;
        return true;
        break;
    default:
        return false;
        break;
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
        if (verificarArgumentos(param1, param2, param3, 0))
        {
            cout << "Saindo do Concordo" << endl;
            return 0;
        }
        else
            cout << "Este comando precisa de 0 argumento(s) para funcionar." << endl;
    }
    else if (comando == "create-user")
    {
        if (verificarArgumentos(param1, param2, param3, 3))
            sistema.adicionarUsuario(param1, param2, param3);
        else
            cout << "Este comando precisa de 3 argumento(s) para funcionar." << endl;
    }
    else if (comando == "login")
    {
        if (verificarArgumentos(param1, param2, param3, 2))
            sistema.login(param1, param2);
        else
            cout << "Este comando precisa de 2 argumento(s) para funcionar." << endl;
    }
    else if (comando == "disconnect")
    {
        if (verificarArgumentos(param1, param2, param3, 0))
            sistema.disconnect();
        else
            cout << "Este comando precisa de 0 argumento(s) para funcionar." << endl;
    }
    else if (comando == "create-server")
    {
        if (verificarArgumentos(param1, param2, param3, 1))
            sistema.criarServidor(param1);
        else
            cout << "Este comando precisa de 1 argumento(s) para funcionar." << endl;
    }
    else if (comando == "set-server-desc")
    {
        if (verificarArgumentos(param1, param2, param3, 2))
            sistema.modificarDescricaoDeServidor(param1, param2);
        else
            cout << "Este comando precisa de 2 argumento(s) para funcionar." << endl;
    }
    else if (comando == "set-server-invite-code")
    {
        if (verificarArgumentos(param1, param2, param3, 2) || verificarArgumentos(param1, param2, param3, 1))
            sistema.modificarCodigoServidor(param1, param2);
        else
            cout << "Este comando precisa de 1 ou 2 argumento(s) para funcionar." << endl;
    }
    else if (comando == "list-servers")
    {
        if (verificarArgumentos(param1, param2, param3, 0))
            sistema.listarServidores();
        else
            cout << "Este comando precisa de 0 argumento(s) para funcionar." << endl;
    }
    else if (comando == "remove-server")
    {
        if (verificarArgumentos(param1, param2, param3, 1))
            sistema.removerServidor(param1);
        else
            cout << "Este comando precisa de 1 argumento(s) para funcionar." << endl;
    }
    else if (comando == "enter-server")
    {
        if (verificarArgumentos(param1, param2, param3, 2) || verificarArgumentos(param1, param2, param3, 1))
            sistema.entrarEmServidor(param1, param2);
        else
            cout << "Este comando precisa de 1 ou 2 argumento(s) para funcionar." << endl;
    }
    else if (comando == "leave-server")
    {
        if (verificarArgumentos(param1, param2, param3, 0))
            sistema.sairDoServidor();
        else
            cout << "Este comando precisa de 0 argumento(s) para funcionar." << endl;
    }
    else if (comando == "list-participants")
    {
        if (verificarArgumentos(param1, param2, param3, 0))
            sistema.listarParticipantesDoServidor();
        else
            cout << "Este comando precisa de 0 argumento(s) para funcionar." << endl;
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

    return 0;
}
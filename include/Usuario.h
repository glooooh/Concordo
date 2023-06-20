/**
 * @file Usuario.h
 * @brief Arquivo header da classe Usuario.
 */
#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

/**
 * @class Usuario
 * @brief Classe que representa um usuário.
 */
class Usuario
{
private:
    int id;
    string nome;
    string email;
    string senha;

public:
    // Construtores
    Usuario(string, string, string, int);
    Usuario();

    // Destrutor
    ~Usuario();

    // Gets
    int getID();
    string getNome();
    string getEmail();
    string getSenha();
};

#endif
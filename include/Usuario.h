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
    /**
     * @brief Construtor da classe Usuario.
     */
    Usuario(string, string, string, int);

    /**
     * @brief Construtor padrão da classe Usuario.
     */
    Usuario();

    /**
     * @brief Destrutor da classe Usuario.
     */
    ~Usuario();

    /**
     * @brief Obtém o ID do usuário.
     *
     * @return O ID do usuário.
     */
    int getID();

    /**
     * @brief Obtém o nome do usuário.
     *
     * @return O nome do usuário.
     */
    string getNome();

    /**
     * @brief Obtém o email do usuário.
     *
     * @return O email do usuário.
     */
    string getEmail();

    /**
     * @brief Obtém a senha do usuário.
     *
     * @return A senha do usuário.
     */
    string getSenha();
};

#endif
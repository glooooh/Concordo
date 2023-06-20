/**
 * @file Usuario.cpp
 * @brief Implementação dos métodos da classe Usuario
 */

#include <iostream>

#include "Usuario.h" /**< Inclui a classe Usuario. */

/**
 * @brief Construtor da classe Usuario.
 *
 * @param n O nome do usuário.
 * @param e O email do usuário.
 * @param s A senha do usuário.
 * @param i O ID do usuário.
 */
Usuario::Usuario(string n, string e, string s, int i)
{
    nome = n;
    email = e;
    senha = s;
    id = i;
}

/**
 * @brief Construtor padrão da classe Usuario.
 */
Usuario::Usuario() {}

/**
 * @brief Destrutor da classe Usuario.
 */
Usuario::~Usuario() {}

/**
 * @brief Obtém o ID do usuário.
 *
 * @return O ID do usuário.
 */
int Usuario::getID() {
    return id;
}

/**
 * @brief Obtém o nome do usuário.
 *
 * @return O nome do usuário.
 */
string Usuario::getNome() {
    return nome;
}

/**
 * @brief Obtém o email do usuário.
 *
 * @return O email do usuário.
 */
string Usuario::getEmail() {
    return email;
}

/**
 * @brief Obtém a senha do usuário.
 *
 * @return A senha do usuário.
 */
string Usuario::getSenha() {
    return senha;
}

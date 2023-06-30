/**
 * @file Canal.cpp
 * @brief Implementação dos métodos da classe Canal
 */

#include <iostream>

#include "Canal.h" /**< Inclui a classe Canal. */

/**
 * @brief Construtor da classe Canal.
 *
 * @param nome O nome do canal.
 */
Canal::Canal(string nn)
{
    this->nome = nn;
}

/**
 * @brief Construtor padrão da classe Canal.
 */
Canal::Canal() {}

/**
 * @brief Destrutor padrão da classe Canal.
 */
Canal::~Canal() {}

/**
 * @brief Obtém o nome do Canal.
 *
 * @return o nome do Canal.
 */
string Canal::getNome()
{
    return nome;
}

/**
 * @brief Obtém o tipo do canal.
 * 
 * @return O tipo do canal.
 */
string Canal::getTipo() const
{
    return "Canal";
}
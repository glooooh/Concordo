/**
 * @file Mensagem.cpp
 * @brief Implementação dos métodos da classe Mensagem
 */

#include <iostream>

#include "Mensagem.h" /**< Inclui a classe Mensagem. */

/**
 * @brief Construtor da classe Mensagem.
 * 
 * @param texto O conteúdo da mensagem.
 * @param idRemetente O ID do remetente da mensagem.
 * @param data_hora A data e hora da mensagem.
 */
Mensagem::Mensagem(const string &texto, int idRemetente, const string &data_hora)
{
    dataHora = data_hora;
    enviadaPor = idRemetente;
    conteudo = texto;
}

/**
 * @brief Construtor padrão da classe Mensagem.
 */
Mensagem::Mensagem() {}

/**
 * @brief Destrutor padrão da classe Mensagem.
 */
Mensagem::~Mensagem() {}

/**
 * @brief Obtém a data e hora da mensagem.
 * 
 * @return A data e hora da mensagem.
 */
string Mensagem::getDataHora()
{
    return dataHora;
}

/**
 * @brief Obtém o ID do remetente da mensagem.
 * 
 * @return O ID do remetente da mensagem.
 */
int Mensagem::getIdRemetente()
{
    return enviadaPor;
}

/**
 * @brief Obtém o conteúdo da mensagem.
 * 
 * @return O conteúdo da mensagem.
 */
string Mensagem::getConteudo() const
{
    return conteudo;
}

/**
 * @brief Verifica se a mensagem está vazia.
 * 
 * @return True se a mensagem estiver vazia, False caso contrário.
 */
bool Mensagem::empty()
{
    if (dataHora.empty())
        return true;
    return false;
}
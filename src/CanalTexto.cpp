/**
 * @file CanalTexto.cpp
 * @brief Implementação dos métodos da classe CanalTexto
 */

#include <iostream>

#include "CanalTexto.h" /**< Inclui a classe CanalTexto. */

/**
 * @brief Construtor da classe CanalTexto.
 * 
 * @param nome O nome do canal de texto.
 */
CanalTexto::CanalTexto(string nome) : Canal(nome) {}

/**
 * @brief Destrutor padrão da classe CanalTexto.
 */
CanalTexto::~CanalTexto() {}

/**
 * @brief Obtém o tipo do canal de texto.
 * 
 * @return O tipo do canal de texto.
 */
string CanalTexto::getTipo() const
{
    return "TEXTO";
}

/**
 * @brief Obtém as mensagens do canal de texto.
 * 
 * @return O vetor de mensagens do canal de texto.
 */
vector<Mensagem> CanalTexto::getMensagens()
{
    return mensagens;
}

/**
 * @brief Envia uma mensagem no canal de texto.
 * 
 * @param mensagem A mensagem a ser enviada.
 */
void CanalTexto::enviarMensagem(const Mensagem &mensagem)
{
    this->mensagens.push_back(mensagem);
}
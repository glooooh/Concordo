/**
 * @file CanalVoz.cpp
 * @brief Implementação dos métodos da classe CanalVoz
 */

#include <iostream>

#include "CanalVoz.h" /**< Inclui a classe CanalVoz. */

/**
 * @brief Construtor da classe CanalVoz.
 * 
 * @param nome O nome do canal de voz.
 */
CanalVoz::CanalVoz(string nome) : Canal(nome) {}

/**
 * @brief Destrutor da classe CanalVoz.
 */
CanalVoz::~CanalVoz() {}

/**
 * @brief Obtém o tipo do canal de voz.
 * 
 * @return O tipo do canal de voz.
 */
string CanalVoz::getTipo() const
{
    return "VOZ";
}

/**
 * @brief Obtém as mensagens do canal de voz.
 * 
 * @return Um vetor contendo as mensagens do canal de voz.
 */
vector<Mensagem> CanalVoz::getMensagens()
{
    vector<Mensagem> mensagem;
    if (!ultimaMensagem.empty())
        mensagem.push_back(ultimaMensagem);
    return mensagem;
}

/**
 * @brief Envia uma mensagem para o canal de voz.
 * 
 * @param mensagem A mensagem a ser enviada.
 */
void CanalVoz::enviarMensagem(const Mensagem &mensagem)
{
    ultimaMensagem = mensagem;
}
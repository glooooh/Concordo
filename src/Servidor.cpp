/**
 * @file Servidor.cpp
 * @brief Implementação dos métodos da classe Servidor
 */

#include <iostream>

#include "Servidor.h" /**< Inclui a classe Servidor. */

/**
 * @brief Construtor da classe Servidor.
 *
 * @param donoId O ID do usuário dono do servidor.
 * @param n O nome do servidor.
 */
Servidor::Servidor(int donoId, string n)
{
    this->usuarioDonoId = donoId;
    this->nome = n;
    this->descricao = "";
    this->codigoConvite = "";
    this->canais = vector<Canal *>();
    this->participantesIDs.push_back(donoId);
}

/**
 * @brief Construtor padrão da classe Usuario.
 */
Servidor::Servidor() {}

/**
 * @brief Destrutor da classe Usuario.
 */
Servidor::~Servidor()
{
    // Liberar a memória alocada para os objetos Canal
    for (size_t i = 0; i < canais.size(); i++)
    {
        delete canais[i];
    }

    canais.clear();           /*<! Limpar o vetor de canais. */ 
    participantesIDs.clear(); /*<! Limpar o vetor de participantesIDs. */
}

/**
 * @brief Obtém o ID do usuário dono do servidor.
 *
 * @return O ID do usuário dono.
 */
int Servidor::getIdDono()
{
    return usuarioDonoId;
}

/**
 * @brief Obtém o nome do servidor.
 *
 * @return O nome do servidor.
 */
string Servidor::getNome()
{
    return nome;
}

/**
 * @brief Obtém a descrição do servidor.
 *
 * @return A descrição do servidor.
 */
string Servidor::getDescricao()
{
    return descricao;
}

/**
 * @brief Obtém o código de convite do servidor.
 *
 * @return O código de convite do servidor.
 */
string Servidor::getCodigo()
{
    return codigoConvite;
}

/**
 * @brief Obtém os IDs dos participantes do servidor.
 *
 * @return Um vetor contendo os IDs dos participantes.
 */
vector<int> Servidor::getParticipantesID()
{
    return participantesIDs;
}

/**
 * @brief Define a descrição do servidor.
 *
 * @param desc A nova descrição a ser atribuída ao servidor.
 */
void Servidor::setDescricao(string desc)
{
    descricao = desc;
}

/**
 * @brief Define o código de convite do servidor.
 *
 * @param cod O novo código de convite a ser atribuído ao servidor.
 */
void Servidor::setCodigo(string cod)
{
    codigoConvite = cod;
}

/**
 * @brief Adiciona um participante ao servidor.
 *
 * @param id O ID do participante a ser adicionado.
 */
void Servidor::adicionarParticipantes(int id)
{
    participantesIDs.push_back(id);
}

/**
 * @brief Verifica se um participante com o ID específico está no servidor.
 *
 * @param id O ID do participante a ser buscado.
 * @return true se o participante está no servidor, false caso contrário.
 */
bool Servidor::buscarParticipantePorId(int id)
{
    for (size_t i = 0; i < participantesIDs.size(); i++)
    {
        if (participantesIDs[i] == id)
        {
            return true;
        }
    }

    return false;
}

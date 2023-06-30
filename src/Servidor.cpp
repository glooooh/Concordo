/**
 * @file Servidor.cpp
 * @brief Implementação dos métodos da classe Servidor
 */

#include <iostream>

#include "Servidor.h"   /**< Inclui a classe Servidor. */
#include "CanalTexto.h" /**< Inclui a classe CanalTexto. */
#include "CanalVoz.h"   /**< Inclui a classe CanalVoz. */

/**
 * @brief Construtor da classe Servidor.
 *
 * @param donoId O ID do usuário dono do servidor.
 * @param nomeServidor O nome do servidor.
 */
Servidor::Servidor(int donoId, string nomeServidor)
{
    this->usuarioDonoId = donoId;
    this->nome = nomeServidor;
    this->descricao = "";
    this->codigoConvite = "";
    this->canais = vector<Canal *>();
    this->participantesIDs.push_back(donoId);
}

/**
 * @brief Construtor padrão da classe Servidor.
 */
Servidor::Servidor() {}

/**
 * @brief Destrutor da classe Servidor.
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
 * @brief Obtém os canais do servidor.
 *
 * @return Um vetor contendo os canais do servidor.
 */
vector<Canal *> Servidor::getCanais()
{
    return canais;
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
    /* Percorre cada membro do vector de ids.*/
    for (int participanteID : participantesIDs)
    {
        /*  Verifica se é o mesmo id fornecido como parâmetro. */
        if (participanteID == id)
            return true;
    }

    return false;
}

/**
 * @brief Cria um novo canal no servidor.
 *
 * @param nome O nome do canal.
 * @param tipo O tipo do canal.
 */
void Servidor::criarCanal(string nome, string tipo)
{
    /* Percorre o vector de canais do servidor. */
    for (Canal *canal : this->getCanais())
    {
        /* Verifica se já existe um canal com o mesmo nome no servidor. */
        if (canal->getNome() == nome)
        {
            cout << "Canal de " << tipo << " '" << nome << "' ja existe!" << endl;
            return;
        }
    }

    /* Cria um canal de acordo com o tipo designado. */
    if (tipo == "texto")
    {
        CanalTexto *canal = new CanalTexto(nome);
        canais.push_back(canal);
    }
    else if (tipo == "voz")
    {
        CanalVoz *canal = new CanalVoz(nome);
        canais.push_back(canal);
    }
    else
    {
        cout << "Tipo de canal invalido" << endl;
        return;
    }

    /* Mensagem de sucesso. */
    cout << "Canal de " << tipo << " '" << nome << "' criado" << endl;
}
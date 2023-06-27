/**
 * @file Sistema.h
 * @brief Arquivo header da classe Sistema.
 */
#ifndef SISTEMA_H
#define SISTEMA_H

#include "Usuario.h"
#include "Servidor.h"

/**
 * @class Sistema
 * @brief Classe que representa um sistema.
 */
class Sistema
{
private:
    vector<Usuario *> *usuariosDoSistema;    /*<! Um vector com todos os usuários do sistema */
    vector<Servidor *> *servidoresDoSistema; /*<! Um vector com todos os servidores do sistema */
    Usuario *usuarioLogadoAtual;             /*<! Qual o usuário atualmente logado no sistema */
    Servidor *servidorAtual;                 /*<! Qual o servidor que o usuário está visualizando no momento */
    Canal *canalAtual;                       /*<! Qual o canal que o usuário está visualizando no momento */

public:
    /**
     * @brief Construtor padrão da classe Sistema.
     */
    Sistema();

    /**
     * @brief Destrutor da classe Sistema.
     */
    ~Sistema();

    /**
     * @brief Adiciona um novo usuário ao sistema.
     *
     * @return Retorna True se o cadastro foi bem sucedido, False caso contrário.
     */
    bool adicionarUsuario(string, string, string);

    /**
     * @brief Busca um usuário pelo índice.
     *
     * @return Um ponteiro para o usuário encontrado, ou nullptr se o índice for inválido.
     */
    Usuario *buscarPeloID(int);

    /**
     * @brief Realiza o login do usuário no sistema.
     *
     * @return True se o login for bem-sucedido, False caso contrário.
     */
    bool login(string, string);

    /**
     * @brief Desconecta o usuário atualmente logado no sistema.
     *
     * @return Retorna true se a desconexão foi bem-sucedida, false caso contrário.
     */
    bool disconnect();

    /**
     * @brief Busca um servidor pelo nome.
     *
     * @return Um ponteiro para o servidor encontrado, ou nullptr caso não seja encontrado.
     */
    Servidor *buscarServidorPorNome(string, string);

    /**
     * @brief Busca um servidor pelo nome e retorna o índice encontrado.
     *
     * @return Um ponteiro para o servidor encontrado, ou nullptr caso não seja encontrado.
     */
    Servidor *buscarServidorPorNome(string, int &, string);

    /**
     * @brief Cria um novo servidor no sistema.
     */
    void criarServidor(string);

    /**
     * @brief Remove um servidor do sistema.
     *
     * @return Retorna true se a remoção foi bem-sucedida, e false caso contrário.
     */
    bool removerServidor(string);

    /**
     * @brief Lista os servidores cadastrados no sistema.
     */
    void listarServidores();

    /**
     * @brief Verifica se o usuário logado é o dono do servidor.
     *
     * @return Retorna true se o usuário logado for o dono do servidor, e false caso contrário.
     */
    bool verificarDonoServidor(Servidor *, string);

    /**
     * @brief Modifica a descrição de um servidor.
     */
    void modificarDescricaoDeServidor(string, string);

    /**
     * @brief Modifica o código de convite de um servidor.
     */
    void modificarCodigoServidor(string, string);

    /**
     * @brief Entra em um servidor com o nome e código de convite fornecidos.
     */
    void entrarEmServidor(string, string);

    /**
     * @brief Sai do servidor atualmente visualizado pelo usuário logado.
     */
    void sairDoServidor();

    /**
     * @brief Lista os participantes do servidor atual.
     */
    void listarParticipantesDoServidor();
};

#endif
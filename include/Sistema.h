/**
 * @file Sistema.h
 * @brief Arquivo header da classe Sistema.
 */
#ifndef SISTEMA_H
#define SISTEMA_H

#include "Usuario.h"    /**< Inclui a classe Usuario. */
#include "Mensagem.h"   /**< Inclui a classe Mensagem. */
#include "Servidor.h"   /**< Inclui a classe Servidor. */
#include "Canal.h"      /**< Inclui a classe Canal. */
#include "CanalTexto.h" /**< Inclui a classe CanalTexto. */
#include "CanalVoz.h"   /**< Inclui a classe CanalVoz. */

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

    /**
     * @brief Salva os usuários do sistema em um arquivo.
     */
    void salvarUsuarios();

    /**
     * @brief Salva os servidores do sistema em um arquivo.
     */
    void salvarServidores();

    /**
     * @brief Carrega os usuários do sistema a partir de um arquivo.
     */
    void carregarUsuarios();

    /**
     * @brief Carrega os servidores do sistema a partir de um arquivo.
     */
    void carregarServidores();

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
     * @brief Salva os usuários e servidores do sistema.
     */
    void salvar();

    /**
     * @brief Carrega os usuários e servidores do sistema.
     */
    void carregar();

    /**
     * @brief Adiciona um novo usuário ao sistema.
     *
     * @param email O email do usuário.
     * @param senha A senha do usuário.
     * @param nome O nome do usuário.
     *
     * @return Retorna True se o cadastro foi bem sucedido, False caso contrário.
     */
    bool adicionarUsuario(string, string, string);

    /**
     * @brief Busca um usuário pelo email.
     *
     * @param email O email do usuário a ser buscado.
     * @return Um ponteiro para o usuário encontrado ou nullptr caso nenhum usuário seja encontrado com o email fornecido.
     */
    Usuario *buscarPeloEmail(string email);

    /**
     * @brief Busca um usuário pelo índice.
     *
     * @param indiceBuscado O índice do usuário a ser buscado.
     *
     * @return Um ponteiro para o usuário encontrado, ou nullptr se o índice for inválido.
     */
    Usuario *buscarPeloID(int);

    /**
     * @brief Realiza o login do usuário no sistema.
     *
     * @param email O email do usuário.
     * @param senha A senha do usuário.
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
     * @param nome O nome do servidor a ser buscado.
     * @param msgDeErro A mensagem de erro a ser exibida caso o servidor não seja encontrado.
     *
     * @return Um ponteiro para o servidor encontrado, ou nullptr caso não seja encontrado.
     */
    Servidor *buscarServidorPorNome(string, string);

    /**
     * @brief Busca um servidor pelo nome e retorna o índice encontrado.
     *
     * @param nome O nome do servidor a ser buscado.
     * @param index A referência para armazenar o índice do servidor encontrado.
     * @param msgDeErro A mensagem de erro a ser exibida caso o servidor não seja encontrado.
     *
     * @return Um ponteiro para o servidor encontrado, ou nullptr caso não seja encontrado.
     */
    Servidor *buscarServidorPorNome(string, int &, string);

    /**
     * @brief Cria um novo servidor no sistema.
     *
     * @param nome O nome do servidor a ser criado.
     */
    void criarServidor(string);

    /**
     * @brief Remove um servidor do sistema.
     *
     * @param nome O nome do servidor a ser removido.
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
     * @param server O servidor a ser verificado.
     * @param mensagemDeErro A mensagem de erro a ser exibida caso o usuário não seja o dono do servidor.
     *
     * @return Retorna true se o usuário logado for o dono do servidor, e false caso contrário.
     */
    bool verificarDonoServidor(Servidor *, string);

    /**
     * @brief Modifica a descrição de um servidor.
     *
     * @param nome O nome do servidor.
     * @param descricao A nova descrição a ser atribuída.
     */
    void modificarDescricaoDeServidor(string, string);

    /**
     * @brief Modifica o código de convite de um servidor.
     *
     * @param nome O nome do servidor.
     * @param codigo O novo código de convite a ser atribuído.
     */
    void modificarCodigoServidor(string, string);

    /**
     * @brief Entra em um servidor com o nome e código de convite fornecidos.
     *
     * @param nome O nome do servidor a entrar.
     * @param cod O código de convite do servidor.
     */
    void entrarEmServidor(string, string);

    /**
     * @brief Sai do servidor atualmente visualizado pelo usuário logado.
     */
    void sairDoServidor();

    /**
     * @brief Lista os participantes do servidor atual.
     *
     * @details Este método obtém a lista de IDs dos participantes do servidor atual. Em seguida,
     * imprime os nomes correspondentes.
     */
    void listarParticipantesDoServidor();

    /**
     * @brief Busca um canal no servidor atual pelo nome.
     *
     * @param nome O nome do canal a ser buscado.
     *
     * @return Um ponteiro para o canal encontrado, ou nullptr caso não seja encontrado.
     */
    Canal *buscarCanalPorNome(string);

    /**
     * @brief Lista os canais do servidor atual.
     */
    void listarCanais();

    /**
     * @brief Cria um novo canal no servidor atual.
     *
     * @param nome O nome do canal a ser criado.
     * @param tipo O tipo do canal a ser criado.
     */
    void criarCanal(string, string);

    /**
     * @brief Entra em um canal no servidor atual.
     *
     * @param nome O nome do canal a ser visualizado.
     */
    void entrarEmCanal(string);

    /**
     * @brief Sai do canal que está sendo visualizado no momento.
     */
    void sairDoCanal();

    /**
     * @brief Envia uma mensagem no canal atualmente visualizado.
     *
     * @param texto O conteúdo da mensagem a ser enviada.
     * @param dataHora A data e hora em que a mensagem está sendo enviada.
     */
    void enviarMensagem(string, string);

    /**
     * @brief Lista as mensagens do canal atualmente visualizado.
     */
    void listarMensagens();
};

#endif
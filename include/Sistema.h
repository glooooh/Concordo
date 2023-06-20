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
    // Construtores
    Sistema();

    // Destrutor
    ~Sistema();

    // Acesso
    bool login(string, string);
    bool disconnect();

    // Funções de usuário
    void adicionarUsuario(string, string, string);
    Usuario *buscarPeloID(int);

    // Funções de servidor
    Servidor *buscarServidorPorNome(string, string);
    Servidor *buscarServidorPorNome(string, int &, string);
    void criarServidor(string);
    bool removerServidor(string);
    void listarServidores();
    bool verificarDonoServidor(Servidor *, string);
    void modificarDescricaoDeServidor(string, string);
    void modificarCodigoServidor(string, string);
    void entrarEmServidor(string, string);
    void sairDoServidor();
    void listarParticipantesDoServidor();

};

#endif
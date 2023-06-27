/**
 * @file Sistema.cpp
 * @brief Implementação dos métodos da classe Sistema
 */

#include <iostream>

#include "Sistema.h" /**< Inclui a classe Sistema. */

/**
 * @brief Construtor padrão da classe Sistema.
 */
Sistema::Sistema()
{
    usuariosDoSistema = new vector<Usuario *>;
    servidoresDoSistema = new vector<Servidor *>;
    usuarioLogadoAtual = nullptr;
    servidorAtual = nullptr;
    canalAtual = nullptr;
}

/**
 * @brief Destrutor da classe Sistema.
 */
Sistema::~Sistema()
{
    /*<! Liberar a memória alocada para a variável usuariosDoSistema */
    for (auto usuario : *usuariosDoSistema)
    {
        delete usuario;
    }

    usuariosDoSistema->clear();
    delete usuariosDoSistema;

    /*<! Liberar a memória alocada para a variável servidoresDoSistema */
    for (auto servidor : *servidoresDoSistema)
    {
        delete servidor;
    }

    servidoresDoSistema->clear();
    delete servidoresDoSistema;
}

/**
 * @brief Adiciona um novo usuário ao sistema.
 *
 * @param email O email do usuário.
 * @param senha A senha do usuário.
 * @param nome O nome do usuário.
 *
 * @return Retorna True se o cadastro foi bem sucedido, False caso contrário.
 */
bool Sistema::adicionarUsuario(string email, string senha, string nome)
{
    // Verifica se um usuário com os mesmos dados já foi cadastrado
    int tamanho = usuariosDoSistema->size();
    for (int ii = 0; ii < tamanho; ii++)
    {
        // Verifica se o email e senha fornecidos correspondem a algum usuário digitado.
        if ((*usuariosDoSistema)[ii]->getEmail() == email)
        {
            cout << "Usuario ja existe!" << endl;
            return false;
        }
    }

    // Cadastra o usuario
    Usuario *user = new Usuario(nome, email, senha, tamanho);
    usuariosDoSistema->push_back(user);
    cout << "Usuario criado" << endl;
    return true;
}

/**
 * @brief Busca um usuário pelo índice.
 *
 * @param indiceBuscado O índice do usuário a ser buscado.
 * @return Um ponteiro para o usuário encontrado, ou nullptr se o índice for inválido.
 */
Usuario *Sistema::buscarPeloID(int indiceBuscado)
{
    if (size_t(indiceBuscado) >= 0 && indiceBuscado < usuariosDoSistema->size())
    {
        Usuario *usuarioEncontrado = (*usuariosDoSistema)[indiceBuscado];
        return usuarioEncontrado;
    }
    else
    {
        cout << "Índice inválido." << endl;
        return nullptr;
    }
}

/**
 * @brief Realiza o login do usuário no sistema.
 *
 * @param email O email do usuário.
 * @param senha A senha do usuário.
 * @return True se o login for bem-sucedido, False caso contrário.
 */
bool Sistema::login(string email, string senha)
{
    /* Verifica se existe algum usuário logado */
    if (usuarioLogadoAtual != nullptr)
    {
        disconnect();
    }

    // Percorre o vector de usuarios cadastrados no sistema.
    for (size_t ii = 0; ii < usuariosDoSistema->size(); ii++)
    {
        if ((*usuariosDoSistema)[ii]->getEmail() == (email) && (*usuariosDoSistema)[ii]->getSenha() == senha)
        {
            usuarioLogadoAtual = (*usuariosDoSistema)[ii];
            cout << "Logado como " << usuarioLogadoAtual->getEmail() << endl;
            return true;
        }
    }

    // Imprime mensagem de erro e retorna False.
    cout << "Senha ou usuario invalidos!" << endl;
    return false;
}

/**
 * @brief Desconecta o usuário atualmente logado no sistema.
 *
 * @return Retorna true se a desconexão foi bem-sucedida, false caso contrário.
 */
bool Sistema::disconnect()
{
    // Verifica se existe algum usuário logado.
    if (usuarioLogadoAtual == nullptr)
    {
        cout << "Nao esta conectado" << endl;
        return false;
    }

    // Desconecta o usuário e imprime mensagem de sucesso
    cout << "Desconectando usuario " << usuarioLogadoAtual->getEmail() << endl;
    usuarioLogadoAtual = nullptr;
    servidorAtual = nullptr;
    canalAtual = nullptr;
    return true;
}

/**
 * @brief Busca um servidor pelo nome.
 *
 * @param nome O nome do servidor a ser buscado.
 * @return Um ponteiro para o servidor encontrado, ou nullptr caso não seja encontrado.
 */
Servidor *Sistema::buscarServidorPorNome(string nome, string msgDeErro)
{
    for (int ii = 0; ii < servidoresDoSistema->size(); ii++)
    {
        // Verifica se o email e senha fornecidos correspondem a algum usuário digitado.
        if ((*servidoresDoSistema)[ii]->getNome() == nome)
        {
            return (*servidoresDoSistema)[ii];
        }
    }

    if (msgDeErro != "")
    {
        cout << msgDeErro << endl;
    }
    return nullptr;
}

/**
 * @brief Busca um servidor pelo nome e retorna o índice encontrado.
 *
 * @param nome O nome do servidor a ser buscado.
 * @param index A referência para armazenar o índice do servidor encontrado.
 * @return Um ponteiro para o servidor encontrado, ou nullptr caso não seja encontrado.
 */
Servidor *Sistema::buscarServidorPorNome(string nome, int &index, string msgDeErro)
{
    for (int ii = 0; ii < servidoresDoSistema->size(); ii++)
    {
        // Verifica se o email e senha fornecidos correspondem a algum usuário digitado.
        if ((*servidoresDoSistema)[ii]->getNome() == nome)
        {
            index = ii;
            return (*servidoresDoSistema)[ii];
        }
    }

    if (msgDeErro != "")
    {
        cout << msgDeErro << endl;
    }
    return nullptr;
}

/**
 * @brief Cria um novo servidor no sistema.
 *
 * @param nome O nome do servidor a ser criado.
 */
void Sistema::criarServidor(string nome)
{
    // Verifica se existe algum usuário logado.
    if (usuarioLogadoAtual == nullptr)
    {
        cout << "Voce nao esta logado!" << endl;
        return;
    }

    // Verifica se já existe um servidor com o mesmo nome.
    Servidor *server = buscarServidorPorNome(nome, "");
    if (server != nullptr)
    {
        cout << "Um servidor com esse nome ja existe!" << endl;
        return;
    }

    // Cria um novo servidor.
    server = new Servidor(usuarioLogadoAtual->getID(), nome);
    servidoresDoSistema->push_back(server);

    // Imprime mensagem de sucesso.
    cout << "Servidor criado" << endl;
}

/**
 * @brief Remove um servidor do sistema.
 *
 * @param nome O nome do servidor a ser removido.
 * @return Retorna true se a remoção foi bem-sucedida, e false caso contrário.
 */
bool Sistema::removerServidor(string nome)
{
    // Verifica se existe algum usuário logado.
    if (usuarioLogadoAtual == nullptr)
    {
        cout << "Voce nao esta logado!" << endl;
        return false;
    }

    int index;
    string msgDeErro = "Servidor '" + nome + "' nao encontrado";
    Servidor *server = buscarServidorPorNome(nome, index, msgDeErro);

    if (server == nullptr)
    {
        return false;
    }

    // Verificar se o servidor escolhido existe e se o dono do servidor é o usuário logado.
    msgDeErro = "Voce nao e o dono do servidor '" + server->getNome() + "'";
    if (server == nullptr || !verificarDonoServidor(server, msgDeErro))
    {
        return false;
    }

    // Sai do servidor, caso esteja nele.
    if (servidorAtual == server)
    {
        sairDoServidor();
    }

    // Apaga o servidor.
    servidoresDoSistema->erase(servidoresDoSistema->begin() + index);
    cout << "Servidor '" + server->getNome() + "' removido" << endl;
    delete server;
    return true;
}

/**
 * @brief Lista os servidores cadastrados no sistema.
 */
void Sistema::listarServidores()
{
    // Verifica se existe algum usuário logado.
    if (usuarioLogadoAtual == nullptr)
    {
        cout << "Voce nao esta logado!" << endl;
        return;
    }

    // Verifica se existem servidores cadastrados.
    if (servidoresDoSistema->size() == 0)
    {
        cout << "Nenhum servidor foi cadastrado" << endl;
    }

    // Percorre a lista de servidores e imprime os nomes dos mesmos.
    for (int ii = 0; ii < servidoresDoSistema->size(); ii++)
    {
        cout << (*servidoresDoSistema)[ii]->getNome() << endl;
    }
}

/**
 * @brief Verifica se o usuário logado é o dono do servidor.
 *
 * @param server O servidor a ser verificado.
 * @param mensagemDeErro A mensagem de erro a ser exibida caso o usuário não seja o dono do servidor.
 * @return Retorna true se o usuário logado for o dono do servidor, e false caso contrário.
 */
bool Sistema::verificarDonoServidor(Servidor *server, string mensagemDeErro)
{
    if (usuarioLogadoAtual->getID() == server->getIdDono())
    {
        return true;
    }

    cout << mensagemDeErro << endl;
    return false;
}

/**
 * @brief Modifica a descrição de um servidor.
 *
 * @param nome O nome do servidor.
 * @param descricao A nova descrição a ser atribuída.
 */
void Sistema::modificarDescricaoDeServidor(string nome, string descricao)
{
    // Verifica se existe algum usuário logado.
    if (usuarioLogadoAtual == nullptr)
    {
        cout << "Voce nao esta logado!" << endl;
        return;
    }

    // Busca pelo servidor escolhido.
    string msgDeErro = "Servidor '" + nome + "' nao existe";
    Servidor *server = buscarServidorPorNome(nome, msgDeErro);

    // Verificar se o servidor escolhido existe e se o dono do servidor é o usuário logado.
    msgDeErro = "Voce nao pode alterar a descricao de um servidor que nao foi criado por voce";
    if (server == nullptr || !verificarDonoServidor(server, msgDeErro))
    {
        return;
    }

    // Modifica a descrição e imprime mensagem de sucesso.
    server->setDescricao(descricao);
    cout << "Descricao do servidor '" << server->getNome() << "' modificada!" << endl;
}

/**
 * @brief Modifica o código de convite de um servidor.
 *
 * @param nome O nome do servidor.
 * @param codigo O novo código de convite a ser atribuído.
 */
void Sistema::modificarCodigoServidor(string nome, string codigo)
{
    // Verifica se existe algum usuário logado.
    if (usuarioLogadoAtual == nullptr)
    {
        cout << "Voce nao esta logado!" << endl;
        return;
    }

    string msgDeErro = "Servidor '" + nome + "' nao encontrado";
    Servidor *server = buscarServidorPorNome(nome, msgDeErro);

    // Verificar se o servidor escolhido existe e se o dono do servidor é o usuário logado.
    msgDeErro = "Voce nao pode alterar o codigo de convite de um servidor que nao foi criado por voce";
    if (server == nullptr || !verificarDonoServidor(server, msgDeErro))
    {
        return;
    }

    // Verifica se o código foi removido ou modificado.
    string status = "modificado";
    if (codigo == "")
    {
        status = "removido";
    }

    // Modifica o código e imprime mensagem de sucesso.
    server->setCodigo(codigo);
    cout << "Codigo de convite do servidor '" << server->getNome() << "' " << status << "!" << endl;
}

/**
 * @brief Entra em um servidor com o nome e código de convite fornecidos.
 *
 * @param nome O nome do servidor a entrar.
 * @param cod O código de convite do servidor.
 */
void Sistema::entrarEmServidor(string nome, string cod)
{
    /* Verifica se existe algum usuário logado. */
    if (usuarioLogadoAtual == nullptr)
    {
        cout << "Voce nao esta logado!" << endl;
        return;
    }

    /* Busca o servidor informado. */
    string msgDeErro = "Servidor '" + nome + "' nao encontrado";
    Servidor *server = buscarServidorPorNome(nome, msgDeErro);

    /* Verifica se o servidor existe. */
    if (server == nullptr)
    {
        return;
    }

    /* Verifica se o usuário logado é o dono do servidor. */
    if (server->getIdDono() == usuarioLogadoAtual->getID())
    {
        servidorAtual = server;
        cout << "Entrou no servidor com sucesso" << endl;
        return;
    }

    /* Verifica se o usuário já está na lista de participantes do servidor. */
    for (size_t ii = 0; ii < server->getParticipantesID().size(); ii++)
    {
        if (server->getParticipantesID()[ii] == usuarioLogadoAtual->getID())
        {
            servidorAtual = server;
            cout << "Entrou no servidor com sucesso" << endl;
            return;
        }
    }

    /* Verifica se o servidor precisa de um código de convite. */
    if (server->getCodigo() != "" && cod == "")
    {
        cout << "Servidor requer codigo de convite" << endl;
        return;
    }

    /* Verifica se o código informado está correto. */
    if (server->getCodigo() != cod)
    {
        if (cod == "")
            cout << "Servidor requer codigo de convite" << endl;
        else
            cout << "Codigo invalido" << endl;
        return;
    }

    /* Permite a entrada no servidor. */
    servidorAtual = server;
    cout << "Entrou no servidor com sucesso" << endl;
    if (!server->buscarParticipantePorId(usuarioLogadoAtual->getID()))
    {
        server->adicionarParticipantes(usuarioLogadoAtual->getID());
    }
}

/**
 * @brief Sai do servidor atualmente visualizado pelo usuário logado.
 */
void Sistema::sairDoServidor()
{
    // Verifica se existe algum usuário logado.
    if (usuarioLogadoAtual == nullptr)
    {
        cout << "Voce nao esta logado!" << endl;
        return;
    }

    // Verifica se o usuário está em algum servidor.
    if (servidorAtual == nullptr)
    {
        cout << "Voce nao esta visualizando nenhum servidor" << endl;
        return;
    }

    cout << "Saindo do servidor '" << servidorAtual->getNome() << "'" << endl;
    servidorAtual = nullptr;
}

/**
 * @brief Lista os participantes do servidor atual.
 *
 * @details Este método obtém a lista de IDs dos participantes do servidor atual. Em seguida,
 * imprime os nomes correspondentes.
 */
void Sistema::listarParticipantesDoServidor()
{
    // Verifica se existe algum usuário logado.
    if (usuarioLogadoAtual == nullptr)
    {
        cout << "Voce nao esta logado!" << endl;
        return;
    }

    // Verifica se o usuário está em algum servidor.
    if (servidorAtual == nullptr)
    {
        cout << "Voce nao esta visualizando nenhum servidor" << endl;
        return;
    }

    vector<int> listaParticipantes = servidorAtual->getParticipantesID();

    for (size_t ii = 0; ii < listaParticipantes.size(); ii++)
    {
        cout << buscarPeloID(listaParticipantes[ii])->getNome() << endl;
    }
}
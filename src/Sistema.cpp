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
 *
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
 *
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
 * @param msgDeErro A mensagem de erro a ser exibida caso o servidor não seja encontrado.
 *
 * @return Um ponteiro para o servidor encontrado, ou nullptr caso não seja encontrado.
 */
Servidor *Sistema::buscarServidorPorNome(string nome, string msgDeErro)
{
    /* Percorre os servidores cadastrados no sistema. */
    for (Servidor *servidor : *servidoresDoSistema)
    {
        /* Verifica se o nome fornecido corresponde ao nome de algum servidor cadastrado. */
        if (servidor->getNome() == nome)
            return servidor;
    }

    /* Imprime mensagem de erro, se houver uma e for necessária. */
    if (msgDeErro != "")
    {
        cout << msgDeErro << endl;
    }
    /* Retornar nullptr caso o servidor não exista. */
    return nullptr;
}

/**
 * @brief Busca um servidor pelo nome e retorna o índice encontrado.
 *
 * @param nome O nome do servidor a ser buscado.
 * @param index A referência para armazenar o índice do servidor encontrado.
 * @param msgDeErro A mensagem de erro a ser exibida caso o servidor não seja encontrado.
 *
 * @return Um ponteiro para o servidor encontrado, ou nullptr caso não seja encontrado.
 */
Servidor *Sistema::buscarServidorPorNome(string nome, int &index, string msgDeErro)
{
    for (int ii = 0; ii < servidoresDoSistema->size(); ii++)
    {
        /* Verifica se o nome fornecido corresponde ao nome de algum servidor cadastrado. */
        if ((*servidoresDoSistema)[ii]->getNome() == nome)
        {
            index = ii; // Armazena o índice do servidor encontrado na variável index.
            return (*servidoresDoSistema)[ii];
        }
    }

    /* Imprime mensagem de erro, se houver uma e for necessária. */
    if (msgDeErro != "")
    {
        cout << msgDeErro << endl;
    }
    /* Retornar nullptr caso o servidor não exista. */
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
 *
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

    /* Verifica se o servidor existe. */
    int index;
    string msgDeErro = "Servidor '" + nome + "' nao encontrado";
    Servidor *server = buscarServidorPorNome(nome, index, msgDeErro);

    if (server == nullptr)
    {
        return false;
    }

    // Verificar se o dono do servidor é o usuário logado.
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
 *
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
    for (int participanteID : server->getParticipantesID())
    {
        if (participanteID == usuarioLogadoAtual->getID())
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

/**
 * @brief Busca um canal no servidor atual pelo nome.
 *
 * @param nome O nome do canal a ser buscado.
 * 
 * @return Um ponteiro para o canal encontrado, ou nullptr caso não seja encontrado.
 */
Canal *Sistema::buscarCanalPorNome(string nome)
{
    for (Canal *canal : servidorAtual->getCanais())
    {
        if (canal->getNome() == nome)
        {
            return canal;
        }
    }

    return nullptr;
}

/**
 * @brief Lista os canais do servidor atual.
 */
void Sistema::listarCanais()
{
    // Verifica se o usuário está em algum servidor.
    if (servidorAtual == nullptr)
    {
        cout << "Voce nao esta visualizando nenhum servidor" << endl;
        return;
    }

    if (servidorAtual->getCanais().size() == 0)
    {
        cout << "Nenhum canal cadastrado" << endl;
        return;
    }

    vector<Canal *> canais = servidorAtual->getCanais();

    cout << "#canais de texto" << endl;
    for (Canal *canal : canais)
    {
        string tipo = canal->getTipo();
        if (tipo == "CanalTexto")
        {
            cout << canal->getNome() << endl;
        }
    }

    cout << "#canais de audio" << endl;
    for (Canal *canal : canais)
    {
        string tipo = canal->getTipo();
        if (tipo == "CanalVoz")
        {
            cout << canal->getNome() << endl;
        }
    }
}

/**
 * @brief Cria um novo canal no servidor atual.
 *
 * @param nome O nome do canal a ser criado.
 * @param tipo O tipo do canal a ser criado.
 */
void Sistema::criarCanal(string nome, string tipo)
{
    /* Verifica se o usuário está em algum servidor. */
    if (servidorAtual == nullptr)
    {
        cout << "Voce nao esta visualizando nenhum servidor" << endl;
        return;
    }

    /* Verifica se o usuário logado é o dono do servidor. */
    if (servidorAtual->getIdDono() != usuarioLogadoAtual->getID())
    {
        cout << "Voce nao e o dono deste servidor" << endl;
        return;
    }

    servidorAtual->criarCanal(nome, tipo);
}

/**
 * @brief Entra em um canal no servidor atual.
 *
 * @param nome O nome do canal a ser visualizado.
 */
void Sistema::entrarEmCanal(string nome)
{
    // Verifica se o usuário está em algum servidor.
    if (servidorAtual == nullptr)
    {
        cout << "Voce nao esta visualizando nenhum servidor" << endl;
        return;
    }

    Canal *canal = buscarCanalPorNome(nome);

    if (!canal)
    {
        cout << "Canal '" << nome << "' nao existe" << endl;
        return;
    }

    cout << "Entrou no canal '" << nome << "'" << endl;
    canalAtual = canal;
}

/**
 * @brief Sai do canal que está sendo visualizado no momento.
 */
void Sistema::sairDoCanal()
{
    // Verifica se o usuário está em algum canal.
    if (canalAtual == nullptr)
    {
        cout << "Voce nao esta visualizando nenhum canal" << endl;
        return;
    }

    cout << "Saindo do canal" << endl;
    canalAtual = nullptr;
}

/**
 * @brief Envia uma mensagem no canal atualmente visualizado.
 *
 * @param texto O conteúdo da mensagem a ser enviada.
 * @param dataHora A data e hora em que a mensagem está sendo enviada.
 */
void Sistema::enviarMensagem(string texto, string dataHora)
{
    // Verifica se o usuário está em algum canal.
    if (canalAtual == nullptr)
    {
        cout << "Voce nao esta visualizando nenhum canal" << endl;
        return;
    }

    Mensagem mensagem(texto, usuarioLogadoAtual->getID(), dataHora);

    canalAtual->enviarMensagem(mensagem);

    cout << "Mensagem enviada com sucesso" << endl;
}

/**
 * @brief Lista as mensagens do canal atualmente visualizado.
 */
void Sistema::listarMensagens()
{
    // Verifica se o usuário está em algum canal.
    if (canalAtual == nullptr)
    {
        cout << "Voce nao esta visualizando nenhum canal" << endl;
        return;
    }

    /* Verificar se existem mensagens no canal. */
    if (canalAtual->getMensagens().size() == 0)
    {
        cout << "Sem mensagens para exibir" << endl;
        return;
    }

    for (Mensagem mensagem : canalAtual->getMensagens())
    {
        /* Imprime as mensagens armazenadas no canal. */
        string nomeUsuario, dataHora, conteudo;
        nomeUsuario = buscarPeloID(mensagem.getIdRemetente())->getNome();
        dataHora = mensagem.getDataHora();
        conteudo = mensagem.getConteudo();
        cout << nomeUsuario << "<" << dataHora << ">: " << conteudo << endl;
    }
}
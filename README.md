# DIM0120 - 2023.1 – Concordo (Projeto 3)

## Desenvolvido por:
Este projeto foi desenvolvido pela aluna do curso de Bacharelado em Tecnologia da Informação, Glória Maria Souza Campêlo (20220034667).


## Como compilar e rodar o programa:
__Para acessar o programa:__
1. Crie um diretório 'build';
1. Acesse o diretório 'build';
1. Execute o comando 'cmake ..';
1. Execute o comando 'make';
1. Execute o arquivo executável 'MeuProjeto'

Pronto, você já tem acesso ao programa :)

__Quanto à navegação pela interface:__ <br>
- O uso do programa se dá através de comandos pré-definidos.

## Comandos do programa:
- <h3>quit</h3>
Este comando fecha a aplicação e pode ser executado a qualquer momento pelo usuário.
_Exemplo:_ 
```
quit
```

- <h3>create-user <__email__> <__senha__> <__nome__></h3>
Este comando permite que o usuário faça o login no sistema e pode ser executado a qualquer momento pelo usuário.
_Exemplo:_ 
```
create-user gloria.maria@imd.ufrn.br 12ab34cd Gloria Maria
```

- <h3>login <__email__> <__senha__></h3>
Este comando permite que o usuário faça o login no sistema e pode ser executado a qualquer momento pelo usuário.
_Exemplo:_ 
```
login gloria.maria@imd.ufrn.br 12ab34cd
```

- <h3>disconnect</h3>
Este comando desconecta o usuário do sistema Concordo e só pode ser executado por usuários logados.
_Exemplo:_ 
```
disconnect
```

- <h3>create-server <__nome__></h3>
Este comando cria um novo servidor  e só pode ser executado por usuários logados.
_Exemplo:_ 
```
create-server meu-servidor
```

- <h3>set-server-desc <__nome__> "<__descrição__>"</h3>
Este comando altera a descrição de um servidor e só pode ser utilizado pelo dono do servidor.
_Exemplo:_ 
```
set-server-desc meu-servidor "Este é o meu servidor"
```

- <h3>set-server-invitecode <__nome__> <__codigo__></h3>
Este comando altera o código de convite de um servidor e só pode ser utilizado pelo dono do servidor. (Se o usuário utilizar o comando sem nenhum código, o sistema remove o código de convite do servidor).
_Exemplo:_ 
```
set-server-invitecode meu-servidor 1234
set-server-invitecode meu-servidor
```

- <h3>list-servers</h3>
Este comando lista os servidores cadastrados no Concordo e só pode ser executado por usuários logados.
_Exemplo:_ 
```
list-servers
```

- <h3>remove-server <__nome__></h3>
Este comando exclui um servidor e só pode ser utilizado pelo dono do servidor. 
_Exemplo:_ 
```
remove-server meu-servidor
```

- <h3>comando enter-server <__nome__> __ou__ comando enter-server <__nome__> <__código__></h3>
Este comando permite que o usuário entre em um servidor e só pode ser executado por usuários logados. (O usuário pode utilizar com o comando com ou sem código, depende do servidor).
_Exemplo:_ 
```
enter-server meu-servidor
enter-server meu-servidor 1234
```

- <h3>leave-server</h3>
Este comando retira o usuário de um servidor e só pode ser executado por usuários dentro de um servidor.
_Exemplo:_ 
```
leave-server
```

- <h3>list-participants</h3>
Este comando lista as pessoas que participam do servidor e só pode ser executado por usuários dentro de um servidor.
_Exemplo:_ 
```
list-participants
```

- <h3>list-channels</h3>
Este comando exibe todos os canais do servidor, mostrando primeiro os nomes dos canais de texto, em
seguida os nomes dos canais de voz. Só pode ser executado por usuários dentro de um servidor.
_Exemplo:_ 
```
list-channels
```

- <h3>create-channel <__nome__> <__tipo__></h3>
Este comando permite criar um canal no servidor informando seu nome e seu tipo (voz ou texto) e só pode ser executado pelo dono do servidor.
_Exemplo:_ 
```
create-channel meu-primeiro-canal texto
```

- <h3>enter-channel <__nome__></h3>
Este comando permite entrar em um canal presente na lista de canais do servidor e só pode ser executado por usuários dentro de um servidor.
_Exemplo:_ 
```
enter-channel meu-primeiro-canal
```

- <h3>leave-channel</h3>
Este comando permite que o usuário saia de um canal e só pode ser executado por usuários dentro de um canal.
_Exemplo:_ 
```
leave-channel
```

- <h3>send-message <__mensagem__></h3>
Este comando permite enviar uma mensagem em um canal e só pode ser executado por usuários dentro de um canal.
_Exemplo:_ 
```
send-message Oi pessoal tudo bem?
```

- <h3>list-messages</h3>
Este comando lista todas as mensagens enviadas em um canal e só pode ser executado por usuários dentro de um canal.
_Exemplo:_ 
```
list-messages
```

## Limitações do Programa:
- Só é possível um usuário logado por vez;
- Os arquivos que armazenam os dados não está protegidos;
- Caso tais arquivos sejam corrompidos pelo usuário, o sistema não funcionará.
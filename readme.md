## CONTROLE DE TRÁFEGO AÉREO

Este projeto tem como objetivo desenvolver um sistema de controle de tráfego
aéreo utilizando uma lista de prioridades implementada como um heap
máximo. A estrutura heap será utilizada para gerenciar as prioridades das
aeronaves de acordo com critérios especı́ficos, permitindo a rápida identificação e remoção da aeronave de maior prioridade. Além disso, o sistema
permitirá a atualização das prioridades das aeronaves, possibilitando ajustes
dinâmicos conforme novas informações sejam inseridas.

**STATUS**: Em andamento

## Estrutura de diretórios

Este projeto contém a seguinte estrutura de diretórios:     

* src: Contém os arquivos de código-fonte em C. Aqui estão os principais módulos do programa:
  - `main.c`: Função principal que executa o programa e interage com o usuário.
  - `heaptree.c`: Implementação da  lista de prioridades com heap máximo, incluindo inserção, consulta, remoção e atualização de prioridade.
* include: Contém os arquivos de cabeçalho (.h) com as definições das funções e tipos usados no projeto.
  - `heaptree.h`: Definições de funções para manipulação da estrutura heap e estrutura `Aeronave`.
* data: Contém os arquivos CSV usados para carregar os dados dos voos.
  - `voos.csv`: arquivo com dados de voos.
* bin: Contém os arquivos executáveis gerados durante a compilação do projeto.
  - `main`: Executável principal do projeto.


## Arquivo Makefile 

O projeto usa um **Makefile** para facilitar a compilação e execução. Aqui estão os comandos principais disponíveis, utilize-os no diretório 
**../Gerenciador_De_Biblioteca**.

- **Compilar o programa**:
  `make`
- **Compilar e executar o programa**:
  `make run`
- **Limpar o diretório**:
  `make clean`

## Dependências
- **Compilador:** GCC
- **Make**: Para facilitar a compilação e execução do projeto.


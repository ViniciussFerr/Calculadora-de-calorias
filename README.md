Este projeto é uma Calculadora de Calorias desenvolvida em linguagem C. Ele permite que os usuários calculem suas necessidades calóricas diárias com base em informações pessoais, como peso, altura, idade, sexo e nível de atividade física. Além disso, o sistema oferece funcionalidades de login e cadastro para gerenciar os dados dos usuários.

Funcionalidades:

Cadastro e Login: 
Os usuários podem criar contas e fazer login para acessar suas informações personalizadas.
Cálculo de Calorias Basais: 
Calcula a taxa metabólica basal (TMB) com base nas informações fornecidas pelo usuário.
Cálculo de Gasto Total Diário : 
Estima o gasto total de calorias diárias considerando o nível de atividade física.
Armazenamento de Dados : 
As informações dos usuários são armazenadas em arquivos de texto (usuarios.txt e infos.txt) para persistência.
Interface Simples : 
Um menu interativo permite que os usuários naveguem pelas funcionalidades do sistema.
Estrutura do Projeto
O projeto está organizado da seguinte forma:

calculadora-calorias/

├── main.c 
# Código principal do programa
├── usuarios.txt
# Arquivo para armazenar dados de login dos usuários
├── infos.txt 
# Arquivo para armazenar informações de cálculos de calorias
├── README.md
# Documentação do projeto
└── Makefile 
# (Opcional) Para compilar o projeto facilmente

Como Executar o Projeto

Pré-requisitos
Compilador C : 
Certifique-se de ter um compilador C instalado (como GCC).
Sistema Operacional : 
Compatível com sistemas Linux, macOS e Windows (usando WSL ou MinGW).
Passos para Execução
Clone o Repositório :

git clone https://github.com/seu-usuario/calculadora-calorias.git 
cd calculadora-calorias

Compile o Código :
Use o GCC para compilar o programa:
gcc main.c -o calculadora-calorias

Execute o Programa :
Após a compilação, execute o programa gerado:
./calculadora-calorias

Interaja com o Sistema :
Siga as instruções no terminal para realizar o cadastro, login e calcular suas necessidades calóricas.
Exemplo de Uso

|-------------------------------|
|----CALCULADORA DE CALORIAS----|
|-------------------------------|

|-( 1 ) CADASTRO -- ( 2 ) LOGIN-|
|-( 3 ) SAIR-|
--> 1

|--CADASTRO--|
|--PARA FECHAR DIGITE 0--|
|--NOME--|
--> João

|--SENHA--|
--> senha123
Cadastro concluído!
Funcionalidades Futuras
Embora o projeto já seja funcional, há espaço para melhorias e novas funcionalidades:

Gerenciamento de Dieta : 
Permitir que os usuários registrem suas refeições diárias e acompanhem o consumo de calorias.
Relatórios Personalizados : 
Gerar gráficos ou relatórios com base nos dados armazenados.
Interface Gráfica : 
Implementar uma interface gráfica para facilitar a interação com o usuário.
Validação de Entrada : 
Melhorar a validação de entradas para evitar erros durante a execução.

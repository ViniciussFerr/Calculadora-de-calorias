[https://img.shields.io/badge/Status-Completo-green](https://img.shields.io/badge/Status-Completo-green)  [https://img.shields.io/badge/Linguagem-C-blue](https://img.shields.io/badge/Linguagem-C-blue)

## Visão Geral

Este projeto é uma Calculadora de Calorias desenvolvida em linguagem C que permite aos usuários calcular suas necessidades calóricas diárias com base em informações pessoais. O sistema inclui funcionalidades de autenticação e armazenamento persistente de dados.

## Funcionalidades Principais

✅  **Cadastro e Login de Usuários**  
✅  **Cálculo de Taxa Metabólica Basal (TMB)**  
✅  **Cálculo de Gasto Calórico Total**  
✅  **Armazenamento Persistente em Arquivos**  
✅  **Gerenciamento de Contas**  
✅  **Visualização de Histórico de Cálculos**

## Estrutura do Projeto

text

Copy

Download

calculadora-calorias/
├── Calculadora_de_calorias.c   # Código fonte principal
├── usuarios.txt                # Armazena credenciais dos usuários
├── infos.txt                   # Armazena dados de cálculos
└── README.md                   # Documentação do projeto

## Como Executar

### Pré-requisitos

-   Compilador C (GCC recomendado)
    
-   Sistema operacional compatível (Windows/Linux/macOS)
    

### Compilação e Execução

bash

Copy

Download

# Compilar o programa
gcc -Wall -Wextra -o calculadora Calculadora_de_calorias.c

# Executar o programa
./calculadora

## Funcionalidades Detalhadas

### 1. Autenticação de Usuários

-   Cadastro com nome de usuário e senha
    
-   Login com validação de credenciais
    
-   Armazenamento seguro em arquivo texto
    

### 2. Cálculos Nutricionais

-   **Taxa Metabólica Basal**: Calculada usando a equação de Mifflin-St Jeor
    
    -   Homens:  `TMB = (10 × peso) + (6,25 × altura) - (5 × idade) + 5`
        
    -   Mulheres:  `TMB = (10 × peso) + (6,25 × altura) - (5 × idade) - 161`
        
-   **Gasto Calórico Total**: Considera o nível de atividade física
    
    -   Sedentário: TMB × 1.2
        
    -   Levemente ativo: TMB × 1.375
        
    -   Moderadamente ativo: TMB × 1.55
        
    -   Muito ativo: TMB × 1.725
        
    -   Extremamente ativo: TMB × 1.9
        

### 3. Gerenciamento de Dados

-   Armazenamento em arquivos texto
    
-   Atualização de informações
    
-   Exclusão de contas
    

## Exemplo de Uso

text

Copy

Download

|----CALCULADORA DE CALORIAS----|


|-( 1 ) CADASTRO -- ( 2 ) LOGIN-|
|-( 3 ) SAIR-|
--> 1

|--CADASTRO--|
|--NOME--|
--> Ana

|--SENHA--| 
--> senha123
Cadastro concluído!

--> 2
|--LOGIN--|
|--NOME--|
--> Ana

|--SENHA--|
--> senha123
Login bem sucedido!

|----CALCULADORA DE CALORIAS----|

1. CALCULAR MACROS
2. GERENCIAR DIETA (não implementado)
3. VISUALIZAR HISTÓRICO
4. GERENCIAR CONTA
5. SAIR
--> 1

Digite seu sexo (m/f): f
Digite seu peso (kg): 60
Digite sua altura (cm): 165
Digite sua idade: 25

Nível de atividade:
[1] Sedentário
[2] Levemente ativo
[3] Moderadamente ativo
[4] Muito ativo
[5] Extremamente ativo
--> 3

Sua TMB: 1326 calorias
Seu gasto total diário: 2055 calorias
Dados salvos com sucesso!

## Melhorias Futuras

🔹 Implementar cálculo de macros (proteínas, carboidratos, gorduras)  
🔹 Adicionar sistema de acompanhamento de dieta diária  
🔹 Melhorar a interface com menus mais intuitivos  
🔹 Adicionar criptografia para armazenamento de senhas  

## Estrutura do Código

O programa utiliza:

-   Structs para organização de dados
    
-   Manipulação de arquivos para persistência
    
-   Listas encadeadas para gerenciamento temporário de dados
    
-   Validação de entrada do usuário

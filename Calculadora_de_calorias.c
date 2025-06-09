#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    char senha[20];
    int basal;
    int gastot;
    int prot;
    int carb;
} user;

typedef struct Node {
    char nome[50];
    int peso;
    int basal;
    int gastot;
    struct Node *prox;
} Node;

void calcular(user *u);
void calculadora_painel(user *u);
void login(user *u);
void cadastro(user *u);
void mostrar_cals(user *u);

Node* criar_no(char nome[], int peso, int basal, int gastot) {
    Node* novo = (Node*)malloc(sizeof(Node)); 
    strcpy(novo->nome, nome);                  
    novo->peso = peso;
    novo->basal = basal;
    novo->gastot = gastot;
    novo->prox = NULL;                         
    return novo;
}

void inserir(Node** inicio, Node* novo) {
    if (*inicio == NULL) {
        *inicio = novo;  
    } else {
        Node* temp = *inicio;
        while (temp->prox != NULL)
            temp = temp->prox;
        temp->prox = novo;  
    }
}

void mostrar_cals(user *u){
	FILE *arquivo = fopen("infos.txt", "r");
	char linha[100], nome[100], peso[100], basal[100], total[100];
	
	while(fgets(linha, sizeof(linha), arquivo)){
		if(sscanf(linha, "%[^;];%[^;];%[^;];%s", nome, peso, basal, total) = 1){
			if(strcmp(u->nome, nome) = 0)
				print("Suas informacoes: \n");
				print("Peso: %s\nBasal: %s\nGasto total: %s\n")
		}
		else{
			print("Informacoes nao encontradas...\nSaindo...\n");
			return;
		}
	}
}

void calcular(user *u) {
    FILE *arquivo = fopen("infos.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo nao encontrado, sera criado um novo.\n");
    }

    Node* lista = NULL;
    char linha[200], nome[50];
    int peso, basal, gastot;
    char op;

    if (arquivo) {
        while (fgets(linha, sizeof(linha), arquivo)) {
            if (sscanf(linha, "%[^;];%d;%d;%d", nome, &peso, &basal, &gastot) == 4) {
                if (strcmp(u->nome, nome) == 0) {
                    printf("Informacoes encontradas: Nome: %s | Peso: %d | Basal: %d | Gasto Total: %d\n", nome, peso, basal, gastot);
                    printf("Deseja sobrescrever os dados? (s/n): ");
                    scanf(" %c", &op);
                    getchar();
                    if (op != 's' && op != 'S') {
                        inserir(&lista, criar_no(nome, peso, basal, gastot));
                        fclose(arquivo);
                        printf("Dados mantidos.\n");
                        return;
                    }
                } else {
                    inserir(&lista, criar_no(nome, peso, basal, gastot));
                }
            }
        }
        fclose(arquivo);
    }

    int altura, idade, escolha;
    float faf;
    char sexo;

    do {
        printf("Digite seu sexo (m/f): ");
        scanf(" %c", &sexo);
    } while (sexo != 'm' && sexo != 'f');

    printf("Digite seu peso (kg): ");
    scanf("%d", &peso);
    printf("Digite sua altura (cm): ");
    scanf("%d", &altura);
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("\nAtividade fisica:\n");
    printf("[1] Sedentario\n[2] Levemente ativo\n[3] Moderadamente ativo\n[4] Muito ativo\n[5] Extremamente ativo\n");
    do {
        printf("--> ");
        scanf("%d", &escolha);
    } while (escolha < 1 || escolha > 5);

    switch (escolha) {
        case 1: faf = 1.2; break;
        case 2: faf = 1.375; break;
        case 3: faf = 1.55; break;
        case 4: faf = 1.725; break;
        case 5: faf = 1.9; break;
    }

    u->basal = (10 * peso) + (6.25 * altura) - (5 * idade);
    if (sexo == 'm') u->basal += 5;
    else u->basal -= 161;
    u->gastot = u->basal * faf;

    inserir(&lista, criar_no(u->nome, peso, u->basal, u->gastot));

    arquivo = fopen("infos.txt", "w");
    Node* temp = lista;
    while (temp) {
        fprintf(arquivo, "%s;%d;%d;%d\n", temp->nome, temp->peso, temp->basal, temp->gastot);
        Node* aux = temp;
        temp = temp->prox;
        free(aux);
    }

    fclose(arquivo);
    printf("Dados salvos com sucesso!\n");
}

void calculadora_painel(user *u) {
    int escolha, run = 0;
    
    while (run != 1)
    {
        printf("|-------------------------------|\n");
        printf("|----CALCULADORA DE CALORIAS----|\n");
        printf("|-------------------------------|\n\n");
        
        printf("ola %s!, o que voce deseja fazer?\n\n", u->nome);

        printf("|-( 1 ) CALCULAR MACROS-|\n");
        printf("|-( 2 ) GERENCIAR DIETA-|\n");
        printf("|-( 3 ) PRINTAR LOG DE CALORIAS-|\n");
        printf("|-( 4 ) GERENCIAR CONTA-|\n");
        printf("|-( 5 ) SAIR-|\n-->");

        scanf("%d", &escolha);

        if (escolha == 1)
        {
            calcular(u);
        }
        else if (escolha == 2)
        {
            printf("nao implementado...");
            return;
        }
        else if (escolha == 3)
        {
            printf("nao implementado...");
            return;
        }
        else if (escolha == 4)
        {
            printf("nao implementado...");
            return;
        }
        else if (escolha == 5)
        {
            run = 1;
        }
        else
        {
            printf("escolha invalida, voltando para tela inicial...");
            return;
        }    
    }
}

void cadastro(user *u){
    FILE *arquivo = fopen("usuarios.txt", "r+"); 
    if(arquivo == NULL){
        arquivo = fopen("usuarios.txt", "w+"); 
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo\n");
            return;
        }
    }

    char linha[100], nome[100], senha[100];

    getchar();
    printf("|--CADASTRO--|\n");
    printf("|--PARA FECHAR DIGITE 0--|\n");
    printf("|--NOME--|\n--> ");
    fgets(u->nome, sizeof(u->nome), stdin); 
    u->nome[strcspn(u->nome, "\n")] = '\0';
    if (strcmp(u->nome, "0") == 0) {
        printf("Saindo...\n");
        fclose(arquivo);
        return;
    }

    printf("\n|--SENHA--|--> ");
    scanf("%s", u->senha); 
    getchar();
    if (strcmp(u->senha, "0") == 0) {
        printf("Saindo...\n");
        fclose(arquivo);
        return;
    }

    rewind(arquivo);
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%[^;];%s", nome, senha) == 2) {
            if(strcmp(u->nome, nome) == 0){
                printf("Pessoa ja cadastrada!\n");
                fclose(arquivo);
                cadastro(u);
                return;
            }
        }
    }

    fseek(arquivo, 0, SEEK_END);
    fprintf(arquivo, "%s;%s\n", u->nome, u->senha);
    printf("Cadastro concluido!\n");
    fclose(arquivo);
}

void login(user *u){
    FILE *arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char linha[100], nome[50], senha[50], escolha;

    printf("|--LOGIN--|\n");
    printf("|--PARA FECHAR DIGITE 0--|\n");
    printf("|--NOME--|\n--> ");
    fgets(u->nome, sizeof(u->nome), stdin); 
    u->nome[strcspn(u->nome, "\n")] = '\0';
    if (strcmp(u->nome, "0") == 0) {
        printf("Saindo...\n");
        fclose(arquivo);
        return;
    }

    printf("\n|--SENHA--|\n--> ");
    scanf(" %s", u->senha);
    getchar();
    if (strcmp(u->senha, "0") == 0) {
        printf("Saindo...\n");
        fclose(arquivo);
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%[^;];%s", nome, senha) == 2) {
            if (strcmp(u->nome, nome) == 0 && strcmp(u->senha, senha) == 0) {
                printf("Login e senha corretos!\n");
                fclose(arquivo);
                calculadora_painel(u);
                return;
            }
        }
    }

    printf("Login ou senha incorretos ou cadastro não encontrado.\n");
    printf("Deseja fazer um cadastro? (s/n)\n--> ");
    scanf(" %c", &escolha);
    getchar();

    if (escolha == 's' || escolha == 'S') {
        fclose(arquivo);
        cadastro(u);
    } else {
        printf("Saindo do login...\n");
        fclose(arquivo);
    }
}

int main() {
    user u;
    int run = 0;

    while (run != 1) {
        int escolhalog;

        printf("|-------------------------------|\n");
        printf("|----CALCULADORA DE CALORIAS----|\n");
        printf("|-------------------------------|\n\n");

        printf("|-( 1 ) CADASTRO -- ( 2 ) LOGIN-|\n");
        printf("|-( 3 ) SAIR-|\n-->");
        scanf("%d", &escolhalog);
        getchar();

        if (escolhalog == 1) {
            cadastro(&u);
        } else if (escolhalog == 2) {
            login(&u);
        } else {
            run = 1;
        }
    }

    FILE *arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo sem conteudo!");
        return 1;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    fclose(arquivo);
    printf("Ate logo!");
    return 0;
}

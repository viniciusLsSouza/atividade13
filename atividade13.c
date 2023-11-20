#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USUARIOS 1000


struct Usuario {
    int id;
    char nome[50];
    char email[50];
    char sexo[15];
    char endereco[100];
    double altura;
    int vacina;
};


int gerarID() {
    return rand() % 100000 + 1;  
}


void cadastrarUsuario(struct Usuario usuarios[], int *totalUsuarios) {
    if (*totalUsuarios < MAX_USUARIOS) {
        struct Usuario novoUsuario;
        novoUsuario.id = gerarID();

        printf("Nome completo: ");
        scanf(" %[^\n]s", novoUsuario.nome);

        printf("Email: ");
        scanf(" %s", novoUsuario.email);

        printf("Sexo (Feminino/Masculino/Indiferente): ");
        scanf(" %s", novoUsuario.sexo);

        printf("Endereço: ");
        scanf(" %[^\n]s", novoUsuario.endereco);

        do {
            printf("Altura (entre 1 e 2 metros): ");
            scanf("%lf", &novoUsuario.altura);
        } while (novoUsuario.altura < 1 || novoUsuario.altura > 2);

        printf("Vacina (1 para sim, 0 para não): ");
        scanf("%d", &novoUsuario.vacina);

        usuarios[*totalUsuarios] = novoUsuario;
        (*totalUsuarios)++;
        printf("Usuário cadastrado com sucesso!\n");
    } else {
        printf("Limite de usuários atingido. Não é possível cadastrar mais usuários.\n");
    }
}


void editarUsuario(struct Usuario usuarios[], int totalUsuarios) {
    int idEditar;
    printf("Digite o ID do usuário que deseja editar: ");
    scanf("%d", &idEditar);

    for (int i = 0; i < totalUsuarios; ++i) {
        if (usuarios[i].id == idEditar) {
            printf("Novo nome completo: ");
            scanf(" %[^\n]s", usuarios[i].nome);

            printf("Novo email: ");
            scanf(" %s", usuarios[i].email);

            printf("Novo sexo (Feminino/Masculino/Indiferente): ");
            scanf(" %s", usuarios[i].sexo);

            printf("Novo endereço: ");
            scanf(" %[^\n]s", usuarios[i].endereco);

            do {
                printf("Nova altura (entre 1 e 2 metros): ");
                scanf("%lf", &usuarios[i].altura);
            } while (usuarios[i].altura < 1 || usuarios[i].altura > 2);

            printf("Nova vacina (1 para sim, 0 para não): ");
            scanf("%d", &usuarios[i].vacina);

            printf("Usuário editado com sucesso!\n");
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}


void excluirUsuario(struct Usuario usuarios[], int *totalUsuarios) {
    int idExcluir;
    printf("Digite o ID do usuário que deseja excluir: ");
    scanf("%d", &idExcluir);

    for (int i = 0; i < *totalUsuarios; ++i) {
        if (usuarios[i].id == idExcluir) {
          
            usuarios[i] = usuarios[(*totalUsuarios) - 1];
            (*totalUsuarios)--;
            printf("Usuário excluído com sucesso!\n");
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}


void buscarUsuarioPorEmail(struct Usuario usuarios[], int totalUsuarios) {
    char emailBusca[50];
    printf("Digite o email do usuário que deseja buscar: ");
    scanf(" %s", emailBusca);

    for (int i = 0; i < totalUsuarios; ++i) {
        if (strcmp(usuarios[i].email, emailBusca) == 0) {
            printf("\nUsuário encontrado:\n");
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereço: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Vacina: %s\n", (usuarios[i].vacina == 1) ? "Sim" : "Não");
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}


void imprimirUsuarios(struct Usuario usuarios[], int totalUsuarios) {
    printf("\nLista de Usuários Cadastrados:\n");
    for (int i = 0; i < totalUsuarios; ++i) {
        printf("\nID: %d\n", usuarios[i].id);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Email: %s\n", usuarios[i].email);
        printf("Sexo: %s\n", usuarios[i].sexo);
        printf("Endereço: %s\n", usuarios[i].endereco);
        printf("Altura: %.2lf\n", usuarios[i].altura);
        printf("Vacina: %s\n", (usuarios[i].vacina == 1) ? "Sim" : "Não");
        printf("---------------------------------\n");
    }
}

int main() {
    srand(time(NULL)); 

    struct Usuario usuarios[MAX_USUARIOS];
    int totalUsuarios = 0;
    char opcao;

    do {
        printf("\nMenu de Opções:\n");
        printf("1. Incluir usuário\n");
        printf("2. Editar usuário\n");
        printf("3. Excluir usuário\n");
        printf("4. Buscar usuário por email\n");
        printf("5. Imprimir todos os usuários\n");
        printf("0. Sair\n");
        printf("Escolha a opção desejada: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                cadastrarUsuario(usuarios, &totalUsuarios);
                break;
            case '2':
                editarUsuario(usuarios, totalUsuarios);
                break;
            case '3':
                excluirUsuario(usuarios, &totalUsuarios);
                break;
            case '4':
                buscarUsuarioPorEmail(usuarios, totalUsuarios);
                break;
            case '5':
                imprimirUsuarios(usuarios, totalUsuarios); 
                break;
            case '0':
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != '0');

    return 0;
}
#include <stdio.h>

//Grupo: Gabrielly Machado, Fernando Vindadé, Pedro Quadros Alves

// Aqui defini 4 constantes, uma para cada candidato
#define CANDIDATO1 "Ada"
#define CANDIDATO2 "Einstein"
#define CANDIDATO3 "Jobs"
#define CANDIDATO4 "Turing"

// Definições das variaveis usadas para contar os codigos e a % dos votos
// brancos
int contVotos1 = 0, contVotos2 = 0, contVotos3 = 0, contVotos4 = 0, nulos = 0,
    brancos = 0;
float brancosp;

/* Aqui criei uma função para a votacao, dependendo da opcao que o usuário
 * escolher ele vai adicionar 1 voto para o candidato ou para a opcão nula ou
 * para o branco caso ele nao digite um numero invalido nenhum voto é
 * contabilizado*/
void votacao() {
  int opcao;
  printf("\n\n--- Escolha seu Candidato ---\n\n");
  printf("\n1 - %s", CANDIDATO1);
  printf("\n2 - %s", CANDIDATO2);
  printf("\n3 - %s", CANDIDATO3);
  printf("\n4 - %s", CANDIDATO4);
  printf("\n5 - %s", "Nulo");
  printf("\n6 - %s", "Branco");

  printf("\n\nDigite sua escolha (1 - 6)\n");
  scanf("%d", &opcao);

  switch (opcao) {
  case 1:
    contVotos1++;
    break;
  case 2:
    contVotos2++;
    break;
  case 3:
    contVotos3++;
    break;
  case 4:
    contVotos4++;
    break;
  case 5:
    nulos++;
    break;
  case 6:
    brancos++;
    break;
  default:
    printf("\nEscolha Invalida");
    getchar();
  }
  printf("\ Voto computado");
}

/* Aqui eu criei uma função para mostrar a contagem dos votos*/
void contagemVotos() {
  printf("\n\n--- Contagem de Votos ---");
  printf("\n%s - %d", CANDIDATO1, contVotos1);
  printf("\n%s - %d", CANDIDATO2, contVotos2);
  printf("\n%s - %d", CANDIDATO3, contVotos3);
  printf("\n%s - %d", CANDIDATO4, contVotos4);
  printf("\n%s - %d", "Votos Nulos", nulos);
  printf("\n%s - %d", "Votos em Branco", brancos);
}

/*Essa função serve para comparar a contagem dos votos de cada candidato e assim
 * dizer qual que esta na liderança*/
void lideranca() {
  printf("\n--- Candidato que esta na frente ---\n");
  if (contVotos1 > contVotos2 && contVotos1 > contVotos3 &&
      contVotos1 > contVotos4) {
    printf("(%s)", CANDIDATO1);
  } else if (contVotos2 > contVotos1 && contVotos2 > contVotos3 &&
             contVotos2 > contVotos4) {
    printf("(%s)", CANDIDATO2);
  } else if (contVotos3 > contVotos1 && contVotos3 > contVotos2 &&
             contVotos3 > contVotos4) {
    printf("(%s)", CANDIDATO3);
  } else if (contVotos4 > contVotos1 && contVotos4 > contVotos2 &&
             contVotos4 > contVotos3) {
    printf("(%s)", CANDIDATO4);
  } else {
    printf("Nao temos uma vitoria definida");
  }
}

/*Aqui criei uma função para calcular a porcentagem de votos brancos FUNCIONANDO
 * TOP*/
void porcentagemBrancos() {
  int total;

  total = contVotos1 + contVotos2 + contVotos3 + contVotos4 + nulos + brancos;
  brancosp = (100 * brancos) / total;
  printf("\n\nA porcentagem de votos brancos: %0.0f%%", brancosp);
}

/* e por fim aqui temos o main com o menu principal do programa*/
int main() {
  int escolha;

  while (escolha != 0) {
    printf("\n\n--- Bem Vindo ao Menu da Eleicao! ---\n");
    printf("\nOpcoes");
    printf("\n1 - Votar");
    printf("\n2 - Contagem de Votos");
    printf("\n3 - Candidato na Lideranca");
    printf("\n4 - Porcentagem de Votos em Branco");
    printf("\n5 - Total de votos Nulos");
    printf("\n0 - Sai\n");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
      votacao();
      break;
    case 2:
      contagemVotos();
      break;
    case 3:
      lideranca();
      break;
    case 4:
      porcentagemBrancos();
      break;
    case 5:
      printf("Total de votos nulos: %d", nulos);
      break;
    case 0:
      printf("Fechando votacao");
      break;
    default:
      printf("Opcao invalida");
      break;
    }
  }
}

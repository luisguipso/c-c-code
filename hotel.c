#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct quarto_t {
	int id;
	int numero;
	double preco;
	bool hospedado;
} hotel_t;

typedef struct cliente_t {
	int id;
	double consumo;
	char nome[50];
	char cpf[11];
	char rg[15];
} cliente_t;

typedef struct itens_consumo_t {
	int id, quantidade, quarto_id, hospedagem_id;
	double valor;
} itens_consumo_t;

typedef struct hospedagem_t {
	int id, cliente_id;
	char checking[10];
	char checkout[10];
	double valor_total;
}

void escrever_arquivo(char *nome_arquivo){
  FILE *fp;
  livro_t livro;

  fp = fopen(nome_arquivo, "rb+"); //parametro que define ler e escrever nao funciona se o arquivo nao existir

//se arquivo for falso
  if(!fp){
    fp = fopen(nome_arquivo, "w");//parametro que define escrita, funciona se nao existir o arquivo

    if(!fp){
      printf("Não foi possivel abril o arquivo: %s\n", nome_arquivo);
      return;
    }
  }
  fseek(fp,0,SEEK_END);
  //definindo valores
  livro.id = 0;
  strcpy(livro.nome, "Harry Potter");
  strcpy(livro.autor, "J.K.Rowling");

  fwrite(&livro, sizeof(livro_t),1,fp);

  livro.id = 1;
  strcpy(livro.nome, "One Piece");
  strcpy(livro.autor, "Eichiiro Oda");
  //escrevendo
  fwrite(&livro, sizeof(livro_t),1,fp);//(end memoria, tamanho do tipo, numero de elementos, ponteiro)
  //se fosse um array de livros não passaria o endereço e sim a variavel, pois o array já é um ponteiro
  // o numero 1 mudaria pro tamanho do array

  fclose(fp);
}

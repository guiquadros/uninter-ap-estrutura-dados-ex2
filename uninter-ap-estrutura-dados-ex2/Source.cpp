/*
* AP Estrutura de Dados - Exercicio 2 - Busca de um Aluno da Uninter a partir do RU informado
* Autor: Guilherme Quadros da Silva (RU = 3282910)
* Implementacao utilizando Arvore Binaria de Busca/Binary Search Tree (BST)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estrutura representando cada nodo da BST
struct UninterStudentNode
{
    char name[50] = "";
    char email[50] = "";
    int RU = 0;
    UninterStudentNode* left = NULL;
    UninterStudentNode* right = NULL;
} *Root;

void generate_students_records();
void insert_student(char name[], char email[], int RU);

int main()
{
    // chama rotina para gerar os dadso dos alunos da arvore
    generate_students_records();

    printf("Hello World!\n");
    system("pause");

    return 0;
}

void generate_students_records()
{
    // 1
    char name[50] = "Guilherme Quadros da Silva";
    char email[50] = "guiquadros35@gmail.com";
    int RU = 3282910;
    insert_student(name, email, RU);

    // 2
    strcpy_s(name, "Pafuncio da Silva");
    strcpy_s(email, "pafuncio.silva@gmail.com");
    RU = 1234567;
    insert_student(name, email, RU);

    // 3
    strcpy_s(name, "Neymar da Silva Jr.");
    strcpy_s(email, "menino-ney@gmail.com");
    RU = 8462537;
    insert_student(name, email, RU);

    // 4
    strcpy_s(name, "Kleitin Souza");
    strcpy_s(email, "kleitin-souza@yahoo.com.br");
    RU = 9452745;
    insert_student(name, email, RU);
}

void insert_student(char name[], char email[], int RU)
{
    // aloca memoria para inserir um novo aluno na arvore
    UninterStudentNode* new_student = (UninterStudentNode*)malloc(sizeof(UninterStudentNode));

    // preenche o nodo com os dados do aluno
    strcpy_s(new_student->name, name);
    strcpy_s(new_student->email, email);
    new_student->RU = RU;

    // arvore esta vazia
    if (Root == NULL)
    {
        Root = new_student;
        return;
    }
}

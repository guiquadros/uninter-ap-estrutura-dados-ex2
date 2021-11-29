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

void generate_students_records_for_BST();
void insert_student(const char* name, const char* email, int RU);

int main()
{
    // chama rotina para gerar os dados dos alunos da arvore
    generate_students_records_for_BST();

    printf("Hello World!\n");
    system("pause");

    return 0;
}

void generate_students_records_for_BST()
{
    // 1 - root
    insert_student("Guilherme Quadros da Silva", 
        "guiquadros35@gmail.com", 
        3282910);

    // 2
    insert_student("Pafuncio da Silva", 
        "pafuncio.silva@gmail.com", 
        1234567);

    // 3
    insert_student("Neymar da Silva Jr.", 
        "menino-ney@gmail.com", 
        5462537);

    // 4
    insert_student("Kleitin Souza", 
        "kleitin-souza@yahoo.com.br", 
        2452745);

    // 5
    insert_student("Beltrano da Cunha",
        "beltrano-cunha@outlook.com",
        3342745);

    // 6
    insert_student("Ronaldo Careca",
        "ronaldo_sem-cabelo@outlook.com",
        1724681);

    // 7
    insert_student("Natsuki Subaru",
        "subaru-dono@gmail.com",
        3856457);

    // 8
    insert_student("Uzumaki Boruto",
        "uzumaki.boruton-kun@konohagakure.com",
        4532758);

    // 9
    insert_student("Uzumaki Naruto",
        "hokage7th@konohagakure.com",
        2548365);

    // 10
    insert_student("Miranha da Marvel",
        "peter.parker@marvel.com",
        1364537);

    // 11
    insert_student("Tony Stark",
        "iron-tony@marvel.com",
        4321543);

    // 12
    insert_student("ET Bilu",
        "busque-conhecimento@gmail.com",
        1351947);

    // 13
    insert_student("ET Bileu",
        "busque-mais-conhecimento@gmail.com",
        4638563);

    // 14
    insert_student("ET Joao",
        "procura-no-google@gmail.com",
        1346373);

    // 15
    insert_student("Pata",
        "patap@gmail.com",
        1456376);

    // 16
    insert_student("Peta",
        "petap@gmail.com",
        2345678);

    // 18
    insert_student("Pita",
        "pitap@gmail.com",
        3465735);

    // 18
    insert_student("Pota",
        "potap@gmail.com",
        3465735);

    // 19
    insert_student("Maria",
        "mariap@gmail.com",
        2424699);

    // 20
    insert_student("Ryu",
        "da-hadouken@capcom.com",
        3457812);
}

void insert_student(const char* name, const char* email, int RU)
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

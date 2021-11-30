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
    struct UninterStudentNode *left, *right;
};

// ponteiro para raiz da BST
UninterStudentNode *Root_ptr = NULL;

void draw_menu();
int read_int_input();
void clear_keyboard_buffer();
void input_RU_search();
void insert_student(const char* name, const char* email, int RU);
void insert_student(UninterStudentNode* searching_node_ptr, UninterStudentNode* new_student_ptr);
void generate_students_records_for_BST();

int main()
{
    // chama rotina para gerar os dados dos alunos da arvore
    generate_students_records_for_BST();

    int option = -1;

    do
    {
        // desenha o menu
        draw_menu();

        // le a opcao que o usuario selecionou
        option = read_int_input();

        // limpa a tela apos o usuario selecionar a opcao para destacar a saida
        system("cls");

        // decide a acao com base na opcao selecionada
        switch (option)
        {
            // procura por um aluno
        case 1:
            input_RU_search();
            system("pause");
            break;

            // sai do programa
        case 2:
            printf("O programa sera encerrado!\n\n");
            break;

            // usuario digitou uma opacao invalida
        default:
            printf("OPCAO INVALIDA! Pressione uma tecla para reiniciar o menu.\n\n");
            system("pause");
            break;
        }

    } while (option != 2); // o menu e desenhado ate o usuario decidir fechar informando a opcao '2'

    system("pause");

    return 0;
}

void draw_menu()
{
    // limpa a tela
    system("cls");

    // opcoes do menu
    printf("MENU:\n");
    printf("1 - Procurar aluno pelo RU.\n");
    printf("2 - Fechar o programa\n");
    printf("\n");
    printf("Selecione uma opcao: ");
}

int read_int_input()
{
    int value;

    // le a opcao como um numero inteiro
    scanf_s("%d", &value);

    // limpa o buffer do teclado para evitar problemas na leitura do input
    clear_keyboard_buffer();

    return value;
}

void clear_keyboard_buffer()
{
    char c;

    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void input_RU_search()
{
    int RU_search = 0;
    printf("Informe o RU do aluno a ser buscado: ");
    RU_search = read_int_input();

    // TODO: search for this RU
}

void insert_student(const char* name, const char* email, int RU)
{
    // aloca memoria para inserir um novo aluno na arvore
    UninterStudentNode* new_student_ptr = (UninterStudentNode*)malloc(sizeof(UninterStudentNode));

    // preenche o nodo com os dados do aluno
    strcpy_s(new_student_ptr->name, name);
    strcpy_s(new_student_ptr->email, email);
    new_student_ptr->RU = RU;

    // insercao e sempre como folha, portanto o novo nodo nao vai ter filhos
    new_student_ptr->left = NULL;
    new_student_ptr->right = NULL;

    // arvore esta vazia, entao o novo element se torna a raiz
    if (!Root_ptr)
    {
        Root_ptr = new_student_ptr;
        return;
    }

    // insere passando o root como elemento por onde inicia a pesquisa da posicao a ser inserida na BST 
    insert_student(Root_ptr, new_student_ptr);
}

/// <summary>
/// Insere na BST procurando nodo livre adequado utilizando recursao.
/// </summary>
/// <param name="searching_node_ptr">Ponteiro para o nodo a ser pesquisado nessa chamada.</param>
/// <param name="new_student_ptr">Ponteiro para dados a serem inseridos.</param>
void insert_student(UninterStudentNode* searching_node_ptr, UninterStudentNode* new_student_ptr)
{
    // se valor do RU a ser inserido MENOR que o do nodo pesquisado atual, entao anda para ESQUERDA
    if (new_student_ptr->RU < searching_node_ptr->RU)
    {
        // se o nodo da ESQUERDA esta vazio entao ele aponta para o novo registro
        if (!searching_node_ptr->left)
        {
            searching_node_ptr->left = new_student_ptr;

            // novo elemento foi inserido na BST, entao ENCERRA a pesquisa
            return;
        }

        // o elemento do lado ESQUERDO do nodo pesquisado JA ESTA PREENCHIDO, 
        //entao continua a pesquisa a partir dele com uma chamada recursiva
        insert_student(searching_node_ptr->left, new_student_ptr);
        return;
    }

    // se valor do RU a ser inserido MAIOR que o do nodo pesquisado atual, entao anda para DIREITA
    if (new_student_ptr->RU > searching_node_ptr->RU)
    {
        // se o nodo da DIREITA esta vazio ele aponta para o novo registro
        if (!searching_node_ptr->right)
        {
            searching_node_ptr->right = new_student_ptr;

            // novo elemento foi inserido na BST, entao ENCERRA a pesquisa
            return;
        }

        // o elemento do lado DIREITO di nodo pesquisado JA ESTA PREENCHIDO, 
        //entao continua a pesquisa a partir dele com uma chamada recursiva
        insert_student(searching_node_ptr->right, new_student_ptr);
        return;
    }

    // Tratamento de erro para caso tente-se inserir 2 alunos com o mesmo RU
    printf("O RU '%d' do aluno '%s' ('%s') que esta sendo inserido nao e menor nem maior que nenhum outro RU!\n", 
        new_student_ptr->RU,
        new_student_ptr->name,
        new_student_ptr->email);
    printf("Por tanto, ELE JA EXISTE. O dado nao sera inserido na BST. \n"); 
    printf("Pressione qualquer tecla para continuae a execucao do programa.\n\n");

    system("pause");
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

    // 17
    insert_student("Pita",
        "pitap@gmail.com",
        6669997);

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

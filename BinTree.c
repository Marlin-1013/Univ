#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Folder  //트리노드 데이터
{
    char* name;
    int size;
}Element;

typedef struct BTrNode //트리구조 생성
{
    Element data;
    struct BTrNode* left;
    struct BTrNode* right;    
}TNode;

TNode* Queue[10];       //레벨 순회를 위한 큐 생성

void EnQueue(TNode* n) //큐 삽입
{
    int i;
    while (1)
    {
        if(Queue[i] != NULL) i++;
        else
        {
            Queue[i] = n;
            break;
        }
    }    
}

TNode* root = NULL;     //루트노드 포인터변수

void init_tree() {root = NULL;} //초기화

int is_empty()              //공백 확인
{
    if(root == NULL) return 1;
    else return 0;
}

int count_node(TNode* n)        //노드 갯수확인
{
    if(n == NULL) return 0;
    return 1 + count_node(n->left) + count_node(n->right);
}

TNode* creat_tree(char* name, int size, TNode* l, TNode* r) //노드 생성
{
    Element val;
    val.name = name;
    val.size = size;
    TNode* n = (TNode*)malloc(sizeof(TNode));
    n->data = val;
    n->left = l;
    n->right = r;
    return n;
} 

void level_order()           //레벨 순회로 배열에 저장
{
    if(is_empty() == 1) printf("데이터 없음\n");
    else
    {
        EnQueue(root);
        for (int i = 0; i < count_node(root); i++)
        {
            TNode* x = Queue[i];
            EnQueue(x->left);
            EnQueue(x->right);
        }       
    }
}

TNode* search_node(char* f)      //name데이터로 노드 탐색
{
    TNode* s;
    if(is_empty() == 1) printf("데이터 없음\n");
    else
    {
        for (int i = 0; i < count_node(root); i++)
        {
            if(Queue[i]->data.name == f)
            {
                s = Queue[i];
                break;
            } 
        }
        return s;
    }
}

int calc_size(TNode* n)         //자신을 포함한 하위노드의 size 합산
{
    if (n == NULL) return 0;
    return n->data.size + calc_size(n->left) + calc_size(n->right);   
}

int main()
{
    TNode *a, *b, *c, *d, *e, *f, *g, *h;       //트리노드 데이터 생성/삽입
    h = creat_tree("외국", 700, NULL, NULL);
    g = creat_tree("한국", 400, NULL, NULL);
    f = creat_tree("동영상", 500, NULL, NULL);
    e = creat_tree("사진", 150, NULL, NULL);
    d = creat_tree("클래식", 300, NULL, NULL);
    c = creat_tree("POP", 0, g, h);
    b = creat_tree("그림", 70, e, f);
    a = creat_tree("음악", 100, c, d);
    root = creat_tree("내 파일", 50, a, b);
    level_order();

    printf("%s 파일의 용량은 %dKB이다\n", c->data.name, calc_size(search_node("POP")));
    printf("%s 파일의 용량은 %dKB이다\n", f->data.name, calc_size(search_node("동영상")));  
    printf("내 파일의 전체 용량은 %dKB이다.\n", calc_size(root));
    printf("%s 파일의 하위 파일수는 %d개이다\n", a->data.name, count_node(search_node("음악"))-1);
    printf("내 파일의 하위 파일수는 %d개이다.\n", count_node(root)-1);
}
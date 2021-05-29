#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Folder  //Ʈ����� ������
{
    char* name;
    int size;
}Element;

typedef struct BTrNode //Ʈ������ ����
{
    Element data;
    struct BTrNode* left;
    struct BTrNode* right;    
}TNode;

TNode* Queue[10];       //���� ��ȸ�� ���� ť ����

void EnQueue(TNode* n) //ť ����
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

TNode* root = NULL;     //��Ʈ��� �����ͺ���

void init_tree() {root = NULL;} //�ʱ�ȭ

int is_empty()              //���� Ȯ��
{
    if(root == NULL) return 1;
    else return 0;
}

int count_node(TNode* n)        //��� ����Ȯ��
{
    if(n == NULL) return 0;
    return 1 + count_node(n->left) + count_node(n->right);
}

TNode* creat_tree(char* name, int size, TNode* l, TNode* r) //��� ����
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

void level_order()           //���� ��ȸ�� �迭�� ����
{
    if(is_empty() == 1) printf("������ ����\n");
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

TNode* search_node(char* f)      //name�����ͷ� ��� Ž��
{
    TNode* s;
    if(is_empty() == 1) printf("������ ����\n");
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

int calc_size(TNode* n)         //�ڽ��� ������ ��������� size �ջ�
{
    if (n == NULL) return 0;
    return n->data.size + calc_size(n->left) + calc_size(n->right);   
}

int main()
{
    TNode *a, *b, *c, *d, *e, *f, *g, *h;       //Ʈ����� ������ ����/����
    h = creat_tree("�ܱ�", 700, NULL, NULL);
    g = creat_tree("�ѱ�", 400, NULL, NULL);
    f = creat_tree("������", 500, NULL, NULL);
    e = creat_tree("����", 150, NULL, NULL);
    d = creat_tree("Ŭ����", 300, NULL, NULL);
    c = creat_tree("POP", 0, g, h);
    b = creat_tree("�׸�", 70, e, f);
    a = creat_tree("����", 100, c, d);
    root = creat_tree("�� ����", 50, a, b);
    level_order();

    printf("%s ������ �뷮�� %dKB�̴�\n", c->data.name, calc_size(search_node("POP")));
    printf("%s ������ �뷮�� %dKB�̴�\n", f->data.name, calc_size(search_node("������")));  
    printf("�� ������ ��ü �뷮�� %dKB�̴�.\n", calc_size(root));
    printf("%s ������ ���� ���ϼ��� %d���̴�\n", a->data.name, count_node(search_node("����"))-1);
    printf("�� ������ ���� ���ϼ��� %d���̴�.\n", count_node(root)-1);
}
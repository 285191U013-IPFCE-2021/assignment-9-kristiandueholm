#include <stdbool.h>		/* bool, true, false */

typedef struct node
{
  int num;
  bool visited;
  struct node *lchild;
  struct node *rchild;
} node;

// Stack holding "item"
typedef struct stack
{
  struct item *head;
} stack;

// item holding pointer to node and to next item
typedef struct item
{
  struct node *node;
  struct item *next;
} item;

node *make_node(int num, node * left, node * right);

void print_node(node * p);

void print_tree(node * p, int depth);

stack *recursiveDFS(node *root, stack *s);

void DFT(node * root);

void push(stack *s, node * node);

bool isEmpty(stack *s);

void print_stack(item *element);

void free_nodes(node *root);

void free_stack(stack *s);

void free_items(item *element);
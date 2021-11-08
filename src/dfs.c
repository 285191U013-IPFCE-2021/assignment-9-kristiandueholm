/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "..\include\dfs.h"

// Main DFT function, calling the recursive below
void DFT (node * root)
{
  stack *s = malloc(sizeof(stack));
  s->head = NULL;

  s = recursiveDFS(root, s);
  
  print_stack(s->head);

  free_stack(s);

  return;
}

// Recursive function for pushing the node DFS style into stack
stack *recursiveDFS(node *root, stack *s)
{

  push(s, root);

  if (root->lchild)
  {
    recursiveDFS(root->lchild, s);
  }

  if (root->rchild)
  {
    recursiveDFS(root->rchild, s);
  }

  return s;
}

// Pushing to stack "oldschool style"
void push (stack *s, node * node)
{
  item *element = malloc(sizeof(item));
  if (isEmpty(s))
  {
    element->next = NULL;
  }
  else
  {
    element->next = s->head;
  }
  element->node = node;
  s->head = element;

  return;
}

bool isEmpty (stack *s)
{
  if (s->head == NULL)
  {
    return true;
  }
  
  return false;
}

// Prints stack recursively
// Nodes are pushed in reverse order,
// So I print in reverse order
void print_stack (item *element)
{
  // Base case
  if (element->next == NULL)
  {
    printf("%d ", element->node->num);
  }

  // Recursive case, go to deepest element
  else
  {
    print_stack(element->next);
    printf("%d ", element->node->num);
  }

  return;
}

void free_nodes(node *root)
{
  if (root->lchild)
  {
    free_nodes(root->lchild);
  }

  if (root->rchild)
  {
    free_nodes(root->rchild);
  }

  free(root);

  return;
}

void free_stack(stack *s)
{
  free_items(s->head);
  free(s);
  
  return;
}

void free_items(item *element)
{
  if (element->next == NULL)
  {
    free(element);
  }

  else
  {
    free_items(element->next);
    free(element);
  }

  return;
}

void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

void print_node (node * p)
{

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}

node *make_node (int num, node * left, node * right)
{
  node *p = malloc(sizeof(node));
  p->visited  = NULL;
  p->num      = num;
  p->lchild   = left;
  p->rchild   = right;

  return p;
}
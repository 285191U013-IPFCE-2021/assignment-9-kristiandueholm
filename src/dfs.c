/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "..\include\dfs.h"


void DFT (node * root)
{
  if (root->visited == 0)
  {
    // push(root);
  }

  if (root->lchild)
  {
    DFT(root->lchild);
  }

  if (root->rchild)
  {
    DFT(root->rchild);
  }
  
  return;
  
  
  
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

void free_node (node * p)
{
  free(p);
  return;
}


void print_node (node * p)
{

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
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

stack *push (stack * topp, node * node)
{
  stack *p = malloc(sizeof(stack));
  p->node = node;

  if (isEmpty(topp))
  {
    p->next = NULL;
  }
  else
  {
    p->next = topp;
  }
  
  return p;
}

bool isEmpty (stack * topp)
{
  if (topp == NULL)
  {
    return true;
  }
  
  return false;
}

node *top (stack * topp)
{
	return topp->node;
}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack * topp)
{
	return 0;
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}

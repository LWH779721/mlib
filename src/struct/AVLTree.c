#include <stdio.h>
#include <stdlib.h>

#include "mlanguage.h"
#include "struct/AVLTree.h"

int Height(AVL *node)
{
    if (NULL == node)
    {
        return -1;
    }
    
    return node->height;
}

static int Max(int a, int b)
{
    return (a >= b)?a:b;
}

static AVL *LL(AVL *root)
{
    AVL *node = root->left;
    
    root->left = node->right; 
    root->height = Max(Height(root->left), Height(root->right)) + 1;
    
    node->right = root;
    node->height = Max(Height(node->left), Height(node->right)) + 1;
    
    return node;
}

static AVL *LR(AVL *root)
{
    AVL *node = root->left;
    
    root->left = node->right; 
    node->right = node->right->left;
    root->left->left = node;
    
    node->height = Max(Height(node->left), Height(node->right)) + 1;
    root->left->height = Max(Height(root->left->left), Height(root->left->right)) + 1;
    root->height = Max(Height(root->left), Height(root->right)) + 1;
    
    node = LL(root);
    return node;
}

static AVL *RR(AVL *root)
{
    AVL *node = root->right;
    
    root->right = node->left; 
    root->height = Max(Height(root->left), Height(root->right)) + 1;
    
    node->left = root;
    node->height = Max(Height(node->left), Height(node->right)) + 1;
    return node;
}

static AVL *RL(AVL *root)
{
    AVL *node = root->right;
    
    root->right = node->left; 
    node->left = node->left->right;
    root->right->right = node;
    
    node->height = Max(Height(node->left), Height(node->right)) + 1;
    root->left->height = Max(Height(root->left->left), Height(root->left->right)) + 1;
    root->height = Max(Height(root->left), Height(root->right)) + 1;
    
    node = RR(root); 
    return node;
}

static AVL * find_max(AVL *root)
{
	AVL *node = root;
	
	while (node->right)
	{
		node = node->right;
	}
	
	return node;
}

static AVL * find_min(AVL *root)
{
	AVL *node = root;
	
	while (node->left)
	{
		node = node->left;
	}
	
	return node;
}

AVL *delete(AVL **root, int id)
{
	AVL *item = NULL, *exChange = NULL;
    int lh, rh;

	if (NULL == (*root))
    {
		
    }
    elif (id == (*root)->id)
    { 
        if ((*root)->right == NULL)
		{
			item = *root;
			*root = (*root)->left;
		}
		elif ((*root)->left == NULL)
		{
			item = *root;
			*root = (*root)->right;
		}
		else
		{
			lh = Height((*root)->left);
			rh = Height((*root)->right);	
			
			if (lh >= rh)
			{
				item = find_max((*root)->left);
				item = delete(&((*root)->left), item->id);
				item->left = (*root)->left;
				item->right = (*root)->right;
				
				exChange = item;
				item = *root;
				*root = exChange;
			}
			else
			{
				item = find_min((*root)->right);
				item = delete(&((*root)->right), (*root)->id);
			
				item->left = (*root)->left;
				item->right = (*root)->right;
				
				exChange = item;
				item = *root;
				*root = exChange;
			}
			
			(*root)->height = Max(Height((*root)->left), Height((*root)->right)) + 1; 
		}
    }
    elif (id > (*root)->id)
    {
        item = delete(&((*root)->right), id); 
        lh = Height((*root)->left);
        rh = Height((*root)->right);

        if ((rh - lh) >= 2)
        {
            lh = Height((*root)->right->left);
            rh = Height((*root)->right->right);    
            if (lh >= rh)
            {
                *root = RL(*root);    
            }
            else
            {
                *root = RR(*root); 
            }    
        }    
        
        (*root)->height = Max(Height((*root)->left), Height((*root)->right)) + 1; 
    }
    elif (id < (*root)->id)
    {
        item = delete(&((*root)->left), id);
        lh = Height((*root)->left);
        rh = Height((*root)->right);

        if ((lh - rh) >= 2)
        {
            lh = Height((*root)->left->left);
            rh = Height((*root)->left->right);    
            if (lh >= rh)
            {
                *root = LL(*root);    
            }
            else
            {
                *root = LR(*root); 
            }    
        }
        
        (*root)->height = Max(Height((*root)->left), Height((*root)->right)) + 1;
    }
    
    return item;   	
}

AVL *find_or_insert(AVL **root, int id)
{
    AVL *item = NULL;
    int lh, rh;
        
    if (NULL == (*root))
    {
        if (NULL == (item = calloc(sizeof(AVL), 1)))
        {
            printf("calloc fail\n");
            return NULL;         
        }
        
        item->id = id;
        
        *root = item;
    }
    elif (id == (*root)->id)
    { 
        item = *root;  
    }
    elif (id > (*root)->id)
    {
        item = find_or_insert(&((*root)->right), id); 
        lh = Height((*root)->left);
        rh = Height((*root)->right);

        if ((rh - lh) >= 2)
        {
            lh = Height((*root)->right->left);
            rh = Height((*root)->right->right);    
            if (lh >= rh)
            {
                *root = RL(*root);    
            }
            else
            {
                *root = RR(*root); 
            }    
        }    
        
        (*root)->height = Max(Height((*root)->left), Height((*root)->right)) + 1; 
    }
    elif (id < (*root)->id)
    {
        item = find_or_insert(&((*root)->left), id);
        lh = Height((*root)->left);
        rh = Height((*root)->right);

        if ((lh - rh) >= 2)
        {
            lh = Height((*root)->left->left);
            rh = Height((*root)->left->right);    
            if (lh >= rh)
            {
                *root = LL(*root);    
            }
            else
            {
                *root = LR(*root); 
            }    
        }
        
        (*root)->height = Max(Height((*root)->left), Height((*root)->right)) + 1;
    }
    
    return item;   
}

AVL *find(AVL *root, int id)
{
	AVL *item = NULL;
	
	if (NULL == root)
    {
		return NULL;
    }
	
	if (root->id == id)
	{
		item = root;
	}
	elif (root->id > id)
	{
		item = find(root->left, id);
	}
	elif (root->id < id)
	{
		item = find(root->right, id);
	}
	
	return item;
}

//	前序遍历
int preOrderTraversal(AVL *root)
{
    if (root)
    {
		printf("id: %d\n", root->id);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right); 
    }
     
    return 0;
}

//	中序遍历
int midOrderTraversal(AVL *root)
{
    if (root)
    {
        midOrderTraversal(root->left); 
		printf("id: %d\n", root->id);
        midOrderTraversal(root->right); 
    }
     
    return 0;
}

//	后序遍历
int postOrderTraversal(AVL *root)
{
    if (root)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right); 
		printf("id: %d\n", root->id);
    }
     
    return 0;
}

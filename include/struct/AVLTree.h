#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#ifdef __cplusplus
extern "C"{
#endif

typedef struct AVLTreeNode
{
    unsigned int id;            	/*�ڵ��id,���������*/
    int height;                 	/*�ڵ�ĸ߶�*/
    void *data;						/*�洢����*/
	
    struct AVLTreeNode *left;       /*ָ��������*/
    struct AVLTreeNode *right;      /*ָ��������*/
} AVL;

/*
 *  ���ң��Ҳ��������
 */
extern AVL *find_or_insert(AVL **root, int id);  
extern AVL *find(AVL *root, int id);
extern AVL *delete(AVL **root, int id);
/*
*  ������������������� ��С����ģ��Ǳ��������ʵ�����õ�
*/
extern int midOrderTraversal(AVL *root); //	�������
extern int preOrderTraversal(AVL *root); //	ǰ�����
extern int postOrderTraversal(AVL *root); // �������

#ifdef __cplusplus
}
#endif
#endif

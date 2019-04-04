#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#ifdef __cplusplus
extern "C"{
#endif

typedef struct AVLTreeNode
{
    unsigned int id;            	/*节点的id,用来排序的*/
    int height;                 	/*节点的高度*/
    void *data;						/*存储数据*/
	
    struct AVLTreeNode *left;       /*指向左子树*/
    struct AVLTreeNode *right;      /*指向右子树*/
} AVL;

/*
 *  查找，找不到则插入
 */
extern AVL *find_or_insert(AVL **root, int id);  
extern AVL *find(AVL *root, int id);
extern AVL *delete(AVL **root, int id);
/*
*  中序遍历出来的数据是 从小到大的，是遍历中最具实际作用的
*/
extern int midOrderTraversal(AVL *root); //	中序遍历
extern int preOrderTraversal(AVL *root); //	前序遍历
extern int postOrderTraversal(AVL *root); // 后序遍历

#ifdef __cplusplus
}
#endif
#endif

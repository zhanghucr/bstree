#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

typedef int bs_type_t;

typedef struct bstree
{
    bs_type_t  key;     //关键字(键值)
    struct bstree  *left;    //左孩子
    struct bstree  *right;   //右孩子
    struct bstree  *parent;  //父结点
} bs_node_t, *bs_tree_t;

int bstree_node_number(bs_tree_t tree);
int bstree_leaf_number(bs_tree_t tree);
int bstree_depth(bs_tree_t tree);
void bstree_traverse_preorder(bs_tree_t tree);
void bstree_traverse_inorder(bs_tree_t tree);
void bstree_traverse_postorder(bs_tree_t tree);
void bstree_traverse_breadth(bs_tree_t tree);
bool bstree_is_complete(bs_tree_t tree);
bool bstree_is_full(bs_tree_t tree);
bs_node_t* bstree_search(bs_tree_t tree, bs_type_t key);
bs_node_t* bstree_search_iterative(bs_tree_t tree, bs_type_t key);
bs_node_t* bstree_minimum(bs_tree_t tree);
bs_node_t* bstree_maximum(bs_tree_t tree);
bs_node_t* bstree_successor(bs_node_t *x);
bs_node_t* bstree_predecessor(bs_node_t *x);
bs_node_t* bstree_insert(bs_tree_t tree, bs_type_t key);
bs_node_t* bstree_delete(bs_tree_t tree, bs_type_t key);
void bstree_destroy(bs_tree_t tree);
void bstree_show(bs_tree_t tree);

#endif  /* __BINARY_SEARCH_TREE_H__ */


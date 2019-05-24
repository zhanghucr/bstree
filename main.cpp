/**
 * C ”Ô—‘: ∂˛≤Ê≤È’“ ˜
 */
#include "bstree.h"

#define MAX_SIZE             32
#define ARRAY_SIZE(a)        ((sizeof(a)) / (sizeof(a[0])))

static int data[MAX_SIZE] = {0};  /* 7, 5, 4, 3, 2, 6 */

/* main */
int main(int argc, char *argv[])
{
    int  count = 0;
    bs_tree_t root = NULL;
    bs_node_t *node;
    bs_node_t *successor;
    bs_node_t *predecessor;

    if (argc != 2)
    {
        printf("CMD <count>.\n");
        printf("Example.\n");
        printf("CMD 6\n");
        printf("Then input data like 7, 5, 4, 3, 2, 6\n");
        return -1;
    }

    count = atoi(argv[1]);
    if (count > MAX_SIZE)
    {
        count = MAX_SIZE;
    }
   
    for (int i = 0; i < count; i++)
    {
        printf("data[%d]: ", i);
        scanf("%d", &data[i]);
        root = bstree_insert(root, data[i]);
        printf("%d insert into tree.\n", data[i]);
    }

    printf("\n== pre-order: ");
    bstree_traverse_preorder(root);

    printf("\n== mid-order: ");
    bstree_traverse_inorder(root);

    printf("\n== post-order: ");
    bstree_traverse_postorder(root);

    printf("\n== breadth: ");
    bstree_traverse_breadth(root);

    printf("\n== max: %d\n", bstree_minimum(root)->key);
    printf("\n== min: %d\n", bstree_maximum(root)->key);
    printf("\n== tree info: \n");
    bstree_show(root);

    int j = 0;
    printf("\n== find successor data index: ");
    scanf("%d", &j);
    if (j < 0 || j >= count)
    {
        j = 0;
    }
    
    node = bstree_search(root, data[j]);
    successor = bstree_successor(node);
    if (successor != NULL)
    {
        printf("data[%d] %d successor: %d\n", j, data[j], successor->key);
    }
    else
    {
        printf("data[%d] %d successor: null\n", j, data[j]);
    }

    int k = 0;
    printf("\n== find predecessor data index: ");
    scanf("%d", &k);
    if (k < 0 || k >= count)
    {
        k = 0;
    }
    
    node = bstree_search(root, data[k]);
    predecessor = bstree_predecessor(node);
    if (predecessor != NULL)
    {
        printf("data[%d] %d predecessor: %d\n", k, data[k], predecessor->key);
    }
    else
    {
        printf("data[%d] %d predecessor: null\n", k, data[k]);
    }

    int i = 0;
    printf("\n== delete node data index: ");
    scanf("%d", &i);
    if (i < 0 || i >= count)
    {
        i = 0;
    }
    root = bstree_delete(root, data[i]);
    printf("delete node %d\n", data[i]);

    printf("\n== tree info: \n");
    bstree_show(root);

    printf("\n== mid-order: ");
    bstree_traverse_inorder(root);
    printf("\n");

    // destory tree
    bstree_destroy(root);
}


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

    int key = 0;
    printf("\n== find successor key: ");
    scanf("%d", &key);
    
    node = bstree_search(root, key);
    successor = bstree_successor(node);
    if (successor != NULL)
    {
        printf("%d successor: %d\n", key, successor->key);
    }
    else
    {
        printf("%d successor: null\n", key);
    }

    printf("\n== find predecessor key: ");
    scanf("%d", &key);
    
    node = bstree_search(root, key);
    predecessor = bstree_predecessor(node);
    if (predecessor != NULL)
    {
        printf("%d predecessor: %d\n", key, predecessor->key);
    }
    else
    {
        printf("%d predecessor: null\n", key);
    }

    printf("\n== delete node key: ");
    scanf("%d", &key);
    root = bstree_delete(root, key);
    printf("delete node %d\n", key);

    printf("\n== tree info: \n");
    bstree_show(root);

    printf("\n== mid-order: ");
    bstree_traverse_inorder(root);
    printf("\n");

    // destory tree
    bstree_destroy(root);
    return 0;
}


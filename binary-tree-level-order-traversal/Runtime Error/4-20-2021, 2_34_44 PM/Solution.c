// https://leetcode.com/problems/binary-tree-level-order-traversal

struct queue {
    struct TreeNode *tn;
    int layer;
    struct qnode *next;
};

void enqueue(struct queue **q, struct TreeNode *tn, int layer) {
    struct queue *new;
    struct queue *p;
    
    new = malloc(sizeof(struct queue));
    new->tn = tn;
    new->layer = layer;
    new->next = 0;
    
    p = (*q);
    if (p == 0)
        *q = new;
    else {
        while (p->next)
            p = p->next;
    
        p->next = new;
    }
}

struct TreeNode *dequeue(struct queue **q, int *layer) {
    struct queue *tmp;
    struct TreeNode *tn;
    
    tmp = *q;
    tn = tmp->tn;
    *layer = tmp->layer;
    *q = tmp->next;
    free(tmp);
    
    return tn;
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    struct queue *q = 0;
    struct TreeNode *p;
    int **trav = 0;
    int layer = 0;
    
    *columnSizes = 0;
    *returnSize = 0;
    if (root == 0)
        return 0;
    
    enqueue(&q, root, layer);
    while (q) {
        p = dequeue(&q, &layer);
        if (p->left)
            enqueue(&q, p->left, layer + 1);
        if (p->right)
            enqueue(&q, p->right, layer + 1);
        
        if (layer == *returnSize) {
            trav = realloc(trav, sizeof(int *) * (*returnSize + 1));
            trav[layer] = 0;
            *columnSizes = realloc(*columnSizes, sizeof(int) * (*returnSize + 1));
            (*columnSizes)[layer] = 0;
            (*returnSize)++;
        }
        trav[layer] = realloc(trav[layer], sizeof(int) * ((*columnSizes)[layer] + 1));
        trav[layer][(*columnSizes)[layer]] = p->val;
        (*columnSizes)[layer] += 1;
    }
    
    return trav;
}
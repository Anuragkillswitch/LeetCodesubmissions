// https://leetcode.com/problems/even-odd-tree

typedef struct queue_node_tag {
   void *p;
   struct queue_node_tag *next;
}queue_node_t;

typedef struct queue_tag {
   queue_node_t *head;
   queue_node_t *tail;
   int count;
}queue_t;

static inline void init_queue(queue_t *q)
{
   q->head = NULL;
   q->tail = NULL;
   q->count = 0;
}

static inline void en_queue(queue_t *q, void *p)
{
   queue_node_t *t = malloc(sizeof(queue_node_t));
   
   t->p = p;
   t->next = NULL;   
   
   if(q->head == NULL) 
      q->head = t;

   if(q->tail == NULL){
      q->tail = t;
   }else {
      q->tail->next = t;
      q->tail = t;      
   }
   q->count++;
}

static inline void* de_queue(queue_t *q)
{
   void *ret;
   queue_node_t *t = q->head;

   if(q->head == NULL)
      return NULL;

   ret = q->head->p;
   q->head = q->head->next;
   if(q->head == NULL)
      q->tail = NULL;
   
   free(t);
   q->count--;
   
   return ret;
}

static inline int count_queue(queue_t *q) {
   return q->count;
}
static inline bool is_empty_queue(queue_t *q) {
   return q->count == 0;
}

/* QUEUE IMPLEMENTATION  END*/



bool isEvenOddTree(struct TreeNode* root){
   queue_t q;
   init_queue(&q);

   en_queue(&q, root);

   int level = 0;
   
   while(!is_empty_queue(&q)) {
      int size = count_queue(&q);
      int cur = 0, prev;
      if(level % 2) 
         prev = INT_MAX;
      else
         prev = 0;
      for(int i = 0; i < size; i++) {
         struct TreeNode *node;
         node = de_queue(&q);
         cur = node->val;
         
         if(node->left != NULL)
            en_queue(&q, node->left);
         if(node->right != NULL)
            en_queue(&q, node->right);
         
         if(level % 2) {
            if(cur % 2)
               return false;
            if(prev <= cur)
               return false;
         }else {
            if(cur % 2 == 0)
               return false;
            if(prev >= cur)
               return false;
         }
         prev = cur;
      }
      level++;
   }
   return true;
   
}
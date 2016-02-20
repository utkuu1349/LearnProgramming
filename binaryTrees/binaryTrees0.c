// example code which explains binary trees

void destroy_tree (struct node *leaf);
void insert (int key, struct node **leaf);
struct node *search (int key, struct node *leaf);


int main () {
    struct node
        {
            int key_value;
            struct node *left;
            struct node *right;
        };
    struct node *root = 0;
}


void destroy_tree(struct node *leaf) {
    if (leaf != 0) {
        destroy_tree (leaf -> left);
        destroy_tree (leaf -> right);
        free(leaf);        
    }
}

void insert (int key, struct node **leaf) {
    if (*leaf == 0) {
        *leaf == (struct node*) malloc(sizeof(struct node));
        (*leaf) -> key_value = key;
        /* initialize the children to null */
        (*leaf) -> left = 0;
        (*leaf) -> right = 0;
    }
    else if (key < (*leaf) -> key_value) {
        insert (key, &(*leaf) -> left);
    }
    else {
        insert (key, &((*leaf -> right)));
    }
}

struct node *search(int key, struct node *leaf) {
    if (leaf != 0) {
        if (key == leaf -> key_value) {
            return leaf;
        }
        else if (key < leaf -> key_value) {
            return search (key, leaf -> left);
        }
        else {
            return search (key, leaf -> right);
        }
    }
    else return 0;
}

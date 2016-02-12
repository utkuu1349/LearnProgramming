#include <stdio.h>

struct xamp1 {
    int x;
};

int main () {
    struct xamp1 structure;
    struct xamp1 *ptr;

    structure.x = 12;
    ptr = &structure; /* Yes, you need the & when dealing with 
                        structures and using pointes to them*/
    printf("%d\n", ptr->x); /* The -> acts somewhat like the * does when
                            it is used with pointers. It says, get whatever
                            is at that memory address Not "get what that 
                            memory addres is" */
}

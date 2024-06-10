#include <stdio.h>

struct Test {
    int x;
    int y;
    int z;
};

int main() {

    struct Test myTest[2];
    myTest[0].x = 1;
    myTest[0].y = 2;
    myTest[0].z = 3;

    struct Test *ptr;
    ptr = myTest;

    printf("first: %d %d %d\n", ptr->x, ptr->y, ptr->z );
    ptr++;
    printf("last null? %d\n", (ptr == NULL));
   return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("\r\nbinclude converts binary files to C/C++ arrays\r\n\tusage:\tbinclude [filename] [array name] [optional column width] > target.c\r\n\r\n");
        return 0;
    }
    int width = argc > 3 ? atoi(argv[3]) : 8;
    int c;
    FILE *file = fopen(argv[1], "r");
    if (file) {
        int col=-1;
        int count=0;
        printf("\r\n\r\nconst unsigned char %s[] = {\r\n", argv[2]);

        printf("    ");
        while ((c = getc(file)) != EOF) {
            if (count != 0) {
                printf(",");
            }
            count++;
            if (col++ > width-2) {
                printf("\r\n    ");
                col = 0;
            }
            printf("0x%02x", c & 0xff);
        }
        printf("\r\n};\r\n\r\n\r\n");
    }
    return 0;
}

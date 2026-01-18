#include <stdio.h>
#include "instructions.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: dump_code file\n");
        return 1;
    }
    FILE *f = fopen(argv[1], "rb");
    if (!f) {
        perror("fopen");
        return 2;
    }
    CodeBlock* cb = createCodeBlock(1000);
    loadCode(cb, f);
    printCodeBlock(cb);
    freeCodeBlock(cb);
    fclose(f);
    return 0;
}

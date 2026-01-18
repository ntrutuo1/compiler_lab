#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: bin_compare file1 file2\n");
        return 1;
    }
    FILE *f1 = fopen(argv[1], "rb");
    FILE *f2 = fopen(argv[2], "rb");
    if (!f1 || !f2) {
        printf("Error opening files.\n");
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return 2;
    }
    int result = 0;
    int pos = 0;
    while (1) {
        int c1 = fgetc(f1);
        int c2 = fgetc(f2);
        if (c1 == EOF && c2 == EOF) break;
        if (c1 != c2) {
            printf("Difference at byte %d: %02X vs %02X\n", pos, c1, c2);
            result = 1;
            break;
        }
        pos++;
    }
    fclose(f1);
    fclose(f2);
    if (result == 0) {
        printf("Files are identical.\n");
    }
    return result;
}

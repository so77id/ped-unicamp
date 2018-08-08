#include <stdio.h>

#define MAX_SIZE 100

void cat(char *dst, char *src) {
    int i, j;

    for (i = 0; dst[i] != '\0'; i++);

    for(j = 0; src[j] != '\0'; j++, i++) {
        dst[i] = src[j];
    }
    dst[i] = '\0';
}

int cmp(char *str1, char *str2) {
    int i;
    int ret;

    ret = 1;
    i = 0;
    while(1) {
        if (str1[i] != str2[i]){
            ret = 0;
            break;
        }
        if (str1[i] == '\0' || str2[i] == '\0') break;

        i++;
    }

    return ret;
}

void sub(char *dst, int start, int end) {
    int i,j;
    for (i = start, j = 0; i < (start+end); i++, j++) {
        dst[j] = dst[i];
    }
    dst[j] = '\0';
}

int main() {
    char cmd[4], buffer[MAX_SIZE], str[MAX_SIZE];
    int start, end;

    buffer[0] = '\0';
    scanf( "%s" , cmd );
    while(cmp(cmd, "END") == 0) {
        if (cmp(cmd, "CAT") == 1) {
            scanf("%s", str);
            cat(buffer, str);
            printf("%s\n", buffer);
        } else if (cmp(cmd, "CMP") == 1) {
            scanf("%s", str);

            if (cmp(buffer, str) == 1) printf("IGUAL\n");
            else printf("DIFERENTE\n");

        } else if (cmp(cmd, "SUB") == 1) {
            scanf("%d %d", &start, &end);
            sub(buffer, start, end);
            printf("%s\n", buffer);
        }

        scanf("%s", cmd);
    }

    return 0;
}

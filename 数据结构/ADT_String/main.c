#include <stdio.h>
#include <stdlib.h>
#include "String.h"

int main() {
    StringPtr str = make_empty_string();
    StringPtr p = make_empty_string();
    char input_str[100], input_p[100];
    scanf("%s", input_str);
    scanf("%s", input_p);

    copy_string_from_char(str, input_str);
    char *temp = to_char_array(str);
    printf("%s\n", temp);
    free(temp);
    copy_string_from_char(p, input_p);
    temp = to_char_array(p);
    printf("%s\n", temp);

    printf("delete_string: ");
    delete_string(str, 1, 3);
    print_string(str);

   /* int *index = index_of_KMP(str, p);
    for (int i = 0;; ++i) {
        if (index[i] == -1) {
            break;
        }
        printf("%d ", index[i]);
    }
    free(index);
    printf("\n");*/
    /*int *index = index_of(str, p);
    for (int i = 0;; ++i) {
        if (index[i] == -1) {
            break;
        }
        printf("%d ", index[i]);
    }
    free(index);*/

    free(temp);
    destroy_string(str);
    destroy_string(p);
    return 0;
}

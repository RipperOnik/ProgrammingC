#include <stdlib.h>
#include "contract.h"
#include "contract.c"



int main(int argc, char const *argv[])
{
    printf("Введите количество договоров: ");
    size_t size;
    scanf("%zu",&size);
    printf("\n");
    Contract* list = (Contract*)calloc(size, sizeof(Contract));
    input_data(list, size);
    search_best(list, size);
    char buffer [MAX_STRING_LENGTH];
    for (size_t i = 0; i < (size < 3 ? size:3); i++){
        getContractInfo(&list[i],buffer);
        printf("%s\n", buffer);
    }
    free(list);
    return 0;
}

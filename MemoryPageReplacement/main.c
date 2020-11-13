#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

#include "Structs/page.h"
#include "Structs/read_model.h"
#include "Structs/write_model.h"

#include "Utils/utils.h"
#include "Utils/reader.h"
#include "Utils/writer.h"

#include "Algorithms/fifo.h"
#include "Algorithms/opt.h"
#include "Algorithms/algorithms.h"

int main(int argc, const char * argv[]) {
    char file_path[128];
    int menu = 0;
    
    printf("Digite o caminho do diretório do arquivo de entrada: \n");
    printf("> ");
    scanf("%s", file_path);
    
    printf("Selecione uma das opções de algoritmos:");
    printf("\n    1. FIFO");
    printf("\n    2. OPT\n");
    printf("> ");
    scanf("%i", &menu);

    ReadModel data = read_file(file_path);
    WriteModel wm = algorithm(data, menu);
    
    write_file(wm, file_path);
    
    printf("\nArquivo saida.txt escrito no caminho: %s\n", file_path);
    
    return 0;
}

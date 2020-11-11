void write_file(WriteModel write_data, char file_path[]) {
    FILE* file;
    char file_name[128];
    strcpy(file_name, file_path);
    strcat(file_name, "/saida.txt");
    
    file = fopen(file_name, "w");
    
    int memory_progress[write_data.page_count][write_data.memory_length];
    int transposed_memory_progress[write_data.memory_length][write_data.page_count];

    clear_matrix(write_data.page_count, write_data.memory_length, memory_progress);

    for (int i = 0; i < write_data.page_count; i++) {
        for (int j = 0; j < write_data.memory_length; j++) {
            Page current_element = write_data.pages[i][j];

            if (current_element.hit) {
                for (int k = 0; k < write_data.memory_length; k++) {
                    memory_progress[i][k] = -1;
                }
            }

            if (current_element.end) {
                break;
            }

            memory_progress[i][j] = current_element.value;
        }
    }

    transpose_matrix(write_data.page_count, write_data.memory_length, memory_progress, transposed_memory_progress);

    fputs("EVOLUÇÃO", file);
    fputs("\n", file);

    for (int i = 0; i < write_data.memory_length; i++) {
        for (int j = 0; j < write_data.page_count; j++) {
            int current_value = transposed_memory_progress[i][j];

            if (current_value == 0) {
                fputs("  ", file);
                continue;
            }
            if (current_value == -1) {
                fputs("_ ", file);
                continue;
            }

            fprintf(file, "%i ", current_value);
        }
        fprintf(file, "\n");
    }
    
    fputs("\n", file);
    fputs("ACERTOS", file);
    fputs("\n", file);
    fprintf(file, "%i", write_data.hits);
    
    fputs("\n", file);
    fputs("ERROS", file);
    fputs("\n", file);
    fprintf(file, "%i", write_data.misses);
    
    fputs("\n", file);
    fputs("TOTAL REQUISIÇÕES", file);
    fputs("\n", file);
    fprintf(file, "%i", write_data.total_requests);
    
    fputs("\n", file);
    fputs("TAXA DE ERRO", file);
    fputs("\n", file);
    fprintf(file, "%.2f", write_data.error_rate);
    
    fclose(file);
}

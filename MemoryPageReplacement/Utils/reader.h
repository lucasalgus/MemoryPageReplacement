ReadModel read_file(char file_path[]) {
    ReadModel file_data = {
        .error = true,
        .memory_length = 0,
        .page_count = 0,
    };

    FILE* file;
    char file_name[128];
    strcpy(file_name, file_path);
    strcat(file_name, "/entrada.txt");

    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Erro ao abrir arquivo: %s não encontrado.", file_name);
        return file_data;
    }

    char current_line[MAX_LINE_SIZE];

    char pages_string[MAX_LINE_SIZE];
    char memory_length_string[MAX_LINE_SIZE];
    
    for (int i = 0; i < 3; i++) {
        fgets(current_line, MAX_LINE_SIZE, file);
        
        switch (i) {
            case 0:
                strcpy(pages_string, current_line);
                break;
            case 2:
                strcpy(memory_length_string, current_line);
            default:
                break;
        }
    }
    
    int memory_length = atoi(memory_length_string);
    int page_count = count_numbers(pages_string);
    Page* pages = string_to_page_array(pages_string);
    
    file_data.error = false;
    file_data.memory_length = memory_length;
    file_data.page_count = page_count;
    file_data.pages = pages;
    
    fclose(file);
    
    return file_data;
}


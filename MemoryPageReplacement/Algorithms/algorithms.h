void fifo(int memory_length, Page* memory_pages, Page* pages, int i) {
    int memory_pages_position = 0;
    int lowest_position = 100;

    for(int k = 0; k < memory_length; k++) {
        if(memory_pages[k].arrival_position < lowest_position) {
            lowest_position = memory_pages[k].arrival_position;
            memory_pages_position = k;
        }
    }
    memory_pages[memory_pages_position] = pages[i];
    lowest_position = 100;
}


void algorithm(int memory_length, int input_number_length, Page *pages, int menu) {
    Page memory_pages[memory_length];
    int hit = 0;

    for(int i = 0; i < memory_length; i++) {
        memory_pages[i].arrival_position = i;
        memory_pages[i].value = 0;
    }

    for(int i = 0; i < input_number_length; i++) {
        for(int j = 0; j < memory_length; j++) {
            printf("pages = %d - ", pages[i].value);
            printf("memory = %d \n", memory_pages[j].value);

            if(pages[i].value == memory_pages[j].value) {
                hit++;
                break;
            }
            if (memory_pages[j].value == 0) {
                memory_pages[j] = pages[i];
                break;
            }
            if (j == (memory_length - 1) && (menu == 0)) {
                fifo(memory_length, memory_pages, pages, i);
                break;
            } else if (j == (memory_length - 1)){
//                opt();
                break;
            }
        }
    }

    for(int l = 0; l < memory_length; l++){
        printf("%d \n", memory_pages[l].value);
    }

    printf("HIT = %d", hit);
}

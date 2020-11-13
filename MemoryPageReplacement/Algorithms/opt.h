void opt(int memory_length, Page* memory_pages, Page* pages, int i, int input_number_length) {
    bool exist_zero = false;
    int biggest_position = -1;
    int lowest_position_zero = 100;
    int memory_pages_position = 0;

    for(int k = 0; k < memory_length; k++){
        for(int w = i + 1; w < input_number_length; w++){
            if(memory_pages[k].value == pages[w].value){
                if((!exist_zero) && (pages[w].arrival_position > biggest_position)){
                    biggest_position = pages[w].arrival_position;
                    memory_pages_position = k;
                }
                break;
            }

            if(w + 1 == input_number_length){
                if(memory_pages[k].arrival_position < lowest_position_zero){
                    lowest_position_zero = memory_pages[k].arrival_position;
                    memory_pages_position = k;
                }
            }
        }
    }
    memory_pages[memory_pages_position] = pages[i];

    biggest_position = -1;
    lowest_position_zero = -1;
}

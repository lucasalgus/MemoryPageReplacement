void fifo(Page* state, Page page, int memory_size) {
    int lowest_arrival_position = 100;
    int lowest_arrival_position_index = 0;
    
    for (int i = 0; i < memory_size; i++) {
        Page current_page = state[i];
        if (current_page.arrival_position < lowest_arrival_position) {
            lowest_arrival_position = current_page.arrival_position;
            lowest_arrival_position_index = i;
        }
    }
    
    state[lowest_arrival_position_index] = page;
}

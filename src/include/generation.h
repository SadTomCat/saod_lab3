#ifndef GENERATION_H_
#define GENERATION_H_

#define RAW 20
#define COL 20

void graph_init(uint8_t graph[][COL]);
void graph_generation(uint8_t graph[][COL]);
void graph_print(uint8_t graph[][COL]);
void num_nil(uint8_t graph[][COL]);

#endif //GENERATION_H_
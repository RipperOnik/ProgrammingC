//
// Created by ripperonik on 09.10.2020.
//

#ifndef DZ1_CONTRACT_H
#define DZ1_CONTRACT_H


#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include <string.h>


typedef struct tm Time;
typedef struct Contract Contract;
#define MAX_STRING_LENGTH 200

struct Contract {
    char kind[20];
    unsigned int sum;
    char counterparty[20];
    bool presence_extra_agreement;
    Time date_conclusion;
};

void getContractInfo(Contract *contract, char* buffer);

void search_best(Contract *list, size_t n);

void input_data(Contract *list, size_t size);

#endif //DZ1_CONTRACT_H

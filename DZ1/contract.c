//
// Created by ripperonik on 09.10.2020.
//
#include "contract.h"


void get_contract_info(const Contract* const contract, char* buffer){
    if (contract != NULL && buffer != NULL) {
        mktime(&contract->date_conclusion);
        sprintf(buffer,
                "Вид: %s, Сумма: %u, Контрагент: %s, Наличие дополнительных соглашений: %s, Дата заключения: %s\n",
                contract->kind, contract->sum, contract->counterparty,
                (contract->presence_extra_agreement) ? "Да" : "Нет",
                asctime(&contract->date_conclusion));
    }
}


void search_best(Contract* const list,const size_t n){
    for (size_t i = 0; i < n; i++){
        size_t max_index = i;
        for (size_t j = i+1; j < n; j++){
            if (list[max_index].sum < list[j].sum){
                max_index = j;
            }
        }
        Contract tmp = list[i];
        list[i] = list[max_index];
        list[max_index] = tmp;
    }
}

void input_data(Contract* const list, const size_t size){

    for (size_t i = 0; i < size; i++){
        printf("Введите вид договора: ");
        char kind[20];
        scanf("%19s",kind);
        printf("\n");
        printf("Введите сумму договора: ");
        unsigned int sum;
        scanf("%u", &sum);
        printf("\n");
        printf("Введите наименование контрагента: ");
        char counterparty[20];
        scanf("%19s", counterparty);
        printf("\n");
        printf("Есть дополнительные соглашения? 1 - да, 0 - нет. Ваш ответ: ");
        unsigned int tmp;
        scanf("%u",&tmp);
        bool presence_extra_agreement = (tmp==1) ? true:false;
        printf("\n");
        printf("Введите дату заключения в формате {sec(0-59):minute(0-59):hour(0-23):day(1-31):month(0-11):year since 1900}\n");
        int sec,min,hour,day,month,year;
        scanf("%d %d %d %d %d %d", &sec,&min,&hour,&day,&month,&year);
        Time date = {sec,min,hour,day,month,year};
        strcpy(list[i].kind, kind);
        list[i].sum = sum;
        strcpy(list[i].counterparty, counterparty);
        list[i].presence_extra_agreement = presence_extra_agreement;
        list[i].date_conclusion = date;
    }
}

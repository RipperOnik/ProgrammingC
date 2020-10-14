//
// Created by ripperonik on 08.10.2020.
//
extern "C" {
#include "../contract.h"
#include "../contract.c"
}
#include "gtest/gtest.h"

TEST(SuiteName, TestName) {
    Contract  contract;
    strncpy(contract.kind, "Гражданский", 20);
    strncpy(contract.counterparty, "ООО Марина", 20);
    contract.date_conclusion = {0,0,0,1,1,120};
    contract.presence_extra_agreement = true;
    contract.sum = 1000;
    mktime(&contract.date_conclusion);
    EXPECT_STREQ(asctime(&contract.date_conclusion), "Sat Feb  1 00:00:00 2020\n");
}

TEST(SuiteName, TestName1) {
    Contract contracts[3] = {{"a",1,"a",1,
                             {0,0,0,1,1,120}},
                            {"b",2,"b",1,
                             {0,0,0,1,1,120}},
                            {"c",3,"c",1,
                             {0,0,0,1,1,120}}};
    search_best(contracts,3);
    char str[4];
    sprintf(str,"%x%x%x",contracts[0].sum,contracts[1].sum,contracts[2].sum);
    EXPECT_STREQ(str,"321");
}

TEST(SuiteName, TestName2) {
    Contract contract = {"a",1,"a",1,
                         {0,0,0,1,1,120}};
    char buffer [MAX_STRING_LENGTH];
    getContractInfo(&contract,buffer);
    EXPECT_TRUE(buffer);
}

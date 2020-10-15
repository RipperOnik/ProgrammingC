//
// Created by ripperonik on 08.10.2020.
//
extern "C" {
#include "../contract.h"
}
#include "gtest/gtest.h"

class Test_contract: public ::testing::Test{
protected:
protected:
    virtual void TearDown() {
        if (list!= nullptr) {
            free(list);
        }
    }

    virtual void SetUp() {
        if (list!= nullptr) {
            for (int i = 0; i < size; i++) {
                list[i].sum = i;
                list[i].date_conclusion = {i + 1, i + 1, i + 1, i + 1, i + 1, 120};
                strncpy(list[i].kind, "Гражданский", 20);
                strncpy(list[i].counterparty, "ООО Марина", 20);
                list[i].presence_extra_agreement = true;
            }
        }
    }

    size_t size = 4;
    Contract* list = (Contract*)calloc(size, sizeof(Contract));

};

TEST_F(Test_contract, TestName) {
    EXPECT_STREQ(asctime(&list[0].date_conclusion), "Sun Feb  1 01:01:01 2020\n");
    EXPECT_STREQ(asctime(&list[1].date_conclusion), "Sun Mar  2 02:02:02 2020\n");
    EXPECT_STREQ(asctime(&list[2].date_conclusion), "Sun Apr  3 03:03:03 2020\n");
    EXPECT_STREQ(asctime(&list[3].date_conclusion), "Sun May  4 04:04:04 2020\n");
}


TEST_F(Test_contract, TestName4){
    search_best(list,4);
    char str[4];
    sprintf(str,"%x%x%x",list[0].sum,list[1].sum,list[2].sum);
    EXPECT_STREQ(str,"321");
}
TEST_F(Test_contract, TestName5){
    search_best(list,2);
    char str[3];
    sprintf(str,"%x%x",list[0].sum,list[1].sum);
    EXPECT_STREQ(str,"10");
}


TEST(SuiteName, TestName2) {
    Contract contract = {"a",1,"a",1,
                         {0,0,0,1,1,120}};
    char buffer [MAX_STRING_LENGTH];
    get_contract_info(&contract, buffer);
    EXPECT_TRUE(buffer);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

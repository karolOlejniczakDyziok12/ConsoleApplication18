#pragma once
#include "gtest\gtest.h"
#include "Client.h"
#include "BankCard.h"

class clientTest : public testing::Test
{
protected:
	virtual void SetUp();

	std::shared_ptr<Client> client;
};

void clientTest::SetUp()
{
	client = std::make_shared<Client>(Human( "Karol", "Olejniczak", 783458 ));
}

TEST_F(clientTest, shouldSetCreditCard)
{
//	Account account{ 500 };
	client->setBankCard(BankCard( 342342, "Karol", "Olejniczak", "Visa", "10/22", "debit card" ), "password");
}
TEST_F(clientTest, shouldGetPesel)
{
	EXPECT_EQ(783458, client->getPesel());
}
TEST_F(clientTest, shouldGetHuman)
{
	std::string name{ client->getName() };
	std::string surname{ client->getSurname() };
	int pesel{ client->getPesel() };
	EXPECT_EQ("Karol", name);
	EXPECT_EQ("Olejniczak", surname);
	EXPECT_EQ(783458, pesel);
}
TEST_F(clientTest, schouldGetEmptyPassword)
{
	EXPECT_EQ("", client->getPassword());
}
TEST_F(clientTest, schouldGetPassword)
{
	client->setBankCard( BankCard(342342, "Karol", "Olejniczak", "Visa", "10/22", "credit card"), "password" );
	EXPECT_EQ("password", client->getPassword());
}
TEST_F(clientTest, schouldDisplayBasicInformationAboutClientWithoutCreditCard)
{
	std::cout << client;
}
TEST_F(clientTest, schouldDisplayBasicInformationAboutClientWithCreditCard)
{
	client->setBankCard( BankCard(342342, "Karol", "Olejniczak", "Visa", "10/22", "credit card"), "password" );
	std::cout << client;
}

// ConsoleApplication18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "bankTest.h"
#include "clientTest.h"
#include "humanTest.h"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


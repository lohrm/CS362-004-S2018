#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void test_isGameOver(){

	struct gameState state;
	
  	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	initializeGame(2, k, 1, &state);

	printf("Testing isGameOver():\n");
	// TEST 1
	printf("   TEST 1: Initial card supply\n");
	if(isGameOver(&state) == 0){
		printf("\tPASS - Game is not over\n");
	}
	else{
		printf("\tFAIL - Game should not be over\n");
	}
	
	// TEST 2
	state.supplyCount[province] = 0;
	printf("   TEST 2: 0 Province cards\n");
	if(isGameOver(&state) == 1){
		printf("\tPASS - Game is over\n");
	}
	else{
		printf("\tFAIL - Game should be over\n");
	}

	// TEST 3
	state.supplyCount[province] = 1;
	state.supplyCount[mine] = 0;
	state.supplyCount[gold] = 0;
	printf("   TEST 3: 1 Province card, two decks empty\n");
	if(isGameOver(&state) == 0){
		printf("\tPASS - Game is not over\n");
	}
	else{
		printf("\tFAIL - Game should not be over\n");
	}
	
	// TEST 4
	state.supplyCount[smithy] = 0;
	printf("   TEST 4: 1 Province card, Three decks empty\n");
	if(isGameOver(&state) == 1){
		printf("\tPASS - Game is over\n");
	}
	else{
		printf("\tFAIL - Game should be over\n");
	}
}

int main(){

	test_isGameOver();

	return 0;

}

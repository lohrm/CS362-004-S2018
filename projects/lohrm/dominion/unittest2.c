#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void test_endTurn(){

	struct gameState state;

	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	initializeGame(2, k, 1, &state);

	int currentPlayer = whoseTurn(&state);

	printf("Testing endTurn():\n");

	state.handCount[currentPlayer] = 5;
	state.discardCount[currentPlayer] = 0;
	printf("Player 1's turn ends with 5 cards in hand and 0 cards in discard deck\n");

	// TEST 1
	printf("   TEST 1: Player 1's hand is empty\n");
	endTurn(&state);
	if(state.handCount[currentPlayer] == 0){
		printf("\tPASS - Player 1's hand is empty\n");
	}
	else{
		printf("\tFAIL - Player 1's hand is not empty\n");
	}

	// TEST 2
	printf("   TEST 2: Player 1's cards were put in discard deck\n");
	if(state.discardCount[currentPlayer] == 5){
		printf("\tPASS - All 5 hand cards were put in discard deck\n");
	}
	else{
		printf("\tFAIL - Hand cards were not put in discard deck\n");
	}

	// TEST 3
	printf("   TEST 3: It is player 2's turn\n");
	if(state.whoseTurn == currentPlayer+1){
		printf("\tPASS - It is player 2's turn\n");
	}
	else{
		printf("\tFAIL - It is not player 2's turn\n");
	}

	printf("Player 2's turn ends\n");
	endTurn(&state);

	// TEST 4
	printf("   TEST 4: It is player 1's turn\n");
	if(state.whoseTurn == currentPlayer){
		printf("\tPASS - It is player 1's turn\n");
	}
	else{
		printf("\tFAIL - It is not player 1's turn\n");
	}

	// TEST 5
	printf("   TEST 5: Player 1's hand is initially empty\n");
	if(state.handCount[currentPlayer] == 0){
		printf("\tPASS - Player 1's hand is empty\n");
	}
	else{
		printf("\tFAIL - Player 1's hand is not empty\n");
	}
}

int main(){

	test_endTurn();

	return 0;

}

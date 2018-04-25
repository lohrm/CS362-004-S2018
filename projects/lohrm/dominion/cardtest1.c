#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void test_smithy(){

	struct gameState state;

	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	initializeGame(2, k, 1, &state);
	
	int currentPlayer = whoseTurn(&state);
	int original_deck = state.deckCount[currentPlayer];
	int original_hand = state.handCount[currentPlayer];
	state.hand[currentPlayer][0] = smithy;

	printf("Testing Smithy:\n");

	cardEffect(smithy, 0, 0, 0, &state, 0, NULL);
	// TEST 1
	printf("   TEST 1: 3 cards were taken from the deck\n");
	if(state.deckCount[currentPlayer] == original_deck-3){
		printf("\tPASS - 3 cards were taken\n");
	}
	else{
		printf("\tFAIL - 3 cards were not taken\n");
	}
	// TEST 2
	printf("   TEST 2: 3 cards were added to the player's hand, and the played card was discarded\n");
	if(state.handCount[currentPlayer] == original_hand+2){
		printf("\tPASS - 3 cards were added and smithy was discarded\n");
	}
	else{
		printf("\tFAIL - 3 cards were not added and smithy was not discarded\n");
	}
}

int main(){

	test_smithy();

	return 0;

}

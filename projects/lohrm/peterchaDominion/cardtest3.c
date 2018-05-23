#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void test_great_hall(){

	struct gameState state;

	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	initializeGame(2, k, 1, &state);
	
	int currentPlayer = whoseTurn(&state);
	int original_actions = state.numActions;
	int original_hand = state.handCount[currentPlayer];
	int original_played = state.playedCardCount;

	printf("Testing Great Hall:\n");

	cardEffect(great_hall, 0, 0, 0, &state, 0, NULL);
	// TEST 1
	printf("   TEST 1: Player drew a card\n");
	if(state.handCount[currentPlayer] == original_hand){
		printf("\tPASS - 1 card was added to player's hand\n");
	}
	else{
		printf("\tFAIL - 1 card was not added to player's hand\n");
	}
	// TEST 2
	printf("   TEST 2: Player gained one action\n");
	if(state.numActions == original_actions+1){
		printf("\tPASS - 1 action was added to player\n");
	}
	else{
		printf("\tFAIL - 1 action was not added to player\n");
	}
	// TEST 3
	printf("   TEST 3: Great hall card was discarded into the played cards deck\n");
	if(state.playedCardCount == original_played+1){
		printf("\tPASS - Great hall card was discarded and not trashed\n");
	}
	else{
		printf("\tFAIL - Great hall card was trashed\n");
	}
}

int main(){

	test_great_hall();

	return 0;
}

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void test_adventurer(){

	struct gameState state;

	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	initializeGame(2, k, 1, &state);
	
	int i;

	int currentPlayer = whoseTurn(&state);
	int original_discard = state.discardCount[currentPlayer];
	int fail = 0;
	int original_hand = state.handCount[currentPlayer];
	state.hand[currentPlayer][0] = smithy;

	printf("Testing Adventurer:\n");

	cardEffect(adventurer, 0, 0, 0, &state, 0, NULL);
	// TEST 1
	printf("   TEST 1: Player's hand only increases by 2\n");
	if(state.handCount[currentPlayer] == original_hand+2){
		printf("\tPASS - 2 cards were added to player's hand\n");
	}
	else{
		printf("\tFAIL - 2 cards were not added to player's hand\n");
	}
	// TEST 2
	printf("   TEST 2: No treasure cards were discarded when drawn\n");
	for(i = original_discard; i < state.discardCount[currentPlayer]; i++){
		if(((state.discard[currentPlayer][i]) == copper) || ((state.discard[currentPlayer][i]) == silver) || ((state.discard[currentPlayer][i]) == gold)){
			printf("\tFAIL - Treasure cards were discarded\n");
			fail = 1;
			break;
		}
	}
	if(fail == 0){
		printf("\tPASS - Treasure cards were not discarded\n");
	}
	fail = 0;

	// TEST 3
	printf("   TEST 3: Only treasure cards were added to player's hand\n");
	for(i = original_hand; i < state.handCount[currentPlayer]; i++){
		if(((state.hand[currentPlayer][i]) != copper) && ((state.hand[currentPlayer][i]) != silver) && ((state.hand[currentPlayer][i]) != gold)){
			printf("\tFAIL - Non-treasure cards were added to player's hand\n");
			fail = 1;
			break;
		}
	}
	if(fail == 0){
		printf("\tPASS - Only treasure cards were added to player's hand\n");
	}
}

int main(){

	test_adventurer();

	return 0;

}

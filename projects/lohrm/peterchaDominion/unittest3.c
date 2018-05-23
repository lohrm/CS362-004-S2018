#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void set_temp_hand(struct gameState *state, int currentPlayer){

	int i;
	
	state->handCount[currentPlayer] = 5;
	for(i = 0; i < 5; i++){
		// Put copper, silver, gold, adventurer, and council_room in hand
		state->hand[currentPlayer][i] = i+4;
	}
}

void test_discardCard(){

	struct gameState state;

	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int original_playedCardCount = state.playedCardCount;
	int original_lastCard = council_room;

	initializeGame(2, k, 1, &state);

	int currentPlayer = whoseTurn(&state);

	set_temp_hand(&state, currentPlayer);

	printf("Testing discardCard():\n");

	printf("Discarding gold, handPos=2, from player's hand. The card is trashed\n");
	
	// TEST 1
	discardCard(2, currentPlayer, &state, 1);
	printf("   TEST 1: Card was not added to played cards pile\n");
	if(original_playedCardCount == state.playedCardCount){
		printf("\tPASS - Card was not added to played cards pile\n");
	}
	else{
		printf("\tFAIL - Card was added to played cards pile\n");
	}

	// TEST 2
	printf("   TEST 2: Discarded card was replaced by last card in hand\n");
	if(state.hand[currentPlayer][2] == original_lastCard){
		printf("\tPASS - Card was replaced by last card\n");
	}
	else{
		printf("\tFAIL - Card was not replaced by last card\n");
	}

	// TEST 3
	printf("Discarding council_room, last card in hand from player's hand. The card is trashed\n");
	set_temp_hand(&state, currentPlayer);
	discardCard(4, currentPlayer, &state, 1);
	printf("   TEST 3: Player's hand count is reduced\n");
	if(state.handCount[currentPlayer] < 5){
		printf("\tPASS - Hand was reduced\n");
	}
	else{
		printf("\tFAIL - Hand was not reduced\n");
	}

	// TEST 4
	printf("Discarding copper, the only card in the player's hand. The card is not trashed\n");
	state.handCount[currentPlayer] = 1;
	state.hand[currentPlayer][0] = copper;
	discardCard(0, currentPlayer, &state, 0);
	printf("   TEST 4: The card was put in the played cards pile\n");
	if(state.playedCardCount > original_playedCardCount){
		printf("\tPASS - The card was put in the played cards pile\n");
	}
	else{
		printf("\tFAIL - The card was not put in the played cards pile\n");
	}
	
	// TEST 5
	printf("   TEST 5: The player's hand is empty\n");
	if(state.handCount[currentPlayer] == 0){
		printf("\tPASS - The player's hand is empty\n");
	}
	else{
		printf("\tFAIL - The player's hand is not empty\n");
	}
}

int main(){

	test_discardCard();

	return 0;

}

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void test_gainCard(){

	struct gameState state;

	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	initializeGame(2, k, 1, &state);

	int currentPlayer = whoseTurn(&state);

	int original_deck = state.deckCount[currentPlayer];
	int original_hand = state.handCount[currentPlayer];
	int original_discard = state.discardCount[currentPlayer];

	printf("Testing getCard():\n");

	printf("Adding a gold card to the discard deck\n");

	// TEST 1
	gainCard(6, &state, 0, currentPlayer);
	printf("   TEST 1: The card was added to the discard deck\n");
	if((state.discard[currentPlayer][state.discardCount[currentPlayer]-1] == 6) && (state.discardCount[currentPlayer] > original_discard)){
		printf("\tPASS - The card was added to the discard deck\n");
	}
	else{
		printf("\tFAIL - The card was not added to the discard deck\n");
	}

	printf("Adding a gold card to the deck\n");
	// TEST 2
	gainCard(6, &state, 1, currentPlayer);
	printf("   TEST 1: The card was added to the deck\n");
	if((state.deck[currentPlayer][state.deckCount[currentPlayer]-1] == 6) && (state.deckCount[currentPlayer] > original_deck)){
		printf("\tPASS - The card was added to the deck\n");
	}
	else{
		printf("\tFAIL - The card was not added to the deck\n");
	}

	printf("Adding a gold card to the player's hand\n");
	// TEST 3
	gainCard(6, &state, 2, currentPlayer);
	printf("   TEST 3: The card was added to the player's hand\n");
	if((state.hand[currentPlayer][state.handCount[currentPlayer]-1] == 6) && (state.handCount[currentPlayer] > original_hand)){
		printf("\tPASS - The card was added to the player's hand\n");
	}
	else{
		printf("\tFAIL - The card was not added to the player's hand\n");
	}

	printf("Trying to add a gold card when there are no gold cards in the supply\n");
	// TEST 4
	printf("   TEST 4: The gold supply is empty\n");
	state.supplyCount[gold] = 0;
	if(gainCard(6, &state, 0, currentPlayer) == -1){
		printf("\tPASS - The card is not added\n");
	}
	else{
		printf("\tFAIL - The card was mistakenly added\n");
	}
	
}

int main(){

	test_gainCard();

	return 0;
}

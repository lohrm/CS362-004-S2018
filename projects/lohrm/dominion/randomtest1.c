#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void random_test_smithy(){

	struct gameState state;
	
  	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	initializeGame(MAX_PLAYERS, k, 1, &state);

	int i, j;
	int currentPlayer, handPos;
	int og_deck, og_hand, og_discard, og_played;

	printf("Random testing smithy:\n");

	for(i = 0; i < 2000; i++){
		state.numPlayers = ((int)(Random()*3))+2;
		currentPlayer = (int)(Random()*(state.numPlayers+1));
		state.handCount[currentPlayer] = (int)(Random()*MAX_HAND);
		og_hand = state.handCount[currentPlayer];
		for(j = 0; j < state.handCount[currentPlayer]; j++){
			state.hand[currentPlayer][j] = (int)(Random()*(treasure_map+1));
		}
		state.deckCount[currentPlayer] = (int)(Random()*MAX_DECK);
		og_deck = state.deckCount[currentPlayer];
		for(j = 0; j < state.deckCount[currentPlayer]; j++){
			state.deck[currentPlayer][j] = (int)(Random()*(treasure_map+1));
		}
		state.discardCount[currentPlayer] = (int)(Random()*MAX_DECK);
		og_discard = state.discardCount[currentPlayer];
		for(j = 0; j < state.discardCount[currentPlayer]; j++){
			state.discard[currentPlayer][j] = (int)(Random()*(treasure_map+1));
		}
		state.playedCardCount = (int)(Random()*MAX_DECK);
		og_played = state.playedCardCount;
		for(j = 0; j < state.playedCardCount; j++){
			state.playedCards[j] = (int)(Random()*(treasure_map+1));
		}
		handPos = (int)(Random()*state.handCount[currentPlayer]);
		smithyEffect(currentPlayer, &state, handPos);
		if((state.deckCount[currentPlayer] == og_deck-3) && (state.handCount[currentPlayer] == og_hand+2) && (state.playedCardCount == og_played)){
			printf("~");
		}
		else{
			printf("!");
		}
	}
	printf("\n");
}

int main(){

	random_test_smithy();

	return 0;

}

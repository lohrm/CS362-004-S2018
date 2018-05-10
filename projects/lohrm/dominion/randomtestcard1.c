#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void generate_randoms(struct gameState *state, int currentPlayer, int *og_hand, int *og_deck, int *og_played){

	int i;

	state->handCount[currentPlayer] = (int)(Random()*MAX_HAND);
	*og_hand = state->handCount[currentPlayer];
	for(i = 0; i < state->handCount[currentPlayer]; i++){
		state->hand[currentPlayer][i] = (int)(Random()*(treasure_map+1));
	}
	state->deckCount[currentPlayer] = (int)(Random()*MAX_DECK);
	*og_deck = state->deckCount[currentPlayer];
	for(i = 0; i < state->deckCount[currentPlayer]; i++){
		state->deck[currentPlayer][i] = (int)(Random()*(treasure_map+1));
	}
	state->playedCardCount = (int)(Random()*MAX_DECK);
	*og_played = state->playedCardCount;
	for(i = 0; i < state->playedCardCount; i++){
		state->playedCards[i] = (int)(Random()*(treasure_map+1));
	}
}

void random_test_smithy(){

	struct gameState state;
	
  	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	initializeGame(MAX_PLAYERS, k, 1, &state);

	int i;
	int currentPlayer, handPos;
	int og_hand, og_deck, og_played;

	printf("Random testing Smithy:\n");

	for(i = 0; i < 2000; i++){
		state.numPlayers = ((int)(Random()*3))+2;
		currentPlayer = (int)(Random()*(state.numPlayers+1));
		generate_randoms(&state, currentPlayer, &og_hand, &og_deck, &og_played);
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

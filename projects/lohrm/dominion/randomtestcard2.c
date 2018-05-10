#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void generate_randoms(struct gameState *state, int currentPlayer, int *og_hand, int *og_actions, int *og_played){

	int i;

	state->handCount[currentPlayer] = (int)(Random()*MAX_HAND);
	*og_hand = state->handCount[currentPlayer];
	for(i = 0; i < state->handCount[currentPlayer]; i++){
		state->hand[currentPlayer][i] = (int)(Random()*(treasure_map+1));
	}
	state->numActions = (int)(Random()*50);
	*og_actions = state->numActions;
	state->playedCardCount = (int)(Random()*MAX_DECK);
	*og_played = state->playedCardCount;
	for(i = 0; i < state->playedCardCount; i++){
		state->playedCards[i] = (int)(Random()*(treasure_map+1));
	}
}

void random_test_village(){

	struct gameState state;
	
  	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	initializeGame(MAX_PLAYERS, k, 1, &state);

	int i;
	int currentPlayer, handPos;
	int og_hand, og_actions, og_played;

	printf("Random testing Village:\n");

	for(i = 0; i < 2000; i++){
		state.numPlayers = ((int)(Random()*3))+2;
		currentPlayer = (int)(Random()*(state.numPlayers+1));
		generate_randoms(&state, currentPlayer, &og_hand, &og_actions, &og_played);
		handPos = (int)(Random()*state.handCount[currentPlayer]);
		villageEffect(currentPlayer, &state, handPos);
		if((state.numActions == og_actions+1) && (state.handCount[currentPlayer] == og_hand) && (state.playedCardCount == og_played+1)){
			printf("~");
		}
		else{
			printf("!");
		}
	}
	printf("\n");
}

int main(){

	random_test_village();

	return 0;

}

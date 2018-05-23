#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void generate_randoms(struct gameState *state, int currentPlayer, int *og_hand, int *og_discard){

	int i;

	state->handCount[currentPlayer] = (int)(Random()*MAX_HAND);
	*og_hand = state->handCount[currentPlayer];
	for(i = 0; i < state->handCount[currentPlayer]; i++){
		state->hand[currentPlayer][i] = (int)(Random()*(treasure_map+1));
	}
	state->discardCount[currentPlayer] = (int)(Random()*MAX_DECK);
	*og_discard = state->discardCount[currentPlayer];
	for(i = 0; i < state->discardCount[currentPlayer]; i++){
		state->discard[currentPlayer][i] = (int)(Random()*(treasure_map+1));
	}
}

void random_test_adventurer(){

	struct gameState state;
	
  	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	initializeGame(MAX_PLAYERS, k, 1, &state);

	int i, j;
	int fail = 0;
	int currentPlayer, cardDrawn;
	int temphand[MAX_HAND];
	int z;
	int og_hand, og_discard;

	printf("Random testing Adventurer:\n");

	for(i = 0; i < 2000; i++){
		z = 0; fail = 0;
		state.numPlayers = ((int)(Random()*3))+2;
		currentPlayer = (int)(Random()*(state.numPlayers+1));
		state.whoseTurn = currentPlayer;
		generate_randoms(&state, currentPlayer, &og_hand, &og_discard);
		cardEffect(adventurer, 0, 0, 0, &state, 0, NULL);
		for(j = og_discard; j < state.discardCount[currentPlayer]; j++){
			if(((state.discard[currentPlayer][j]) == copper) || ((state.discard[currentPlayer][j]) == silver) || ((state.discard[currentPlayer][j]) == gold)){
				fail = 1;
			}
		}
		for(j = og_hand; j < state.handCount[currentPlayer]; j++){
			if(((state.hand[currentPlayer][j]) != copper) && ((state.hand[currentPlayer][j]) != silver) && ((state.hand[currentPlayer][j]) != gold)){
				fail = 1;
			}
		}
		if((state.handCount[currentPlayer] == og_hand+2) && fail == 0){
			printf("~");
		}
		else{
			printf("!");
		}
	}
	printf("\n");
}

int main(){

	random_test_adventurer();

	return 0;

}

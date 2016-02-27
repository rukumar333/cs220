#include <stdio.h>
#include <math.h>
#include <assert.h>

/*-----------------------------------------------------------------------------------------------------
  A program to play tic-tac-toe.

  The state of the game is represented by a 9 digit base 3 number.
  Each digit represents one position on the board, labeled as follows:
  0 | 1 | 2
  --+--+--
  3 | 4 | 5
  --+--+--
  6 | 7 | 8

  Each digit can have values 0: Empty, 1: X, or 2: O
  Every state can be represented as number between 0
  and 3**9 - 1.  By convention, 3**9: tie, 3**9+1: X win, 3**9+2: O win

  The program is designed to play with other tic-tac-toe players.  Therefore
  uses the following conventions...

  1. The first parameter to the program must be either "X" or "O" (the
  letter O... not the number) to represent whether this program should
  play "X" or "O".

  2. X always takes the first turn.

  3. When the program  makes a move, it writes the state out to standard
  output via a simple printf statement.  The program will not write anything
  else to standard output.  (However, it can write messages to standard
  error.)

  4. The program will determine what its opponent's move is by reading
  a single integer from standard input.  This number represents the
  position (0-8) which your opponent will take.  For instance, if the
  program is playing "O", and reads "2" from standard input, then
  the opponent is asking to put an "X" in the upper right hand
  corner of the board.  If the opponent specifies an incorrect input,
  either an invalid number, or a position that has already been taken,
  then the program can claim a win by default.

  ----------------------------------------------------------------------------------------------*/
#define STATE_TIE 3*3*3*3*3*3*3*3*3
#define STATE_XWIN STATE_TIE+1
#define STATE_OWIN STATE_TIE+2
#define DBG 1

short int myTurn(short int state, char me);
short int theirTurn(short int state, char them);
short int checkWin(short int state);
short int addState(short int state, char pos, char xo);
char getState(short int state, char pos);
void fprintState(short int state);
char p2c(short int state,char pos);
short int myTurnCount = 0;
short int other = 0;
short int blockOrWin(short int state, char me, char check);
short int forkBlockOrWin(short int state, char me, char check);
char zero = -1;
char one = -1;
char two = -1;
char three = -1;
char four = -1;
char five = -1;
char six = -1;
char seven = -1;
char eight = -1;

int main(int argc,char **argv) {

    setbuf(stdin,0);
    setbuf(stdout,0);
    setbuf(stderr,0);

    char me=0; // Am I X or O... don't know yet
    char them=0; // Is my opponent X or O

    if (argc<2) {
	fprintf(stderr,"Please specify whether %s should play X or O.\n",
		argv[0]);
	return 1; /* Issue a non-zero return code to indicate an error */
    }

    if (argv[1][0]=='X') {
	me=1;
	them=2;
    } else if (argv[1][0]=='O') {
	me=2;
	them=1;
    } else {
	fprintf(stderr,"Please enter either X or O as the first argument to %s\n",
		argv[0]);
	return 1;
    }

    short int state=0; // Current state... starts off empty
    int turn=1; // Whose turn is it?  X or O?

    while(state<STATE_TIE) {

	if (DBG) {
	    fprintf(stderr,"It's %c's turn...\n",(turn==1)?'X':'O');
	}

	if (me==turn) state = myTurn(state,me);
	else state=theirTurn(state,them);

	printf("%d\n",state); // Write state after each move to standard out
	state=checkWin(state);

	if (turn==1) turn=2; // X just went... O next
	else turn=1; // O just went... X next
    }
    printf("%d\n",state); // Write final state to standard out

    if (state==STATE_TIE) fprintf(stderr,"Good game, but you didn't beat me.... it's a tie.\n");
    else if (state==(STATE_TIE+me))
	fprintf(stderr,"Got you this time!... I won.\n");
    else
	fprintf(stderr,"You got me this time... you won.\n");

    return 0;
}

short int myTurn(short int state, char me) {
    /* Your code to make your next move goes here */
    zero = getState(state, 0);
    one = getState(state, 1);
    two = getState(state, 2);
    three = getState(state, 3);
    four = getState(state, 4);
    five = getState(state, 5);
    six = getState(state, 6);
    seven = getState(state, 7);
    eight = getState(state, 8);
    if(other == 0){
	if(me == 1){
	    other = 2;
	}else{
	    other = 1;
	}
    }
    myTurnCount ++;
    //First turn
    printf("First turn\n");
    if(myTurnCount == 1){
	if(me == 1){
	    state = addState(state, 4, me);
	    return state;
	}
	if(me == 2){
	    if(getState(state, 4) == 0){
		state = addState(state, 4, me);
		return state;
	    }else{
		state = addState(state, 0, me);
		return state;
	    }
	}
    }
    //Try to win
    printf("Try to win\n");
    short int nState = blockOrWin(state, me, me);
    if(nState != -1){
	state = nState;
	return state;
    }
    
    //Try to block
    printf("Try to block\n");
    nState = blockOrWin(state, me, other);
    if(nState != -1){
	state = nState;
	return state;
    }
     
    //Create Fork
    printf("Try to fork\n");
    nState = forkBlockOrWin(state, me, me);
    if(nState != -1){
	state = nState;
	return state;
    }

    //Block Fork
    printf("Block fork\n");
    nState = forkBlockOrWin(state, me, other);
    if(nState != -1){
	state = nState;
	return state;
    }
    
    //Opposite corner
    printf("Opposite corner\n");
    if(zero == other){
	state = addState(state, 8, me);
	return state;
    }
    if(two == other){
	state = addState(state, 6, me);
	return state;
    }
    if(six == other){
	state = addState(state, 2, me);
	return state;
    }
    if(eight == other){
	state = addState(state, 0, me);
	return state;
    }

    //Choose corner
    printf("Choose corner\n");
    if(zero == 0){
	state = addState(state, 0, me);
	return state;
    }
    if(two == 0){
	state = addState(state, 2, me);
	return state;
    }
    if(six == 0){
	state = addState(state, 6, me);
	return state;
    }
    if(eight == 0){
	state = addState(state, 8, me);
	return state;
    }

    //Choose last
    printf("Last option\n");
    if(one == 0){
	state = addState(state, 1, me);
	return state;
    }
    if(three == 0){
	state = addState(state, 3, me);
	return state;
    }
    if(five == 0){
	state = addState(state, 5, me);
	return state;
    }
    if(seven == 0){
	state = addState(state, 7, me);
	return state;
    }
   
    return state; // Return an updated state
}

short int forkBlockOrWin(short int state, char me, char check){
    if(zero == check){
	if(five == check){
	    if(two == 0 && one == 0 && eight == 0){
		state = addState(state, 2, me);
		return state;
	    }
	    if(three == 0 && four == 0 && six == 0){
		state = addState(state, 3, me);
		return state;
	    }
	    if(four == 0 && three == 0 && eight == 0){
		state = addState(state, 4, me);
		return state;
	    }
	    if(eight == 0 && two == 0 && four == 0){
		state = addState(state, 8, me);
		return state;
	    }
	}
	if(seven == check){
	    if(one == 0 && two == 0 && four == 0){
		state = addState(state, 1, me);
		return state;
	    }
	    if(six == 0 && three == 0 && eight == 0){
		state = addState(state, 6, me);
		return state;
	    }
	    if(four == 0 && one == 0 && eight == 0){
		state = addState(state, 4, me);
		return state;
	    }
	    if(eight == 0 && four == 0 && six == 0){
		state = addState(state, 8, me);
		return state;
	    }	    
	}
    }
    if(two == check){
	if(three == check){
	    if(five == 0 && four == 0 && eight == 0){
		state = addState(state, 5, me);
		return state;
	    }
	    if(six == 0 && zero == 0 && four == 0 ){
		state = addState(state, 6, me);
		return state;
	    }
	    if(four == 0 && five == 0 && six == 0){
		state = addState(state, 4, me);
		return state;
	    }
	    if(zero == 0 && one == 0 && six == 0){
		state = addState(state, 0, me);
		return state;
	    }
	}
	if(seven == check){
	    if(one == 0 && zero == 0 && four == 0){
		state = addState(state, 1, me);
		return state;
	    }
	    if(six == 0 && four == 0 && eight == 0){
		state = addState(state, 6, me);
		return state;
	    }
	    if(four == 0 && one == 0 && six == 0){
		state = addState(state, 4, me);
		return state;
	    }
	    if(eight == 0 && five == 0 && six == 0){
		state = addState(state, 8, me);
		return state;
	    }	    
	}
    }
    if(six == check){
	if(one == check){
	    if(zero == 0 && three == 0 && two == 0){
		state = addState(state, 0, me);
		return state;
	    }
	    if(four == 0 && two == 0 && seven == 0 ){
		state = addState(state, 4, me);
		return state;
	    }
	    if(seven == 0 && four == 0 && eight == 0){
		state = addState(state, 7, me);
		return state;
	    }
	    if(two == 0 && zero == 0 && four == 0){
		state = addState(state, 2, me);
		return state;
	    }
	}
	if(five == check){
	    if(two == 0 && eight == 0 && four == 0){
		state = addState(state, 2, me);
		return state;
	    }
	    if(three == 0 && four == 0 && zero == 0){
		state = addState(state, 3, me);
		return state;
	    }
	    if(four == 0 && two == 0 && three == 0){
		state = addState(state, 4, me);
		return state;
	    }
	    if(eight == 0 && seven == 0 && two == 0){
		state = addState(state, 8, me);
		return state;
	    }	    
	}
    }
    if(eight == check){
	if(one == check){
	    if(zero == 0 && four == 0 && two == 0){
		state = addState(state, 0, me);
		return state;
	    }
	    if(two == 0 && five == 0 && zero == 0 ){
		state = addState(state, 0, me);
		return state;
	    }
	    if(four == 0 && seven == 0 && zero == 0){
		state = addState(state, 4, me);
		return state;
	    }
	    if(seven == 0 && six == 0 && four == 0){
		state = addState(state, 7, me);
		return state;
	    }
	}
	if(three == check){
	    if(zero == 0 && six == 0 && four == 0){
		state = addState(state, 0, me);
		return state;
	    }
	    if(four == 0 && five == 0 && zero == 0){
		state = addState(state, 4, me);
		return state;
	    }
	    if(five == 0 && two == 0 && four == 0){
		state = addState(state, 5, me);
		return state;
	    }
	    if(six == 0 && seven == 0 && zero == 0){
		state = addState(state, 6, me);
		return state;
	    }	    
	}
    }
    if(one == check){
	if(three == check){
	    if(zero == 0 && six == 0 && two == 0){
		state = addState(state, 0, me);
		return state;
	    }
	    if(four == 0 && seven == 0 && five == 0){
		state = addState(state, 4, me);
		return state;
	    }
	}
	if(five == check){
	    if(two == 0 && eight == 0 && zero == 0){
		state = addState(state, 2, me);
		return state;
	    }	    
	    if(four == 0 && seven == 0 && three == 0){
		state = addState(state, 4, me);
		return state;
	    }
	}
    }
    return -1;
}

short int blockOrWin(short int state, char me, char check){    
    if(zero == check){
	printf("Zero check\n");
	if(one == check && two == 0){
	    state = addState(state, 2, me);
	    return state;
	}
	if(two == check && one == 0){
	    state = addState(state, 1, me);
	    return state;
	}	
	if(three == check && six == 0){
	    state = addState(state, 6, me);
	    return state;	    
	}
	if(six == check && three == 0){
	    state = addState(state, 3, me);
	    return state;	    
	}
	if(four == check && eight == 0){
	    state = addState(state, 8, me);
	    return state;	    
	}
	if(eight == check && four == 0){
	    state = addState(state, 4, me);
	    return state;	    
	}
    }
    if(one == check){
	printf("One check\n");
	if(two == check && zero == 0){
	    state = addState(state, 0, me);
	    return state;
	}
	if(four == check && seven == 0){
	    state = addState(state, 7, me);
	    return state;	    
	}
	if(seven == check && four == 0){
	    state = addState(state, 4, me);
	    return state;	    
	}
    }
    if(two == check){
	printf("Two check\n");
	if(five == check && eight == 0){
	    printf("Five\n");
	    state = addState(state, 8, me);
	    return state;	    	    
	}
	if(eight == check && five == 0){
	    printf("Eight\n");
	    state = addState(state, 5, me);
	    return state;	    	    
	}
	if(four == check && six == 0){
	    printf("Four\n");
	    state = addState(state, 6, me);
	    return state;	    	    
	}
	if(six == check && four == 0){
	    printf("Six\n");
	    state = addState(state, 4, me);
	    return state;	    	    
	}
    }
    if(three == check){
	printf("Three check\n");
	if(four == check && five == 0){
	    state = addState(state, 5, me);
	    return state;	    
	}
	if(five == check && four == 0){
	    state = addState(state, 4, me);
	    return state;	    
	}
	if(six == check && zero == 0){
	    state = addState(state, zero, me);
	    return state;	    
	}
    }
    if(four == check){
	printf("Four check\n");
	if(five == check && three == 0){
	    state = addState(state, 3, me);
	    return state;
	}
	if(six == check && two == 0){
	    state = addState(state, 2, me);
	    return state;	    
	}
	if(seven == check && one == 0){
	    state = addState(state, 1, me);
	    return state;	    
	}
	if(eight == check && zero == 0){
	    state = addState(state, 0, me);
	    return state;	    
	}	
    }
    if(five == check){
	printf("Five check\n");
	if(eight == check && two == 0){
	    state = addState(state, 2, me);
	    return state;	    
	}
    }
    if(six == check){
	printf("Six check\n");
	if(seven == check && eight == 0){
	    state = addState(state, 8, me);
	    return state;	    
	}
	if(eight == check && seven == 0){
	    state = addState(state, 7, me);
	    return state;	    
	}
    }
    if(seven == check){
	printf("Seven check\n");
	if(eight == check && six == 0){
	    state = addState(state, 6, me);
	    return state;	    	    
	}
    }
    return -1;
}



short int theirTurn(short int state, char them) {
    int pos=9; // Position they choose... initialized to an invalid position
    char me;
    if (them==1) me=2; else me=1;
    fprintState(state); // Print out the current board to standard error
    fprintf(stderr,"Enter the position for the next %c: ",(them==1)?'X':'O'); // write a prompt to stderr
    assert(!feof(stdin));
    if (1!=scanf("%d",&pos)) { // Read opponents choice from standard input, and save it in pos
	fprintf(stderr,"Illegal or no position entered... I win!\n");
	return STATE_TIE+me;
    }
    if (DBG) {
	fprintf(stderr,"User asked for a %c at position %d\n",(them==1)?'X':'O',pos);
    }
    if ((pos>8) || (pos<0)) {
	fprintf(stderr,"Illegal position of %d must be 0-8... I win!\n",pos);
	return STATE_TIE+me;
    }
    if (0!=getState(state,pos)) {
	fprintf(stderr,"Illegal position of %d already taken... I win!\n",pos);
	return STATE_TIE+me;
    }
    return addState(state,pos,them);
}

short int checkWin(short int state) {
    /* Checks state to see if there is a winner or a tie */
    char ul=getState(state,0); // Get the upper left corner value
    if (ul!=0) {
	if ((ul==getState(state,1)) && (ul==getState(state,2)))
	    return STATE_TIE+ul;
	if ((ul==getState(state,4)) && (ul==getState(state,8)))
	    return STATE_TIE+ul;
	if ((ul==getState(state,3)) && (ul==getState(state,6)))
	    return STATE_TIE+ul;
    }

    char ce=getState(state,4); // Get the center square value
    if (ce!=0) {
	if ((ce==getState(state,3)) && (ce==getState(state,5)))
	    return STATE_TIE+ce;
	if ((ce==getState(state,1)) && (ce==getState(state,7)))
	    return STATE_TIE+ce;
	if ((ce==getState(state,2)) && (ce==getState(state,6)))
	    return STATE_TIE+ce;
    }

    char lr=getState(state,8); // Get the lower right value
    if (lr!=0) {
	if ((lr==getState(state,6)) && (lr==getState(state,7)))
	    return STATE_TIE+lr;
	if ((lr==getState(state,2)) && (lr==getState(state,5)))
	    return STATE_TIE+lr;
    }

    /* No winner... maybe a tie? */
    int pos;
    for(pos=0;pos<9;pos++) {
	if (0==getState(state,pos)) return state; // There is an open space
    }
    return STATE_TIE; // No open positions left
}

short int addState(short int state, char pos, char xo) {
    assert(0==getState(state,pos));
    return state + pow(3,pos)*xo;
}

char getState(short int state, char pos) {
    assert(pos>=0);
    assert(pos<9);
    return (state/(int)pow(3,pos))%3;
}

void fprintState(short int state) {
    fprintf(stderr," 0: %c | 1: %c | 2: %c\n", p2c(state,0), p2c(state,1),p2c(state,2));
    fprintf(stderr," -----+------+------\n");
    fprintf(stderr," 3: %c | 4: %c | 5: %c\n", p2c(state,3), p2c(state,4),p2c(state,5));
    fprintf(stderr," -----+------+------\n");
    fprintf(stderr," 6: %c | 7: %c | 8: %c\n", p2c(state,6), p2c(state,7),p2c(state,8));
}


char p2c(short int state,char pos) {
    int val=getState(state,pos);
    if (val==0) return '_';
    if (val==1) return 'X';
    return 'O';
}

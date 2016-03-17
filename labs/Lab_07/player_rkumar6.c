int fgCount = 0;
int sgCount = 0;
int tgCount = 0;

int fgWinCount = 0;
int sgWinCount = 0;
int tgWinCount = 0;

int oppFgCount = 0;
int oppSgCount = 0;
int oppTgCount = 0;

int oppFgWinCount = 0;
int oppSgWinCount = 0;
int oppTgWinCount = 0;

//0 == fg
//1 == sg
//2 == tg
char prev = -1;

//0 == self check
//1 == opponent check
char selfOrOther = -1;
int selfWins = 0;
int otherWins = 0;
int selfCount = 0;
int otherCount = 0;
/* char oppPrev = -1; */
winner prevWinner = Unknown;


rps winnerRPS(rps val){
    if(val == Paper) return Scissors;
    if(val == Scissors) return Rock;
    if(val == Rock) return Paper;
    return Paper;
}

rps loserRPS(rps val){
    if(val == Paper) return Rock;
    if(val == Scissors) return Paper;
    if(val == Rock) return Scissors;
    return Paper;
}

//Each of these takes in the input of the player, not OPPONENT

char increment = 0;

/* rps firstGuess(rps val, winner res){ */
rps firstGuess(rps val){
    if(increment){
	++ fgCount;
	prev = 0;
    }
    /* if(res == Player1 || Player2)  */return loserRPS(val);
    return Paper;
}

/* rps secondGuess(rps val, winner res){ */
rps secondGuess(rps val){
    if(increment){
	++ sgCount;
	prev = 1;
    }
    /* if(res == Player1 || Player2)  */return winnerRPS(val);
    return Paper;
}

/* rps thirdGuess(rps val, winner res){ */
rps thirdGuess(rps val){
    if(increment){
	++ tgCount;
	prev = 2;
    }
    /* if(res == Player1 || Player2)  */return val;
    return Paper;
}

char getOppModeG(){
    if(oppFgCount > oppSgCount){
	if(oppFgCount > oppTgCount){
	    return 0;
	}else{
	    return 2;
	}
    }else{
	if(oppSgCount > oppTgCount){
	    return 1;
	}else{
	    return 2;
	}
    }
}

char getMin(int first, int second, int third){
    if(first < second){
	if(first < third){
	    return 0;
	}else{
	    return 2;
	}
    }else{
	if(second < third){
	    return 1;
	}else{
	    return 2;
	}
    }    
}

char getFMax(float first, float second, float third){
    if(first > second){
	if(first > third){
	    return 0;
	}else{
	    return 2;
	}
    }else{
	if(second > third){
	    return 1;
	}else{
	    return 2;
	}
    }    
}

char floatEqual(float one, float two){
    return (one >= (two - 0.00001) && one <= (two + 0.00001));
}

rps selfMove(int round, rps * myhist, rps * opphist){    
    selfOrOther = 0;
    ++ selfCount;
    float fgPerc, sgPerc, tgPerc;
    if(fgCount == 0) fgPerc = 0;
    else fgPerc = (float)fgWinCount / (float)fgCount;
    if(sgCount == 0) sgPerc = 0;
    else sgPerc = (float)sgWinCount / (float)sgCount;
    if(tgCount == 0) tgPerc = 0;
    else tgPerc = (float)tgWinCount / (float)tgCount;
    int fgLoses = fgCount - fgWinCount;
    int sgLoses = sgCount - sgWinCount;
    int tgLoses = tgCount - tgWinCount;
    /* printf("Self\n"); */
    /* printf("fgPerc: %.5f\n", fgPerc); */
    /* printf("sgPerc: %.5f\n", sgPerc); */
    /* printf("tgPerc: %.5f\n", tgPerc); */
    /* printf("fgLoses: %d\n", fgLoses); */
    /* printf("sgLoses: %d\n", sgLoses); */
    /* printf("tgLoses: %d\n", tgLoses); */
    char move = -1;
    increment = 1;
    if(floatEqual(fgPerc, sgPerc) && floatEqual(fgPerc, tgPerc)){
	move = getMin(fgLoses, sgLoses, tgLoses);
	switch(move){
	case 0: return firstGuess(*(myhist + round - 1));
	case 1: return secondGuess(*(myhist + round - 1));
	case 2: return thirdGuess(*(myhist + round - 1));
	}
    }    
    if(fgPerc > sgPerc && floatEqual(sgPerc, tgPerc) && fgPerc >= 0.5){
	return firstGuess(*(myhist + round - 1));
    }
    if(sgPerc > fgPerc && floatEqual(fgPerc, tgPerc) && sgPerc >= 0.5){
	return secondGuess(*(myhist + round - 1));
    }
    if(tgPerc > sgPerc && floatEqual(sgPerc, fgPerc) && tgPerc >= 0.5){
	return thirdGuess(*(myhist + round - 1));
    }
    move = getFMax(fgPerc, sgPerc, tgPerc);
    switch(move){
    case 0: if(fgPerc >= 0.25) return firstGuess(*(myhist + round - 1));
    case 1: if(sgPerc >= 0.25) return secondGuess(*(myhist + round - 1));
    case 2: if(tgPerc >= 0.25) return thirdGuess(*(myhist + round - 1));
    }
    //Random return
    char i = rand()%3;
    switch(i){
    case 0: return firstGuess(*(myhist + round - 1));
    case 1: return secondGuess(*(myhist + round - 1));
    case 2: return thirdGuess(*(myhist + round - 1));
    }
}

rps otherMove(int round, rps * myhist, rps * opphist){
    selfOrOther = 1;
    ++ otherCount;
    char nextMove = getOppModeG();
    /* printf("Other\n"); */
    /* printf("oppFgCount: %d\n", oppFgCount); */
    /* printf("oppSgCount: %d\n", oppSgCount); */
    /* printf("oppTgCount: %d\n", oppTgCount); */
    switch(nextMove){
    case 0: return winnerRPS(firstGuess(*(opphist + round - 1)));
    case 1: return winnerRPS(secondGuess(*(opphist + round - 1)));
    case 2: return winnerRPS(thirdGuess(*(opphist + round - 1)));
    }
}

rps player_rkumar6(int round,rps *myhist,rps *opphist) {
    //Randomly generate value if round is 0    
    /* printf("Round: %d\n", round); */
    increment = 0;
    if(round == 0 || round == 1){
	time_t t;

	if (round==0) srand((unsigned) time(&t)); /* Intializes random number generator */
	
	char i = rand()%3;
	switch(i) {
	case 0: return Rock;
	case 1: return Scissors;
	}
	return Paper;
    }else{
	prevWinner = eval_round(*(myhist + round - 1), *(opphist + round - 1), NULL, NULL);
	if(prevWinner == Player1){
	    switch(prev){
	    case 0: ++ fgWinCount;
	    case 1: ++ sgWinCount;
	    case 2: ++ tgWinCount;
	    }
	    switch(selfOrOther){
	    case 0: ++ selfWins;		
	    case 1: ++ otherWins;
	    }
	}
	if(round > 1){
	    if(firstGuess(*(opphist + round - 2)) == *(opphist + round - 1)){
		++ oppFgCount;
		if(prevWinner == Player2){
		    ++ oppFgWinCount;
		}
	    }

	    if(secondGuess(*(opphist + round - 2)) == *(opphist + round - 1)){
		++ oppSgCount;
		if(prevWinner == Player2){
		    ++ oppSgWinCount;
		}
	    }
	    if(thirdGuess(*(opphist + round - 2)) == *(opphist + round - 1)){
		++ oppTgCount;
		if(prevWinner == Player2){
		    ++ oppTgWinCount;
		}
	    }
	}
	if(selfWins == otherWins){
	    return otherMove(round, myhist, opphist);
	}
	float fSelfWins = (float)selfWins;
	float fSelfCount = (float)selfCount;
	float fOtherWins = (float)otherWins;
	float fOtherCount = (float)otherCount;
	float otherPerc, selfPerc;
	if(fOtherWins == 0) otherPerc = 0;
	else otherPerc = fOtherWins / fOtherCount;
	if(fSelfWins == 0) selfPerc = 0;
	else selfPerc = fSelfWins / fSelfCount;
	if(floatEqual(otherPerc, selfPerc)){
	    if((selfCount - selfWins) > (otherCount - otherWins)){
		return otherMove(round, myhist, opphist);
	    }else{
		return selfMove(round, myhist, opphist);
	    }
	}
	if(otherPerc < selfPerc && selfPerc >= 0.5){
	    return selfMove(round, myhist, opphist);
	}
	if(otherPerc > selfPerc && otherPerc >= 0.5){
	    return otherMove(round, myhist, opphist);
	}
	char move = rand()%2;
	if(move == 0) return selfMove(round, myhist, opphist);
	else return otherMove(round, myhist, opphist);
    }
}

register_player(player_rkumar6,"rkumar6");

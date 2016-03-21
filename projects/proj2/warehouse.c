#include "slots.h"
#include <stdio.h>

void updateAge(int bin);
void printAges();
int nextBin = 0;
int oldest = -1;
int changed = -1;
int slotAge[4] = {0, 0, 0, 0};

int main(int argc, char ** argv) {
    int bin;
    int found;
    initSlots();
    while(1==scanf("%d",&bin)) {
	found = findSlot(bin);
	if (-1==found) {
	    if(nextBin < 4){
		getBin(bin, nextBin);
		changed = nextBin;
		++ nextBin;
	    }else{
		getBin(bin, oldest);
		changed = oldest;
	    }
	}else{
	    changed = found;
	}
	updateAge(changed);
	getWidget(bin);	
	/* printAges(); */
    }
    printEarnings();
    return 0;
}

void printAges(){
    int i;
    printf("{");
    for(i = 0; i < 4; ++ i){
	printf("%d, ", slotAge[i]);
    }
    printf("}\n");
}

void updateAge(int bin){
    int max = -1;
    int maxIndex = -1;
    int i;
    for(i = 0; i < 4; ++ i){
	if(i != bin) slotAge[i] = slotAge[i] + 1;
	else slotAge[i] = 0;
	if(max < slotAge[i]){
	    max = slotAge[i];
	    maxIndex = i;
	}
    }
    oldest = maxIndex;
}

int minFreq(enum colors color) {
    assert(color>=0);
    if (color==uv) return 1000000;
    assert(color<uv);
    return maxw[color+1];
}

int main(int argc, char **argv) {
    /* enum colors color; */
    /* int i; */
    /* for(i=1; i<argc; i++) { */
    /* 	int freq=atoi(argv[i]); */
    /* 	if (freq) { */
    /* 	    color=getColor(freq); */
    /* 	    printf("Color %s has frequency %d to %d THz\n", */
    /* 		   colorName(color),minFreq(color),maxFreq(color)); */
    /* 	} */
    /* } */
    return 0;
}

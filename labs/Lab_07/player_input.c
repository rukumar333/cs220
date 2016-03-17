rps player_input(int round,rps *myhist,rps *opphist) {
    char in[12];
    printf("Enter choice: ");
    scanf ("%[^\n]%*c", in);
    if(in[0] == 'R' || in[0] == 'r'){
	return Rock;
    }
    if(in[0] == 'S' || in[0] == 's'){
	return Scissors;
    }
    return Paper;
}

register_player(player_input,"input");

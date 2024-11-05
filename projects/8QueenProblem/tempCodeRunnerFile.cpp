	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; i++){
			if((i+j)%2==0){
				board[i][j] = &bb;
			}
			else {
				board[i][j] = &wb;
			}
		}
	}
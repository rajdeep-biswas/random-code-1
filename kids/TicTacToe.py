def display_board():
    print(board[0]+"    |"+board[1]+"    |"+board[2])
    print("-----------------")
    print(board[3]+"    |"+board[4]+"    |"+board[5])
    print("-----------------")
    print(board[6]+"    |"+board[7]+"    |"+board[8])
def check_win():
    if board[0]==board[1]==board[2]!=" " or board[3]==board[4]==board[5]!=" " or board[6]==board[7]==board[8]!=" " or board[0]==board[3]==board[6]!=" " or board[1]==board[4]==board[7]!=" " or board[2]==board[5]==board[8]!=" " or board[0]==board[4]==board[8]!=" " or board[6]==board[4]==board[2]!=" ":
        return False
    else:
        return True
def check_draw():
    if board.count(" ")==0:
        return False
    else:
        return True
start_game="Y"
while start_game=="Y":
    board=[]
    board=[" "]*9
    p1=input("Enter Player 1's name ")
    p2=input("Enter Player 2's name ")
    next_turn_valid=True
    turn=0
    result=0
    
    while (next_turn_valid):
        if turn==0:
            display_board()
            pos=int(input(p1+" enter the position "))
            if pos<1 or pos>9 or board[pos-1]!=" ":
                print("Invalid position")
            
            else:
                board[pos-1]="X"
                next_turn_valid = check_win()
                if next_turn_valid==False:
                    result=1
                    continue
                next_turn_valid=check_draw()
                turn=1
               
        else:
            display_board()
            pos=int(input(p2+" enter the position "))
            if pos<1 or pos>9 or board[pos-1]!=" ":
                print("Invalid position")
            
            else:
                board[pos-1]="O"
                next_turn_valid=check_win()
                if next_turn_valid==False:
                    result=2
                    continue
                next_turn_valid=check_draw()
                turn=0
    if result==0:
        display_board()
        start_game=input("The match is drawn. Do you want to start again? Y for Yes, N for No ")
    elif result==1:
        display_board()
        start_game=input("Congratulations "+p1+"..!! You have won the game. Do you want to start again? Y for Yes, N for No ")
    else:
        display_board()
        start_game=input("Congratulations "+p2+"..!! You have won the game. Do you want to start again? Y for Yes, N for No ")
print("Thank You for trying out my game..! ")

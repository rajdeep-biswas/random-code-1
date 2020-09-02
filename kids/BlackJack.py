import random
suits=["Hearts","Diamonds","Spades","Clubs"]
ranks=["Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"]
values={"Ace":11,"Two":2,"Three":3,"Four":4,"Five":5,"Six":6,"Seven":7,"Eight":8,"Nine":9,"Ten":10,"Jack":10,"Queen":10,"King":10}
class Card:
    def __init__(self,suit,rank):
        self.suit=suit
        self.rank=rank
    def __str__(self):
        return self.rank +" of "+self.suit
class Deck:
    def __init__(self):
        self.deck=[]
        for suit in suits:
            for rank in ranks:
                self.deck.append(Card(suit,rank))
    def __str__(self):
       deck_comp=""
       for card in self.deck:
           deck_comp=deck_comp+"\n"+card.__str__()
       return("The deck has: "+deck_comp)
    def Shuffle(self):
        random.shuffle(self.deck)
    def deal(self):
        return self.deck.pop()
class hand:
    def __init__(self):
        self.owned_cards=[]
        self.value=0
        self.aces=0
    def add_card(self,card):
        self.owned_cards.append(card)
        self.value+= values[card.rank]
        if card.rank=="Ace":
            self.aces+=1
    def manage_aces(self):
        while self.value>21 and self.aces:
            self.value-=10
            self.aces-=1
class chips: 
    def __init__(self,total=100):
        self.total=total
        self.bet=0
    def win_bet(self):
        self.total+=self.bet
    def lose_bet(self):
        self.total-=self.bet
def take_bet(user):
    while True:
        try:
            bet=int(input("Enter your bet "))
        except:
            print("Enter an integer. ")
            continue
        else:
            if bet>user.total:
                print("Your bet is more than your available balance.")
                continue
            else:
                user.bet=bet
                break
def show_some(dealer,user):
    print("Dealer's Hand: \n",dealer.owned_cards[1])
    print("< Hidden Card >")
    print("\n")
    print("User's Hand: ", *user.owned_cards, sep="\n")
    print("\n")
def show_all(dealer,user):
    print("Dealer's Hand: \n", *dealer.owned_cards, sep="\n")
    print("Dealer's Hand Value: ", dealer.value)
    print("\n")
    print("User's Hand: ", *user.owned_cards, sep="\n")
    print("User's Hand Value: ", user.value)
    print("\n")
def user_wins(user):
    print("User wins..!!")
    print("\n")
    user.win_bet()
def user_busts(user):
    print("User busts... Dealer Wins...!! ")
    print("\n")
    user.lose_bet()
def dealer_wins(user):
    print("Dealer wins..!! ")
    print("\n")
    user.lose_bet()
def dealer_busts(user):
    print("Dealer Busts.. User Wins..!! ")
    print("\n")
    user.win_bet()
def hit_or_stand(dealer,user):
    global deck
    global user_chips
    decision=True
    while decision:
        decision=input("Do you want to hit or stand? Enter 'h' to hit or 's' to stand ")
        print("\n")
        if decision=='h':
            user.add_card(deck.deal())
            user.manage_aces()
            if user.value>21:
                   show_all(dealer,user)
                   user_busts(user_chips)
                   break
            show_some(dealer,user)
        else:
            while True:
                if dealer.value<17:
                    dealer.add_card(deck.deal())
                    dealer.manage_aces()
                    if dealer.value>21:
                        show_all(dealer,user)
                        dealer_busts(user_chips)
                        decision=False
                        break
                else:
                    if dealer.value>user.value:
                        show_all(dealer,user)
                        dealer_wins(user_chips)
                        decision=False
                        break
                    else:
                        show_all(dealer,user)
                        user_wins(user_chips)
                        decision=False
                        break
play= True
while play:
    print("Welcome to BlackJack. The User hits untill the sum reaches 21 and the dealer hits untill the sum is 17. Aces count as either 1 or 11.")
    print("\n")
    try:
            user_chips=chips(int(input("Enter the starting amount of chips with User. ")))
            print("\n")
    except:
            print("Enter an integer. ")
            print("\n")
            continue
    while True:
        deck=Deck()
        deck.Shuffle()
        take_bet(user_chips)
        user=hand()
        user.add_card(deck.deal())
        user.add_card(deck.deal())
        user.manage_aces()
        dealer=hand()
        dealer.add_card(deck.deal())
        dealer.add_card(deck.deal())
        dealer.manage_aces()
        show_some(dealer,user)
        hit_or_stand(dealer,user)
        if user_chips.total<=0:
            decision=input("GAME OVER. USER HAS LOST. Do you want to start a new game? Enter 'y' for yes or 'n' for no ")
            print("\n")
            if decision=='y':
                play=True
                break
            else:
                play=False
                break
        play_again=input("User's Chips stand at {}. Do you want to play again with the updated chips? Enter 'y' for yes or 'n' for no ".format(user_chips.total))
        print("\n")
        if play_again=='n':
            decision=input("Do you want to start a new game? Enter 'y' for yes or 'n' for no ")
            print("\n")
            if decision=='y':
                play=True
                break
            else:
                play=False
                break
print("Thank You for playing..!!")
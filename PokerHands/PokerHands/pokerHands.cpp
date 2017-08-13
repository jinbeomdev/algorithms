enum class patterns {
	C,
	D,
	H,
	S
};

enum class numbers {
	two = 2,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	T,
	J,
	Q,
	K,
	A
};

struct Card {
	int pattern;
	int number;
};

class PokerHands {
	
};

class Player {
	Card *cards;
public:
	Player() {
		cards = new Card[5];
	}
	~Player() {
		delete[] cards;
	}
};
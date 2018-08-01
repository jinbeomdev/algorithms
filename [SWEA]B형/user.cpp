#define N 4



typedef struct {

	int strike;

	int ball;

} Result;



// API

extern Result query(int guess[]);



void doUserImplementation(int guess[]) {

	// Implement a user's implementation function

	//

	// The array of guess[] is a return array that

	// is your guess for what digits[] would be.

}

/*
1) 리스트에 모든 경우의 수를 저장 해 놓음.
2) 랜덤으로 수를 뽑아서 query를 날려봄
3-1) 스트라이크 4 일 경우 return
3-2) 스트라이크와 볼이 조합된 경우
-		
3-3) 스트라이크와 볼이 하나도 없을 경우
- 해당 숫자를 가지고 있는 모든 노드를 삭제함
*/
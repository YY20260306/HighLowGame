#include <ctime>
#include <iostream>
#include <cstdlib>

int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr))); //時刻を乱数の種として取得→型を符号なし整数に変換
	int answer = std::rand() % 100 + 1; //100で割った余り0～99に+1することで1～100の乱数を取得

	int guess = 1; //解答者の入力を受け取る変数

	for (int i = 1; answer != guess; i++) {
		std::cout << "正解だと思う数字を入力してください。" << std::endl;
		std::cin >> guess;

		if (answer > guess) {
			std::cout << "もっと大きいです。" << std::endl;
		}
		else if (answer < guess) {
			std::cout << "もっと小さいです。" << std::endl;
		}
		else {
			std::cout << "正解です。おめでとう！" << std::endl;
			std::cout << i << "回目の入力で正解しました！" << std::endl;
		}

	}
return 0;
}
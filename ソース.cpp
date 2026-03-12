#include <ctime>
#include <iostream>
#include <cstdlib>

int main() {
	char retry; //リトライするかの入力を受け取る変数

	do{
	std::srand(static_cast<unsigned int>(std::time(nullptr))); //時刻を乱数の種として取得→型を符号なし整数に変換
	const int max_number = 100;
	int answer = std::rand() % max_number + 1; //100で割った余り0～99に+1することで1～100の乱数を取得

	int guess = 0; //解答者の入力を受け取る変数
	int count = 0; //解答した回数のカウント
	while (answer != guess) {
		std::cout << "1から" << max_number << "の中で正解だと思う数字を入力してください。" << std::endl;
		std::cin >> guess;

		if (std::cin.fail()) {
			std::cout << "数字以外を入力しないでください（怒）。" << std::endl;
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			continue;
		}

		count++;

		if (answer > guess) {
			std::cout << "もっと大きいです。" << std::endl;
		}
		else if (answer < guess) {
			std::cout << "もっと小さいです。" << std::endl;
		}
		else {
			std::cout << "正解です。おめでとう！" << std::endl;
			std::cout << count << "回目の入力で正解しました！" << std::endl;
		}
	}
		std::cout << "再トライなさいますか？（y/n）" << endl;
		std::cin >> retry;
		}while(retry == 'y');
return 0;
}

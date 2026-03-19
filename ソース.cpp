#include <ctime>
#include <iostream>
#include <cstdlib>

void PlayGame() {
	std::srand(static_cast<unsigned int>(std::time(nullptr))); //時刻を乱数の種として取得→型を符号なし整数に変換
	const int max_number = 10;
	int answer = std::rand() % max_number + 1; //100で割った余り0～99に+1することで1～100の乱数を取得
	const int give_up = 0;

	int guess = 0; //解答者の入力を受け取る変数
	int count = 0; //解答した回数のカウント
	while (true) {
		std::cout << "1から" << max_number << "の中で正解だと思う数字を入力してください。" << std::endl;
		std::cout << "ゲームをやり直すには" << give_up << "を入力してください。\n";
		std::cin >> guess;

		if (std::cin.fail()) {
			std::cout << "数字以外を入力しないでください（怒）。" << std::endl;
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			continue;
		} //まず最初に入力エラーをはじく（ガード条件？）

		else if (guess == give_up) {
			break;
		} //0を入力した際にやり直し

		count++;

		if (answer > guess) {
			std::cout << "もっと大きいです。" << std::endl;
		}
		else if (answer < guess) {
			std::cout << "もっと小さいです。" << std::endl;
		}
		else {
			std::cout << "正解です。おめでとう！\n"; //\nの場合は文字列の中に含む
			std::cout << count << "回目の入力で正解しました！" << std::endl;
			break; //これでループを抜けてAskRetry実行
		}
	}
}


bool AskRetry() {
	char retry; //リトライするかの入力を受け取る変数
	while (true) {
		std::cout << "再トライなさいますか？（y/n）" << std::endl;
		std::cin >> retry;

		if (retry == 'y') {
			return true;
		}
		else if (retry == 'n') {
			return false;
		}
		else if (retry != 'y' && retry != 'n') {
			std::cout << "yかnを入力してください（怒）。\n";
			std::cin.clear();
			std::cin.ignore(1024, '\n');
		}
	}
}


int main() {

	do {
		PlayGame();
	} while (AskRetry());
	return 0;
}
#include <ctime>
#include <iostream>
#include <cstdlib>

int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr))); //時刻を乱数の種として取得→型を符号なし整数に変換
	int answer = std::rand() % 100 + 1; //100で割った余り0～99に+1することで1～100の乱数を取得

	int guess; //解答者の入力を受け取る変数
	std::cout << "正解だと思う数字を入力してください。" << std::endl;
	std::cin >> guess;
}
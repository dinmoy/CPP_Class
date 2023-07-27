#include<SFML/Graphics.hpp>
#include<stdlib.h> // srand(), rand()
#include<time.h>   // time()

#include<stdio.h>

#define DIR_UP		0
#define DIR_DOWN	1
#define DIR_LEFT	2
#define DIR_RIGHT	3

#define BODY_MAX	20  // 뱀 몸통의 최대길이

using namespace sf;

const int WIDTH = 1000;
const int HEIGHT = 800;

int block = 40; // 한 칸을 40으로
const int W = WIDTH / block;
const int H = HEIGHT / block;

class Object {
public:
	int x_;
	int y_;
	RectangleShape sprite_; // 그래픽
};

class Apple {
public:
	int x_;
	int y_;
	RectangleShape sprite_;
};

class Snake {
public:
	// score에 값을 주지 않으면 default로 0이 들어간다
	Snake(int dir, int length, float thickness, int block, int score = 0) // == new Snake(DiR_DOWN, 1, 5.f, block, 0)
		:dir_(dir), length_(length), thickness_(thickness), score_(score)
	{
		inner_ = block - thickness_;
	}

	void InitBody(void)
	{
		float snake_inner = this->GetInner();
		for (int i = 0; i < BODY_MAX; i++) {
			this->body_[i].x_ = -100;
			this->body_[i].y_ = -100;
			this->body_[i].sprite_.setPosition(this->body_[i].x_ * block, this->body_[i].y_ * block);
			this->body_[i].sprite_.setSize(Vector2f(inner_, inner_));
			this->body_[i].sprite_.setFillColor(Color::Green);

			// 뱀의 테두리
			this->body_[i].sprite_.setOutlineColor(Color::Color(0, 128, 0));
			this->body_[i].sprite_.setOutlineThickness(5);
		}
		this->body_[0].x_ = 3;
		this->body_[0].y_ = 3;
	}

	// 현재 사과를 먹고있는 상태인가?
	bool isCollide(Apple* apple)
	{
		return this->body_[0].x_ == apple->x_ && this->body_[0].y_ == apple->y_;
	}

	//몸통
	void UpdateBody(void)
	{
		// 몸통에 대한 이동
		// 몸통만 움직이게 하기 위해서 0보다 클 때까지만
		for (int i = length_; i > 0; i--) {
			this->body_[i].x_ = this->body_[i - 1].x_;
			this->body_[i].y_ = this->body_[i - 1].y_;
		}
	}

	//머리
	void UpdateHead(void)
	{
		// 머리에 대한 이동
		if (dir_ == DIR_UP) {
			this->body_[0].y_--;
		}
		else if (dir_ == DIR_DOWN) {
			this->body_[0].y_++;
		}
		else if (dir_ == DIR_RIGHT) {
			this->body_[0].x_++;
		}
		else if (dir_ == DIR_LEFT) {
			this->body_[0].x_--;
		}
	}

	void UpdateBoundary(void)
	{
		// 경계범위(바운더리)를 넘어섰을 때, 화면 밖으로 넘어갔을 때
		if (this->body_[0].x_ < 0)
			this->body_[0].x_ = 0;
		if (this->body_[0].x_ >= W)
			this->body_[0].x_ = W - 1;
		if (this->body_[0].y_ < 0)
			this->body_[0].y_ = 0;
		if (this->body_[0].y_ >= H)
			this->body_[0].y_ = H - 1;

		for (int i = 0; i < length_; i++) {
			this->body_[i].sprite_.setPosition(this->body_[i].x_ * block, this->body_[i].y_ * block);
		}
	}

	void Render(RenderWindow* window)
	{
		for (int i = 0; i < BODY_MAX; i++)
			window->draw(this->body_[i].sprite_);
	}

	int GetDir(void) { return dir_; }
	int GetLength(void) { return length_; }
	int GetScore(void) { return score_; }
	int GetThickness(void) { return thickness_; }
	int GetInner(void) { return inner_; }

	void SetDir(int dir) { dir_ = dir; }
	void SetLength(int length) { length_ = length; }
	void SetCore(int score) { score_ = score; }
	void Setthickness(int thickness) { thickness_ = thickness; }
	void SetInner(int inner) { inner_ = inner; }

	void IncLength(void) { length_++; }
	void IncScore(int val) { score_ += val; }

private:
	int dir_;
	int length_ = 1; // 길이
	int score_;
	float thickness_;   // 외피두께
	float inner_; // 내부두께
	Object body_[BODY_MAX];
};

int main(void)
{
	printf("%d \n", DIR_RIGHT);


	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Snake Game");

	// 1초에 60번의 작업이 이루어 지도록 frame 조절
	// 컴퓨터 사양이 달라도 똑같은 속도로 처리함

	window.setFramerateLimit(12);

	srand(time(NULL));

	Font font;
	// bool ss = font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
	if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
	{
		printf("폰트 불러오기 실패\n");
		return -1;
	}

	Text info;
	info.setFont(font);
	info.setCharacterSize(60);
	info.setFillColor(Color::Magenta);

	char info_text[100];


	Snake snake = Snake(DIR_DOWN, 1, 5.f, block);
	snake.InitBody();

	Apple apple;
	apple.x_ = rand() % W;
	apple.y_ = rand() % H;
	apple.sprite_.setPosition(apple.x_ * block, apple.y_ * block);
	apple.sprite_.setSize(Vector2f(block, block));
	apple.sprite_.setFillColor(Color::Red);

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			// 윈도우의 x를 눌렀을 때 창이 닫아지도록
			if (e.type == Event::Closed) // x표를 누른다면
				window.close();
		}

		sprintf(info_text, "score : %d \n", snake.GetScore());
		info.setString(info_text);

		// input
		// else if로 하면 키를 동시에 적용할 수 없음
		// 네 개의 방향키가 중복으로 input되면 안 됨
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			snake.SetDir(DIR_UP);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			snake.SetDir(DIR_DOWN);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			snake.SetDir(DIR_RIGHT);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			snake.SetDir(DIR_LEFT);
		}

		// update

		// 뱀이 사과를 먹으면 길이가 길어짐
		// if (snake.body_[0].x_ == apple.x_ && snake.body_[0].y_ == apple.y_)
		if (snake.isCollide(&apple)) // intersect == 교집합
		{
			apple.x_ = rand() % W;
			apple.y_ = rand() % H;
			apple.sprite_.setPosition(apple.x_ * block, apple.y_ * block);
			snake.IncScore(100);
			if (snake.GetLength() < BODY_MAX)
				snake.IncLength();
		}

		snake.UpdateBody();
		snake.UpdateHead();
		snake.UpdateBoundary();

		// render
		window.clear();

		snake.Render(&window);

		window.draw(apple.sprite_); // 뱀과 사과가 겹칠경우 사과가 위에 나옴 (draw한 순서 때문)
		window.draw(info);

		window.display();
	}

	return 0;
}
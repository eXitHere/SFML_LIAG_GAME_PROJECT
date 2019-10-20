#include<"kickBall>

kickBall::kickBall()
{
	this->Ball.loadFromFile("texture\\effect\\ball.png");
	this->texture.loadFromFile("texture\\effect\\effect_ball.png");
	this->ball.setScale(0.7, 0.7);
	this->obj.setScale(0.7, 0.7);
	this->ball.setTexture(Ball);
	this->ball.setPosition(Vector2f(200, 650));
	this->obj.setTexture(texture);
	this->obj.setPosition(Vector2f(200, 690));
	this->obj.setTextureRect(this->Area);
	this->obj.setRotation(-15.0);
	//cout << "Load Complete !!";
}

void kickBall::testEffect(RenderWindow* window)
{
	if (this->haveBall)
	{
		// sin(x/5)*1000/x
		//this->ball.move(20,sin(A));
		//cout << A << endl;
		
		A-=1;
		B -= 0.3;
		window->draw(ball);
	    if (B < 0)
		{
			this->waitForHide = true;
		}
		else
		{
			this->ball.setPosition(this->ball.getPosition().x + B, 680 - (((abs(sin(A / 5) * A))) / 10) * 10);
		}
		if (waitForHide)
		{
			//cout << clock.getElapsedTime().asSeconds() << endl;;
			if (clock.getElapsedTime().asSeconds() >= 3)
			{
				this->haveBall = false;
				this->ball.setPosition(Vector2f(200, 680));
				clock.restart();
				waitForHide = false;
			}
		}
		//cout << this->ball.getPosition().x << endl;
	}
	if (this->haveEffect)
	{
		//cout << this->Area.width << endl;
		this->Area.width += 20;
		this->obj.setTextureRect(this->Area);
		window->draw(this->obj);
		if (Area.width > texture.getSize().x)
		{
			this->haveEffect = false;
			Area.width = 0;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::T) && !this->haveEffect && !this->haveBall)
	{
		this->haveEffect = true;
		this->haveBall = true;
		this->A = 100;
		this->B = 25;
		//cout << "Draw !!";
	}
}

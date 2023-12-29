#include <iostream>
#include <conio.h>


int main()
{
	ConsoleScreen NewScreen = ConsoleScreen('*');
	Galaga NewGalaga = Galaga();

	// Player가 bool& _OtherFire; 총알이 무조건 먼저 만들어져야 한다.
	Bullet NewBullet = Bullet({ 0,0 }, '^');
	// NewBullet.GetIsFireRef()
	Player NewPlayer = Player({ ScreenXHalf, ScreenYHalf }, '@');

	bool& Ref = NewBullet.GetIsFireRef();
	NewPlayer.SetBulletFire(&Ref);

	while (true)
	{
		NewScreen.ClearScreen();
		NewGalaga.GalagaWallDraw(NewScreen);

		int2 Index = NewPlayer.GetPos();
		char Ch = NewPlayer.GetRenderChar();

		NewScreen.SetPixel(Index, Ch);

		if (true == NewBullet.GetIsFireRef())
		{
			NewScreen.SetPixel(NewBullet.GetPos(), NewBullet.GetRenderChar());
		}

		NewScreen.PrintScreen();
		NewPlayer.Update();
	}
}

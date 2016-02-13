
#include "tikuneLib/ヘッダー/SceneManager.h"

int main()
{
	CApp::Get();

	SceneManager manager;

	while (CApp::Get().isOpen() &&
		   manager.CheckWhatTime() == false)
	{
		manager.UpDate();

		CApp::Get().begin();

		manager.Draw();

		CApp::Get().end();
	}
}

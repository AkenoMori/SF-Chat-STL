#include "Chat.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "");
	Chat chat;
	chat.startChat();
	chat.showLoginMenu();
	if (chat.work())
	{
		chat.showUserMenu();
	}
	return 0;
}
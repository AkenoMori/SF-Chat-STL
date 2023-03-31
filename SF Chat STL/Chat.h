#pragma once
#include <vector>
#include <exception>
#include <memory>
#include <algorithm>
#include "Message.h"

struct UserLoginEx : public std::exception
{
	const char* what() const noexcept override { return "Логин уже использован, введите другой вариант"; }
};

class Chat
{
public:
	void startChat();
	void showLoginMenu();
	void showUserMenu();
	bool work() const { return work_; }
	std::shared_ptr<User> getcurrentUser() const { return currentUser_; }

private:
	std::vector<User> userArr_;
	std::vector<Message> messageArr_;
	std::shared_ptr<User> currentUser_ = nullptr;
	bool work_ = false;

	void userLogin();
	void userRegistration();
	void showChat() const;
	void showAllUsers() const;
	void addMessage();

	std::vector<User>& getAlluser() { return userArr_; }
	std::vector<Message>& getAllmessage() { return messageArr_; }
	std::shared_ptr<User> getUserLog(const std::string& login) const;
	std::shared_ptr<User> getUserName(const std::string& name) const;
};
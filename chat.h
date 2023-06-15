#pragma once

#include <string.h>
#include <iostream>
#include "sha1.h"

#define NAME 10
#define LOGL 10

typedef char Name[NAME];

class chat
{
public:

	chat();
	~chat();
	void add(Name login, uint hpas);
	void reg(Name _login, char _pass[], int pass_length);
	bool login(char _login[10], char _pass[], int pass_length);

private:

	enum enps
	{
		free,
		eng,
		del
	};

	struct user
	{
		user();

		user(Name login, int hpas);

		user& operator = (const user& other);

		Name u_login;
		int u_hpas;
		enps status;
		uint* pass_sha1_hash;
	};

	int h_fun(Name login, int st);

	user* arr;
	int m_size;
	int count;
	
};


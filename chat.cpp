#include "chat.h"
#include <string.h>

chat::chat()
{
	count = 0;
	m_size = 8;
	arr = new user[m_size];
}
chat::~chat()
{
	delete[] arr;
}
void chat::reg(Name _login, char _pass[], int pass_length) {
	arr[count++] = user(_login, *sha1(_pass, pass_length));
}
bool chat::login(char _login[LOGL], char _pass[], int pass_length) {
	int i = 0;
	for (; i < count; i++) {
		user& ad = arr[i];
		if (!strcmp(ad.u_login, _login)) {
			break;
		}
	}
	if (i >= count) return false;

	uint* digest = sha1(_pass, pass_length);

	bool cmpHashes = !memcmp(
		arr[i].pass_sha1_hash,
		digest,
		SHA1HASHLENGTHBYTES);
	delete[] digest;

	return cmpHashes;
}
int chat::h_fun(Name login, int st)
{
	int sum = 0;
	int i = 0;
	for (i; i < strlen(login); ++i)
	{
		sum += login[i];
	}
	return (sum % m_size + st * st) % m_size;
}
chat::user::user(): u_login(""), u_hpas(-1), status(enps::free)
{}
chat::user::user(Name login, int hpas) : u_hpas(hpas), status(enps::eng)
{
	strcpy_s(u_login, login);
}
chat::user&  chat::user:: operator = (const user& other)
{
	u_hpas = other.u_hpas;
	strcpy_s(u_login, other.u_login);
	status = other.status;

	return *this;
}

void chat::add(Name login, uint hpas)
{
	int index = -1, i = 0;
	for (; i < m_size; i++)
	{
		index = h_fun(login, i);
		if (arr[index].status != enps::eng)
		{
			break;
		}
	}
	if (i >= m_size) return;

	arr[index] = user(login, hpas);
	count++;
}
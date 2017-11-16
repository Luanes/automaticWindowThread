#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include <string>
#include <curl/curl.h>

class Connection {
	public:
	Connection();
	std::string retrieve();

	private:
	static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

};
#endif /* CONNECTION_H_H */

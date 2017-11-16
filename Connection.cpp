#include "Connection.h"

Connection::Connection(){}

std::string Connection::retrieve(){
  CURL *curl;
  CURLcode res;
  std::string readBuffer;
  curl = curl_easy_init();
  if(curl) {
    const char *data = "tag=jLt";
    curl_easy_setopt(curl, CURLOPT_URL, "http://appinvtinywebdb.appspot.com/getvalue");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 7L);
    res = curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }
	std::cout << readBuffer<< std::endl;
    return readBuffer;
}

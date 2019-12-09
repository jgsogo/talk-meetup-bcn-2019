
#include <iostream>
#include <sstream>
#include <string>

#include <curl/curl.h>
#include <oauth.h>

int main() {
    const char* api_key = std::getenv("TWITTER_API_KEY");
    const char* api_secret_key = std::getenv("TWITTER_API_SECRET_KEY");
    const char* access_token = std::getenv("TWITTER_ACCESS_TOKEN");
    const char* access_token_secret = std::getenv("TWITTER_ACCESS_TOKEN_SECRET");

    std::cout << "TWITTER_API_KEY: '" << api_key << "'\n";
    std::cout << "TWITTER_ACCESS_TOKEN: '" << access_token << "'\n";

    const std::string message = "This is a test message";

    curl_global_init(CURL_GLOBAL_DEFAULT);
    auto curl = curl_easy_init();

    std::ostringstream os;
    os << "https://api.twitter.com/1.1/statuses/update.json?status=" << curl_easy_escape(curl, message.c_str(), message.size());

    auto r = oauth_sign_url2(os.str().c_str(), nullptr, OA_HMAC, "POST", api_key, api_secret_key, access_token, access_token_secret);
    curl_easy_setopt(curl, CURLOPT_URL, r);
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Console client");
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1);

    auto status = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return 0;
}

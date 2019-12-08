
#include <iostream>
#include <sstream>
#include <string>

#include <sys/stat.h>
#include <curl/curl.h>
#include <oauth.h>

#include "base64.h"


const char* api_key = std::getenv("TWITTER_API_KEY");
const char* api_secret_key = std::getenv("TWITTER_API_SECRET_KEY");
const char* access_token = std::getenv("TWITTER_ACCESS_TOKEN");
const char* access_token_secret = std::getenv("TWITTER_ACCESS_TOKEN_SECRET");

int post_image(const char* image);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Pass a path to an image\n"; 
        return -1;
    }
    const char* image = argv[1];
    std::cout << "Will post image at " << image << "\n";

    std::cout << "TWITTER_API_KEY: '" << api_key << "'\n";
    //std::cout << "TWITTER_API_SECRET_KEY: '" << api_secret_key << "'\n";
    std::cout << "TWITTER_ACCESS_TOKEN: '" << access_token << "'\n";
    //std::cout << "TWITTER_ACCESS_TOKEN_SECRET: '" << access_token_secret << "'\n";
    
    
    const std::string message = "This is a test message";

    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    auto image_ret = post_image(image);
    curl_global_cleanup();
}

int post_image(const char* image) {
    struct stat file_info;
    FILE* fd = fopen(image, "rb"); /* open file to upload */ 
    if(!fd) {
        std::cerr << "Cannot read file";
        exit(-1);
    }
    /* to get the file size */ 
    if(fstat(fileno(fd), &file_info) != 0) {
        exit(-1);
    }
    std::cout << "Image '" << image << "' (size: '" << file_info.st_size << "')\n";

    auto curl = curl_easy_init();

    std::ostringstream os;
    os << "https://upload.twitter.com/1.1/media/upload.json?media_category=tweet_image";

    auto r = oauth_sign_url2(os.str().c_str(), nullptr, OA_HMAC, "POST", api_key, api_secret_key, access_token, access_token_secret);
    curl_easy_setopt(curl, CURLOPT_URL, r);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
    curl_easy_setopt(curl, CURLOPT_READDATA, fd);
    curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE, (curl_off_t)file_info.st_size);
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    //curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Console client");
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1);

    auto status = curl_easy_perform(curl);
    std::cout << "Status: " << status << "\n";
    std::cout << curl_easy_strerror(status) << "\n";
    return 0;
}

/*
int post_message() {
    auto curl = curl_easy_init();

    std::ostringstream os;
    os << "https://api.twitter.com/1.1/statuses/update.json?status=" << curl_easy_escape(curl, message.c_str(), message.size());

    auto r = oauth_sign_url2(os.str().c_str(), nullptr, OA_HMAC, "POST", api_key, api_secret_key, access_token, access_token_secret);
    curl_easy_setopt(curl, CURLOPT_URL, r);
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Console client");
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1);

    auto status = curl_easy_perform(curl);
    std::cout << "Status: " << status << "\n";

    curl_easy_cleanup(curl);
    
}
*/

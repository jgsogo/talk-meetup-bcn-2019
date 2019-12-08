#pragma once

#include <curl/curl.h>

size_t Curl_base64_encode(struct SessionHandle *data,
                          const char *input, size_t size, char **str);
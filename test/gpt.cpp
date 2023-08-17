//#define CURL_STATICLIB
//#include <iostream>
//#include <curl/curl.h>
//size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
//    ((std::string*)userp)->append((char*)contents, size * nmemb);
//    return size * nmemb;
//}
//
//int main() {
//    CURL* curl;
//    CURLcode res;
//    std::string response;
//
//    curl_global_init(CURL_GLOBAL_DEFAULT);
//    curl = curl_easy_init();
//    if (curl) {
//        std::string apiKey = "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";
//        std::string question = "What is the capital of France?";
//
//        std::string url = "https://api.openai.com/v1/chat/completions";
//        std::string postFields = R"({"messages":[{"role":"system","content":"You are a helpful assistant."},{"role":"user","content":")" + question + R"("}],"model": "gpt-3.5-turbo"})";
//
//        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.c_str());
//        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
//
//        struct curl_slist* headers = nullptr;
//        headers = curl_slist_append(headers, ("Content-Type: application/json"));
//        headers = curl_slist_append(headers, ("Authorization: Bearer " + apiKey).c_str());
//        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
//
//        res = curl_easy_perform(curl);
//
//        if (res != CURLE_OK) {
//            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
//        }
//        else {
//            std::cout << "Response: " << response << std::endl;
//        }
//
//        curl_easy_cleanup(curl);
//        curl_slist_free_all(headers);
//    }
//    curl_global_cleanup();
//
//    return 0;
//}
//#define CURL_STATICLIB
//#include <iostream>
//#include <curl/curl.h>
//
//
//void get_price() {
//    CURL* curl;
//    CURLcode res;
//    std::string response;
//
//    curl_global_init(CURL_GLOBAL_DEFAULT);
//    curl = curl_easy_init();
//    if (curl) {
//        // Составьте URL-адрес для получения курса определенной криптовалюты, например BTCUSDT
//        std::string url = "https://api.binance.com/api/v3/ticker/price?symbol=BTCUSDT";
//
//        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//        //curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
//
//        curl_easy_perform(curl);
//        std::cout << "Response: " << response << std::endl;
//        //if (res != CURLE_OK) {
//        //    std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
//        //}
//        //else {
//        //    // Обработка полученных данныхbd::endl;
//        //   
//        //}
//
//        curl_easy_cleanup(curl);
//    }
//    curl_global_cleanup();
//}
//
//
//
//int main() {
//
//    get_price();
//
//	return 0;
//}

//sk - sO8QkzQC4yaTIDARfCHaT3BlbkFJf0uuzO6umGoQKqdC7roC
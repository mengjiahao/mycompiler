#ifndef INCLUDE_LOGIMSG_H
#define INCLUDE_LOGIMSG_H

#include <iostream>
#include <string>

using namespace std;

class LogiMsg {
    public:
        string log;

        inline static void logi(const string &msg_t) {
            std::cout << msg_t << std::endl;
        }

        inline static void logi(const string &msg_t, int line_t) {
            std::cout << msg_t << " at line " << line_t << std::endl;
        }

};

#endif

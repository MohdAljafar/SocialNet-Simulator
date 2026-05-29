#ifndef POST_HPP
#define POST_HPP

#include <string>

class Post {
public:
    long long timestamp;
    std::string content;

    Post(long long ts, const std::string& text)
        : timestamp(ts), content(text) {}
};

#endif
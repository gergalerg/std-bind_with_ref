#ifndef TEST_H_
#define TEST_H_

#include <string>
#include <iostream>

namespace Lexer {
    enum class Kind : char {
        name=66, number, end, plus='='

    };
    struct Token {
        Kind kind;
        std::string string_value;
        double number_value;
    };
    class Token_stream {
    public:
        Token_stream(std::istream s) {}
        Token_stream(std::istream* p) {}
        Token_stream() : ct{Kind::name } {}
        ~Token_stream() { close(); }

        Kind get() { return ct.kind; };
        Token& current();

    private:
    void close() { if (owns) delete ip;} 

    std::istream* ip;
    bool owns; 
    Token ct { Kind::end };
    };
    extern Token_stream ts; 
}
#endif

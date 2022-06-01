#ifndef _FUNC_H
#define _FUNC_H
#include <iostream>
#include <string>
#include <algorithm>

class Codec {
public:
    virtual void encode() = 0;
    virtual void decode() = 0;
    virtual ~Codec() { } // Do nothing
    virtual void show(std::ostream& os) const = 0;
    virtual bool is_encoded() const = 0;
};

class DummyCodec: public Codec {
public:
    DummyCodec(std::string s): encoded{false}, code_str{s} { }

    void encode() {
        encoded = true;
    }

    void decode() {
        encoded = false;
    }

    void show(std::ostream& os) const {
        os << code_str;
    }

    bool is_encoded() const { return encoded; }

private:
    bool encoded;
    std::string code_str;
};

class RleCodec: public Codec
{
public:
    RleCodec(std::string s): encoded{false}, code_str{s} { }
    void encode();
    void decode();
    void show(std::ostream& os) const {
        os << code_str;
    }
    bool is_encoded() const { return encoded; }

private:
    bool encoded;
    std::string code_str;
};
void RleCodec::encode() {
    encoded = true;
    std::string cp;
    char tmp = code_str[0];
    int count = 1;
    for (int i = 1; i <= code_str.size(); i++) {
        if (code_str[i] == tmp) {
            count++;
        }
        else {
            if (count == 1) {
                cp += tmp;
                tmp = code_str[i];
            }
            else if (count == 2) {
                cp += tmp;
                cp += tmp;
                tmp = code_str[i];
                count = 1;
            }
            else {
                std::string n = std::to_string(count);
                cp += n;
                cp += tmp;
                tmp = code_str[i];
                count = 1;
            }
        }
    }
    code_str = cp;
}

void RleCodec::decode() {
    encoded = false;
    std::string cp, tmp;
    for (int i = 0; i < code_str.size(); i++) {
        if (code_str[i] <= '9' && code_str[i] >= '0') {
            tmp += code_str[i];
        }
        else {
            if (tmp == "") {
                cp += code_str[i];
            }
            else {
                int ct = std::stoi(tmp);
                for (int j = 0; j < ct; j++) cp += code_str[i];
                tmp = "";
            }
        }
    }
    code_str = cp;
}
#endif
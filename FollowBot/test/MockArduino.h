#ifndef ARDUINO_H_MOCK
#define ARDUINO_H_MOCK

#include <string>
#include <cstdint>
#include <algorithm>
#include <sstream>

// Forward declaration of the String class
class String;

// Mock Arduino functions
unsigned long millis() { return 0; }
unsigned long micros() { return 0; }

// String class implementation for mocking Arduino's String
class String {
private:
    std::string str;

public:
    // Constructors
    String() : str("") {}
    String(const char* cstr) : str(cstr ? cstr : "") {}
    String(const String& other) : str(other.str) {}
    String(const std::string& stdstr) : str(stdstr) {}
    String(float value, unsigned int decimalPlaces = 2) {
        std::ostringstream oss;
        oss.precision(decimalPlaces);
        oss << std::fixed << value;
        str = oss.str();
    }
    String(int value) { str = std::to_string(value); }

    // Assignment
    String& operator=(const String& rhs) {
        str = rhs.str;
        return *this;
    }
    String& operator=(const char* cstr) {
        str = cstr ? cstr : "";
        return *this;
    }

    // Concatenation
    String& operator+=(const String& rhs) {
        str += rhs.str;
        return *this;
    }
    String operator+(const String& rhs) const {
        return String(str + rhs.str);
    }
    friend String operator+(const char* lhs, const String& rhs) {
        return String(std::string(lhs) + rhs.str);
    }

    // Comparison
    bool operator==(const String& rhs) const { return str == rhs.str; }
    bool operator==(const char* cstr) const { return str == std::string(cstr ? cstr : ""); }
    bool operator!=(const String& rhs) const { return !(*this == rhs); }
    bool operator!=(const char* cstr) const { return !(*this == cstr); }
    
    // String methods
    unsigned int length() const { return str.length(); }
    bool startsWith(const String& prefix) const {
        return str.rfind(prefix.str, 0) == 0;
    }

    // Conversion
    float toFloat() const { 
        try {
            return std::stof(str);
        } catch(...) {
            return 0.0f;
        }
    }
    int toInt() const { 
        try {
            return std::stoi(str);
        } catch(...) {
            return 0;
        }
    }
    const char* c_str() const { return str.c_str(); }

    // Arduino String methods
    String substring(unsigned int beginIndex, unsigned int endIndex = std::string::npos) const {
        if (beginIndex >= str.length()) return "";
        if (endIndex == std::string::npos) endIndex = str.length();
        endIndex = std::min(endIndex, str.length());
        return String(str.substr(beginIndex, endIndex - beginIndex));
    }

    int indexOf(char ch, unsigned int fromIndex = 0) const {
        if (fromIndex >= str.length()) return -1;
        size_t pos = str.find(ch, fromIndex);
        return pos == std::string::npos ? -1 : (int)pos;
    }

    int indexOf(const String& val, unsigned int fromIndex = 0) const {
        if (fromIndex >= str.length()) return -1;
        size_t pos = str.find(val.str, fromIndex);
        return pos == std::string::npos ? -1 : (int)pos;
    }

    String& trim() {
        // Remove whitespace from beginning and end
        size_t start = str.find_first_not_of(" \t\n\r\f\v");
        if (start == std::string::npos) {
            str = "";
            return *this;
        }
        size_t end = str.find_last_not_of(" \t\n\r\f\v");
        str = str.substr(start, end - start + 1);
        return *this;
    }

    // Debug output
    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        return os << str.str;
    }
};

// Additional Arduino functions
void delay(unsigned long ms) {}
void pinMode(int pin, int mode) {}
int digitalRead(int pin) { return 0; }
void digitalWrite(int pin, int val) {}
int analogRead(int pin) { return 0; }

// Constants
#define HIGH 1
#define LOW 0
#define INPUT 0
#define OUTPUT 1
#define INPUT_PULLUP 2

class Serial_ {
public:
    void begin(int baud) {}
    void print(const String& s) {}
    void print(const char* s) {}
    void print(int n) {}
    void print(float f, int precision = 2) {}
    void println(const String& s) {}
    void println(const char* s) {}
    void println(int n) {}
    void println(float f, int precision = 2) {}
    void println() {}
    int available() { return 0; }
    String readStringUntil(char c) { return String(); }
};

// Global Serial object
extern Serial_ Serial;
Serial_ Serial;

#endif // ARDUINO_H_MOCK
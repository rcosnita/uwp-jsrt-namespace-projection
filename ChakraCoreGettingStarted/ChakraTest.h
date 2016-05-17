#pragma once
#include <jsrt.h>

#include <string>

using namespace std;

namespace jsutils {
    class ChakraTest {
    public:
        ChakraTest();
        virtual ~ChakraTest();

        wstring sayHello();

    private:
        JsRuntimeHandle runtime_;
        JsContextRef context_;
    };
}
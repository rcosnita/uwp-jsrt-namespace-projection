#pragma once
#include <jsrt.h>

#include <string>

using namespace std;
using namespace Windows::UI::Xaml::Controls;

namespace jsutils {
    class ChakraTest {
    public:
        ChakraTest(TextBox^ textfield);
        virtual ~ChakraTest();

        wstring sayHello();
        void runApp(Platform::String^ fileName);

    private:
        TextBox^ textfield_;
        JsRuntimeHandle runtime_;
        JsContextRef context_;
    };
}
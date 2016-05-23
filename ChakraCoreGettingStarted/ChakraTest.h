#pragma once
#include <jsrt.h>

#include <string>

using namespace std;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml::Controls;

using namespace WindowsRuntimeComponent1::Events;

namespace jsutils {
    class ChakraTest {
    public:
        ChakraTest(TextBox^ textfield, EventEmitter^ eventEmitter, CoreDispatcher^ uiDispatcher);
        virtual ~ChakraTest();

        wstring sayHello();
        void runApp(Platform::String^ fileName);

    private:
        CoreDispatcher^ uiDispatcher_;
        EventEmitter^ eventEmitter_;
        TextBox^ textfield_;

        JsRuntimeHandle runtime_;
        JsContextRef context_;
    };
}
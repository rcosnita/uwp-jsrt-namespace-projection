#pragma once

using namespace Platform;
using namespace Windows::UI::Xaml::Controls;

namespace WindowsRuntimeComponent1
{
    public ref class Class1 sealed
    {
    public:
        Class1();

        Class1(TextBox^ textfield);

        String^ sayHello(String^ msg);

        void updateUI(String^ msg);
    
        static Class1^ GetInstance();

    private:
        static Class1^ instance_;
        TextBox^ textfield_;
    };
}

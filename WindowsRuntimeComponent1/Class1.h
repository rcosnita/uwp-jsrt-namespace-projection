#pragma once

#include "events\EventsEmitter.h"

using namespace Platform;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml::Controls;

using namespace WindowsRuntimeComponent1::Events;

namespace WindowsRuntimeComponent1
{
    public ref class Class1 sealed
    {
    public:
        property EventEmitter^ Emitter {
            EventEmitter^ get();
        }
    public:
        Class1();

        Class1(TextBox^ textfield, EventEmitter^ eventEmitter, CoreDispatcher^ uiDispatcher_);

        String^ sayHello(String^ msg);

        void updateUI(String^ msg);

        bool processEvents();

        static Class1^ GetInstance();

    private:
        CoreDispatcher^ uiDispatcher_;
        EventEmitter^ eventEmitter_;
        static Class1^ instance_;
        TextBox^ textfield_;
    };
}

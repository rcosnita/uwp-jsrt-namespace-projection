#pragma once

#include <map>
#include <vector>

using namespace Platform;

namespace WindowsRuntimeComponent1 {
namespace Events {
    public delegate void EventHandlerFn(String^ evtName);

    public ref class EventEmitter sealed {
    public:
        void on(String^ evtName, EventHandlerFn^ fn);

        void emit(String^ evtName);

        void processEvents();
    private:
        std::map<Platform::String^, std::vector<EventHandlerFn^>> listeners_;
        std::vector<Platform::String^> pendingEvents_;
    };
}
}
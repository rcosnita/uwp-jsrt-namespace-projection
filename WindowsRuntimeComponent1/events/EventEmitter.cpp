#include "pch.h"
#include "EventsEmitter.h"

namespace WindowsRuntimeComponent1 {
namespace Events {
    void EventEmitter::on(String^ evtName, EventHandlerFn^ fn) {
        auto handlers = listeners_[evtName];

        handlers.push_back(fn);

        listeners_[evtName] = handlers;
    }

    void EventEmitter::emit(String^ evtName) {
        pendingEvents_.push_back(evtName);
    }

    void EventEmitter::processEvents() {
        for (auto evtIt = pendingEvents_.begin(); evtIt != pendingEvents_.end(); evtIt++) {
            auto evtName = *evtIt;
            auto handlers = listeners_[evtName];

            for (auto it = handlers.begin(); it != handlers.end(); it++) {
                (*it)(evtName);
            }
        }

        pendingEvents_.clear();
    }
}
}
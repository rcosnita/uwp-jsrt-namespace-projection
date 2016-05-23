#include "pch.h"
#include "Class1.h"

#include <chrono>
#include <thread>

using namespace WindowsRuntimeComponent1;
using namespace Platform;

Class1^ Class1::instance_ = nullptr;

Class1::Class1()
{
    instance_ = this;
}

Class1::Class1(TextBox^ textfield, EventEmitter^ eventEmitter, CoreDispatcher^ uiDispatcher)
    : textfield_(textfield),
      eventEmitter_(eventEmitter),
      uiDispatcher_(uiDispatcher)
{
    instance_ = this;
}

EventEmitter^ Class1::Emitter::get() {
    return eventEmitter_;
}

String^ Class1::sayHello(String^ msg) {
    return msg;
}

void Class1::updateUI(String^ msg) {
    uiDispatcher_->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this, msg]() {
        textfield_->Text = msg;
    }));
}

bool Class1::processEvents() {
    eventEmitter_->processEvents();

    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    return true;
}

Class1^ Class1::GetInstance() {
    return instance_;
}
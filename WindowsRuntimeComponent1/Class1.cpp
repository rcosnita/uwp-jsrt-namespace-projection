#include "pch.h"
#include "Class1.h"

using namespace WindowsRuntimeComponent1;
using namespace Platform;

Class1^ Class1::instance_ = nullptr;

Class1::Class1()
{
    instance_ = this;
}

Class1::Class1(TextBox^ textfield)
    : textfield_(textfield)
{
    instance_ = this;
}

Class1^ Class1::GetInstance() {
    return instance_;
}

String^ Class1::sayHello(String^ msg) {
    return msg;
}

void Class1::updateUI(String^ msg) {
    textfield_->Text = msg;
}
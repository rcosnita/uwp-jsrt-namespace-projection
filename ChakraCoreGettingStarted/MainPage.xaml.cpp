//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <iostream>

using namespace ChakraCoreGettingStarted;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

static DependencyProperty^ HelloMsgProperty = DependencyProperty::RegisterAttached(
    "HelloMsg",
    String::typeid,
    MainPage::typeid,
    ref new PropertyMetadata(nullptr)
);

static DependencyProperty^ MsgForJsProperty = DependencyProperty::RegisterAttached(
    "MsgForJs",
    String::typeid,
    MainPage::typeid,
    ref new PropertyMetadata(nullptr)
);


MainPage::MainPage() {
    InitializeComponent();

    eventEmitter_ = ref new EventEmitter();
    chakraTest_ = new jsutils::ChakraTest(helloMsg, eventEmitter_, Dispatcher);

    DataContext = this;

    appThread_ = std::thread([this]() {
        chakraTest_->runApp("js/app.js");
    });
}

MainPage::~MainPage() {
    delete chakraTest_;
}

String^ MainPage::HelloMsg::get() {
    return dynamic_cast<String^>(GetValue(HelloMsgProperty));
}

void MainPage::HelloMsg::set(String^ value) {
    SetValue(HelloMsgProperty, value);
}

String^ MainPage::MsgForJs::get() {
    return dynamic_cast<String^>(GetValue(MsgForJsProperty));
}

void MainPage::MsgForJs::set(String^ value) {
    SetValue(MsgForJsProperty, value);
}

void ChakraCoreGettingStarted::MainPage::button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    auto result = chakraTest_->sayHello();
    String^ msg = ref new String(result.c_str());

    SetValue(HelloMsgProperty, msg);
}

void ChakraCoreGettingStarted::MainPage::btnLaunchApp_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    auto msg = MsgForJs;

    HelloMsg = "No event handler registered for " + msg + ". Try changedEvent or changedEvent2";

    eventEmitter_->emit(msg);
}

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

MainPage::MainPage()
{
	InitializeComponent();

    DataContext = this;
}


void ChakraCoreGettingStarted::MainPage::button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    auto result = chakraTest_.sayHello();
    String^ msg = ref new String(result.c_str());

    SetValue(HelloMsgProperty, msg);
}

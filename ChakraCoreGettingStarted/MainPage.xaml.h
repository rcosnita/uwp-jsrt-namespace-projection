//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
#include "ChakraTest.h"

#include <thread>

using namespace Platform;
using namespace WindowsRuntimeComponent1::Events;

namespace ChakraCoreGettingStarted
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
    public:
        property String^ HelloMsg {
            String^ get();
            void set(String^ value);
        }

        property String^ MsgForJs {
            String^ get();
            void set(String^ value);
        }
	public:
		MainPage();
        virtual ~MainPage();

    private:
        std::thread appThread_;
        jsutils::ChakraTest* chakraTest_;
        EventEmitter^ eventEmitter_;
    private:
        void button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void btnLaunchApp_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
    };
}

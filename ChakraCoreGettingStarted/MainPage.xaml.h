//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
#include "ChakraTest.h"

namespace ChakraCoreGettingStarted
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
    public:
        property Platform::String^ HelloMsg;
	public:
		MainPage();
        virtual ~MainPage();

    private:
        jsutils::ChakraTest* chakraTest_;
    private:
        void button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void btnLaunchApp_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
    };
}

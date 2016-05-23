#include "pch.h"

#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

#include "ChakraTest.h"

using namespace std;

jsutils::ChakraTest::ChakraTest(TextBox^ textfield, EventEmitter^ eventEmitter, CoreDispatcher^ uiDispatcher)
    : textfield_(textfield),
      eventEmitter_(eventEmitter),
      uiDispatcher_(uiDispatcher)
{
    JsCreateRuntime(JsRuntimeAttributeNone, nullptr, &runtime_);
    JsCreateContext(runtime_, &context_);
    JsSetCurrentContext(context_);

    JsProjectWinRTNamespace(L"WindowsRuntimeComponent1");
    JsStartDebugging();
}

jsutils::ChakraTest::~ChakraTest() {
    JsSetCurrentContext(JS_INVALID_REFERENCE);
    JsDisposeRuntime(runtime_);
}

wstring jsutils::ChakraTest::sayHello()
{
    JsValueRef result;
    unsigned currentSourceContext = 0;
    wstring script = L"(() => {var comp = new WindowsRuntimeComponent1.Class1(); return comp.sayHello(\"Works just fine ...\");})()";

    JsRunScript(script.c_str(), currentSourceContext++, L"", &result);
    JsValueRef resultJSString;
    JsConvertValueToString(result, &resultJSString);

    const wchar_t *resultWC;
    size_t stringLength;
    JsStringToPointer(resultJSString, &resultWC, &stringLength);

    wstring resultW(resultWC);

    return resultW;
}

static std::wstring readFile(Platform::String^ fileName) {
    auto fileNameData = fileName->Data();
    std::wstring fileNameWide = fileNameData;
    std::string fileNameStr(fileNameWide.begin(), fileNameWide.end());

    std::ifstream t(fileNameStr);
    std::wstring str((std::istreambuf_iterator<char>(t)),
                     std::istreambuf_iterator<char>());

    return str;
}

void jsutils::ChakraTest::runApp(Platform::String^ fileName) {
    auto appScript = readFile(fileName);

    JsRuntimeHandle runtimeHandleInner;
    JsContextRef contextInner;

    JsCreateRuntime(JsRuntimeAttributeNone, nullptr, &runtimeHandleInner);
    JsCreateContext(runtimeHandleInner, &contextInner);
    JsSetCurrentContext(contextInner);

    JsProjectWinRTNamespace(L"WindowsRuntimeComponent1");
    JsStartDebugging();

    unsigned int sourceContext = 0;
    auto class1 = ref new WindowsRuntimeComponent1::Class1(textfield_, eventEmitter_, uiDispatcher_);
    JsRunScript(appScript.c_str(), sourceContext++, fileName->Data(), nullptr);

    JsSetCurrentContext(JS_INVALID_REFERENCE);
    JsDisposeRuntime(runtimeHandleInner);
}
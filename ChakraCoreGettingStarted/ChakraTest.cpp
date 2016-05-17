#include "pch.h"

#include <iostream>

#include "ChakraTest.h"

using namespace std;

jsutils::ChakraTest::ChakraTest() {
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
    wstring script = L"(() => {debugger;var comp = new WindowsRuntimeComponent1.Class1(); return comp.sayHello(\"Works just fine ...\");})()";

    JsRunScript(script.c_str(), currentSourceContext++, L"", &result);
    JsValueRef resultJSString;
    JsConvertValueToString(result, &resultJSString);

    const wchar_t *resultWC;
    size_t stringLength;
    JsStringToPointer(resultJSString, &resultWC, &stringLength);

    wstring resultW(resultWC);

    return resultW;
}
#include "QtCore/QTextDocumentFragment/qtextdocumentfragment_wrap.h"

#include "Extras/Utils/nutils.h"

Napi::FunctionReference QTextDocumentFragmentWrap::constructor;

Napi::Object QTextDocumentFragmentWrap::init(Napi::Env env,
                                             Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QTextDocumentFragment";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("isEmpty", &QTextDocumentFragmentWrap::isEmpty),
       InstanceMethod("toHtml", &QTextDocumentFragmentWrap::toHtml),
       InstanceMethod("toPlainText", &QTextDocumentFragmentWrap::toPlainText),
       StaticMethod("fromHtml",
                    &StaticQTextDocumentFragmentWrapMethods::fromHtml),
       StaticMethod("fromPlainText",
                    &StaticQTextDocumentFragmentWrapMethods::fromPlainText),
       COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QTextDocumentFragmentWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QTextDocumentFragmentWrap::QTextDocumentFragmentWrap(
    const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QTextDocumentFragmentWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    this->instance = std::unique_ptr<QTextDocumentFragment>(
        info[0].As<Napi::External<QTextDocumentFragment>>().Data());
  } else if (info.Length() == 0) {
    this->instance = std::make_unique<QTextDocumentFragment>();
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QTextDocumentFragmentWrap::~QTextDocumentFragmentWrap() {
  this->instance.reset();
}

QTextDocumentFragment* QTextDocumentFragmentWrap::getInternalInstance() {
  return this->instance.get();
}

Napi::Value QTextDocumentFragmentWrap::isEmpty(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  return Napi::Value::From(env, this->instance->isEmpty());
}
Napi::Value QTextDocumentFragmentWrap::toHtml(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  QString html = this->instance->toHtml();
  Napi::String txt = Napi::String::New(env, html.toStdString());
  return Napi::Value::From(env, txt);
}
Napi::Value QTextDocumentFragmentWrap::toPlainText(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  QString plainText = this->instance->toPlainText();
  Napi::String txt = Napi::String::New(env, plainText.toStdString());
  return Napi::Value::From(env, txt);
}
Napi::Value StaticQTextDocumentFragmentWrapMethods::fromHtml(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  std::string napiText = info[0].As<Napi::String>().Utf8Value();
  QString htmlText = QString::fromUtf8(napiText.c_str());

  auto frag = QTextDocumentFragment::fromHtml(htmlText);

  auto instance = QTextDocumentFragmentWrap::constructor.New(
      {Napi::External<QTextDocumentFragment>::New(
          env, new QTextDocumentFragment(frag))});
  // auto instance = QTextDocumentFragmentWrap::constructor.New(
  //     {Napi::External<QTextDocumentFragment>::New(env, )});
  return instance;
}
Napi::Value StaticQTextDocumentFragmentWrapMethods::fromPlainText(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  std::string napiText = info[0].As<Napi::String>().Utf8Value();
  QString text = QString::fromUtf8(napiText.c_str());

  auto frag = QTextDocumentFragment::fromPlainText(text);

  auto instance = QTextDocumentFragmentWrap::constructor.New(
      {Napi::External<QTextDocumentFragment>::New(
          env, new QTextDocumentFragment(frag))});
  // auto instance = QTextDocumentFragmentWrap::constructor.New(
  //     {Napi::External<QTextDocumentFragment>::New(env, )});
  return instance;
}
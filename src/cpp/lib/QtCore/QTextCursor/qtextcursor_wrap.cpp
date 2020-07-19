#include "QtCore/QTextCursor/qtextcursor_wrap.h"

#include "Extras/Utils/nutils.h"
#include "QtCore/QVariant/qvariant_wrap.h"

Napi::FunctionReference QTextCursorWrap::constructor;

Napi::Object QTextCursorWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QTextCursor";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      // {InstanceMethod("position", &QTextCursorWrap::position),
      {InstanceMethod("selectedText", &QTextCursorWrap::selectedText),
       InstanceMethod("movePosition", &QTextCursorWrap::movePosition),
       InstanceMethod("insertText", &QTextCursorWrap::insertText),
       InstanceMethod("insertHtml", &QTextCursorWrap::insertHtml),
       InstanceMethod("clearSelection", &QTextCursorWrap::clearSelection),
       // StaticMethod("fromQVariant",
       //              &StaticQTextCursorWrapMethods::fromQVariant),
       COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QTextCursorWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QTextCursorWrap::QTextCursorWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QTextCursorWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    this->instance = std::unique_ptr<QTextCursor>(
        info[0].As<Napi::External<QTextCursor>>().Data());
  } else if (info.Length() == 0) {
    this->instance = std::make_unique<QTextCursor>();
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QTextCursorWrap::~QTextCursorWrap() { this->instance.reset(); }

QTextCursor* QTextCursorWrap::getInternalInstance() {
  return this->instance.get();
}

// Napi::Value QTextCursorWrap::position(const Napi::CallbackInfo& info) {
//   Napi::Env env = info.Env();
//   Napi::HandleScope scope(env);
//   return Napi::Value::From(env, this->instance->position());
// }
Napi::Value QTextCursorWrap::clearSelection(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->instance->clearSelection();
  return env.Null();
}
Napi::Value QTextCursorWrap::insertText(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  std::string napiText = info[0].As<Napi::String>().Utf8Value();
  QString text = QString::fromUtf8(napiText.c_str());

  this->instance->insertText(text);

  return env.Null();
}
Napi::Value QTextCursorWrap::insertHtml(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  std::string napiText = info[0].As<Napi::String>().Utf8Value();
  QString text = QString::fromUtf8(napiText.c_str());

  this->instance->insertHtml(text);

  return env.Null();
}
Napi::Value QTextCursorWrap::movePosition(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int operation = info[0].As<Napi::Number>().Int32Value();
  int mode = info[1].As<Napi::Number>().Int32Value();

  this->instance->movePosition(QTextCursor::MoveOperation(operation),
                               QTextCursor::MoveMode(mode));
  return env.Null();
}
Napi::Value QTextCursorWrap::selectedText(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  QString text = this->instance->selectedText();
  Napi::String txt = Napi::String::New(env, text.toStdString());
  return Napi::Value::From(env, txt);
}
// Napi::Value StaticQTextCursorWrapMethods::fromQVariant(
//     const Napi::CallbackInfo& info) {
//   Napi::Env env = info.Env();
//   Napi::HandleScope scope(env);
//   Napi::Object variantObject = info[0].As<Napi::Object>();
//   QVariantWrap* variantWrap =
//       Napi::ObjectWrap<QVariantWrap>::Unwrap(variantObject);
//   QVariant* variant = variantWrap->getInternalInstance();
//   QTextCursor cursor = variant->value<QTextCursor>();
//   auto instance = QTextCursorWrap::constructor.New(
//       {Napi::External<QTextCursor>::New(env, new QTextCursor(cursor))});
//   return instance;
// }
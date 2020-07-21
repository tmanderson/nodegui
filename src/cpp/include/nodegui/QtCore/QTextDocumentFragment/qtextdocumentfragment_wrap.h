#pragma once

#include <napi.h>

#include <QTextDocumentFragment>

#include "Extras/Export/export.h"
#include "core/Component/component_macro.h"

class DLL_EXPORT QTextDocumentFragmentWrap
    : public Napi::ObjectWrap<QTextDocumentFragmentWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION
 private:
  std::unique_ptr<QTextDocumentFragment> instance;

 public:
  static Napi::FunctionReference constructor;
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QTextDocumentFragmentWrap(const Napi::CallbackInfo& info);
  ~QTextDocumentFragmentWrap();
  QTextDocumentFragment* getInternalInstance();
  // Wrapped methods
  Napi::Value isEmpty(const Napi::CallbackInfo& info);
  Napi::Value toHtml(const Napi::CallbackInfo& info);
  Napi::Value toPlainText(const Napi::CallbackInfo& info);
};

namespace StaticQTextDocumentFragmentWrapMethods {
DLL_EXPORT Napi::Value fromHtml(const Napi::CallbackInfo& info);
DLL_EXPORT Napi::Value fromPlainText(const Napi::CallbackInfo& info);
}  // namespace StaticQTextDocumentFragmentWrapMethods
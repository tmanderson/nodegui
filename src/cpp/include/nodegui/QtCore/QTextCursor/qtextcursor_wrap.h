#pragma once

#include <napi.h>

#include <QTextCursor>

#include "Extras/Export/export.h"
#include "core/Component/component_macro.h"

class DLL_EXPORT QTextCursorWrap : public Napi::ObjectWrap<QTextCursorWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION
 private:
  std::unique_ptr<QTextCursor> instance;

 public:
  static Napi::FunctionReference constructor;
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QTextCursorWrap(const Napi::CallbackInfo& info);
  ~QTextCursorWrap();
  QTextCursor* getInternalInstance();
  // Wrapped methods
  // Napi::Value anchor(const Napi::CallbackInfo& info)
  // Napi::Value atBlockEnd(const Napi::CallbackInfo& info)
  // Napi::Value atBlockStart(const Napi::CallbackInfo& info)
  // Napi::Value atEnd(const Napi::CallbackInfo& info)
  // Napi::Value atStart(const Napi::CallbackInfo& info)
  // Napi::Value beginEditBlock(const Napi::CallbackInfo& info)
  // Napi::Value block(const Napi::CallbackInfo& info)
  // Napi::Value blockCharFormat(const Napi::CallbackInfo& info)
  // Napi::Value blockFormat(const Napi::CallbackInfo& info)
  // Napi::Value blockNumber(const Napi::CallbackInfo& info)
  Napi::Value charFormat(const Napi::CallbackInfo& info);
  Napi::Value clearSelection(const Napi::CallbackInfo& info);
  // Napi::Value columnNumber(const Napi::CallbackInfo& info)
  // Napi::Value currentFrame(const Napi::CallbackInfo& info)
  // Napi::Value currentList(const Napi::CallbackInfo& info)
  // Napi::Value currentTable(const Napi::CallbackInfo& info)
  // Napi::Value deleteChar(const Napi::CallbackInfo& info)
  // Napi::Value deletePreviousChar(const Napi::CallbackInfo& info)
  // Napi::Value document(const Napi::CallbackInfo& info)
  // Napi::Value endEditBlock(const Napi::CallbackInfo& info)
  // Napi::Value hasComplexSelection(const Napi::CallbackInfo& info)
  // Napi::Value hasSelection(const Napi::CallbackInfo& info)
  // Napi::Value insertBlock(const Napi::CallbackInfo& info)
  // Napi::Value insertImage(const QImage &image, QString &name = QString(const
  Napi::Value insertText(const Napi::CallbackInfo& info);
  Napi::Value insertHtml(const Napi::CallbackInfo& info);
  Napi::Value movePosition(const Napi::CallbackInfo& info);
  // Napi::CallbackInfo& info) Napi::Value isNull(const Napi::CallbackInfo&
  // info) Napi::Value joinPreviousEditBlock(const Napi::CallbackInfo& info)
  // Napi::Value keepPositionOnInsert(const Napi::CallbackInfo& info)
  // Napi::Object position(const Napi::CallbackInfo& info);
  // Napi::Value positionInBlock(const Napi::CallbackInfo& info)
  // Napi::Value removeSelectedText(const Napi::CallbackInfo& info)
  Napi::Value selectedText(const Napi::CallbackInfo& info);
  Napi::Value selection(const Napi::CallbackInfo& info);
  // Napi::Value selectionEnd(const Napi::CallbackInfo& info);
  // Napi::Value selectionStart(const Napi::CallbackInfo& info);
  // Napi::Value verticalMovementX(const Napi::CallbackInfo& info)
  // Napi::Value visualNavigation(const Napi::CallbackInfo& info)
};

// namespace StaticQTextCursorWrapMethods {
// // DLL_EXPORT Napi::Value fromQVariant(const Napi::CallbackInfo& info);
// }  // namespace StaticQTextCursorWrapMethods
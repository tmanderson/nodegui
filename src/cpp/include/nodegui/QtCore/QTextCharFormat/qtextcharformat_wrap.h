#pragma once

#include <napi.h>

#include <QTextCharFormat>

#include "Extras/Export/export.h"
#include "core/Component/component_macro.h"

class DLL_EXPORT QTextCharFormatWrap : public Napi::ObjectWrap<QTextCharFormatWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION
 private:
  std::unique_ptr<QTextCharFormat> instance;

 public:
  static Napi::FunctionReference constructor;
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QTextCharFormatWrap(const Napi::CallbackInfo& info);
  ~QTextCharFormatWrap();
  QTextCharFormat* getInternalInstance();
  // Wrapped methods
  Napi::Value anchorHref(const Napi::CallbackInfo& info); // ();
  // Napi::Value anchorNames(const Napi::CallbackInfo& info); // ();
  // Napi::Value font(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontCapitalization(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontFamilies(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontFamily(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontFixedPitch(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontHintingPreference(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontItalic(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontKerning(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontLetterSpacing(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontLetterSpacingType(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontOverline(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontPointSize(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontStretch(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontStrikeOut(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontStyleHint(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontStyleName(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontStyleStrategy(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontUnderline(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontWeight(const Napi::CallbackInfo& info); // ();
  // Napi::Value fontWordSpacing(const Napi::CallbackInfo& info); // ();
  Napi::Value isAnchor(const Napi::CallbackInfo& info); // ();
  // Napi::Value isValid(const Napi::CallbackInfo& info); // ();
  Napi::Value setAnchor(const Napi::CallbackInfo& info); // (bool anchor);
  Napi::Value setAnchorHref(const Napi::CallbackInfo& info); // (const QString &value);
  // Napi::Value setAnchorNames(const Napi::CallbackInfo& info); // (const QStringList &names);
  // Napi::Value setFont(const Napi::CallbackInfo& info); // (const QFont &font, QTextCharFormat::FontPropertiesInheritanceBehavior behavior);
  // Napi::Value setFontCapitalization(const Napi::CallbackInfo& info); // (QFont::Capitalization capitalization);
  // Napi::Value setFontFamilies(const Napi::CallbackInfo& info); // (const QStringList &families);
  // Napi::Value setFontFamily(const Napi::CallbackInfo& info); // (const QString &family);
  // Napi::Value setFontFixedPitch(const Napi::CallbackInfo& info); // (bool fixedPitch);
  // Napi::Value setFontHintingPreference(const Napi::CallbackInfo& info); // (QFont::HintingPreference hintingPreference);
  // Napi::Value setFontItalic(const Napi::CallbackInfo& info); // (bool italic);
  // Napi::Value setFontKerning(const Napi::CallbackInfo& info); // (bool enable);
  // Napi::Value setFontLetterSpacing(const Napi::CallbackInfo& info); // (qreal spacing);
  // Napi::Value setFontLetterSpacingType(const Napi::CallbackInfo& info); // (QFont::SpacingType letterSpacingType);
  // Napi::Value setFontOverline(const Napi::CallbackInfo& info); // (bool overline);
  // Napi::Value setFontPointSize(const Napi::CallbackInfo& info); // (qreal size);
  // Napi::Value setFontStretch(const Napi::CallbackInfo& info); // (int factor);
  // Napi::Value setFontStrikeOut(const Napi::CallbackInfo& info); // (bool strikeOut);
  // Napi::Value setFontStyleHint(const Napi::CallbackInfo& info); // (QFont::StyleHint hint, QFont::StyleStrategy strategy = QFont::PreferDefault);
  // Napi::Value setFontStyleName(const Napi::CallbackInfo& info); // (const QString &styleName);
  // Napi::Value setFontStyleStrategy(const Napi::CallbackInfo& info); // (QFont::StyleStrategy strategy);
  // Napi::Value setFontUnderline(const Napi::CallbackInfo& info); // (bool underline);
  // Napi::Value setFontWeight(const Napi::CallbackInfo& info); // (int weight);
  // Napi::Value setFontWordSpacing(const Napi::CallbackInfo& info); // (qreal spacing);
  // Napi::Value setTextOutline(const Napi::CallbackInfo& info); // (const QPen &pen);
  // Napi::Value setToolTip(const Napi::CallbackInfo& info); // (const QString &text);
  // Napi::Value setUnderlineColor(const Napi::CallbackInfo& info); // (const QColor &color);
  // Napi::Value setUnderlineStyle(const Napi::CallbackInfo& info); // (QTextCharFormat::UnderlineStyle style);
  // Napi::Value setVerticalAlignment(const Napi::CallbackInfo& info); // (QTextCharFormat::VerticalAlignment alignment);
  // Napi::Value textOutline(const Napi::CallbackInfo& info); // ();
  // Napi::Value toolTip(const Napi::CallbackInfo& info); // ();
  // Napi::Value underlineColor(const Napi::CallbackInfo& info); // ();
  // Napi::Value underlineStyle(const Napi::CallbackInfo& info); // ();
  // Napi::Value verticalAlignment(const Napi::CallbackInfo& info); // ();
};
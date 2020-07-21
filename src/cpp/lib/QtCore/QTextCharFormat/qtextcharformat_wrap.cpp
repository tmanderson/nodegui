#include "QtCore/QTextCharFormat/qtextcharformat_wrap.h"

#include "Extras/Utils/nutils.h"
#include "QtCore/QTextDocumentFragment/qtextdocumentfragment_wrap.h"
#include "QtCore/QVariant/qvariant_wrap.h"

Napi::FunctionReference QTextCharFormatWrap::constructor;

Napi::Object QTextCharFormatWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QTextCharFormat";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("anchorHref", &QTextCharFormatWrap::anchorHref),
        // InstanceMethod("anchorNames", &QTextCharFormatWrap::anchorNames),
        // InstanceMethod("font", &QTextCharFormatWrap::font),
        // InstanceMethod("fontCapitalization", &QTextCharFormatWrap::fontCapitalization),
        // InstanceMethod("fontFamilies", &QTextCharFormatWrap::fontFamilies),
        // InstanceMethod("fontFamily", &QTextCharFormatWrap::fontFamily),
        // InstanceMethod("fontFixedPitch", &QTextCharFormatWrap::fontFixedPitch),
        // InstanceMethod("fontHintingPreference", &QTextCharFormatWrap::fontHintingPreference),
        // InstanceMethod("fontItalic", &QTextCharFormatWrap::fontItalic),
        // InstanceMethod("fontKerning", &QTextCharFormatWrap::fontKerning),
        // InstanceMethod("fontLetterSpacing", &QTextCharFormatWrap::fontLetterSpacing),
        // InstanceMethod("fontLetterSpacingType", &QTextCharFormatWrap::fontLetterSpacingType),
        // InstanceMethod("fontOverline", &QTextCharFormatWrap::fontOverline),
        // InstanceMethod("fontPointSize", &QTextCharFormatWrap::fontPointSize),
        // InstanceMethod("fontStretch", &QTextCharFormatWrap::fontStretch),
        // InstanceMethod("fontStrikeOut", &QTextCharFormatWrap::fontStrikeOut),
        // InstanceMethod("fontStyleHint", &QTextCharFormatWrap::fontStyleHint),
        // InstanceMethod("fontStyleName", &QTextCharFormatWrap::fontStyleName),
        // InstanceMethod("fontStyleStrategy", &QTextCharFormatWrap::fontStyleStrategy),
        // InstanceMethod("fontUnderline", &QTextCharFormatWrap::fontUnderline),
        // InstanceMethod("fontWeight", &QTextCharFormatWrap::fontWeight),
        // InstanceMethod("fontWordSpacing", &QTextCharFormatWrap::fontWordSpacing),
        InstanceMethod("isAnchor", &QTextCharFormatWrap::isAnchor),
        // InstanceMethod("isValid", &QTextCharFormatWrap::isValid),
        InstanceMethod("setAnchor", &QTextCharFormatWrap::setAnchor),
        InstanceMethod("setAnchorHref", &QTextCharFormatWrap::setAnchorHref),
        // InstanceMethod("setAnchorNames", &QTextCharFormatWrap::setAnchorNames),
        // InstanceMethod("setFont", &QTextCharFormatWrap::setFont),
        // InstanceMethod("setFontCapitalization", &QTextCharFormatWrap::setFontCapitalization),
        // InstanceMethod("setFontFamilies", &QTextCharFormatWrap::setFontFamilies),
        // InstanceMethod("setFontFamily", &QTextCharFormatWrap::setFontFamily),
        // InstanceMethod("setFontFixedPitch", &QTextCharFormatWrap::setFontFixedPitch),
        // InstanceMethod("setFontHintingPreference", &QTextCharFormatWrap::setFontHintingPreference),
        // InstanceMethod("setFontItalic", &QTextCharFormatWrap::setFontItalic),
        // InstanceMethod("setFontKerning", &QTextCharFormatWrap::setFontKerning),
        // InstanceMethod("setFontLetterSpacing", &QTextCharFormatWrap::setFontLetterSpacing),
        // InstanceMethod("setFontLetterSpacingType", &QTextCharFormatWrap::setFontLetterSpacingType),
        // InstanceMethod("setFontOverline", &QTextCharFormatWrap::setFontOverline),
        // InstanceMethod("setFontPointSize", &QTextCharFormatWrap::setFontPointSize),
        // InstanceMethod("setFontStretch", &QTextCharFormatWrap::setFontStretch),
        // InstanceMethod("setFontStrikeOut", &QTextCharFormatWrap::setFontStrikeOut),
        // InstanceMethod("setFontStyleHint", &QTextCharFormatWrap::setFontStyleHint),
        // InstanceMethod("setFontStyleName", &QTextCharFormatWrap::setFontStyleName),
        // InstanceMethod("setFontStyleStrategy", &QTextCharFormatWrap::setFontStyleStrategy),
        // InstanceMethod("setFontUnderline", &QTextCharFormatWrap::setFontUnderline),
        // InstanceMethod("setFontWeight", &QTextCharFormatWrap::setFontWeight),
        // InstanceMethod("setFontWordSpacing", &QTextCharFormatWrap::setFontWordSpacing),
        // InstanceMethod("setTextOutline", &QTextCharFormatWrap::setTextOutline),
        // InstanceMethod("setToolTip", &QTextCharFormatWrap::setToolTip),
        // InstanceMethod("setUnderlineColor", &QTextCharFormatWrap::setUnderlineColor),
        // InstanceMethod("setUnderlineStyle", &QTextCharFormatWrap::setUnderlineStyle),
        // InstanceMethod("setVerticalAlignment", &QTextCharFormatWrap::setVerticalAlignment),
        // InstanceMethod("textOutline", &QTextCharFormatWrap::textOutline),
        // InstanceMethod("toolTip", &QTextCharFormatWrap::toolTip),
        // InstanceMethod("underlineColor", &QTextCharFormatWrap::underlineColor),
        // InstanceMethod("underlineStyle", &QTextCharFormatWrap::underlineStyle),
        // InstanceMethod("verticalAlignment", &QTextCharFormatWrap::verticalAlignment),
       COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QTextCharFormatWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QTextCharFormatWrap::QTextCharFormatWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QTextCharFormatWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    this->instance = std::unique_ptr<QTextCharFormat>(
        info[0].As<Napi::External<QTextCharFormat>>().Data());
  } else if (info.Length() == 0) {
    this->instance = std::make_unique<QTextCharFormat>();
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QTextCharFormatWrap::~QTextCharFormatWrap() { this->instance.reset(); }

QTextCharFormat* QTextCharFormatWrap::getInternalInstance() {
  return this->instance.get();
}

Napi::Value QTextCharFormatWrap::anchorHref(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  QString text = this->instance->anchorHref();
  Napi::String txt = Napi::String::New(env, text.toStdString());
  return Napi::Value::From(env, txt);
}
// Napi::Value QTextCharFormatWrap::anchorNames(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::font(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontCapitalization(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontFamilies(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontFamily(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontFixedPitch(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontHintingPreference(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontItalic(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontKerning(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontLetterSpacing(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontLetterSpacingType(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontOverline(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontPointSize(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontStretch(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontStrikeOut(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontStyleHint(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontStyleName(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontStyleStrategy(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontUnderline(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontWeight(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::fontWordSpacing(const Napi::CallbackInfo& info) {}
Napi::Value QTextCharFormatWrap::isAnchor(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  bool isAnchorValue = this->instance->isAnchor();
  Napi::Boolean isAnchor = Napi::Boolean::New(env, isAnchorValue);
  return Napi::Value::From(env, isAnchor);
}
// Napi::Value QTextCharFormatWrap::isValid(const Napi::CallbackInfo& info) {}
Napi::Value QTextCharFormatWrap::setAnchor(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  bool isAnchor = info[0].As<Napi::Boolean>();
  this->instance->setAnchor(isAnchor);

  return env.Null();
}
Napi::Value QTextCharFormatWrap::setAnchorHref(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  std::string str = info[0].As<Napi::String>().Utf8Value();
  QString href = QString::fromUtf8(str.c_str());
  this->instance->setAnchorHref(href);
  
  return env.Null();
}
// Napi::Value QTextCharFormatWrap::setAnchorNames(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFont(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFont(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontCapitalization(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontFamilies(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontFamily(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontFixedPitch(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontHintingPreference(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontItalic(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontKerning(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontLetterSpacing(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontLetterSpacingType(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontOverline(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontPointSize(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontStretch(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontStrikeOut(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontStyleHint(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontStyleName(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontStyleStrategy(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontUnderline(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontWeight(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setFontWordSpacing(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setTextOutline(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setToolTip(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setUnderlineColor(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setUnderlineStyle(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::setVerticalAlignment(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::textOutline(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::toolTip(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::underlineColor(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::underlineStyle(const Napi::CallbackInfo& info) {}
// Napi::Value QTextCharFormatWrap::verticalAlignment(const Napi::CallbackInfo& info) {}
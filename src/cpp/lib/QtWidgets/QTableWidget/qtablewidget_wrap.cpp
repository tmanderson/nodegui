#include "QtWidgets/QTableWidget/qtablewidget_wrap.h"

#include "Extras/Utils/nutils.h"
#include "QtWidgets/QTableWidgetItem/qtablewidgetitem_wrap.h"
#include "QtWidgets/QWidget/qwidget_wrap.h"

Napi::FunctionReference QTableWidgetWrap::constructor;

Napi::Object QTableWidgetWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QTableWidget";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("selectedRanges", &QTableWidgetWrap::selectedRanges),
       InstanceMethod("closePersistentEditor",
                      &QTableWidgetWrap::closePersistentEditor),
       InstanceMethod("editItem", &QTableWidgetWrap::editItem),
       InstanceMethod("setCellWidget", &QTableWidgetWrap::setCellWidget),
       InstanceMethod("setItem", &QTableWidgetWrap::setItem),
       InstanceMethod("setHorizontalHeaderItem",
                      &QTableWidgetWrap::setHorizontalHeaderItem),
       InstanceMethod("setHorizontalHeaderLabels",
                      &QTableWidgetWrap::setHorizontalHeaderLabels),
       InstanceMethod("setVerticalHeaderItem",
                      &QTableWidgetWrap::setVerticalHeaderItem),
       InstanceMethod("setVerticalHeaderLabels",
                      &QTableWidgetWrap::setVerticalHeaderLabels),
       InstanceMethod("clear", &QTableWidgetWrap::clear),
       InstanceMethod("clearContents", &QTableWidgetWrap::clearContents),
       InstanceMethod("insertColumn", &QTableWidgetWrap::insertColumn),
       InstanceMethod("removeColumn", &QTableWidgetWrap::removeColumn),
       InstanceMethod("insertRow", &QTableWidgetWrap::insertRow),
       InstanceMethod("removeRow", &QTableWidgetWrap::removeRow),
       InstanceMethod("scrollToItem", &QTableWidgetWrap::scrollToItem),
       // FROM TABLEVIEW
       InstanceMethod("hideColumn", &QTableWidgetWrap::hideColumn),
       InstanceMethod("hideRow", &QTableWidgetWrap::hideRow),
       InstanceMethod("resizeColumnToContents",
                      &QTableWidgetWrap::resizeColumnToContents),
       InstanceMethod("resizeColumnsToContents",
                      &QTableWidgetWrap::resizeColumnsToContents),
       InstanceMethod("resizeRowToContents",
                      &QTableWidgetWrap::resizeRowToContents),
       InstanceMethod("resizeRowsToContents",
                      &QTableWidgetWrap::resizeRowsToContents),
       InstanceMethod("selectColumn", &QTableWidgetWrap::selectColumn),
       InstanceMethod("selectRow", &QTableWidgetWrap::selectRow),
       InstanceMethod("setShowGrid", &QTableWidgetWrap::setShowGrid),
       InstanceMethod("showGrid", &QTableWidgetWrap::showGrid),
       InstanceMethod("showColumn", &QTableWidgetWrap::showColumn),
       InstanceMethod("showRow", &QTableWidgetWrap::showRow),
       InstanceMethod("sortByColumn", &QTableWidgetWrap::sortByColumn),
       InstanceMethod("setColumnWidth", &QTableWidgetWrap::setColumnWidth),
       InstanceMethod("setRowHeight", &QTableWidgetWrap::setRowHeight),
       InstanceMethod("columnCount", &QTableWidgetWrap::columnCount),
       InstanceMethod("rowCount", &QTableWidgetWrap::rowCount),
       InstanceMethod("setColumnCount", &QTableWidgetWrap::setColumnCount),
       InstanceMethod("setRowCount", &QTableWidgetWrap::setRowCount),
       InstanceMethod("setSortingEnabled",
                      &QTableWidgetWrap::setSortingEnabled),
       InstanceMethod("isSortingEnabled", &QTableWidgetWrap::isSortingEnabled),

       QABSTRACTSCROLLAREA_WRAPPED_METHODS_EXPORT_DEFINE(QTableWidgetWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

NTableWidget* QTableWidgetWrap::getInternalInstance() { return this->instance; }
QTableWidgetWrap::~QTableWidgetWrap() {
  extrautils::safeDelete(this->instance);
}

QTableWidgetWrap::QTableWidgetWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QTableWidgetWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 2 || info.Length() == 3) {
    int rows = info[0].As<Napi::Number>().Int32Value();
    int columns = info[1].As<Napi::Number>().Int32Value();

    if (info.Length() == 3) {
      Napi::Object parentObject = info[2].As<Napi::Object>();
      NodeWidgetWrap* parentWidgetWrap =
          Napi::ObjectWrap<NodeWidgetWrap>::Unwrap(parentObject);
      this->instance = new NTableWidget(
          rows, columns, parentWidgetWrap->getInternalInstance());
    } else {
      this->instance = new NTableWidget(rows, columns);
    }

  } else if (info.Length() == 1) {
    Napi::Object parentObject = info[0].As<Napi::Object>();
    NodeWidgetWrap* parentWidgetWrap =
        Napi::ObjectWrap<NodeWidgetWrap>::Unwrap(parentObject);
    this->instance = new NTableWidget(parentWidgetWrap->getInternalInstance());
  } else if (info.Length() == 0) {
    this->instance = new NTableWidget();
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureQWidget(
      this->getInternalInstance(), this->getInternalInstance()->getFlexNode(),
      false);
}
Napi::Value QTableWidgetWrap::selectedRanges(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  QList<QTableWidgetSelectionRange> range = this->instance->selectedRanges();
  Napi::Array napiRange = Napi::Array::New(env, range.size());

  for (int i = 0; i < range.size(); i++) {
    int topRow = range[0].topRow();
    int leftColumn = range[0].leftColumn();
    int bottomRow = range[0].bottomRow();
    int rightColumn = range[0].rightColumn();
    int columnCount = range[0].columnCount();
    int rowCount = range[0].rowCount();
    Napi::Object newRange = Napi::Object::New(env);
    newRange.Set("topRow", Napi::Number::New(env, topRow));
    newRange.Set("leftColumn", Napi::Number::New(env, leftColumn));
    newRange.Set("bottomRow", Napi::Number::New(env, bottomRow));
    newRange.Set("rightColumn", Napi::Number::New(env, rightColumn));
    newRange.Set("columnCount", Napi::Number::New(env, columnCount));
    newRange.Set("rowCount", Napi::Number::New(env, rowCount));
    napiRange[i] = newRange;
  }
  return napiRange;
  return env.Null();
}
Napi::Value QTableWidgetWrap::closePersistentEditor(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::Object itemObject = info[0].As<Napi::Object>();
  QTableWidgetItemWrap* itemWrap =
      Napi::ObjectWrap<QTableWidgetItemWrap>::Unwrap(itemObject);

  this->instance->closePersistentEditor(itemWrap->getInternalInstance());
  return env.Null();
}

Napi::Value QTableWidgetWrap::editItem(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::Object itemObject = info[0].As<Napi::Object>();
  QTableWidgetItemWrap* itemWrap =
      Napi::ObjectWrap<QTableWidgetItemWrap>::Unwrap(itemObject);

  this->instance->editItem(itemWrap->getInternalInstance());
  return env.Null();
}

Napi::Value QTableWidgetWrap::setCellWidget(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int row = info[0].As<Napi::Number>().Int32Value();
  int column = info[1].As<Napi::Number>().Int32Value();
  Napi::Object widgetObject = info[2].As<Napi::Object>();
  NodeWidgetWrap* widgetWrap =
      Napi::ObjectWrap<NodeWidgetWrap>::Unwrap(widgetObject);

  this->instance->setCellWidget(row, column, widgetWrap->getInternalInstance());
  return env.Null();
}
Napi::Value QTableWidgetWrap::setItem(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int row = info[0].As<Napi::Number>().Int32Value();
  int column = info[1].As<Napi::Number>().Int32Value();
  Napi::Object itemObject = info[2].As<Napi::Object>();
  QTableWidgetItemWrap* itemWrap =
      Napi::ObjectWrap<QTableWidgetItemWrap>::Unwrap(itemObject);

  this->instance->setItem(row, column, itemWrap->getInternalInstance());
  return env.Null();
}
Napi::Value QTableWidgetWrap::setHorizontalHeaderItem(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int column = info[0].As<Napi::Number>().Int32Value();
  Napi::Object itemObject = info[1].As<Napi::Object>();
  QTableWidgetItemWrap* itemWrap =
      Napi::ObjectWrap<QTableWidgetItemWrap>::Unwrap(itemObject);

  this->instance->setHorizontalHeaderItem(column,
                                          itemWrap->getInternalInstance());
  return env.Null();
}

Napi::Value QTableWidgetWrap::setHorizontalHeaderLabels(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::Array labelsNapi = info[0].As<Napi::Array>();
  QList<QString> list;
  for (int i = 0; i < labelsNapi.Length(); i++) {
    Napi::Value labelNapi = labelsNapi[i];
    list.append(labelNapi.As<Napi::String>().Utf8Value().c_str());
  }
  QStringList labels = QStringList(list);

  this->instance->setHorizontalHeaderLabels(labels);
  return env.Null();
}
Napi::Value QTableWidgetWrap::setVerticalHeaderItem(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int row = info[0].As<Napi::Number>().Int32Value();
  Napi::Object itemObject = info[0].As<Napi::Object>();
  QTableWidgetItemWrap* itemWrap =
      Napi::ObjectWrap<QTableWidgetItemWrap>::Unwrap(itemObject);

  this->instance->setVerticalHeaderItem(row, itemWrap->getInternalInstance());
  return env.Null();
}

Napi::Value QTableWidgetWrap::setVerticalHeaderLabels(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::Array labelsNapi = info[0].As<Napi::Array>();
  QList<QString> list;
  for (int i = 0; i < labelsNapi.Length(); i++) {
    Napi::Value labelNapi = labelsNapi[i];
    list.append(labelNapi.As<Napi::String>().Utf8Value().c_str());
  }
  QStringList labels = QStringList(list);

  this->instance->setVerticalHeaderLabels(labels);
  return env.Null();
}

Napi::Value QTableWidgetWrap::clear(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  this->instance->clear();
  return env.Null();
}
Napi::Value QTableWidgetWrap::clearContents(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  this->instance->clearContents();
  return env.Null();
}
Napi::Value QTableWidgetWrap::insertColumn(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int column = info[0].As<Napi::Number>().Int32Value();
  this->instance->insertColumn(column);
  return env.Null();
}
Napi::Value QTableWidgetWrap::removeColumn(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int column = info[0].As<Napi::Number>().Int32Value();
  this->instance->removeColumn(column);
  return env.Null();
}
Napi::Value QTableWidgetWrap::insertRow(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int row = info[0].As<Napi::Number>().Int32Value();
  this->instance->insertRow(row);
  return env.Null();
}
Napi::Value QTableWidgetWrap::removeRow(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int row = info[0].As<Napi::Number>().Int32Value();
  this->instance->removeRow(row);
  return env.Null();
}
Napi::Value QTableWidgetWrap::scrollToItem(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::Object itemObject = info[0].As<Napi::Object>();
  QTableWidgetItemWrap* itemWrap =
      Napi::ObjectWrap<QTableWidgetItemWrap>::Unwrap(itemObject);

  int hintInt = info[1].As<Napi::Number>().Int32Value();
  QAbstractItemView::ScrollHint hint =
      static_cast<QAbstractItemView::ScrollHint>(hintInt);
  this->instance->scrollToItem(itemWrap->getInternalInstance(), hint);
  return env.Null();
}
// FROM TABLEVIEW

Napi::Value QTableWidgetWrap::hideColumn(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int column = info[0].As<Napi::Number>().Int32Value();
  this->instance->hideColumn(column);
  return env.Null();
}
Napi::Value QTableWidgetWrap::hideRow(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int row = info[0].As<Napi::Number>().Int32Value();
  this->instance->hideRow(row);
  return env.Null();
}

Napi::Value QTableWidgetWrap::resizeColumnToContents(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int column = info[0].As<Napi::Number>().Int32Value();
  this->instance->resizeColumnToContents(column);
  return env.Null();
}
Napi::Value QTableWidgetWrap::resizeColumnsToContents(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->instance->resizeColumnsToContents();
  return env.Null();
}
Napi::Value QTableWidgetWrap::resizeRowToContents(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int row = info[0].As<Napi::Number>().Int32Value();
  this->instance->resizeRowToContents(row);
  return env.Null();
}
Napi::Value QTableWidgetWrap::resizeRowsToContents(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->instance->resizeRowsToContents();
  return env.Null();
}

Napi::Value QTableWidgetWrap::selectColumn(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int column = info[0].As<Napi::Number>().Int32Value();
  this->instance->selectColumn(column);
  return env.Null();
}
Napi::Value QTableWidgetWrap::selectRow(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int row = info[0].As<Napi::Number>().Int32Value();
  this->instance->selectRow(row);
  return env.Null();
}

Napi::Value QTableWidgetWrap::setShowGrid(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  bool show = info[0].As<Napi::Boolean>().Value();
  this->instance->setShowGrid(show);
  return env.Null();
}
Napi::Value QTableWidgetWrap::showGrid(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  bool show = this->instance->showGrid();
  return Napi::Boolean::New(env, show);
}

Napi::Value QTableWidgetWrap::showColumn(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int column = info[0].As<Napi::Number>().Int32Value();
  this->instance->showColumn(column);
  return env.Null();
}
Napi::Value QTableWidgetWrap::showRow(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int row = info[0].As<Napi::Number>().Int32Value();
  this->instance->showRow(row);
  return env.Null();
}
Napi::Value QTableWidgetWrap::sortByColumn(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int column = info[0].As<Napi::Number>().Int32Value();
  int orderInt = info[1].As<Napi::Number>().Int32Value();
  Qt::SortOrder order = static_cast<Qt::SortOrder>(orderInt);
  this->instance->sortByColumn(column, order);
  return env.Null();
}
Napi::Value QTableWidgetWrap::setColumnWidth(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int column = info[0].As<Napi::Number>().Int32Value();
  int width = info[1].As<Napi::Number>().Int32Value();
  this->instance->setColumnWidth(column, width);
  return env.Null();
}
Napi::Value QTableWidgetWrap::setRowHeight(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int row = info[0].As<Napi::Number>().Int32Value();
  int height = info[1].As<Napi::Number>().Int32Value();
  this->instance->setRowHeight(row, height);
  return env.Null();
}
Napi::Value QTableWidgetWrap::columnCount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int count = static_cast<int>(this->instance->columnCount());
  return Napi::Number::New(env, count);
}
Napi::Value QTableWidgetWrap::rowCount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int count = static_cast<int>(this->instance->rowCount());
  return Napi::Number::New(env, count);
}
Napi::Value QTableWidgetWrap::setColumnCount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int count = info[0].As<Napi::Number>().Int32Value();
  this->instance->setColumnCount(count);
  return env.Null();
}
Napi::Value QTableWidgetWrap::setRowCount(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int count = info[0].As<Napi::Number>().Int32Value();
  this->instance->setRowCount(count);
  return env.Null();
}

Napi::Value QTableWidgetWrap::setSortingEnabled(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  bool enable = info[0].As<Napi::Boolean>().Value();
  this->instance->setSortingEnabled(enable);
  return env.Null();
}
Napi::Value QTableWidgetWrap::isSortingEnabled(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  bool enabled = this->instance->isSortingEnabled();
  return Napi::Boolean::New(env, enabled);
}

import {
  QMainWindow,
  QLabel,
  QCheckBox,
  QLineEdit,
  QPushButton,
  QProgressBar,
  QRadioButton,
  FlexLayout,
  QWidget,
  QIcon,
  QDial,
  QDialEvents,
  QPlainTextEdit
} from "./index";
import { QScrollArea } from "./lib/QtWidgets/QScrollArea";
import { QPixmap } from "./lib/QtGui/QPixmap";
import { Orientation } from "./lib/QtEnums";

const path = require("path");

const win = new QMainWindow();

const label = new QLabel();
label.setText("Hello world 🧙");
label.setInlineStyle("font-size: 20px;");

const checkbox = new QCheckBox();
checkbox.setText("Check me out?");
checkbox.setObjectName("check");
checkbox.setChecked(true);

const dial = new QDial();
checkbox.setObjectName("dial");
dial.setWrapping(true);
dial.setNotchesVisible(true);
dial.setSingleStep(10);
dial.setSingleStep(5);
dial.setMinimum(55);
dial.setMaximum(95);
setInterval(() => {
  dial.setValue(Math.floor(Math.random() * 100));
  console.log(dial.minimum(), dial.maximum(), dial.value());
}, 500);
dial.addEventListener(QDialEvents.sliderReleased, () => {
  console.log('RELEASED!');
});
dial.addEventListener(QDialEvents.sliderPressed, () => {
  console.log('PRESSED!');
});

const lineEdit = new QLineEdit();
lineEdit.setPlaceholderText("Enter your thoughts here");
lineEdit.setObjectName("editable");

const button = new QPushButton();
button.setText("Push Push Push!");
button.setObjectName("btn");
button.setFlat(true);

const icon = new QIcon(
  path.resolve(__dirname, "../extras/assets/start_icon.png")
);
button.setIcon(icon);

const progressbar = new QProgressBar();
progressbar.setValue(6);
progressbar.setMinimum(1);
progressbar.setMaximum(15);

const radioButton = new QRadioButton();
radioButton.setText("Roger that!");

const rootView = new QWidget();
rootView.setObjectName("root");
rootView.setLayout(new FlexLayout());

const textEdit = new QPlainTextEdit();
textEdit.setPlainText("Hello");

const scrollArea = new QScrollArea();
scrollArea.setInlineStyle("flex: 1; width:'100%';");

const imageLabel = new QLabel();
const pixmap = new QPixmap(
  path.resolve(__dirname, "../extras/assets/kitchen.png")
);
imageLabel.setPixmap(pixmap);
scrollArea.setWidget(imageLabel);

if (rootView.layout) {
  rootView.layout.addWidget(label);
  rootView.layout.addWidget(checkbox);
  rootView.layout.addWidget(radioButton);
  rootView.layout.addWidget(lineEdit);
  rootView.layout.addWidget(button);
  rootView.layout.addWidget(progressbar);
  rootView.layout.addWidget(textEdit);
  rootView.layout.addWidget(scrollArea);
  rootView.layout.addWidget(dial);
}

win.setCentralWidget(rootView);
win.setStyleSheet(`
  #root {
    flex: 1;
    height: '100%';
    align-items: 'center';
    justify-content: 'space-around';
  }
`);

win.resize(400, 400);
win.show();

(global as any).win = win; // To prevent win from being garbage collected.

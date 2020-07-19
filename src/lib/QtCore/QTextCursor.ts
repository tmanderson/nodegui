import { NativeElement, Component } from '../core/Component';
import addon from '../utils/addon';
import { checkIfNativeElement } from '../utils/helpers';
import { QTextDocumentFragment } from './QTextDocumentFragment';
import { QVariant } from './QVariant';
import { QPoint } from './QPoint';

enum MoveOperation {
    NoMove = 0,
    Start = 1,
    StartOfLine = 3,
    StartOfBlock = 4,
    StartOfWord = 5,
    PreviousBlock = 6,
    NextWord = 18,
}

enum MoveMode {
    MoveAnchor = 0,
    KeepAnchor = 1,
}

/**
 * The QTextCursor class defines a point in the plane using integer precision.
 */
export class QTextCursor extends Component {
    static MoveOperation = MoveOperation;
    static MoveMode = MoveMode;

    native: NativeElement;
    constructor();
    constructor(nativeElement: NativeElement);
    constructor(x?: number, y?: number);
    constructor(arg?: NativeElement | number, y = 0) {
        super();
        if (checkIfNativeElement(arg)) {
            this.native = arg as NativeElement;
        } else if (typeof arg === 'number') {
            this.native = new addon.QTextCursor(arg);
        } else {
            this.native = new addon.QTextCursor();
        }
    }
    clearSelection(): void {
        this.native.clearSelection();
    }
    selection(): QTextDocumentFragment {
        return this.native.selection();
    }
    selectedText(): string {
        return this.native.selectedText();
    }
    insertText(text: string): void {
        this.native.insertText(text);
    }
    insertHtml(html: string): void {
        this.native.insertHtml(html);
    }
    movePosition(command: MoveOperation | number, mode: MoveMode | number) {
        this.native.movePosition(command, mode);
    }
}

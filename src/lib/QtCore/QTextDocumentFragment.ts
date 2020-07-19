import { NativeElement, Component } from '../core/Component';
import addon from '../utils/addon';
import { checkIfNativeElement } from '../utils/helpers';
import { QVariant } from './QVariant';
import { QPoint } from './QPoint';

/**
 * The QTextDocumentFragment class represents a portion of some QDocument
 */
export class QTextDocumentFragment extends Component {
    native: NativeElement;
    constructor();
    constructor(nativeElement: NativeElement);
    constructor(x?: number, y?: number);
    constructor(arg?: NativeElement | number, y = 0) {
        super();
        if (checkIfNativeElement(arg)) {
            this.native = arg as NativeElement;
        } else if (typeof arg === 'number') {
            this.native = new addon.QTextDocumentFragment(arg);
        } else {
            this.native = new addon.QTextDocumentFragment();
        }
    }
    isEmpty(): boolean {
        return this.native.isEmpty()
    }
    toHtml(): string {
        return this.native.toHtml();
    }
    toPlainText(): string {
        return this.native.toPlainText();
    }
    fromHtml(): string {
        return this.native.toHtml();
    }
    fromPlainText(): string {
        return this.native.toPlainText();
    }
    static fromHtml(html: string): QTextDocumentFragment {
        return new QTextDocumentFragment(addon.QTextDocumentFragment.fromHtml(html));
    }
    static fromPlainText(text: string): QTextDocumentFragment {
        return new QTextDocumentFragment(addon.QTextDocumentFragment.fromPlainText(text));
    }
}

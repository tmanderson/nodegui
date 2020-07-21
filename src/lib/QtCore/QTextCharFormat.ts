import { NativeElement, Component } from '../core/Component';
import addon from '../utils/addon';
import { checkIfNativeElement } from '../utils/helpers';

/**
 * The QTextCharFormat class defines a point in the plane using integer precision.
 */
export class QTextCharFormat extends Component {
    native: NativeElement;
    constructor();
    constructor(nativeElement: NativeElement);
    constructor(x?: number, y?: number);
    constructor(arg?: NativeElement | number, y = 0) {
        super();
        if (checkIfNativeElement(arg)) {
            this.native = arg as NativeElement;
        } else if (typeof arg === 'number') {
            this.native = new addon.QTextCharFormat(arg);
        } else {
            this.native = new addon.QTextCharFormat();
        }
    }
    
    anchorHref(): string {
        return this.native.anchorHref();
    }
    isAnchor(): boolean {
        return this.native.isAnchor();
    }
    setAnchor(isAnchor: boolean): void {
        this.native.setAnchor(isAnchor);
    }
    setAnchorHref(path: string): void {
        this.native.setAnchorHref(path);
    }
}

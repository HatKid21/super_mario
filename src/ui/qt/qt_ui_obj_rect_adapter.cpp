#include "qt_ui_obj_rect_adapter.hpp"

using hatkid::QtUIObjectRectAdapter;

QRectF QtUIObjectRectAdapter::getBounds() const noexcept {
    return QRectF(
        biv::Rect::get_x(),
        biv::Rect::get_y(),
        width,
        biv::Rect::get_height()
    );
}

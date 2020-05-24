#include "GUI.h"

GUI::GUI(Service& srv, QWidget *parent)
    :srv{ srv }, QWidget(parent)
{
    ui.setupUi(this);
}
